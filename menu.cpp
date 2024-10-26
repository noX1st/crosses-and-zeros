#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_startBtn_clicked()
{
    emit startBtn_clicked();
}


void menu::on_singleBtn_clicked()
{
    emit singleBtn_clicked();
}


void menu::on_settingsBtn_clicked()
{
    emit settingsBtn_clicked();
}


void menu::on_multiplayerBtn_clicked()
{
    emit multiplayerBtn_clicked();
}


void menu::on_statisticBtn_clicked()
{
    emit statisticBtn_clicked();
}


void menu::on_exitBtn_clicked()
{
    emit exitBtn_clicked();
}

