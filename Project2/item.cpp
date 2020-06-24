#include "item.h"

item::item(string name, int level, int value)
{
	setName(name);
	setLevel(level);
	setValue(value);
}

void item::setName(string name)
{
	itemName = name;
}
string item::getName()
{
	return itemName;
}

void item::setLevel(int level)
{
	itemLevel = level;
}
int item::getLevel()
{
	return itemLevel;
}

void item::setValue(int value)
{
	itemValue = value;
}
int item::getValue()
{
	return itemValue;
}