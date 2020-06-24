#include <string>
#include "Enemy.h"


enemy::enemy(string name, int lvl)
{
    setName(name);
    setLevel(lvl);
    setDifficulty();
    setDamage();
    setMaxHealth();
    setHealth(mobMaxHealth);
    setEXP();
	setSpeed();
}

void enemy::setName(string name)
{
    mobName = name;
}

void enemy::setLevel(int level)
{
    mobLevel = level;
}

void enemy::setDifficulty()
{
    int x, y;
	int difficulty;
	x = rand() % 100 + 1;
	if (x <= 60)
	{
		y = 1;
	}
	else
	{
		if (x <= 90)
		{
			y = 2;
		}
		else
		{
			y = 3;
		}
	}
	switch (y)
	{
	case 1:
		difficulty = 1;
		break;
	case 2:
		difficulty = 2;
		break;
	default:
		difficulty = 3;
		break;
	
	}
	mobDifficulty = difficulty;
}

void enemy::setDamage()
{
    mobDamage = 1;
}

void enemy::setHealth(double health)
{
	if (health < 0)
	{
		health = 0;
	}
    mobHealth = health;
}

void enemy::setMaxHealth()
{
    mobMaxHealth = 10*getLevel()*getDifficulty();
}

string enemy::getName()
{
    return mobName;
}

int enemy::getLevel()
{
    return mobLevel;
}

int enemy::getDifficulty()
{
    return mobDifficulty;
}

int enemy::getDamage()
{
    return mobDamage;
}

double enemy::getHealth()
{
    return mobHealth;
}
double enemy::getMaxHealth()
{
    return mobMaxHealth;
}

int enemy::getEXP()
{
    return EXP;
}

void enemy::setEXP()
{
    EXP = (getLevel() * 35);
}

void enemy::setSpeed()
{
	mobSpeed = (rand() % 3 + mobLevel) + mobDifficulty;
}
int enemy::getSpeed()
{
	return mobSpeed;
}