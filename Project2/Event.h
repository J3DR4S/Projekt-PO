#pragma once
#include "Player.h"

using namespace std;


class event :
	public player
{
	
public:
	void book(player);
	event(int);
};
