#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->lineEdit->SetMaxCharactorLength(50);
}

Dialog::~Dialog()
{
    delete ui;
}

