#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);

    settingsButtonGroup = new QButtonGroup(this);
    settingsButtonGroup->addButton(ui->settingsPageGameBtn, 0);
    settingsButtonGroup->addButton(ui->settingsPageAppearanceBtn, 1);
    settingsButtonGroup->addButton(ui->settingsPageOtherBtn, 2);
    settingsButtonGroup->setExclusive(true);

    connect(settingsButtonGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            this, [this](QAbstractButton *button) {
                int id = settingsButtonGroup->id(button);
                ui->stackedWidget_2->setCurrentIndex(id);
            });
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
    ui->stackedWidget->setCurrentIndex(1);
    emit settingsBtn_clicked();
}

void menu::on_multiplayerBtn_clicked()
{
    emit multiplayerBtn_clicked();
}

void menu::on_statisticBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    emit statisticBtn_clicked();
}

void menu::on_exitBtn_clicked()
{
    emit exitBtn_clicked();
}

void menu::on_BackBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu::on_BackBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu::on_SettingsCancelBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu::on_SettingsOkBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
