#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_startBtn_clicked();
    void on_singleBtn_clicked();
    void on_settingsBtn_clicked();
    void on_multiplayerBtn_clicked();
    void on_statisticBtn_clicked();
    void on_exitBtn_clicked();
    void on_BackBtn_clicked();

    void on_SettingsCancelBtn_clicked();
    void on_SettingsOkBtn_clicked();

    void on_BackBtn_2_clicked();

    void on_SettingsApplyBtn_clicked();

signals:
    void startBtn_clicked();
    void singleBtn_clicked();
    void settingsBtn_clicked();
    void multiplayerBtn_clicked();
    void statisticBtn_clicked();
    void exitBtn_clicked();

private:
    Ui::menu *ui;
    QButtonGroup *settingsButtonGroup;

    struct Settings
    {
        QString theme;
        QString font;
    };
    Settings pendingSettings;
    Settings appliedSettings;

    void rollbackSettings();
    void changeTheme(const QString &theme);
    void changeFont(const QFont &font);
    void applyFont(const QFont &font);
    void applyTheme();
    void applySettings();
};

#endif // MENU_H
