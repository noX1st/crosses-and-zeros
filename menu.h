#ifndef MENU_H
#define MENU_H

#include <QDialog>

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

signals:
    void startBtn_clicked();

    void singleBtn_clicked();

    void settingsBtn_clicked();

    void multiplayerBtn_clicked();

    void statisticBtn_clicked();

    void exitBtn_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
