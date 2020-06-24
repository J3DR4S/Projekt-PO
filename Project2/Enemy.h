#include <string>

using namespace std;

class enemy
{
public:
    enemy(string, int); 
    void setName(string);
    void setLevel(int);
    void setDamage();
    void setHealth(double);
    void setMaxHealth();
    void setDifficulty();
    void setSpeed();
    int getSpeed();
    string getName();
    int getLevel();
    int getDamage();
    double getHealth();
    double getMaxHealth();
    int getDifficulty();
    int getEXP();
    void setEXP();
private:
    string mobName;
    int mobLevel;
    int mobDamage;
    double mobHealth;
    double mobMaxHealth;
    int mobDifficulty;
    int mobSpeed;
    int EXP;
};