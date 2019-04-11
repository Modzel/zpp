#include "puzzlegame.h"

PuzzleGame::PuzzleGame()
{
    connect(&gm,SIGNAL(menu_option_selected(GameMenuItems)),this,SLOT(receive_from_gui(GameMenuItems)));
    connect(&sm,SIGNAL(back_option_selected(GameMenuItems)),this,SLOT(receive_from_gui(GameMenuItems)));
    connect(&sm,SIGNAL(number_of_blocks_changed(QString)),&gameSettings,SLOT(blocks_changed(QString)));
    connect(&sm,SIGNAL(sound_setting_changed(int)),&gameSettings,SLOT(sound_changed(int)));
    connect(&w,SIGNAL(checkIntersections(QPoint)),this,SLOT(checkIintersections(QPoint)));
    connect(this,SIGNAL(redrawBoard(vector<vector<Block*>>)),&w,SLOT(handleRedraw(vector<vector<Block*>>)));
    connect(&w,SIGNAL(goBackToMenu(GameMenuItems)),this,SLOT(receive_from_gui(GameMenuItems)));
    connect(this,SIGNAL(userWon()),&w,SLOT(handleGameWon()));

    board = NULL;
}

void PuzzleGame::showMenu()
{
    gm.show();
}

void PuzzleGame::receive_from_gui(GameMenuItems option)
{
    switch (option) {
        case START:
            board = boardFactory.getBoard(gameSettings.getNumberOfBlocks());
            gm.hide();
            w.startNewGame(board->getBoard());
            w.show();
            break;
        case SETTINGS:
            gm.hide();
            sm.show();
            break;
        case SETTINGS_BACK:
            sm.hide();
            gm.show();
            break;
        case GAME_BOARD_BACK:
            w.hide();
            gm.show();
            break;
    }

}

void PuzzleGame::checkIintersections(QPoint point)
{
    int xEmpty = board->getXEmpty();
    int yEmpty = board->getYEmpty();
    vector<vector<Block *> > blocks = board->getBoard();
    for (int i=0; i< blocks.size(); i++) {
      for (int j=0; j<blocks[i].size(); j++) {
      if (blocks[i][j]->getRect().intersects(QRect(point, QSize(5, 5)))) {
          if(isNeighbourEmpty(i, j, xEmpty, yEmpty)){
              QString tmp = board->getBoard()[i][j]->getBlockNumber();
              blocks[i][j]->setBlockNumber(NULL);
              blocks[xEmpty][yEmpty]->setBlockNumber(tmp);
              board->setBlockMatrix(blocks);
              if(gameSettings.getIsSoundOn()){
                  QSound::play("./dzwiek.wav");
              }
              emit redrawBoard(blocks);
              checkWinCondition();
              return;
          }
        }
      }
    }
}

bool PuzzleGame::isNeighbourEmpty(int i, int j, int xEmpty, int yEmpty)
{
    if(xEmpty == i){
        if(j-1 == yEmpty || j+1 == yEmpty){
            return true;
        }
    }
    else if(yEmpty == j){
        if(xEmpty == i-1 || xEmpty ==i +1){
            return true;
        }
    }
    return false;
}

void PuzzleGame::checkWinCondition()
{
    vector<vector<Block *> > blocks = board->getBoard();
    int k = 1;
    for (int i=0; i<blocks.size(); i++) {
      for (int j=0; j<blocks[i].size(); j++) {
          if(blocks[i][j]->getBlockNumber() != NULL){
              int liczba = blocks[i][j]->getBlockNumber().toInt();
              if(liczba == k){
                  k++;
              }
              else {
                 return;
              }
          }
      }
    }
    emit userWon();
}
