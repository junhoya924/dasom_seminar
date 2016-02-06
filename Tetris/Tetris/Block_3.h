#include "Block.h"
#pragma once
class System;
//0 :  0
//    00
//    0 
//1 : 00
//     00
class Block_3 : public Block
{
public:
	Block_3();
	void initShape();
	void changeShape();
	void setShape(int i_type);
	void clearShape();
	void move(int i_direction);
};