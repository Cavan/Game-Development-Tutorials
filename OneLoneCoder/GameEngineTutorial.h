#include <iostream>
#include "olcConsoleGameEngine.h"



class Example : public olcConsoleGameEngine
{
public:
	Example()
	{

	}

	virtual bool OnUserCreate()
	{
		return true;
	}


	virtual bool OnUserUpdate(float fElapsedTime)
	{
		return true;
	}
};