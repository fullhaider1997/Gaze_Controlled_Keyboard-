#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "keyboardprocessor.h"
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




private:
    KeyBoardProcessor *keyBoardProcessor;
    Ui::MainWindow * mainGUI;
    VideoProcessorPipleLine *videoProccessorPipeLine;
    QThread *threadVideoProcessor;
    QThread *threadKeyBoardProcessor;



};
#endif // MAINWINDOW_H
