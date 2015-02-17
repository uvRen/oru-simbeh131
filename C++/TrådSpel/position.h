#pragma once
class position
{
private:
	int x;
	int y;
	int id;
public:

	position() : x(0), y(0), id(-1){ }

	position(int id, int x, int y)
	{
		this->id = id;
		this->x = x;
		this->y = y;
	}

	~position()
	{
	}

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_id(){ return id; }
};