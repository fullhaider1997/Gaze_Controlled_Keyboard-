#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eyealogrithms.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      mainGUI(new Ui::MainWindow),
      videoProccessorPipeLine(new VideoProcessorPipleLine),
      threadVideoProcessor(new QThread),
      threadKeyBoardProcessor(new QThread),
      keyboard( *new MainWindow::KeyBoardProcessor)


{


    mainGUI->setupUi(this);


    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("A_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("B_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("C_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("D_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("E_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("F_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("G_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("H_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("I_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("J_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("K_Button");
    listButtons += mainGUI->centralwidget->findChildren<QPushButton*>("L_Button");


    videoProccessorPipeLine->moveToThread(threadVideoProcessor);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(loopThroughButtons()));
    timer->start(3000);

    connect(videoProccessorPipeLine,SIGNAL(videoProcessorBlinked(bool)),this,SLOT(userIsBlinking(bool)));

    connect(videoProccessorPipeLine, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect( threadVideoProcessor, SIGNAL(started()), videoProccessorPipeLine, SLOT(displayVideo()));
    connect( threadVideoProcessor, SIGNAL(finished()), threadVideoProcessor, SLOT(deleteLater()));
    connect(videoProccessorPipeLine, SIGNAL(finished()),  threadVideoProcessor, SLOT(quit()));
    connect(videoProccessorPipeLine, SIGNAL(finished()), videoProccessorPipeLine, SLOT(deleteLater()));
    connect(videoProccessorPipeLine,SIGNAL(display(QPixmap)),mainGUI->originallabel,SLOT(setPixmap(QPixmap)));

    connect( threadVideoProcessor, SIGNAL(started()), videoProccessorPipeLine, SLOT(displayVideo()));


    threadVideoProcessor->start();



}

void MainWindow::userIsBlinking(bool answer){

      qDebug() << "user blinking status: " << answer;

}

void MainWindow::loopThroughButtons(){

     qDebug() << "Looping through buttons: " <<  keyboard.getCurrentButtonPosition();

      listButtons.at(keyboard.getCurrentButtonPosition())->animateClick(3000);
      keyboard.IncrementKeyBoardPosition();


}

MainWindow::~MainWindow()
{
    delete mainGUI;
}



