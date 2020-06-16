#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>
#include <qabstractbutton.h>
namespace Ui {
class KeyBoard;
}

class KeyBoard : public QDialog
{
    Q_OBJECT

public:
    explicit KeyBoard(QWidget *parent = nullptr);
public:

    ~KeyBoard();


private:
    Ui::KeyBoard *ui;
    std::vector<QAbstractButton*> *KeyBoardButtons;
};

#endif // KEYBOARD_H
