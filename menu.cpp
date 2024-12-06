#include "menu.h"
#include "ui_menu.h"
#include <QSettings>


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

    connect(settingsButtonGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked), this, [this](QAbstractButton *button) {
        int id = settingsButtonGroup->id(button);
        ui->stackedWidgetSettings->setCurrentIndex(id);
    });
    connect(ui->themeComboBox, &QComboBox::currentTextChanged, this, &menu::changeTheme);
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


void menu::changeTheme(const QString &theme)
{
    QString menuStyle;

    QString menuPageStyle;
    QString labelStyle;
    QString stackedWidgetSettingsStyle;

    QString settingsPageStyle;
    QString pushButtonStyle;
    QString comboBoxStyle;
    QString spinBoxStyle;
    QString resetBtnStyle;

    QString statisticPageStyle;

    QString CornerBtns;

    if (theme == "Black")
    {
        menuStyle = "background-color: rgb(30, 30, 30); color: black;";
        //Menu
        menuPageStyle = "background-color: rgb(30, 30, 30); color: white;";
        labelStyle = "color: white;";


        //Settings
        settingsPageStyle = "background-color: rgb(30, 30, 30); color: white;";
        stackedWidgetSettingsStyle = "background-color: rgb(38, 38, 38); color: white;";
        pushButtonStyle = "QPushButton"
        "{ background-color: rgb(38, 38, 38); color: white; border: none; padding: 5px; }"
        "QPushButton:hover"
        "{ background-color: rgb(48, 48, 48);  }"
        "QPushButton:pressed"
        "{ background-color: rgb(62, 62, 62);  }";

        resetBtnStyle = "QPushButton"
        "{ background-color: rgb(55, 55, 55); color: white; border: none; padding: 5px; }"
        "QPushButton:hover"
        "{ background-color: rgb(65, 65, 65); }"
        "QPushButton:pressed"
        "{ background-color: rgb(70, 70, 70); }";

        comboBoxStyle = "background-color: rgb(62, 62, 62); color: white; border: none; padding: 5px;";
        spinBoxStyle = "background-color: rgb(55, 55, 55); color: white;";


        //Statistic
        statisticPageStyle = "background-color: rgb(30, 30, 30); color: white;";

        //
        CornerBtns = "QPushButton"
        "{ background-color: rgb(55, 55, 55); color: rgb(255, 255, 255); border: none; padding: 5px; }"
        "QPushButton:hover"
        "{ background-color: rgb(50, 50, 50); }"
        "QPushButton:pressed"
        "{ background-color: rgb(46, 46, 46); }";
    }
    else if (theme == "White")
    {
        menuStyle = "background-color: rgb(220, 220, 220); color: black;";
        //Menu
        menuPageStyle = "background-color: rgb(220, 220, 220); color: black;";
        labelStyle = "color: black;";


        //Settings
        settingsPageStyle = "background-color: rgb(220, 220, 220); color: rgb(50, 50, 50);";
        stackedWidgetSettingsStyle = "background-color: rgb(212, 212, 212); color: rgb(50, 50, 50);";
        pushButtonStyle = "QPushButton"
        "{ background-color: rgb(208, 208, 208); color: rgb(50, 50, 50); border: none; padding: 5px; }"
        "QPushButton:hover"
        "{ background-color: rgb(200, 200, 200); }"
        "QPushButton:pressed"
        "{ background-color: rgb(188, 188, 188); }";

        resetBtnStyle = "QPushButton"
        "{ background-color: rgb(195, 195, 195); color: rgb(50, 50, 50); border: none; padding: 5px; }"
        "QPushButton:hover"
        "{ background-color: rgb(185, 185, 185); }"
        "QPushButton:pressed"
        "{ background-color: rgb(171, 171, 171); }";

        comboBoxStyle = "background-color: rgb(190, 190, 190); color: rgb(50, 50, 50); border: none; padding: 5px;";
        spinBoxStyle = "background-color: rgb(190, 190, 190); color: rgb(50, 50, 50)";


        //Statistic
        statisticPageStyle = "background-color: rgb(220, 220, 220); color: black; border: white;";

        //
        CornerBtns = "QPushButton"
        "{ background-color: rgb(212, 212, 212); color: rgb(50, 50, 50); border: none; padding: 5px; }"
        "QPushButton:hover"
        "{ background-color: rgb(200, 200, 200); }"
        "QPushButton:pressed"
        "{ background-color: rgb(188, 188, 188); }";
    }

    this->setStyleSheet(menuStyle);
    //Menu
    ui->menuPage->setStyleSheet(menuPageStyle);
    QList<QLabel *> menuLabels = ui->menuPage->findChildren<QLabel *>();
    for (QLabel *label : menuLabels) {
        label->setStyleSheet(labelStyle);
    }
    QList<QPushButton *> menuPagePushButtons = ui->menuPage->findChildren<QPushButton *>();
    for (QPushButton *pushButton : menuPagePushButtons) {
        pushButton->setStyleSheet(pushButtonStyle);
    }


    //Settings
    ui->settingsPage->setStyleSheet(settingsPageStyle);
    ui->stackedWidgetSettings->setStyleSheet(stackedWidgetSettingsStyle);
    ui->settingsResetBtn->setStyleSheet(resetBtnStyle);
    QList<QLabel *> settingsLabels = ui->settingsPage->findChildren<QLabel *>();
    for (QLabel *label : settingsLabels) {
        label->setStyleSheet(labelStyle);
    }

    QList<QPushButton *> settingsPushButtons = ui->settingsPage->findChildren<QPushButton *>();
    for (QPushButton *pushButton : settingsPushButtons) {
        if (pushButton != ui->settingsResetBtn) {
            pushButton->setStyleSheet(pushButtonStyle);
        }
    }

    QList<QComboBox *> settingsComboBoxes = ui->settingsPage->findChildren<QComboBox *>();
    for (QComboBox *comboBox : settingsComboBoxes) {
        comboBox->setStyleSheet(comboBoxStyle);
    }

    QList<QSpinBox *> settingsSpinBoxes = ui->settingsPage->findChildren<QSpinBox *>();
    for (QSpinBox *spinBox : settingsSpinBoxes) {
        spinBox->setStyleSheet(spinBoxStyle);
    }


    //Statistic
    ui->statisticPage->setStyleSheet(statisticPageStyle);
    ui->stackedWidgetSettings_2->setStyleSheet(stackedWidgetSettingsStyle);
    QList<QLabel *> statisticLabels = ui->statisticPage->findChildren<QLabel *>();
    for (QLabel *label : statisticLabels) {
        label->setStyleSheet(labelStyle);
    }

    QList<QPushButton *> statisticPushButtons = ui->statisticPage->findChildren<QPushButton *>();
    for (QPushButton *pushButton : statisticPushButtons) {
        pushButton->setStyleSheet(pushButtonStyle);
    }

    //
    ui->SettingsOkBtn->setStyleSheet(CornerBtns);
    ui->SettingsCancelBtn->setStyleSheet(CornerBtns);
    ui->SettingsApplyBtn->setStyleSheet(CornerBtns);
}
