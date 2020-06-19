#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
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

public slots:
    void loopThroughButtons();
    void userIsBlinking(bool answer);


private:
    Ui::MainWindow * mainGUI;
    VideoProcessorPipleLine *videoProccessorPipeLine;
    QThread *threadVideoProcessor;
    QThread *threadKeyBoardProcessor;
    QList<QPushButton *> listButtons;


public:
    struct KeyBoardProcessor{

        KeyBoardProcessor()
            :
            buttonPosition(1),
            blinkingStatus(false)
            {}

        void IncrementKeyBoardPosition(){
            buttonPosition++;
            if(buttonPosition == 11){
                buttonPosition = 1;
            }
        }
        int getCurrentButtonPosition(){
            return buttonPosition;
        }

    private:
        int buttonPosition;
        bool blinkingStatus;
    };

private:
    MainWindow::KeyBoardProcessor keyboard;





};
#endif // MAINWINDOW_H
