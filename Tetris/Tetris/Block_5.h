#include "Block.h"
#pragma once
class System;
//0 : 0
//    0
//    00 

//1 : 000
//    0

//2 : 00
//     0
//     0

//3 :   0
//    000
class Block_5 : public Block
{
public:
	Block_5();
	void initShape();
	void changeShape();
	void setShape(int i_type);
	void clearShape();
	void move(int i_direction);
};