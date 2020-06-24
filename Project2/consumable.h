#pragma once
#include "item.h"
class consumable :
    public item
{
public:
    consumable(string, int, int);
    void setAmount(int);
    int getAmount();
    void setAmountRestored(int);
    int getAmountRestored();
private:
    int itemAmount;
    int itemAmountRestored;

};

