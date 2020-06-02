#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      videoProccessorPipeLine(new VideoProcessorPipleLine),
      thread(new QThread)
{
    ui->setupUi(this);

\

    videoProccessorPipeLine->moveToThread(thread);

    connect(videoProccessorPipeLine, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), videoProccessorPipeLine, SLOT(displayVideo()));
    connect(videoProccessorPipeLine, SIGNAL(finished()), thread, SLOT(quit()));
    connect(videoProccessorPipeLine, SIGNAL(finished()), videoProccessorPipeLine, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(videoProccessorPipeLine,SIGNAL(display(QPixmap)),ui->originallabel,SLOT(setPixmap(QPixmap)));

    connect(videoProccessorPipeLine,SIGNAL(display(QPixmap)),ui->eyelabel,SLOT(setPixmap(QPixmap)));
    thread->start();






}

MainWindow::~MainWindow()
{
    delete ui;
}

