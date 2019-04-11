#include "puzzlegame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PuzzleGame puzzleGame;

    puzzleGame.showMenu();

    return a.exec();
}
