#include "mainwindow.h"

// Qt 관련 헤더
#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QWidget>
#include <QtDebug>
#include <QtSql>

// 외부 GPIO 라이브러리 (pigpio)
#include <pigpio.h>

// 애플리케이션의 진입점
int main(int argc, char *argv[]) {
  // Qt 애플리케이션 초기화
  QApplication app(argc, argv);

  // 메인 윈도우 생성 및 표시
  MainWindow window;
  window.show();

  // pigpio 라이브러리 초기화
  if (gpioInitialise() < 0) {
    fprintf(stderr, "pigpio 초기화 실패\n");
    return 1;
  } else {
    fprintf(stderr, "pigpio 초기화 성공\n");
  }

  // GPIO 23번 핀을 PWM 출력 모드로 설정하고 리니어 액추에이터 제어용 펄스를
  // 전송
  gpioSetMode(23, PI_OUTPUT);
  gpioSetPWMfrequency(23, 200);
  gpioSetPWMrange(23, 2500);
  gpioServo(23, 2100); // 2100마이크로초 펄스 전송 (서보모터 각도 제어)
  time_sleep(9);       // 9초 동안 유지

  // Qt 이벤트 루프 실행
  return app.exec();
}