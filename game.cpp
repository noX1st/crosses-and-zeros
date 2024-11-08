#include "game.h"
#include "ui_game.h"
#include "QMessageBox"
#include "QDebug"


Game::Game(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Game)
    , painter(new QPainter(this))
    , player(1)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
    delete painter;
}

void Game::mouseMoveEvent(QMouseEvent* event)
{
    update();
}

void Game::mousePressEvent(QMouseEvent* event)
{
    x1 = event->position().x();
    y1 = event->position().y();
    isClicked = true;
    qDebug()<<x1<< " " << y1;
}

void Game::paintEvent(QPaintEvent* event)
{
    painter->begin(this);
    painter->setPen(QPen(Qt::black, 2));
    painter->drawLine(this->width()/3, 50, this->width()/3, this->height());
    painter->drawLine(this->width()/1.5, 50, this->width()/1.5, this->height());
    painter->drawLine(0, (this->height() - 50) /1.5 + 50, this->width(), (this->height() - 50) /1.5 + 50);
    painter->drawLine(0, (this->height() - 50) /3 + 50, this->width(), (this->height() - 50) /3 + 50);
    painter->drawLine(0, 50, this->width(), 50);
    //drawCircle(10, 10);
    //drawCross(175, 25, 275, 125, 275, 25, 175, 125);
    if (player == 1)
    {
        painter->setPen(QPen(Qt::black, 2));
        painter->setFont(QFont("Verdana", 14));
        painter->drawText(width()/3, 30, "player 1 turn");
    }
    else
    {
        painter->setPen(QPen(Qt::black, 2));
        painter->setFont(QFont("Verdana", 14));
        painter->drawText(width()/3, 30, "player 2 turn");
    }
    if (isClicked)
    {
        if (y1 <= ((this->height() - 50) /3 + 50) && y1 >= 50)
        {
            if (x1 <= this->width()/3 && x1 >= 0)
            {
                if (player == 1)
                {
                    drawCircle(10, 60);
                }
                else
                {
                    drawCross(225, 75, 325, 175, 325, 75, 225, 175);
                }
            }
        }
        //isClicked = false;
    }
    painter->end();
}

void Game::drawCircle(int x, int y)
{
    painter->setPen(QPen(Qt::black, 2));
    painter->drawEllipse(x, y, 125, 125);
}

void Game::drawCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    painter->setPen(QPen(Qt::black, 2));
    painter->drawLine(x1, y1, x2, y2);
    painter->drawLine(x3, y3, x4, y4);
}
