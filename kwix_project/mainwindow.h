#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <raspicam/raspicam_cv.h>

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core/core.hpp>

#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/features2d/features2d.hpp>
#include <opencv4/opencv2/shape.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <wiringPi.h>
#include <softPwm.h>
#include <QThread>
#include <QtWebKitWidgets>
#include <raspicam/raspicam_cv.h>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/features2d/features2d.hpp>
#include <opencv4/opencv2/shape.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <QSqlTableModel>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QImage qimgOriginal;
    void on_btn_backward_clicked();

    void on_btn_forward_clicked();
    void on_btn_measure_clicked();
    void on_btn_start_clicked();
    void on_btn_save_clicked();
    void on_lineEdit_QR_editingFinished();

    void on_btn_pause_clicked();

    void on_btn_refresh_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;

    //void DB_connect();
    //void processFrameAndUpdateGUI();
    QTimer*tmrTimer;
    QTimer*cntTimer;
    QTimer*processTimer;
    cv::Mat image;
    cv::Mat image_cascaded;
    raspicam::RaspiCam_Cv Camera;

public slots:
    void processFrameAndUpdateGUI();
    void timer_Count();
    void reactionEvent(int);
    void motor_go();
    void result_Count();
    void DB_connect();
    void set_gpio();
    void setReaction();
    void setTmb();

    void toggle_Resume();

private slots:
    void on_btn_st_in_clicked();
    //void on_btn_resume_clicked();

    void on_btn_set_save_clicked();


};

#endif // MAINWINDOW_H
