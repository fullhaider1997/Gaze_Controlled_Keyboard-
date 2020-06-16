#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>

#include "keyboard.h"
#include "videoprocessorpipeline.h"
#include "qthread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }


QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow * mainGUI;
    KeyBoard * keyboard;
    VideoProcessorPipleLine *videoProccessorPipeLine;
    QThread *threadVideoProcessor;
    QThread *threadKeyBoard;


};
#endif // MAINWINDOW_H
