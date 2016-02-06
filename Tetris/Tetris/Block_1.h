#include "Block.h"
#pragma once
class System;

//0 : 0000
//1 : 0
//    0
//    0
//    0
class Block_1 : public Block
{	
public:
	Block_1();	
	void initShape();
	void changeShape();
	void setShape(int i_type);
	void clearShape();
	void move(int i_direction);
};