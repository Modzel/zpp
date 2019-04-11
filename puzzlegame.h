#ifndef PUZZLEGAME_H
#define PUZZLEGAME_H

#include <QObject>
#include <QSound>
#include "boardfactory.h"
#include "gamemenu.h"
#include "gamesettings.h"
#include "mainwindow.h"
#include "settingsmenu.h"



class PuzzleGame : public QObject
{
    Q_OBJECT

public:
    PuzzleGame();
    void showMenu();

private:
    GameMenu gm;
    MainWindow w;
    SettingsMenu sm;
    GameSettings gameSettings;
    Board* board;
    BoardFactory boardFactory;

    bool isNeighbourEmpty(int i, int j, int xEmpty, int yEmpty);
    void checkWinCondition();
signals:
    void redrawBoard(vector<vector<Block*>> board);
    void userWon();
private slots:
    void receive_from_gui(GameMenuItems option);
    void checkIintersections(QPoint point);
};

#endif // PUZZLEGAME_H
