#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include "settingsmenu.h"

#include<QObject>

class GameSettings : public QObject
{
    Q_OBJECT
public:
    explicit GameSettings(QObject *parent = nullptr);

    int getNumberOfBlocks() const;

    bool getIsSoundOn() const;

signals:

public slots:
    void blocks_changed(QString blocks);
    void sound_changed(int index);

private:
    int numberOfBlocks = 15;
    bool isSoundOn = true;
};

#endif // GAMESETTINGS_H
