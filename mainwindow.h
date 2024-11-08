#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "sign_in.h"
#include "sign_up.h"
#include "sql.h"
#include "menu.h"
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void changeWindow();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void display();
    void signIn();
    void signUp();

    void startGame();
    void singleGame();
    void multiplayerGame();
    void settings();
    void statistic();

    void exit();
    void exitApp();

private:
    sign_in sign_in;
    sign_up registration;
    User *user;
    Ui::MainWindow *ui;
    sql* userSql;

    Game game;
    menu mainMenu;
};
#endif // MAINWINDOW_H
