#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);

    // Создание группы кнопок для settingsPage
    settingsButtonGroup = new QButtonGroup(this);
    settingsButtonGroup->addButton(ui->settingsGameBtn, 0);
    settingsButtonGroup->addButton(ui->settingsOtherBtn, 1);
    settingsButtonGroup->addButton(ui->settingsResetBtn, 2);
    settingsButtonGroup->addButton(ui->settingsThemeBtn, 3);
    settingsButtonGroup->setExclusive(true);

    // Подключение сигналов для переключения вкладок в stackedWidget_2
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
