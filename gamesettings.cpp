#include "gamesettings.h"

GameSettings::GameSettings(QObject *parent) : QObject(parent)
{

}

int GameSettings::getNumberOfBlocks() const
{
    return numberOfBlocks;
}

bool GameSettings::getIsSoundOn() const
{
    return isSoundOn;
}

void GameSettings::blocks_changed(QString blocks)
{
    numberOfBlocks = blocks.toInt();
}

void GameSettings::sound_changed(int index)
{
    isSoundOn = index == 0 ? true : false;
}
