#include "mainwindow.h"

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

    if(gameWon) {
        painter.drawText(100, 100, "Wygrana!!");
    }
    else {
        drawObjects(&painter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
            emit checkIntersections(event->pos());
    }
}

void MainWindow::startNewGame(vector<vector<Block*>> board)
{
    gameWon = false;
    blocks = board;
    this->repaint();
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

void MainWindow::handleGameWon()
{
    gameWon = true;
    this->repaint();
}


void MainWindow::drawObjects(QPainter *painter) {


    for (int i=0; i<blocks.size(); i++) {
      for (int j=0; j<blocks[i].size(); j++) {
            painter->drawRect(blocks[i][j]->getRect());
            painter->drawText(blocks[i][j]->getRect().center(), blocks[i][j]->getBlockNumber());
        }
    }
}



void MainWindow::on_backToMenuButton_clicked()
{
    emit goBackToMenu(GAME_BOARD_BACK);
}
