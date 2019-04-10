#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QRect>
#include <QSize>
#include<iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x = 0;
    gameOver = false;
    gameWon = false;
    paused = false;
    gameStarted = false;
    xEmpty = 1;
    yEmpty = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);

    if (gameOver) {

//    finishGame(&painter, "Game lost");

    } else if(gameWon) {
        painter.drawText(100, 100, "WYGRAŚŚŚŚKOW");
//    finishGame(&painter, "Victory");
    }
    else {

    drawObjects(&painter);
//    if(checkWinCondition()) {
//            painter.drawText(100, 100, "WYGRAŚŚŚŚKOW");
//    }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
            emit checkIntersections(event->pos());
    }
}

void MainWindow::drawBoard(vector<vector<Block*>> board)
{
    blocks = board;
    this->repaint();
}

void MainWindow::handleRedraw(vector<vector<Block *> > board)
{
    drawBoard(board);
}


void MainWindow::drawObjects(QPainter *painter) {


    for (int i=0; i<blocks.size(); i++) {
      for (int j=0; j<blocks[i].size(); j++) {
            painter->drawRect(blocks[i][j]->getRect());
            painter->drawText(blocks[i][j]->getRect().center(), blocks[i][j]->getBlockNumber());
        }
    }
}


