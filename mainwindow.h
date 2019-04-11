#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "block.h"
#include "gamemenuitems.h"
#include <QPainter>
#include <QMouseEvent>
#include <QRect>
#include <QSize>
#include<iostream>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "ui_mainwindow.h"

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
    void startNewGame(vector<vector<Block*>> board);

signals:
    void checkIntersections(QPoint pos);
    void goBackToMenu(GameMenuItems item);
private slots:
    void handleRedraw(vector<vector<Block*>> board);
    void handleGameWon();
    void on_backToMenuButton_clicked();

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
