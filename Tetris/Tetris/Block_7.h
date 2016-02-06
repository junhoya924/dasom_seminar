#include "Block.h"
#pragma once

class System;
//0 : 0
//    00
//    0 

//1 :  0
//    000

//2 :  0
//    00
//     0

//3 : 000
//     0
class Block_7 : public Block
{
public:
	Block_7();
	void initShape();
	void changeShape();
	void setShape(int i_type);
	void clearShape();
	void move(int i_direction);
};