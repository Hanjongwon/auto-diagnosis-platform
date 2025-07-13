#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt 관련 헤더
#include <QImage>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QThread>
#include <QTimer>
#include <QtWebKitWidgets/QWebView>

// OpenCV 관련 헤더
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/features2d/features2d.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/shape.hpp>

// raspicam 헤더
#include <raspicam/raspicam_cv.h>

// 하드웨어 관련 헤더
#include <softPwm.h>
#include <wiringPi.h>

// 표준 라이브러리
#include <iostream>

namespace Ui {
class MainWindow;
}

// Main GUI class controlling the Auto Diagnosis Platform
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr); // Constructor
  ~MainWindow();                                  // Destructor

  // 주요 멤버 변수
  QImage qimgOriginal; // 원본 이미지 (표시용)

  // 주요 버튼 클릭 이벤트 핸들러 (UI 연결용)
  void on_btn_backward_clicked();        // 뒤로가기 버튼 클릭
  void on_btn_forward_clicked();         // 앞으로가기 버튼 클릭
  void on_btn_measure_clicked();         // 측정 시작 버튼 클릭
  void on_btn_start_clicked();           // 진단 시작 버튼 클릭
  void on_btn_save_clicked();            // 결과 저장 버튼 클릭
  void on_lineEdit_QR_editingFinished(); // QR코드 입력 완료 시 동작
  void on_btn_pause_clicked();           // 일시정지 버튼 클릭
  void on_btn_refresh_clicked();         // 새로고침 버튼 클릭

private:
  Ui::MainWindow *ui;    // UI 객체
  QSqlTableModel *model; // DB 테이블 모델

  QTimer *tmrTimer;     // 주 타이머
  QTimer *cntTimer;     // 카운트용 타이머
  QTimer *processTimer; // 프로세스 제어용 타이머

  cv::Mat image;                // 현재 프레임 이미지
  cv::Mat image_cascaded;       // 전처리된 이미지
  raspicam::RaspiCam_Cv Camera; // 라즈베리파이 카메라 객체

public slots:
  void processFrameAndUpdateGUI(); // 카메라 프레임 처리 및 UI업데이트
  void timer_Count();              // 타이머 기반 카운트 핸들러
  void reactionEvent(int);         // 사용자 반응 이벤트 처리
  void motor_go();                 // 모터 작동 로직
  void result_Count();             // 결과 카운트 및 UI 반영
  void DB_connect();               // DB 연결 초기화
  void set_gpio();                 // 모터 제어용 GPIO 설정
  void setReaction();              // 반응 관련 설정
  void setTmb();                   // 추가 파라미터 설정
  void toggle_Resume();            // 재시작/일시정지 토글

private slots:
  void on_btn_st_in_clicked(); // 시작 입력 버튼 클릭
  // void on_btn_resume_clicked();
  void on_btn_set_save_clicked(); // 설정 저장 버튼 클릭
};

#endif // MAINWINDOW_H