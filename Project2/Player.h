#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class player
{
public:
    
    player(string, int, int);
    void setName(string);
    string getName();
    void setRace(string);
    string getRace();
    void setClass(string);
    string getClass();
    void setLevel(int);
    void setEXP(int);
    void setHealth(int);
    void setMaxHealth(int);
    void setSpeed(int);
    int getSpeed();
    void setStrength(int);
    int getStrength();
    void setMaxStamina(int);
    int getMaxStamina();
    void setStamina(int);
    int getStamina();
    void setMaxMana(int);
    int getMaxMana();
    void setMana(int);
    int getMana();
    void setAtributes();
    void playerCreator();
    void setDamage();
    int getLevel();
    int getHealth();
    int getMaxHealth();
    int getDamage();
    int getEXP();
    int getEXPReq();
    void setEXPReq();
    void setGold(int);
    int getGold();
    void playerStatus();
    void playerOrigin();
    void duel();
    void book();
    void nothing();
    void setClassAbilities(int);
    int getClassAbilities();
    void setRaceAbilities(int);
    int getRaceAbilities();
    void useAbilities(int);
    void setAbilityDamage(int);
    int getAbilityDamage();
    void HumanAbility();
    void ElfAbility();
    void OrcAbility();
    void WarriorAbility1();
    void WarriorAbility2();
    void WarriorAbility3();
    void WizardAbility1();
    void WizardAbility2();
    void WizardAbility3();
    void RogueAbility1();
    void RogueAbility2();
    void RogueAbility3();
    int power_strike=0;
    
private:
    string playerName;
    string playerRace;
    string playerClass;
    int playerLevel;
    int playerHealth;
    int playerMaxHealth;
    int playerSpeed=1;
    int playerStrength=1;
    int playerMaxStamina;
    int playerStamina;
    int playerMaxMana=10;
    int playerMana;
    int playerDamage;
    int playerEXP;
    int playerEXPReq;
    int playerGold = 0;
    int playerClassAbilities;
    int playerRaceAbilities;
    int playerAbilityDamage;
 
};