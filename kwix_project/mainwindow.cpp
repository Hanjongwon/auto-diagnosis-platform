#include "mainwindow.h"
#include "QDebug"
#include "ui_mainwindow.h"

#include "stdio.h"
#include <QComboBox>
#include <QCoreApplication>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QString>
#include <QUrl>
#include <QtCore>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QtSql>
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <pigpio.h>
#include <qcombobox.h>
#include <qmath.h>
#include <softPwm.h>
#include <string>
#include <sys/time.h>
#include <vector>
#include <wiringPi.h>
QPalette covid;
using namespace std;
using namespace cv;

bool resume = false;
bool start = false;
bool filledMotor_go = false;
bool rslt_flag = false;
bool FLAG_FILLED = false;

static int PIN_LED = 2;
static int PIN_MOTOR = 1;

float R, G, B, RG, RB, GB, S_tmp, SAT, LUM;
double sum_RGB, RG_sq, num, decim, H_tmp, HUE;

float rslt_avg = 0.0;
double rslt_min = 100.0;
double rslt_max = 0.0;

int pwm_value = 2100;
int sequence = 1;
int reaction_time;
int tmb_time;
int filled_stack = 0;
int empty_stack = 0;
int fs_needs = 10;
int es_needs = 15;
int cnt = 0;
int cropped_x = 225;
int cropped_y = 147;
int cropped_w = 160;
int cropped_h = 160;
int old_time = 0;
long curTime2 = 0;
long prevTime = 0;
long secTime = 0;
float fps = 0;
bool delay_tmp_ = true;
QString name;
QString location;

String modelfile_empty = "RPI_empty210308.xml";
String modelfile_filled = "rpi_filled210423.xml";
CascadeClassifier objectDetector_empty;
CascadeClassifier objectDetector_filled;

vector<Rect> objects_empty;
vector<Rect> objects_filled;

void digitalPwmWrite(); // f
void motor_go();
void DB_Connect(int);

QThread *mthread = QThread::create(digitalPwmWrite);
static QString UserConcentration = "0.12ng/ml";
static QString UserLocation;
static QString UserName;
static QDateTime UserDateTime;
static bool UserResult = false;
bool qrOnOff = false;
QStringList qrlist;
class MyThread : public QThread {
private:
  void run() Q_DECL_OVERRIDE {
    qDebug() << __func__ << "in MyThread" << currentThread();
  }
};

void MainWindow::DB_connect() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
  db.setPort(8082);
  db.setHostName("211.212.149.167");
  db.setUserName("KWIX");
  db.setPassword("kwix");       // raspberry
  db.setDatabaseName("userDB"); // db

  if (db.open()) {
    qDebug() << "Database connected";
  } else {
    qDebug() << "Database connect failed";
  }
  QSqlQuery query;
  UserDateTime = QDateTime::currentDateTime();
  // model = new QSqlTableModel(this);
  // model->setTable("COVID19");
  // ui->tableView->setModel(model);
  // ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

  query.prepare("INSERT IGNORE INTO "
                "COVID19(`NAME`,`LOCATION`,`DATETIME`,`CONCENTRATION`,`RESULT`)"
                "VALUES(:NAME,:LOCATION,:DATETIME,:CONCENTRATION,:RESULT)");

  query.bindValue(":NAME", UserName);
  query.bindValue(":DATETIME", UserDateTime);
  query.bindValue(":CONCENTRATION", UserConcentration);
  query.bindValue(":LOCATION", UserLocation);
  query.bindValue(":RESULT", UserResult);
  /*if (1) {
      //if (Measure > ~) -> result = 1
      UserResult = true;
      query.bindValue(":RESULT", UserResult);
  }
  else {
      UserResult = false;
      query.bindValue(":RESULT", UserResult);
  }
  */

  query.exec();
  db.close();
  qDebug() << "DB closed";

  /*
        if (!query.exec()){
           qDebug() << query.lastError().text();
           qDebug() << "Database Insert failed";
         }
        else {
           qDebug() << "Database Insert success";
           //qDebug() << c;
        }*/

  // qDebug() << "DB closed";
}

// int sum_RGB, R, G, B, RG, RB, GB;

QString userStr = NULL;
int rslt_frm = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->tabWidget->setCurrentIndex(0);
  // ui->webView_result->load(QUrl("http://211.212.149.167:8081"));

  QMainWindow::showNormal();
  wiringPiSetup();
  // gpioInitialise();
  gpioSetMode(23, PI_OUTPUT);
  gpioSetPWMfrequency(23, 500);
  gpioSetPWMrange(23, 2500);
  gpioWrite(23, 1);
  softPwmCreate(PIN_MOTOR, 0, 20); //<-------------------
  pinMode(2, OUTPUT);

  // on_btn_save_clicked();
  setReaction();
  setTmb();
  on_btn_set_save_clicked();
  on_btn_refresh_clicked();

  Camera.set(cv::CAP_PROP_FORMAT, CV_8UC3);
  Camera.set(cv::CAP_PROP_FRAME_WIDTH, 720);
  Camera.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
  if (!objectDetector_empty.load(modelfile_empty)) {
    qDebug() << "invailid modelfile_empty";
  }

  if (!objectDetector_filled.load(modelfile_filled)) {
    qDebug() << "invailid modelfile_filled";
  };
  if (!Camera.open()) {
    return;
  }
  tmrTimer = new QTimer(this);
  connect(tmrTimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
  tmrTimer->start(50);
}

MainWindow::~MainWindow() { delete ui; }
Point from(cropped_x, cropped_y);
Point to(cropped_x + cropped_w, cropped_y + cropped_h);
int avg_x[20][20] = {
    0,
};

Point from_position(cropped_x + 67, cropped_y + 50);
Point to_position(cropped_x + 100, cropped_y + 110);
// value setting //

void MainWindow::setReaction() {
  QFile inputFile(QString(
      "/home/pi//home/pi/build-kwix_project-Desktop-Debug/set_Reaction.txt"));
  inputFile.open(QIODevice::ReadOnly);
  if (!inputFile.isOpen())
    return;
  QTextStream stream(&inputFile);
  for (QString setReaction = stream.readLine(); !setReaction.isNull();
       setReaction = stream.readLine()) {
    qDebug() << setReaction;
    ui->spinBox_Reaction->setValue((setReaction.toInt()) /
                                   60000); //        atoi
  }
}
void MainWindow::setTmb() {
  QFile inputFile(QString(
      "/home/pi//home/pi/build-kwix_project-Desktop-Debug/set_Tmb.txt"));
  inputFile.open(QIODevice::ReadOnly);
  if (!inputFile.isOpen())
    return;
  QTextStream stream(&inputFile);
  for (QString setTmb = stream.readLine(); !setTmb.isNull();
       setTmb = stream.readLine()) {
    qDebug() << setTmb;
    ui->spinBox_Tmb->setValue((setTmb.toInt()) / 60000); //        atoi
  }
}

void MainWindow::processFrameAndUpdateGUI() {
  Camera.grab();          // get from cam
  Camera.retrieve(image); // setting the camera into variable->

  Vec3b rgb; // vector 3d -> 3value( r, g, b)
  Point tmp;

  int rgb_sum_r = 0;
  int rgb_sum_g = 0;
  int rgb_sum_b = 0;
  rgb = image.at<cv::Vec3b>(
      (cropped_x, cropped_y)); // region(=roi), vector for cal rgb value

  int center_y = (int)(cropped_y + cropped_h / 2 - 5);
  int center_x = (int)(cropped_x + cropped_w / 2 - 5);

  for (int y = center_y + 1; y < center_y + 10; y++) {
    for (int x = center_x + 1; x < center_x + 10; x++) {
      tmp.x = x;
      tmp.y = y;
      rgb = image.at<Vec3b>(tmp);

      rgb_sum_r += rgb.val[2];
      rgb_sum_g += rgb.val[1];
      rgb_sum_b += rgb.val[0];
    }

    {
      sum_RGB = rgb_sum_r + rgb_sum_g + rgb_sum_b;

      R = ((rgb_sum_r / 81) * (100 / sum_RGB));
      G = ((rgb_sum_g / 81) * (100 / sum_RGB));
      B = ((rgb_sum_b / 81) * (100 / sum_RGB));

      {
        RG = R - G;
        RB = R - B;
        GB = G - B;
        RG_sq = qPow(RG, 2);

        num = (RG + RB) / 2;

        decim = qSqrt(RG_sq + (RB * GB));
        H_tmp = num / decim;
        HUE = qAcos(H_tmp); // calculate rgb is for get hue value
      }

      {
        if (R < G)
          S_tmp = R;
        else
          S_tmp = G;

        if (S_tmp > B)
          S_tmp = B;

        SAT = 1 - ((R + G + B) / 3) * S_tmp;
      }

      {
        LUM = (R + G + B) / 3;
      }

      //            qDebug()<<HUE;

      if (rslt_flag) {

        rslt_min = min(rslt_min, HUE);
        //                rslt_avg += HUE;

        if (rslt_frm > 39) {
          //                    rslt_avg /= 10.0;
          //                    ui->lineEdit_Result->setText("Result:
          //                    "+QString::number(rslt_avg));

          ui->lineEdit_Result->setText("Result: " + QString::number(rslt_min));

          rslt_flag = false;
          rslt_frm = 0;
          rslt_min = 100.0;
        }

        rslt_frm++;
      }
    }
  }
  // for detection
  rectangle(image, Point(center_x, center_y),
            Point(center_x + 10, center_y + 10), Scalar(255, 255, 255), 1);

  cv::Rect cascadeROI(10, 10, 100, 100);

  cv::cvtColor(image, image, COLOR_BGR2RGB);

  QImage qimgOriginal((uchar *)image.data, image.cols, image.rows, image.step,
                      QImage::Format_RGB888);

  if (resume) {
    rectangle(image, from, to, Scalar(255, 0, 0), 2);

    Mat Gray = image;
    cvtColor(image, Gray, COLOR_BGR2GRAY);
    Mat cropedImage = Gray(Rect(cropped_x, cropped_y, cropped_w, cropped_h));

    objectDetector_empty.detectMultiScale(cropedImage, objects_empty, 1.03, 1,
                                          0, Size(0, 0), Size(200, 300));
    objectDetector_filled.detectMultiScale(cropedImage, objects_filled, 1.04, 6,
                                           0, Size(0, 0), Size(300, 300));

    for (int pwm_value = 0; pwm_value < objects_empty.size(); pwm_value++) {
      Point from(cropped_x + objects_empty[pwm_value].x,
                 cropped_y + objects_empty[pwm_value].y);
      Point to(cropped_x + objects_empty[pwm_value].x +
                   objects_empty[pwm_value].width,
               cropped_y + objects_empty[pwm_value].y +
                   objects_empty[pwm_value].height);
      rectangle(image, from, to, Scalar(255, 255, 255), 1);
      // putText(image, "Detected : Empty", Point(cropped_x, cropped_y - 40),
      // FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 0, 0), 2.0);
      ui->label_state->setText("Detected : EMPTY");
      empty_stack += 1;
      filled_stack = 0;

      if (empty_stack >= es_needs) {
        FLAG_FILLED = false;
        empty_stack = 0;
        filledMotor_go = false;
      }
    }

    if (!FLAG_FILLED && delay_tmp_) {
      qDebug() << "motor run";
      motor_go();
      delay_tmp_ = false;
    }

    if (!objects_empty.size()) // for solving multiple detection
      for (int pwm_value = 0; pwm_value < objects_filled.size(); pwm_value++) {
        Point from(cropped_x + objects_filled[pwm_value].x,
                   cropped_y + objects_filled[pwm_value].y);
        Point to(cropped_x + objects_filled[pwm_value].x +
                     objects_filled[pwm_value].width,
                 cropped_y + objects_filled[pwm_value].y +
                     objects_filled[pwm_value].height);
        rectangle(image, from, to, Scalar(255, 255, 255), 1);
        // putText(image, "Detected : Filled", Point(cropped_x, cropped_y - 40),
        // FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 0, 0), 2.0);
        ui->label_state->setText("Detected : FIILLED");
        filled_stack += 1;
        empty_stack = 0;

        if (filledMotor_go && delay_tmp_ && resume) {
          qDebug() << "motor run";
          motor_go();
          delay_tmp_ = false;
        }

        if (filled_stack >= fs_needs) {
          FLAG_FILLED = true;
          filled_stack = 0;
          if (sequence != 3)
            motor_go();
          qDebug() << "filled";
        }

        if (FLAG_FILLED && resume && !filledMotor_go) {
          filledMotor_go = true;
          FLAG_FILLED = false;
          qDebug() << "timerStart";
          reactionEvent(sequence); //<<---------
        }
      }
  }
  // end detection
  // else{
  //     rectangle(image,from_position,to_position,Scalar(255,0,0),2);
  // }

  int st = getTickCount();
  float fps = 1000000000 / (float)(st - old_time);

  QString rgbtxt = "R : " + QString::number(rgb_sum_r / 81) +
                   " G : " + QString::number(rgb_sum_g / 81) +
                   " B : " + QString::number(rgb_sum_b / 81);
  QString huetxt = "HUE : " + QString::number(HUE);
  QString sattxt = "SAT : " + QString::number(SAT);
  QString lumtxt = "LUM : " + QString::number(LUM);

  ui->label_FPS->setText("FPS : " + QString::number(fps));

  ui->lineEdit_RGB->setText(rgbtxt);
  ui->lineEdit_HUE->setText(huetxt);
  ui->lineEdit_Sat->setText(sattxt);
  ui->lineEdit_Lum->setText(lumtxt);

  old_time = st;

  ui->VideoLabel->setPixmap(QPixmap::fromImage(qimgOriginal));
}
void MainWindow::set_gpio() {
  /*wiringPiSetup();
  gpioInitialise();
  gpioSetMode(23,PI_OUTPUT);
  gpioSetPWMfrequency(23, 500);
  gpioSetPWMrange(23,2500);
  gpioWrite(23,1);
  softPwmCreate(PIN_MOTOR, 0, 20);      //<-------------------
  pinMode(2, OUTPUT);*/
}

void MainWindow::on_btn_backward_clicked() {
  if (pwm_value > 1000) {
    pwm_value = pwm_value - 10;
    gpioServo(23, pwm_value);
    // ui->label_step->setText("back ward");
  }
}
// about setting

void MainWindow::on_btn_forward_clicked() {
  if (pwm_value < 2100) {
    pwm_value = pwm_value + 50;
    gpioServo(23, pwm_value);
    qDebug() << "Exhale:" << pwm_value;
  }
}

void MainWindow::on_btn_pause_clicked() {
  if (start && !resume) {
    resume = true;
    ui->btn_pause->setText("Pause");
  } else {
    resume = false;
    ui->btn_pause->setText("Resume");
  }
}

void MainWindow::on_btn_start_clicked() {
  if (!start) {
    start = true;
    resume = true;
    ui->btn_start->setText("Return");
  } else {
    start = false;
    resume = false;
    sequence = 1;
    ui->btn_start->setText("Start");
    sequence = 1;
    pwm_value = 1850;
    gpioServo(23, pwm_value);
  }
}

void MainWindow::on_btn_measure_clicked() {
  rslt_flag = true;
  if (HUE >= 0.3) {
    // ui->label_covid->setStyleSheet("{color: #FF0000}");
    // ui->label_covid->setText("POSITIVE") ;
    covid.setColor(QPalette::Text, Qt::red);
    ui->lineEdit_covid->setPalette(covid);
    ui->lineEdit_covid->setText("POSITIVE");

    UserResult = true;
  } else if (HUE < 0.3) {
    covid.setColor(QPalette::Text, Qt::blue);
    ui->lineEdit_covid->setPalette(covid);
    ui->lineEdit_covid->setText("NEGATIVE");
    UserResult = false;
  }
}

void MainWindow::on_btn_save_clicked() {
  DB_connect();
  on_btn_refresh_clicked();
}

void digitalPwmWrite() {
  qDebug() << "Thread is started";
  //    mthread->msleep(2000);

  while (1) {
    mthread->msleep(5000);
    delay_tmp_ = true;

    if (QThread::currentThread()->isInterruptionRequested()) {
      return;
    }
  }
}

void MainWindow::reactionEvent(int sequence) {

  qDebug() << "Seq: " << sequence;

  cntTimer = new QTimer(this);
  tmrTimer = new QTimer(this);

  tmrTimer->setSingleShot(true);

  //    cntTimer->setSingleShot(true);

  if (sequence == 1) {
    resume = false;
    cnt = reaction_time / 1000;
    connect(tmrTimer, SIGNAL(timeout()), this, SLOT(toggle_Resume()));
    tmrTimer->start(reaction_time);

    if (cnt >= 0) {
      connect(cntTimer, SIGNAL(timeout()), this, SLOT(timer_Count()));
      cntTimer->start(1000);
    }
  }

  else if (sequence == 2) {
    /*connect(tmrTimer, SIGNAL(timeout()), this, SLOT(toggle_Resume()));
    tmrTimer->start()*/
    ;

    resume = false;
    // toggle_Resume();
  }

  else if (sequence == 3) {
    resume = false;
    cnt = tmb_time / 1000;
    connect(tmrTimer, SIGNAL(timeout()), this, SLOT(result_Count()));
    tmrTimer->start(tmb_time);

    if (cnt >= 0) {
      connect(cntTimer, SIGNAL(timeout()), this, SLOT(timer_Count()));
      cntTimer->start(1000);
    }
  }
}

void MainWindow::motor_go() {

  gpioServo(23, pwm_value);

  if (pwm_value > 1000)
    pwm_value = pwm_value - 10;
  qDebug() << "H_PWM: " << pwm_value;
  //    }

  mthread->start();
  mthread->exit();
}

void MainWindow::timer_Count() {

  cnt--;
  qDebug() << cnt;

  if (cnt <= 0) {
    ui->label_Timer->setText("Timer: ");
    disconnect(cntTimer, SIGNAL(timeout()), 0, 0);
    //        this->close();
  } else {
    ui->label_Timer->setText("Timer: " + QString::number(cnt) + " sec");
  }
}

void MainWindow::toggle_Resume() {
  if (!resume) {
    resume = true;
    sequence++;
    ui->label_Sequence->setText("Sequence: " + QString::number(sequence - 1));

    qDebug() << "timerStop";
  }

  if (sequence > 3) {
    //        sequence=1;
    resume = false;
  }
}

void MainWindow::result_Count() {
  rslt_flag = true;
  sequence++;
  ui->label_Sequence->setText("Sequence: " + QString::number(sequence - 1));
}

// about setting
void MainWindow::on_btn_set_save_clicked() {
  location = ui->location_box->currentText();
  QString setfile_Reaction = "set_Reaction.txt";
  QString setfile_Tmb = "set_Tmb.txt";
  // QString setfile_motorspd = "set_mtrspd.txt";

  QFile file1(setfile_Reaction);
  if (file1.open(QIODevice::ReadWrite)) {
    QTextStream stream(&file1);
    stream << QString::number(ui->spinBox_Reaction->value() * 60000) << endl;
  }

  QFile file2(setfile_Tmb);
  if (file2.open(QIODevice::ReadWrite)) {
    QTextStream stream(&file2);
    stream << QString::number(ui->spinBox_Tmb->value() * 60000) << endl;
  }

  // QFile file3(setfile_motorspd);
  // if (file3.open(QIODevice::ReadWrite)) {
  //     QTextStream stream(&file3);

  //    stream <<QString::number(ui->spinBox_motorspd->value()) <<endl;
  //}
  reaction_time = ui->spinBox_Reaction->value() * 60000;
  tmb_time = ui->spinBox_Tmb->value() * 60000;
  // motor_speed = ui->spinBox_motorspd->value()*100;
}

void MainWindow::on_lineEdit_QR_editingFinished() {
  userStr = ui->lineEdit_QR->text();
  qrlist = userStr.split(",");
  qDebug() << qrlist;
  name = qrlist.at(0);
  // location = qrlist.at(1);
  // ui->tabWidget->setCurrentIndex(1);
  ui->label_userinfo->setText(name);

  UserName = name;
  UserLocation = location;

  /*
      if (userStr.length() != 0) {
         ui->lineEdit_QR->setText("Connect Success");
         qrOnOff = true;
         qDebug() << userStr;

         while (1) {
            if (user[i] != ',') {
               name = name.append(user[i]);
               i++;
            }
            else if (user[i] == ',') {
               qDebug() << name;
               i++;
               break;
            }
         }
          while(1) {
              if(user[i] != ','){
                  location = location.append(user[i]);
                  i++;
              }
              else if(user[i] == ','){
                  qDebug() << location;
                  i = 0;
                  break;
              }
         }


         UserName = name;
         UserLocation = location;

         qDebug() << "QR OK";



      }
      else {
         qrOnOff = false;
      }
         */
}

void MainWindow::on_btn_st_in_clicked() {
  ui->lineEdit_QR->setText(" ");
  ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_btn_refresh_clicked() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
  db.setPort(8082);
  db.setHostName("211.212.149.167");
  db.setUserName("KWIX");
  db.setPassword("kwix");       // raspberry
  db.setDatabaseName("userDB"); // db
  model = new QSqlTableModel(this);
  model->setTable("COVID19");
  ui->tableView->setModel(model);
  ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui->tableView->setColumnHidden(0, true);
  ui->tableView->sortByColumn(3);
  model->select();
}
