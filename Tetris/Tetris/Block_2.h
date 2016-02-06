#include "Block.h"
#pragma once
class System;
//0 : 00
//    00
class Block_2 : public Block
{
public:
	Block_2();
	void initShape();
	void changeShape() {}
	void setShape(int i_type);
	void clearShape();
	void move(int i_direction);
};