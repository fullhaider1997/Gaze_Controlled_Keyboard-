#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      mainGUI(new Ui::MainWindow),
      videoProccessorPipeLine(new VideoProcessorPipleLine),
      keyBoardProcessor(new KeyBoardProcessor),
      threadVideoProcessor(new QThread),
      threadKeyBoardProcessor(new QThread)


{


    mainGUI->setupUi(this);

    videoProccessorPipeLine->moveToThread(threadVideoProcessor);
    keyBoardProcessor->moveToThread(threadKeyBoardProcessor);


    connect( threadKeyBoardProcessor, SIGNAL(started()), keyBoardProcessor, SLOT(loopThroughButtons()));
    connect(keyBoardProcessor, SIGNAL(finished()),  threadKeyBoardProcessor, SLOT(quit()));
    connect(keyBoardProcessor, SIGNAL(finished()), keyBoardProcessor, SLOT(deleteLater()));

    connect(videoProccessorPipeLine, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect( threadVideoProcessor, SIGNAL(started()), videoProccessorPipeLine, SLOT(displayVideo()));
    connect( threadVideoProcessor, SIGNAL(finished()), threadVideoProcessor, SLOT(deleteLater()));
    connect(videoProccessorPipeLine, SIGNAL(finished()),  threadVideoProcessor, SLOT(quit()));
    connect(videoProccessorPipeLine, SIGNAL(finished()), videoProccessorPipeLine, SLOT(deleteLater()));
    connect(videoProccessorPipeLine,SIGNAL(display(QPixmap)),mainGUI->originallabel,SLOT(setPixmap(QPixmap)));

      connect( threadVideoProcessor, SIGNAL(started()), videoProccessorPipeLine, SLOT(displayVideo()));



    threadVideoProcessor->start();
    threadKeyBoardProcessor->start();


}



MainWindow::~MainWindow()
{
    delete mainGUI;
}



