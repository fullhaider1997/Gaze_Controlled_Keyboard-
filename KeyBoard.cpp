#include "KeyBoard.h"
#include "ui_keyboard.h"

KeyBoard::KeyBoard(QWidget *parent) :
    QDialog(parent),
    Ui(new Ui::KeyBoard)
{
    Ui->setupUi(this);
}

KeyBoard::~KeyBoard()
{
    delete Ui;
}
