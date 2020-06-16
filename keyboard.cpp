#include "keyboard.h"
#include "ui_keyboard.h"

KeyBoard::KeyBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyBoard)

{
    ui->setupUi(this);

    KeyBoardButtons->push_back(ui->A_Button);
    KeyBoardButtons->push_back(ui->B_Button);
    KeyBoardButtons->push_back(ui->C_Button);
    KeyBoardButtons->push_back(ui->D_Button);
    KeyBoardButtons->push_back(ui->C_Button);
    KeyBoardButtons->push_back(ui->E_Button);
    KeyBoardButtons->push_back(ui->F_Button);
    KeyBoardButtons->push_back(ui->G_Button);
    KeyBoardButtons->push_back(ui->I_Button);
    KeyBoardButtons->push_back(ui->J_Button);
    KeyBoardButtons->push_back(ui->K_Button);
    KeyBoardButtons->push_back(ui->L_Button);

}

KeyBoard::~KeyBoard()
{
    delete ui;
}

