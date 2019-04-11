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
    QRect getRect();
    void setRect(QRect);
    QString getBlockNumber();
    void setBlockNumber(QString);
    
private:
    QString block_number;
    string name;
    QRect rect;

signals:

public slots:
};

#endif // BLOCK_H
