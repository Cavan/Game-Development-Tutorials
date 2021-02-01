#pragma once
/*
Original source: https://github.com/OneLoneCoder/videos/blob/master/OneLoneCoder_RetroArcadeRacer.cpp


Background
~~~~~~~~~~
I'm a sim-racer when I'm not coding. Racing games are far more sophisticated than
they used to be. Frankly, retro racing games are a bit naff. But when done in the
command prompt they have a new level of craziness.
Controls
~~~~~~~~
Left Arrow/Right Arrow Steer, Up Arrow accelerates. There are no brakes!
Set the fastest lap times you can!

Author
~~~~~~
Twitter: @javidx9
Blog: www.onelonecoder.com
Video:
~~~~~~
https://youtu.be/KkMZI5Jbf18
Last Updated: 10/07/2017

*/

#include <iostream>
#include <string>

#include "olcConsoleGameEngine.h"

using namespace std;

class FormulaOLC : olcConsoleGameEngine
{
public:
	FormulaOLC()
	{
		m_sAppName = L"Formula OLC";
	}

private:

		float fDistance = 0.0f;			// distance car has traveled around track
		float fCurvature = 0.0f;		// Current track curvature, lerped between track sections
		float fTrackCurvature = 0.0f;	// Accumulation of track curvature
		float fTrackDistance = 0.0f;	// Total distance of track

		float fCarPos = 0.0f;			// Current car position
		float fPlayerCurvature = 0.0f;	// Accumulation of player curvature
		float fSpeed = 0.0f;			// Current player speed

		vector<pair<float, float>> vecTrack; // Track sections, sharpness of bend, length of section

		list<float> listLapTimes;			// List of previous lap times
		float fCurrentLapTime;				// Current lap time


protected:
		// Called by olcConsoleGameEngine
		virtual bool OnUserCreate()
		{
			// Define track
			vecTrack.push_back(make_pair(0.0f, 10.0f));		// Short section for start/finish line
			vecTrack.push_back(make_pair(0.0f, 200.0f));
			vecTrack.push_back(make_pair(1.0f, 200.0f));
			vecTrack.push_back(make_pair(0.0f, 400.0f));
			vecTrack.push_back(make_pair(-1.0f, 100.0f));
			vecTrack.push_back(make_pair(0.0f, 200.0f));
			vecTrack.push_back(make_pair(-1.0f, 200.0f));
			vecTrack.push_back(make_pair(1.0f, 200.0f));
			vecTrack.push_back(make_pair(0.0f, 200.0f));
			vecTrack.push_back(make_pair(0.2f, 500.0f));
			vecTrack.push_back(make_pair(0.0f, 200.0f));

			// Calculate total track distance, so we can set lap times
			for (auto t : vecTrack)
				fTrackDistance += t.second;

			listLapTimes = { 0,0,0,0,0 };
			fCurrentLapTime = 0.0f;

			return true;
		}


		// Called by olcConsoleGameEngine
		virtual bool OnUserUpdate(float fElapsedTime)
		{
			// Handle control input
			int nCarDirection = 0;


		}
};