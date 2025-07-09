/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_main;
    QLabel *label_home;
    QLineEdit *lineEdit_QR;
    QTextEdit *textEdit;
    QPushButton *btn_st_in;
    QWidget *tab_elisa;
    QLineEdit *lineEdit_back;
    QLabel *VideoLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_HUE;
    QLineEdit *lineEdit_Sat;
    QLineEdit *lineEdit_RGB;
    QLineEdit *lineEdit_Lum;
    QLineEdit *lineEdit_Result;
    QPushButton *btn_measure;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btn_start;
    QPushButton *btn_backward;
    QPushButton *btn_forward;
    QPushButton *btn_pause;
    QPushButton *btn_save;
    QLabel *label_FPS;
    QLabel *label_Sequence;
    QLabel *label_Timer;
    QLabel *label_userinfo;
    QLineEdit *lineEdit_covid;
    QLabel *label_covid;
    QLabel *label_state;
    QWidget *tab_setting;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_Reaction;
    QLabel *label_enzyme_time;
    QLabel *label;
    QLabel *label_antibody_time;
    QLabel *label_min_1;
    QSpinBox *spinBox_Tmb;
    QLabel *label_min_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_location;
    QComboBox *location_box;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_set_save;
    QWidget *tab_result;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *btn_refresh;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 791, 481));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setIconSize(QSize(64, 64));
        tabWidget->setElideMode(Qt::ElideNone);
        tab_main = new QWidget();
        tab_main->setObjectName(QStringLiteral("tab_main"));
        label_home = new QLabel(tab_main);
        label_home->setObjectName(QStringLiteral("label_home"));
        label_home->setGeometry(QRect(0, 0, 701, 361));
        label_home->setPixmap(QPixmap(QString::fromUtf8("../build-kwix_project-Desktop-Debug/main_screen.png")));
        label_home->setScaledContents(true);
        lineEdit_QR = new QLineEdit(tab_main);
        lineEdit_QR->setObjectName(QStringLiteral("lineEdit_QR"));
        lineEdit_QR->setGeometry(QRect(10, 390, 171, 71));
        textEdit = new QTextEdit(tab_main);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 360, 191, 111));
        btn_st_in = new QPushButton(tab_main);
        btn_st_in->setObjectName(QStringLiteral("btn_st_in"));
        btn_st_in->setGeometry(QRect(190, 360, 99, 111));
        QIcon icon;
        icon.addFile(QStringLiteral("../build-kwix_project-Desktop-Debug/img/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_main, icon, QString());
        label_home->raise();
        textEdit->raise();
        lineEdit_QR->raise();
        btn_st_in->raise();
        tab_elisa = new QWidget();
        tab_elisa->setObjectName(QStringLiteral("tab_elisa"));
        lineEdit_back = new QLineEdit(tab_elisa);
        lineEdit_back->setObjectName(QStringLiteral("lineEdit_back"));
        lineEdit_back->setEnabled(false);
        lineEdit_back->setGeometry(QRect(470, 50, 231, 291));
        lineEdit_back->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        VideoLabel = new QLabel(tab_elisa);
        VideoLabel->setObjectName(QStringLiteral("VideoLabel"));
        VideoLabel->setGeometry(QRect(10, 50, 651, 291));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(124, 124, 124, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        VideoLabel->setPalette(palette);
        VideoLabel->setAutoFillBackground(false);
        VideoLabel->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(124, 124, 124);\n"
"font: 75 23pt \"\353\202\230\353\210\224\352\263\240\353\224\225\";\n"
"color: rgb(255, 255, 255);"));
        VideoLabel->setAlignment(Qt::AlignCenter);
        VideoLabel->setWordWrap(true);
        verticalLayoutWidget = new QWidget(tab_elisa);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(490, 90, 191, 201));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_HUE = new QLineEdit(verticalLayoutWidget);
        lineEdit_HUE->setObjectName(QStringLiteral("lineEdit_HUE"));
        lineEdit_HUE->setEnabled(false);
        lineEdit_HUE->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(lineEdit_HUE);

        lineEdit_Sat = new QLineEdit(verticalLayoutWidget);
        lineEdit_Sat->setObjectName(QStringLiteral("lineEdit_Sat"));
        lineEdit_Sat->setEnabled(false);
        lineEdit_Sat->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(lineEdit_Sat);

        lineEdit_RGB = new QLineEdit(verticalLayoutWidget);
        lineEdit_RGB->setObjectName(QStringLiteral("lineEdit_RGB"));
        lineEdit_RGB->setEnabled(false);
        lineEdit_RGB->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(lineEdit_RGB);

        lineEdit_Lum = new QLineEdit(verticalLayoutWidget);
        lineEdit_Lum->setObjectName(QStringLiteral("lineEdit_Lum"));
        lineEdit_Lum->setEnabled(false);

        verticalLayout_3->addWidget(lineEdit_Lum);

        lineEdit_Result = new QLineEdit(verticalLayoutWidget);
        lineEdit_Result->setObjectName(QStringLiteral("lineEdit_Result"));
        lineEdit_Result->setEnabled(false);

        verticalLayout_3->addWidget(lineEdit_Result);

        btn_measure = new QPushButton(tab_elisa);
        btn_measure->setObjectName(QStringLiteral("btn_measure"));
        btn_measure->setGeometry(QRect(490, 290, 191, 41));
        gridLayoutWidget_2 = new QWidget(tab_elisa);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 350, 531, 101));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_start = new QPushButton(gridLayoutWidget_2);
        btn_start->setObjectName(QStringLiteral("btn_start"));

        gridLayout_2->addWidget(btn_start, 0, 0, 1, 1);

        btn_backward = new QPushButton(gridLayoutWidget_2);
        btn_backward->setObjectName(QStringLiteral("btn_backward"));

        gridLayout_2->addWidget(btn_backward, 1, 0, 1, 1);

        btn_forward = new QPushButton(gridLayoutWidget_2);
        btn_forward->setObjectName(QStringLiteral("btn_forward"));

        gridLayout_2->addWidget(btn_forward, 1, 1, 1, 1);

        btn_pause = new QPushButton(gridLayoutWidget_2);
        btn_pause->setObjectName(QStringLiteral("btn_pause"));

        gridLayout_2->addWidget(btn_pause, 0, 1, 1, 1);

        btn_save = new QPushButton(tab_elisa);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setGeometry(QRect(550, 360, 151, 81));
        label_FPS = new QLabel(tab_elisa);
        label_FPS->setObjectName(QStringLiteral("label_FPS"));
        label_FPS->setGeometry(QRect(310, 60, 151, 30));
        label_FPS->setMaximumSize(QSize(16777215, 30));
        label_Sequence = new QLabel(tab_elisa);
        label_Sequence->setObjectName(QStringLiteral("label_Sequence"));
        label_Sequence->setGeometry(QRect(20, 300, 401, 31));
        label_Timer = new QLabel(tab_elisa);
        label_Timer->setObjectName(QStringLiteral("label_Timer"));
        label_Timer->setGeometry(QRect(10, 60, 191, 30));
        label_Timer->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_Timer->setFont(font);
        label_Timer->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(139, 139, 139);"));
        label_Timer->setAlignment(Qt::AlignCenter);
        label_userinfo = new QLabel(tab_elisa);
        label_userinfo->setObjectName(QStringLiteral("label_userinfo"));
        label_userinfo->setGeometry(QRect(10, 0, 681, 51));
        lineEdit_covid = new QLineEdit(tab_elisa);
        lineEdit_covid->setObjectName(QStringLiteral("lineEdit_covid"));
        lineEdit_covid->setGeometry(QRect(490, 50, 189, 32));
        lineEdit_covid->setFont(font);
        lineEdit_covid->setTabletTracking(false);
        label_covid = new QLabel(tab_elisa);
        label_covid->setObjectName(QStringLiteral("label_covid"));
        label_covid->setGeometry(QRect(500, 50, 171, 31));
        label_covid->setAlignment(Qt::AlignCenter);
        label_state = new QLabel(tab_elisa);
        label_state->setObjectName(QStringLiteral("label_state"));
        label_state->setGeometry(QRect(30, 280, 241, 41));
        QFont font1;
        font1.setPointSize(19);
        font1.setBold(true);
        font1.setWeight(75);
        label_state->setFont(font1);
        label_state->setAlignment(Qt::AlignCenter);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../build-kwix_project-Desktop-Debug/img/operation.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_elisa, icon1, QString());
        VideoLabel->raise();
        lineEdit_back->raise();
        verticalLayoutWidget->raise();
        btn_measure->raise();
        gridLayoutWidget_2->raise();
        btn_save->raise();
        label_FPS->raise();
        label_Timer->raise();
        label_userinfo->raise();
        label_Sequence->raise();
        lineEdit_covid->raise();
        label_covid->raise();
        label_state->raise();
        tab_setting = new QWidget();
        tab_setting->setObjectName(QStringLiteral("tab_setting"));
        gridLayoutWidget = new QWidget(tab_setting);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 681, 351));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_Reaction = new QSpinBox(gridLayoutWidget);
        spinBox_Reaction->setObjectName(QStringLiteral("spinBox_Reaction"));
        spinBox_Reaction->setMinimum(1);
        spinBox_Reaction->setMaximum(180);
        spinBox_Reaction->setValue(40);

        gridLayout->addWidget(spinBox_Reaction, 1, 1, 1, 1);

        label_enzyme_time = new QLabel(gridLayoutWidget);
        label_enzyme_time->setObjectName(QStringLiteral("label_enzyme_time"));
        label_enzyme_time->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_enzyme_time, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_antibody_time = new QLabel(gridLayoutWidget);
        label_antibody_time->setObjectName(QStringLiteral("label_antibody_time"));
        label_antibody_time->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_antibody_time, 3, 0, 1, 1);

        label_min_1 = new QLabel(gridLayoutWidget);
        label_min_1->setObjectName(QStringLiteral("label_min_1"));

        gridLayout->addWidget(label_min_1, 1, 2, 1, 1);

        spinBox_Tmb = new QSpinBox(gridLayoutWidget);
        spinBox_Tmb->setObjectName(QStringLiteral("spinBox_Tmb"));
        spinBox_Tmb->setMinimum(1);
        spinBox_Tmb->setMaximum(180);
        spinBox_Tmb->setValue(15);

        gridLayout->addWidget(spinBox_Tmb, 3, 1, 1, 1);

        label_min_2 = new QLabel(gridLayoutWidget);
        label_min_2->setObjectName(QStringLiteral("label_min_2"));

        gridLayout->addWidget(label_min_2, 3, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_location = new QLabel(gridLayoutWidget);
        label_location->setObjectName(QStringLiteral("label_location"));
        label_location->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_location, 5, 0, 1, 1);

        location_box = new QComboBox(gridLayoutWidget);
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->addItem(QString());
        location_box->setObjectName(QStringLiteral("location_box"));

        gridLayout->addWidget(location_box, 5, 1, 1, 1);

        horizontalLayoutWidget_2 = new QWidget(tab_setting);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(50, 370, 561, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_set_save = new QPushButton(horizontalLayoutWidget_2);
        btn_set_save->setObjectName(QStringLiteral("btn_set_save"));

        horizontalLayout_3->addWidget(btn_set_save);

        QIcon icon2;
        icon2.addFile(QStringLiteral("../build-kwix_project-Desktop-Debug/img/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_setting, icon2, QString());
        tab_result = new QWidget();
        tab_result->setObjectName(QStringLiteral("tab_result"));
        verticalLayoutWidget_2 = new QWidget(tab_result);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 681, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget_2);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        pushButton = new QPushButton(verticalLayoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        btn_refresh = new QPushButton(verticalLayoutWidget_2);
        btn_refresh->setObjectName(QStringLiteral("btn_refresh"));

        verticalLayout->addWidget(btn_refresh);

        QIcon icon3;
        icon3.addFile(QStringLiteral("../build-kwix_project-Desktop-Debug/img/results.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_result, icon3, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_home->setText(QString());
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'PibotoLt'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Touch and Scan QR Code</p></body></html>", nullptr));
        btn_st_in->setText(QApplication::translate("MainWindow", "NEW", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_main), QString());
        lineEdit_back->setText(QString());
        VideoLabel->setText(QString());
        lineEdit_HUE->setText(QApplication::translate("MainWindow", "Hue : ", nullptr));
        lineEdit_Sat->setText(QApplication::translate("MainWindow", "Sat : ", nullptr));
        lineEdit_RGB->setText(QApplication::translate("MainWindow", "RGB : ", nullptr));
        lineEdit_Lum->setText(QApplication::translate("MainWindow", "Lum: ", nullptr));
        lineEdit_Result->setText(QApplication::translate("MainWindow", "Result :", nullptr));
        btn_measure->setText(QApplication::translate("MainWindow", "MEASURE", nullptr));
        btn_start->setText(QApplication::translate("MainWindow", "START", nullptr));
        btn_backward->setText(QApplication::translate("MainWindow", "BACKWARD", nullptr));
        btn_forward->setText(QApplication::translate("MainWindow", "FORWARD", nullptr));
        btn_pause->setText(QApplication::translate("MainWindow", "STOP", nullptr));
        btn_save->setText(QApplication::translate("MainWindow", "SAVE", nullptr));
        label_FPS->setText(QApplication::translate("MainWindow", "FPS : ", nullptr));
        label_Sequence->setText(QString());
        label_Timer->setText(QApplication::translate("MainWindow", "Timer:  15 minutes", nullptr));
        label_userinfo->setText(QApplication::translate("MainWindow", "USER : ", nullptr));
        label_covid->setText(QString());
        label_state->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_elisa), QString());
        label_enzyme_time->setText(QApplication::translate("MainWindow", "REACTION Time", nullptr));
        label->setText(QString());
        label_antibody_time->setText(QApplication::translate("MainWindow", "TMB Time", nullptr));
        label_min_1->setText(QApplication::translate("MainWindow", "min", nullptr));
        label_min_2->setText(QApplication::translate("MainWindow", "min", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_5->setText(QString());
        label_location->setText(QApplication::translate("MainWindow", "Location", nullptr));
        location_box->setItemText(0, QApplication::translate("MainWindow", "Seoul", nullptr));
        location_box->setItemText(1, QApplication::translate("MainWindow", "jeju-do", nullptr));
        location_box->setItemText(2, QApplication::translate("MainWindow", "Gangwon-do", nullptr));
        location_box->setItemText(3, QApplication::translate("MainWindow", "Incheon", nullptr));
        location_box->setItemText(4, QApplication::translate("MainWindow", "Busan", nullptr));
        location_box->setItemText(5, QApplication::translate("MainWindow", "Sejong", nullptr));
        location_box->setItemText(6, QApplication::translate("MainWindow", "Daegu", nullptr));
        location_box->setItemText(7, QApplication::translate("MainWindow", "Gwangju", nullptr));
        location_box->setItemText(8, QApplication::translate("MainWindow", "Daejeon", nullptr));
        location_box->setItemText(9, QApplication::translate("MainWindow", "Ulsan", nullptr));
        location_box->setItemText(10, QApplication::translate("MainWindow", "Gyeonggi-do", nullptr));
        location_box->setItemText(11, QApplication::translate("MainWindow", "Chungcheongnam-do", nullptr));
        location_box->setItemText(12, QApplication::translate("MainWindow", "Chungcheongbuk-do", nullptr));
        location_box->setItemText(13, QApplication::translate("MainWindow", "Jeollanam-do", nullptr));
        location_box->setItemText(14, QApplication::translate("MainWindow", "Jeollabuk-do", nullptr));
        location_box->setItemText(15, QApplication::translate("MainWindow", "Gyeongsangnam-do", nullptr));
        location_box->setItemText(16, QApplication::translate("MainWindow", "Gyeongsangbuk-do", nullptr));

        btn_set_save->setText(QApplication::translate("MainWindow", "SAVE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_setting), QString());
        pushButton->setText(QApplication::translate("MainWindow", "WEB UPLOAD", nullptr));
        btn_refresh->setText(QApplication::translate("MainWindow", "REFRESH", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_result), QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
