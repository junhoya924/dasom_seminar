#pragma once
class System;

class Block
{
protected:
	int x;
	int y;
	int type; //0 1 2 3 
	bool gameOver;
	bool finish; //블럭 바닥 도달시 true
public:
	Block() { }
	//int getX() { return x; }
	//int getY() { return y; }
	//void setX(int i_x) { x = i_x; }
	//void setY(int i_y) { y = i_y; }
	bool checkGameOver() { return gameOver; }
	bool checkFinish() { return finish; }
	virtual void initShape() = 0;//블럭이 생성될수 있으면 true 아니면 false
	virtual void changeShape() = 0; //모양 바꿈
	virtual void setShape(int i_type) = 0; //바뀐 모양이 map에 적용
	virtual void clearShape() = 0; //기존 모양 삭제
	virtual void move(int i_direction) = 0; // 0 왼쪽 1 오른쪽 2 아래 3수직하강
};