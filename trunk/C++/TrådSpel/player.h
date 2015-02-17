#pragma once
#include <deque>
#include <mutex>
#include <chrono>
#include <array>
#include <thread>
#include "position.h"

using namespace std;

extern mutex mutex_pos;
extern array<mutex, 2> mutex_keyboard;

class player
{
private:
	int x;
	int y;
	int id;
	array<char, 4> keybinds;
	deque<char> *keys;
	deque<position> *q_pos;
public:

	player() : keys(nullptr), q_pos(nullptr)
	{
	}

	player(int id, int x, int y, char keybinds[], deque<char> *keys, deque<position> *q_pos)
	{
		this->id = id;
		this->x = x;
		this->y = y;
		for (int i = 0; i < 4; i++)
			this->keybinds[i] = keybinds[i];
		this->keys = keys;
		this->q_pos = q_pos;
	}

	~player()
	{
	}

	void move(char &c)
	{
		bool moved = false;
		if (c == keybinds[0] && x > 0)
		{
			x--;
			moved = true;
		}
		else if (c == keybinds[1] && y > 0)
		{
			y--;
			moved = true;
		}
		else if (c == keybinds[2] && x < 10)
		{
			x++;
			moved = true;
		}
		else if (c == keybinds[3] && y < 10)
		{
			y++;
			moved = true;
		}
		if (moved)
		{
			mutex_pos.lock();
			q_pos->push_back(position(id, x, y));
			mutex_pos.unlock();
		}
	}

	void operator()()
	{
		while (true)
		{
			mutex_keyboard[id].lock();
			while (keys->size() > 0)
			{
				char c = keys->front();
				keys->pop_front();
				move(c);
			}
			mutex_keyboard[id].unlock();
			this_thread::sleep_for(chrono::milliseconds(10));
		}
	}
};