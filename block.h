#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QString>
#include <QImage>
#include <QRect>

using namespace std; 

class Block : public QObject
{
    Q_OBJECT
public:
    Block(int, int, int);
    ~Block();

    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();
    QString getBlockNumber();
    void setBlockNumber(QString);
    
private:
    QString block_number;
    string name;
    QImage image;
    QRect rect;

    bool destroyed;

signals:

public slots:
};

#endif // BLOCK_H
