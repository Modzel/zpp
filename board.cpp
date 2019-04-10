#include "board.h"


Board::Board(vector<vector<Block *> > blockMatrix)
{
    this->blockMatrix = blockMatrix;
    recalculateEmptyPosition();
}

Board::~Board()
{
    blockMatrix.clear();
}

vector<vector<Block*>> Board::getBoard()
{
    return blockMatrix;
}

int Board::getXEmpty()
{
    return xEmpty;
}

int Board::getYEmpty()
{
    return xEmpty;
}

void Board::recalculateEmptyPosition()
{
    for (int i=0; i<blockMatrix.size(); i++) {
      for (int j=0; j<blockMatrix[i].size(); j++) {
          if(blockMatrix[i][j]->getBlockNumber() == NULL){
              xEmpty = i;
              yEmpty = j;
          }
      }
    }
}

void Board::setBlockMatrix(vector<vector<Block *> > blockMatrix)
{
    this->blockMatrix = blockMatrix;
    recalculateEmptyPosition();
}
