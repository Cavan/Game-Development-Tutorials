#pragma once
/*
Video:
~~~~~~
https ://youtu.be/E7CxMHsYzSs
	Last Updated : 14 / 07 / 2017
	*/

#include <iostream>
#include "olcConsoleGameEngine.h"

	using namespace std;


class GameOfLIfe : public olcConsoleGameEngine
{
	public:
		GameOfLIfe()
		{
			m_sAppName = L"Game Of Life";
		}
private:
	int* m_output;
	int* m_state;



protected:
	// Called by olcConsoleGameEngine
	virtual bool OnUserCreate()
	{
		m_output = new int[ScreenWidth() * ScreenHeight()];
		m_state = new int[ScreenWidth() * ScreenHeight()];

		memset(m_output, 0, ScreenWidth() * ScreenHeight() * sizeof(int));
		memset(m_state, 0, ScreenWidth() * ScreenHeight() * sizeof(int));

		for (int i = 0; i < ScreenWidth() * ScreenHeight(); i++)
			m_state[i] = rand() % 2;

		auto set = [&](int x, int y, wstring s)
		{
			int p = 0;
			for (auto c : s)
			{
				m_state[y * ScreenWidth() + x + p] = c == L'#' ? 1 : 0;
				p++;
			}
		};

		// R-Pentomino
		/*
		set(80, 50, L"  ## ");
		set(80, 51, L" ##  ");
		set(80, 52, L"  #  ");
		// Gosper Glider Gun
		set(60, 45, L"........................#............");
		set(60, 46, L"......................#.#............");
		set(60, 47, L"............##......##............##.");
		set(60, 48, L"...........#...#....##............##.");
		set(60, 49, L"##........#.....#...##...............");
		set(60, 50, L"##........#...#.##....#.#............");
		set(60, 51, L"..........#.....#.......#............");
		set(60, 52, L"...........#...#.....................");
		set(60, 53, L"............##.......................");
		set(20, 50, L"########.#####...###......#######.#####");
		// Infinite Growth
		*/
		
		return true;
	}



	// Called by olcConsoleGameEngine
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		//this_thread::sleep_for(50ms);

		//if (!m_keys[VK_SPACE].bReleased)
		//	return true;

		auto cell = [&](int x, int y)
		{
			return m_output[y * ScreenWidth() + x];
		};

		// Store output state
		for (int i = 0; i < ScreenWidth() * ScreenHeight(); i++)
			m_output[i] = m_state[i];

		for (int x = 1; x < ScreenWidth() - 1; x++)
			for (int y = 1; y < ScreenHeight() - 1; y++)
			{
				// The secret of artificial life =================================================
				int nNeighbours = cell(x - 1, y - 1) + cell(x - 0, y - 1) + cell(x + 1, y - 1) +
					cell(x - 1, y + 0) + 0 + cell(x + 1, y + 0) +
					cell(x - 1, y + 1) + cell(x + 0, y + 1) + cell(x + 1, y + 1);

				if (cell(x, y) == 1)
					m_state[y * ScreenWidth() + x] = nNeighbours == 2 || nNeighbours == 3;
				else
					m_state[y * ScreenWidth() + x] = nNeighbours == 3;
				// ===============================================================================


				if (cell(x, y) == 1)
					Draw(x, y, PIXEL_SOLID, FG_WHITE);
				else
					Draw(x, y, PIXEL_SOLID, FG_BLACK);
			}

		return true;
	}
};
