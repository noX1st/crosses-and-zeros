#ifndef GAME_H
#define GAME_H
#include "QPaintEvent"
#include "QPainter"
#include <QWidget>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    void drawCircle(int x, int y);
    void drawCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);


private:
    Ui::Game *ui;

    QPainter* painter;

    int player;

    int x1, y1;
    bool isClicked;
};

#endif // GAME_H
