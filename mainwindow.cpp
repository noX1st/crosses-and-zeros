#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , sign_in(new class sign_in(this))
    , registration(new sign_up(this))
    , user(nullptr)
    , ui(new Ui::MainWindow)
    , userSql(new sqlUser(sqlConstans::mainConnection, sqlConstans::DBname))
{
    ui->setupUi(this);

    connect(&sign_in, &sign_in::signInBtn_clicked, this, &MainWindow::signIn);
    connect(&registration, &sign_up::signUpBtnClicked, this, &MainWindow::signUp);
    connect(&registration, SIGNAL(finished(int)), &sign_in, SLOT(show()));
    connect(&sign_in, SIGNAL(signUpBtn_clicked()), this, SLOT(changeWindow()));

    connect(&mainMenu, &menu::startBtn_clicked, this, &MainWindow::startGame);
    connect(&mainMenu, &menu::multiplayerBtn_clicked, this, &MainWindow::multiplayerGame);
    connect(&mainMenu, &menu::settingsBtn_clicked, this, &MainWindow::settings);
    connect(&mainMenu, &menu::singleBtn_clicked, this, &MainWindow::singleGame);
    connect(&mainMenu, &menu::statisticBtn_clicked, this, &MainWindow::statistic);
    connect(&mainMenu, &menu::exitBtn_clicked, this, &MainWindow::exit);

    userSql->createTable();
}

/*void MainWindow::BackBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}*/

void MainWindow::changeWindow()
{
    registration.show();
    sign_in.hide();
}

void MainWindow::startGame()
{
    game.show();
    mainMenu.hide();
}

void MainWindow::singleGame()
{

}

void MainWindow::multiplayerGame()
{

}

void MainWindow::settings()
{

}

void MainWindow::statistic()
{

}

void MainWindow::exit()
{
    mainMenu.close();
}

void MainWindow::exitApp()
{
    sign_in.close();
}

void MainWindow::signIn()
{
    delete user;
    user = new User;
    sqlUser* sql = dynamic_cast<sqlUser*> (userSql);
    if (sql == nullptr)
    {
        throw (std::runtime_error("dynamic cast error"));
    }
    /*if (!sql->getUser(*user, sqlConstans::userTableName, sign_in.get_email(), sign_in.get_password()))
    {
        QMessageBox MSG(
            QMessageBox::Warning, "warning", "you don't have an account", QMessageBox::Ok);
        MSG.exec();
        return;
    }
    QMessageBox MSG(
        QMessageBox::Information, "information", "sign in was successful", QMessageBox::Ok);
    MSG.exec();

    sign_in.hide();

    this->show();*/

    if (!sql->getUser(*user, sqlConstans::userTableName, sign_in.get_email(), sign_in.get_password()))
    {
        QMessageBox::warning(this, "warning", "The entered data is incorrect", QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, "information", "Sign in was successful", QMessageBox::Ok);
    mainMenu.show();
    sign_in.hide();
}

void MainWindow::signUp()
{
    if (registration.get_username().isEmpty() || registration.get_email().isEmpty() || registration.get_password().isEmpty() || registration.get_confirm().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Please fill in all fields.", QMessageBox::Ok);
        return;
    }
    if (!registration.get_email().contains('@'))
    {
        QMessageBox::warning(this, "Warning", "Please enter a valid email", QMessageBox::Ok);
        return;
    }
    if (registration.get_password() != registration.get_confirm())
    {
        QMessageBox MSG(
            QMessageBox::Warning, "warning", "passwords doesn't match", QMessageBox::Ok);
        MSG.exec();
        return;
    }
    delete user;
    user = new User(registration.get_username(), registration.get_email(), registration.get_password(), registration.get_birthday());
    sqlUser* sql = dynamic_cast<sqlUser*> (userSql);
    if (sql == nullptr)
    {
        throw (std::runtime_error("dynamic cast error"));
    }
    if (sql->getUser(*user, sqlConstans::userTableName, registration.get_email(), registration.get_password()))
    {
        QMessageBox::warning(this, "Warning", "This user already exists", QMessageBox::Ok);
        return;
    }
    sql->insertUser(*user);
    QMessageBox MSG(
        QMessageBox::Information, "information", "Sign up was succesfull", QMessageBox::Ok);

    MSG.exec();
    sign_in.show();
    registration.hide();
}

void MainWindow::display()
{
    sign_in.show();
}


MainWindow::~MainWindow()
{
    delete userSql;
    delete user;
    delete ui;
}
