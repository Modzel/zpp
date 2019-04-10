#include "boardfactory.h"

BoardFactory::BoardFactory(QObject *parent) : QObject(parent)
{

}

Board* BoardFactory::getBoard(int numberOfBlocks)
{
    switch(numberOfBlocks){
    case 15:
        return get15BlocksBoard();
    case 8:
        return get8BlocksBoard();
    }
}


Board* BoardFactory::get15BlocksBoard()
{
    vector<int> row1 = {15,2,1,12};
    vector<int> row2 = {8,5,6,11};
    vector<int> row3 = {4,9,10,7};
    vector<int> row4 = {3,14,13,-1};

    vector<vector<int>> numberMatrix;
    numberMatrix.push_back(row1);
    numberMatrix.push_back(row2);
    numberMatrix.push_back(row3);
    numberMatrix.push_back(row4);

    return createBoard(numberMatrix);

}

Board *BoardFactory::get8BlocksBoard()
{
    vector<int> row1 = {-1,1,3};
    vector<int> row2 = {4,2,5};
    vector<int> row3 = {7,8,6};

    vector<vector<int>> numberMatrix;
    numberMatrix.push_back(row1);
    numberMatrix.push_back(row2);
    numberMatrix.push_back(row3);

    return createBoard(numberMatrix);
}

Board *BoardFactory::createBoard(vector<vector<int> > numberMatrix)
{
    vector<vector<Block*> > blockMatrix;

    for (int i=0; i<numberMatrix.size(); i++) {
        vector<Block*> rowOfBlocks;
      for (int j=0; j<numberMatrix[i].size(); j++) {
          if(numberMatrix[i][j] == -1){
              Block* emptyBlock = new Block(i*40+30, j*30+50, -1);
              emptyBlock->setBlockNumber(NULL);
              rowOfBlocks.push_back(emptyBlock);
          }
          else {
              rowOfBlocks.push_back(new Block(i*40+30, j*30+50, numberMatrix[i][j]));
          }
      }
      blockMatrix.push_back(rowOfBlocks);
    }

    return new Board(blockMatrix);
}
