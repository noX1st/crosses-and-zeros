#include "menu.h"
#include "ui_menu.h"
#include <QSettings>
#include <QIcon>


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

    connect(settingsButtonGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked), this, [this](QAbstractButton *button){
        int id = settingsButtonGroup->id(button);
        ui->stackedWidgetSettings->setCurrentIndex(id);
    });
    connect(ui->themeComboBox, &QComboBox::currentTextChanged, this, &menu::changeTheme);
    connect(ui->fontComboBox, &QFontComboBox::currentFontChanged, this, &menu::changeFont);

    loadSettings();
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

void menu::rollbackSettings()
{
    pendingSettings = appliedSettings;
    changeTheme(appliedSettings.theme);
    changeFont(appliedSettings.font);
    QFont font;
    if (font.fromString(pendingSettings.font))
    {
        ui->fontComboBox->setCurrentFont(font);
    }
    else
    {
        ui->fontComboBox->setCurrentFont(QFont("Segoe UI"));
    }

    ui->themeComboBox->setCurrentText(appliedSettings.theme);
}

void menu::on_SettingsCancelBtn_clicked()
{
    rollbackSettings();
    ui->stackedWidget->setCurrentIndex(0);
}

void menu::on_SettingsOkBtn_clicked()
{
    applySettings();
    saveSettings();
    ui->stackedWidget->setCurrentIndex(0);
}

void menu::on_SettingsApplyBtn_clicked()
{
    applySettings();
    saveSettings();
}

void menu::applySettings()
{
    applyTheme();
    QFont font;
    if (font.fromString(pendingSettings.font))
    {
        applyFont(font);
    }

    appliedSettings = pendingSettings;
    saveSettings();
}

void menu::changeTheme(const QString &theme)
{
    pendingSettings.theme = theme;
}

void menu::changeFont(const QFont &font)
{
    pendingSettings.font = font.toString();
}

void menu::applyFont(const QFont &font)
{
    QString fontBox;
    if (pendingSettings.font.isEmpty())
    {
        qDebug() << "Font is empty. Applying default font";
        pendingSettings.font = "Segoe UI";
    }
    QString fontStyle;
    if (appliedSettings.theme == "Black")
    {
        fontStyle = QString("font-family: '%1'; color: white").arg(font.family());
    }
    else if (appliedSettings.theme == "White")
    {
        fontStyle = QString("font-family: '%1'; color: black").arg(font.family());
    }
    /*else if (appliedSettings.theme == "") {
        fontStyle = QString("font-family: '%1'; color: white").arg(font.family());
        //fontStyle = QString("font-family: 'Nirmala UI'; color: white");
    }*/
    if (appliedSettings.theme == "Black")
    {
        fontBox = "font-family: Segoe UI; background-color: rgb(62, 62, 62); color: white; border: none; padding: 5px;";
    }
    else if (appliedSettings.theme == "White")
    {
        fontBox = "font-family: Segoe UI; background-color: rgb(188, 188, 188); color: black; border: none; padding: 5px;";
    }
    ui->menuPage->setStyleSheet(fontStyle);
    ui->settingsPage->setStyleSheet(fontStyle);
    ui->statisticPage->setStyleSheet(fontStyle);
    ui->fontComboBox->setStyleSheet(fontBox);
    /*QList<QLabel *> labels = this->findChildren<QLabel *>();
    for (QLabel *label : labels)
    {
        label->setStyleSheet(fontStyle);
    }

    QList<QPushButton *> settingsPushButtons = this->findChildren<QPushButton *>();
    for (QPushButton *pushButton : settingsPushButtons)
    {
        QFont font = pushButton->font();
        font.setFamily(pendingSettings.font);
        pushButton->setFont(font);
    }

    QList<QComboBox *> settingsComboBoxes = this->findChildren<QComboBox *>();
    for (QComboBox *comboBox : settingsComboBoxes)
    {
        QFont font = comboBox->font();
        font.setFamily(pendingSettings.font);
        comboBox->setFont(font);
    }
    //
    /*QList<QFontComboBox *> settingsFontComboBoxes = this->findChildren<QFontComboBox *>();
    for (QFontComboBox *fontComboBox : settingsFontComboBoxes) {
        QFont font = fontComboBox->font();
        font.setFamily(pendingSettings.font);
        fontComboBox->setFont(font);
    }*/

    qDebug() << "Applied font: " << font.family();
}

void menu::applyTheme()
{
    if (pendingSettings.theme.isEmpty())
    {
        qDebug() << "Theme is empty. Applying default theme";
        pendingSettings.theme = "Black";
    }
    appliedSettings.theme = pendingSettings.theme;

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

    QString cornerBtns;
    QString backBtn;
    QIcon setIcon;

    if (appliedSettings.theme == "Black")
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
                          "QPushButton:checked"
                          "{ background-color: rgb(62, 62, 62);  }"
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
        cornerBtns = "QPushButton"
                     "{ background-color: rgb(55, 55, 55); color: rgb(255, 255, 255); border: none; padding: 5px; }"
                     "QPushButton:hover"
                     "{ background-color: rgb(50, 50, 50); }"
                     "QPushButton:pressed"
                     "{ background-color: rgb(46, 46, 46); }";

        backBtn = "background-color: rgb(30, 30, 30); color: rgb(255, 255, 255); border: none; padding: 5px;";
        ui->BackBtn->setIcon(QIcon("D:/programs/programming/qt folder/2/2/icons/arrow.png"));
        ui->BackBtn_2->setIcon(QIcon("D:/programs/programming/qt folder/2/2/icons/arrow.png"));
    }
    else if (appliedSettings.theme == "White")
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
                          "QPushButton:checked"
                          "{ background-color: rgb(188, 188, 188); }"
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
        cornerBtns = "QPushButton"
                     "{ background-color: rgb(212, 212, 212); color: rgb(50, 50, 50); border: none; padding: 5px; }"
                     "QPushButton:hover"
                     "{ background-color: rgb(200, 200, 200); }"
                     "QPushButton:pressed"
                     "{ background-color: rgb(188, 188, 188); }";

        backBtn = "background-color: rgb(220, 220, 220); color: rgb(255, 255, 255); border: none; padding: 5px;";
        ui->BackBtn->setIcon(QIcon("D:/programs/programming/qt folder/2/2/icons/blackArrow.png"));
        ui->BackBtn_2->setIcon(QIcon("D:/programs/programming/qt folder/2/2/icons/blackArrow.png"));
    }

    this->setStyleSheet(menuStyle);
    //Menu
    ui->menuPage->setStyleSheet(menuPageStyle);
    QList<QLabel *> menuLabels = ui->menuPage->findChildren<QLabel *>();
    for (QLabel *label : menuLabels)
    {
        label->setStyleSheet(labelStyle);
    }
    QList<QPushButton *> menuPagePushButtons = ui->menuPage->findChildren<QPushButton *>();
    for (QPushButton *pushButton : menuPagePushButtons)
    {
        pushButton->setStyleSheet(pushButtonStyle);
    }


    //Settings

    QList<QLabel *> settingsLabels = ui->settingsPage->findChildren<QLabel *>();
    for (QLabel *label : settingsLabels)
    {
        label->setStyleSheet(labelStyle);
    }

    QList<QPushButton *> settingsPushButtons = ui->settingsPage->findChildren<QPushButton *>();
    for (QPushButton *pushButton : settingsPushButtons)
    {
        pushButton->setStyleSheet(pushButtonStyle);
    }

    QList<QComboBox *> settingsComboBoxes = ui->settingsPage->findChildren<QComboBox *>();
    for (QComboBox *comboBox : settingsComboBoxes)
    {
        comboBox->setStyleSheet(comboBoxStyle);
    }

    QList<QSpinBox *> settingsSpinBoxes = ui->settingsPage->findChildren<QSpinBox *>();
    for (QSpinBox *spinBox : settingsSpinBoxes)
    {
        spinBox->setStyleSheet(spinBoxStyle);
    }
    ui->settingsPage->setStyleSheet(settingsPageStyle);
    ui->stackedWidgetSettings->setStyleSheet(stackedWidgetSettingsStyle);
    ui->settingsResetBtn->setStyleSheet(resetBtnStyle);


    //Statistic
    ui->statisticPage->setStyleSheet(statisticPageStyle);
    ui->stackedWidgetSettings_2->setStyleSheet(stackedWidgetSettingsStyle);
    QList<QLabel *> statisticLabels = ui->statisticPage->findChildren<QLabel *>();
    for (QLabel *label : statisticLabels)
    {
        label->setStyleSheet(labelStyle);
    }

    QList<QPushButton *> statisticPushButtons = ui->statisticPage->findChildren<QPushButton *>();
    for (QPushButton *pushButton : statisticPushButtons)
    {
        pushButton->setStyleSheet(pushButtonStyle);
    }


    //
    ui->SettingsOkBtn->setStyleSheet(cornerBtns);
    ui->SettingsCancelBtn->setStyleSheet(cornerBtns);
    ui->SettingsApplyBtn->setStyleSheet(cornerBtns);
    ui->BackBtn->setStyleSheet(backBtn);
    ui->BackBtn_2->setStyleSheet(backBtn);

    qDebug() << "Applied theme: " << pendingSettings.theme;
}

void menu::saveSettings()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "nxst", "user");


    settings.beginGroup("Appearance");
    settings.setValue("theme", appliedSettings.theme);
    settings.setValue("font", appliedSettings.font);
    settings.endGroup();

    qDebug() << "Settings saved at:" << settings.fileName()
             << "Theme:" << appliedSettings.theme
             << "Font:" << appliedSettings.font;

}

void menu::loadSettings()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "nxst", "user");


    //default
    settings.beginGroup("Appearance");
    QString theme = settings.value("theme", "Black").toString();
    QString font = settings.value("font", "Segoe UI").toString();
    settings.endGroup();

    //load
    pendingSettings.theme = theme;
    pendingSettings.font = font;
    QFont fontB;
    if (fontB.fromString(pendingSettings.font))
    {
        ui->fontComboBox->setCurrentFont(font);
    }
    else
    {
        ui->fontComboBox->setCurrentFont(QFont("Segoe UI"));
    }
    ui->themeComboBox->setCurrentText(pendingSettings.theme);
    applySettings();

    qDebug() << "Settings loaded!";
}
