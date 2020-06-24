#include "location.h"

location::location(int level)
{
		setLevel(level);
		setNumber();
		setName(getLevel() / 5, getNumber());
		setDescription(getLevel() / 5, getNumber());
	
}

void location::setLevel(int level)
{
	locationLevel = level;
}
int location::getLevel()
{
	return locationLevel;
}

void location::setNumber()
{
	locationNumber = rand()%3;
}
int location::getNumber()
{
	return locationNumber;
}

void location::setName(int level, int number)
{
	locationName = locationNames[level][number];
}
string location::getName()
{
	return locationName;
}

void location::setDescription(int level, int number)
{
	locationDescription = locationDescriptions[level][number];
}
string location::getDescription()
{
	return locationDescription;
}