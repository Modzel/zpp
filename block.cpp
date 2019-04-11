#include "block.h"

Block::Block(int x, int y, int block_number) {
  rect = QRect(x, y, 30, 30);
  this->block_number = block_number < 0 ? NULL : QString::number(block_number);
}

Block::~Block() {

}

QRect Block::getRect() {

  return rect;
}

void Block::setRect(QRect rct) {

  rect = rct;
}

QString Block::getBlockNumber()
{
    return block_number;
}

void Block::setBlockNumber(QString str)
{
 block_number = str;
}
