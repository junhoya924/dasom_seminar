#pragma once
class System;

class Block
{
protected:
	int x;
	int y;
	int type; //0 1 2 3 
	bool gameOver;
	bool finish; //�� �ٴ� ���޽� true
public:
	Block() { }
	//int getX() { return x; }
	//int getY() { return y; }
	//void setX(int i_x) { x = i_x; }
	//void setY(int i_y) { y = i_y; }
	bool checkGameOver() { return gameOver; }
	bool checkFinish() { return finish; }
	virtual void initShape() = 0;//���� �����ɼ� ������ true �ƴϸ� false
	virtual void changeShape() = 0; //��� �ٲ�
	virtual void setShape(int i_type) = 0; //�ٲ� ����� map�� ����
	virtual void clearShape() = 0; //���� ��� ����
	virtual void move(int i_direction) = 0; // 0 ���� 1 ������ 2 �Ʒ� 3�����ϰ�
};