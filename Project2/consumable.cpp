#include "consumable.h"

consumable::consumable(string name, int amount, int value)
{
	setName(name);
	setAmount(amount);
	setValue(value);

}

void consumable::setAmount(int amount)
{
	itemAmount = amount;
}
int consumable::getAmount()
{
	return itemAmount;
}

void consumable::setAmountRestored(int amount)
{
	itemAmountRestored = amount;
}
int consumable::getAmountRestored()
{
	return itemAmountRestored;
}