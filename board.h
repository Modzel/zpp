#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include "block.h"

class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(vector<vector<Block*> > blockMatrix);
    ~Board();
    vector<vector<Block*>> getBoard();
    int getXEmpty();
    int getYEmpty();
    void recalculateEmptyPosition();
    void setBlockMatrix(vector<vector<Block*> > blockMatrix);


private:
    vector<vector<Block*> > blockMatrix;
    int xEmpty;
    int yEmpty;
};

#endif // BOARD_H
