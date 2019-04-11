#ifndef BOARDFACTORY_H
#define BOARDFACTORY_H

#include "board.h"

#include <QObject>

class BoardFactory : public QObject
{
    Q_OBJECT
public:
    explicit BoardFactory(QObject *parent = nullptr);
    Board* getBoard(int numberOfBlocks);

private:
    Board* get15BlocksBoard();
    Board* get8BlocksBoard();

    Board* createBoard(vector<vector<int>> numberMatrix);
};

#endif // BOARDFACTORY_H
