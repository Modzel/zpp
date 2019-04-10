#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "block.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void drawBoard(vector<vector<Block*>> board);

signals:
    void checkIntersections(QPoint pos);
private slots:
    void handleRedraw(vector<vector<Block*>> board);

private:
    Ui::MainWindow *ui;
    int x;

    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    void drawObjects(QPainter *painter);

    vector<vector<Block*>> blocks;
    int xEmpty;
    int yEmpty;
};

#endif // MAINWINDOW_H
