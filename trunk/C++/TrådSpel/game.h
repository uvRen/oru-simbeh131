#pragma once
#include <conio.h>
#include <deque>
#include <thread>
#include <mutex>
#include <chrono>
#include <array>
#include "position.h"
#include "player.h"

using namespace std;

mutex mutex_pos;
array<mutex, 2> mutex_keyboard;

class game
{
private:
	deque<position> q_pos;
	array<deque<char>, 2> keys;
	array<position, 2> pos;
public:

	game()
	{
	}

	~game()
	{
	}

	void draw()
	{
		system("cls");
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				char c = '-';
				for (int k = 0; k < pos.size(); k++)
				{
					if (pos[k].get_x() == i && pos[k].get_y() == j)
					{
						c = 48 + pos[k].get_id();
						break;
					}
				}
				cout << c;
			}
			cout << endl;
		}
	}

	void operator()()
	{
		char p1_binds[] = { 'w', 'a', 's', 'd' };
		player p1(0, 0, 0, p1_binds, &keys[0], &q_pos);
		pos[0] = position(0, 0, 0);
		char p2_binds[] = { 'i', 'j', 'k', 'l' };
		player p2(1, 5, 5, p2_binds, &keys[1], &q_pos);
		pos[1] = position(1, 5, 5);
		thread t1(p1);
		thread t2(p2);
		draw();

		while (true)
		{
			bool changed = false;
			mutex_pos.lock();
			while (q_pos.size() > 0)
			{
				position p = q_pos.front();
				q_pos.pop_front();
				pos[p.get_id()] = p;
				changed = true;
			}
			mutex_pos.unlock();
			if (changed)
				draw();

			if (_kbhit())
			{
				char c = _getch();
				if (c == 'w' || c == 'a' || c == 's' || c == 'd')
				{
					mutex_keyboard[0].lock();
					keys[0].push_back(c);
					mutex_keyboard[0].unlock();
				}
				else if (c == 'i' || c == 'j' || c == 'k' || c == 'l')
				{
					mutex_keyboard[1].lock();
					keys[1].push_back(c);
					mutex_keyboard[1].unlock();
				}
			}
			this_thread::sleep_for(chrono::milliseconds(5));
		}
	}
};
