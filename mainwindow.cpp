#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      videoProccessor(new VideoProcessor),
      thread(new QThread)
{
    ui->setupUi(this);

\

    videoProccessor->moveToThread(thread);
    connect(videoProccessor, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), videoProccessor, SLOT(displayVideo()));
    connect(videoProccessor, SIGNAL(finished()), thread, SLOT(quit()));
    connect(videoProccessor, SIGNAL(finished()), videoProccessor, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(videoProccessor,SIGNAL(display(QPixmap)),ui->originallabel,SLOT(setPixmap(QPixmap)));
    thread->start();






}

MainWindow::~MainWindow()
{
    delete ui;
}

