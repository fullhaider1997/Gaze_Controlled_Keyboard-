#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "keyboard.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mainGUI(new Ui::MainWindow),
      keyboard(new KeyBoard(this)),
      videoProccessorPipeLine(new VideoProcessorPipleLine),
      threadVideoProcessor(new QThread),
      threadKeyBoard(new QThread)

{
    mainGUI->setupUi(this);


    videoProccessorPipeLine->moveToThread( threadVideoProcessor);
    keyboard->moveToThread(threadKeyBoard);

    connect(videoProccessorPipeLine, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect( threadVideoProcessor, SIGNAL(started()), videoProccessorPipeLine, SLOT(displayVideo()));
    connect(videoProccessorPipeLine, SIGNAL(finished()),  threadVideoProcessor, SLOT(quit()));
    connect(videoProccessorPipeLine, SIGNAL(finished()), videoProccessorPipeLine, SLOT(deleteLater()));
    connect( threadVideoProcessor, SIGNAL(finished()), threadVideoProcessor, SLOT(deleteLater()));
    connect(videoProccessorPipeLine,SIGNAL(display(QPixmap)),mainGUI->originallabel,SLOT(setPixmap(QPixmap)));

     threadVideoProcessor->start();




}




MainWindow::~MainWindow()
{
    delete mainGUI;
}


void MainWindow::on_pushButton_clicked()
{

    threadKeyBoard->start();
    keyboard->show();


}
