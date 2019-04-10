#include "block.h"
#include <iostream>

Block::Block(int x, int y, int block_number) {

  image.load("brickie.png");
  destroyed = false;
  rect = QRect(x, y, 30, 30);
  this->block_number = block_number < 0 ? NULL : QString::number(block_number);
}

Block::~Block() {

  std::cout << ("Block deleted") << std::endl;
}

QRect Block::getRect() {

  return rect;
}

void Block::setRect(QRect rct) {

  rect = rct;
}

QImage & Block::getImage() {

    return image;
}

QString Block::getBlockNumber()
{
    return block_number;
}

void Block::setBlockNumber(QString str)
{
 block_number = str;
}

bool Block::isDestroyed() {

  return destroyed;
}

void Block::setDestroyed(bool destr) {

  destroyed = destr;
}
