#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Player.h"
#include "consumable.h"
#include <vector>
#include <algorithm>
#include <limits>
#include "location.h"


using namespace std;

player battle(player account);
player calcEXP(player account, enemy monster);
player levelUp(player account);
player duel(player account);
player explore(player account);
player inventory(player account, int battle);
player shop(player account);
void death();
item axe("Axe", 0, 0);
item dagger("Dagger", 0, 0);
item wand("Wand", 0, 0);
item HpRing("Health Ring", 0, 0);
item StaminaRing("Stamina Ring", 0, 0);
item ManaRing("Mana Ring", 0, 0);
consumable HpPotion("Health Potion", 3, 150);
consumable StaminaPotion("Stamina Potion", 1, 150);
consumable ManaPotion("Mana Potion", 1, 150);
consumable Campfire("Campfire", 0, 400);

int main()
{
    srand(time(NULL));
    string name;
    int option1;
    cout << "Welcome, please enter your name\n";
    getline(cin, name);
    player account(name, 1, 0);
    account.playerStatus();
    system("CLS");
    location level(account.getLevel());
    cout << "You open your eyes. The only thing that you remember is your name: \"" << account.getName();
    cout << "\"." << endl << "You don't know how you ended up here," << endl << "but after a moment of looking around you come to a conclusion that you are in a " << level.getName() << "." << endl;
    cout << level.getDescription();
    int choice;
    int first_location = 0;
    while (account.getHealth()>0)
    { 
      
        cout << endl;
        system("PAUSE");
        system("CLS");
        cout << " ___________________________________________" << endl;
        cout << "|__________What do you want to do?__________|" << endl;
        cout << ">1. Explore" << endl;
        cout << ">2. Character screen" << endl;
        cout << ">3. Inventory" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            account = explore(account);
            cout << endl;
            
            system("CLS");
            level.setLevel(account.getLevel());
            level.setNumber();
            level.setName(level.getLevel() / 5, level.getNumber());
            level.setDescription(level.getLevel() / 5, level.getNumber());
            cout << "You approach a " << level.getName() << "." << endl;
            cout << level.getDescription() << endl;
            break;
        case 2:
            account.playerStatus();
            
            break;
        case 3:
           account = inventory(account, 0);
           

        default:
            
            break;
        }
    }
    return 0;

}




player battle(player account)
{
    int gold_before;
    int mana_before;
    int player_health_before;
    int monster_health_before;
    int walka = 1;
    string option;
    string monster_names[4][3] = { {"stray dog","huge rat","venomous snake"},{"goblin","gnoll","wolf"},{"bandit","lizardman","scavenger"},{"necromancer","black knight","skeleton king"} };
    Sleep(20);
    enemy monster(monster_names[account.getLevel()/5][rand() % 3], account.getLevel() + (rand() % 3)); //COS TU NIE DZIALA ZMIENIC [3-1]
    system("CLS");
    if (account.getSpeed() < monster.getSpeed())
    {
        int surprise_damage = (monster.getDamage() + rand() % 5);
        account.setHealth(account.getHealth() - surprise_damage);
        cout << "Suddenly you notice something lurking in the shadows... You pull out your weapon but you are to slow! The enemy attacks dealing "<< surprise_damage << " damage."  << endl;
        if (account.getHealth() <= 0)
        {
            death;
        }
        cout << "Only now can you see a " <<monster.getName() << " standing in front of you." << endl;
        cout << endl;
        system("PAUSE");
        
    }
    else
    {
        cout << "You continue exploring while suddenly you see a creature standing in the distance." << endl << "You can't be sure what you're looking at so you approach it carefully. " << endl;
        cout << endl;
        system("PAUSE");
        
    }
    while (walka)
    {
        int warunek = 1;
        while (warunek)
        {
            system("CLS");
            cout << " ";
            int size = (monster.getName()).size();
            for (int i = 0; i<=size+19; i++)
            {
                cout << "_";
            }
            cout << endl;
            cout << "|__________"<< monster.getName() <<"__________|" << endl;
            cout << "|Level: " << monster.getLevel() << endl;
            cout << "|Difficulty: " << monster.getDifficulty() << endl;
            cout << "|Health <";
            for (int i = 0; i < (monster.getHealth()); i++)
            {
                cout << "#";
            }
            for (int i = 0; i < ((monster.getMaxHealth() - monster.getHealth())); i++)
            {
                cout << " ";
            }
            cout << ">" << endl;
            
            cout << endl;
            cout << " ";
            int size2 = (account.getName()).size();
            for (int i = 0; i <= size2 + 19; i++)
            {
                cout << "_";
            }
            cout << endl;
            cout << "|__________" << account.getName() << "__________|" << endl;
            cout << "|Health: " << account.getHealth() << "/" << account.getMaxHealth() << endl;
            cout << "|Stamina: " << account.getStamina() << "/" << account.getMaxStamina() << endl;
            cout << "|Mana: " << account.getMana() << "/" << account.getMaxMana() << endl;
            cout << endl;
            cout << "What do you want to do?" << endl;
            cout << ">1. Attack" << endl;
            cout << ">2. Use Ability" << endl;
            cout << ">3. Inventory" << endl;
            cout << ">4. Rest" << endl;
            cout << ">5. Escape" << endl;
            int akcja;
            cin >> akcja;
            switch (akcja)
            {
            case 1:
                if (account.getStamina() >= 5)
                {
                    int attack_damage = ((account.getLevel() * (rand() % 5 + 1)) + (account.getLevel() * account.getStrength()));
                    monster.setHealth(monster.getHealth() - attack_damage);
                    account.setStamina(account.getStamina() - 5);
                    warunek = 0;
                    cout << "You deal " << attack_damage << " damage!" << endl;
                }
                else
                {
                    cout << "You don't have enough energy." << endl;
                    system("PAUSE");
                }
                break;
            case 2:
                system("CLS");
                player_health_before = account.getHealth();
                mana_before = account.getMana();
                account.useAbilities(1);
                monster_health_before = monster.getHealth();
                monster.setHealth(monster.getHealth() - account.getAbilityDamage());
                if (account.getMana() < mana_before)
                {
                    if (account.getAbilityDamage() > 0)
                    {
                        cout << "You have dealt " << monster_health_before - monster.getHealth() << " damage with your ability." << endl;
                    }
                    if (account.getHealth() > player_health_before)
                    {
                        cout << "You have healed yourself by " << account.getHealth() - player_health_before << " with your ability." << endl;
                    }
                    warunek = 0;
                } 
                break;
            case 3:
                account = inventory(account, 1);
                warunek = 1;
                break;
            case 4:
                account.setStamina(account.getStamina()+account.getMaxStamina() / 2+5);
                warunek = 0;
                break;
            case 5:
                int szansa;
                szansa = rand() % 100 + 1;
                if (account.getSpeed() > monster.getSpeed())
                {
                    if (szansa <= 75)
                    {
                        cout << "You have managed to run away" << endl;
                        walka = 0;
                    }
                    else
                    {
                        cout << "You failed to escape. You lose a turn." << endl;
                    }
                }
                else
                {
                    if (szansa <= 25)
                    {
                        walka = 0;
                    }
                    else
                    {
                        cout << "You failed to escape. You lose a turn." << endl;
                    }
                }
                warunek = 0;

                break;
            default:
                cout << "Choose a correct option.";
                break;
            }


        }
        if (walka)
        {

            if (monster.getHealth() <= 0)
            {
                Sleep(1500);
                system("CLS");
                cout << "You have defeated your enemy." << endl;
                account = calcEXP(account, monster);
                gold_before = account.getGold();
                account.setGold(account.getGold()+(monster.getLevel() + (monster.getDifficulty())) * (rand() % 20 + 1));
                cout << "You got " << account.getGold() - gold_before << " gold" << endl;
                walka = 0;

                
            }
            else
            {
                int monster_damage = (monster.getDamage() + (monster.getLevel() * (rand() % 5 + 1)));
                account.setHealth(account.getHealth() - monster_damage);
                cout << "The enemy deals " << monster_damage << " damage." << endl;
                if (account.getHealth() <= 0)
                {
                    death;
                }
                
            }

        }
        
        system("PAUSE");
    }
return account;
} 

void death()
{
    cout << "You died.";
}

player calcEXP(player account, enemy monster)
{
    for (int i = 0; i <= 10; i++)
    {
        cout << "#";
        Sleep(50);
    }  
    char calculating[] = "Calculating EXP";
    for (int i = 0; i <= 15; i++)
    {
        cout << calculating[i];
        Sleep(50);
    }
   
    for (int i = 0; i <= 10; i++)
    {
        cout << "#";
        Sleep(50);
    }
  
    account.setEXP(account.getEXP() + monster.getEXP());
    cout << endl;
    cout << "EXP: " << account.getEXP() << "/" << account.getEXPReq() << "\n";
    if (account.getEXP() >= account.getEXPReq())
    {
        account = levelUp(account);
    }
    return account;
}

player levelUp(player account)
{
    account.setLevel(account.getLevel() + 1);
    int EXP_left = (account.getEXP() - account.getEXPReq());
    account.setEXPReq();
    account.setEXP(EXP_left);
    account.setMaxHealth(HpRing.getLevel());
    account.setHealth(account.getMaxHealth());
    account.setMaxStamina(StaminaRing.getLevel());
    account.setStamina(account.getMaxStamina());
    cout << "Level up! you are now level: " << account.getLevel() << "!\n";
    cout << "Choose a stat you want to increase: " << endl;
    cout << "1.Strength" << endl << "2.Speed" << endl << "3.Mana" << endl;
    int x;
    bool error;
    cin >> x;
    do {
        error = 0;
        switch (x)
        {
        case 1:
            account.setStrength(account.getStrength()+1);
            break;
        case 2:
            account.setSpeed(account.getSpeed()+1);
            break;
        case 3:
            account.setMaxMana(account.getMaxMana()+10);
            break;
        default:
            cout << "Choose a correct option." << endl;
            error = 1;
            break;
        }
    } while (error);
    account.setMana(account.getMaxMana());
    if (account.getLevel() == 5 || account.getLevel() == 10 || account.getLevel() == 15)
    {
        Sleep(500);
        cout << endl;
        cout << "With reaching level " << account.getLevel() << " you also unlock a new class ability!" << endl;
    }
    return account;
}

player explore(player account)
{
    int rand_event;
    int random = rand() % 100 + 1;
    
    if (random <= 50)
    {
        rand_event = 1;
    }
    else if(random<=70)
    {
        rand_event = 3;
    }
    else if (random <= 80)
    {
        rand_event = 2;
    }
    else if (random <= 80)
    {
        rand_event = 4;
    }
    else
    {
        rand_event = 5;
    }
    
    
    
    switch (rand_event)
    {
    case 1:
        account = battle(account);
        break;
    case 2:
        account.duel();
        system("PAUSE");
        break;
    case 3:
        account = shop(account);
        system("PAUSE");
        break;
    case 4:
        account.book();
        break;
    case 5:
        account.nothing();
        break;
        
    }
    return account;
}

player inventory(player account, int battle)
{
    system("CLS");
    cout << " _________________________________________________" << endl;
    cout << "|____________________Inventory____________________|" << endl;
    cout << "|_____Gold: " << account.getGold() << "_____|"<< endl;
    cout << "|||||||||| Equipped Gear ||||||||||" << endl;
    cout << "Weapon:" << endl;
    if (axe.getLevel() > 0)
    {
        cout << axe.getName() << " +" << axe.getLevel() << endl;
    }
    if (dagger.getLevel() > 0)
    {
        cout << dagger.getName() << " +" << dagger.getLevel() << endl;
    }
    if (wand.getLevel() > 0)
    {
        cout << wand.getName() << " +" << wand.getLevel() << endl;
    }
    cout << "Ring:" << endl;
    if (HpRing.getLevel() > 0)
    {
        cout << HpRing.getName() << " +" << HpRing.getLevel() << endl;
    }
    if (StaminaRing.getLevel() > 0)
    {
        cout << StaminaRing.getName() << " +" << StaminaRing.getLevel() << endl;
    }
    if (ManaRing.getLevel() > 0)
    {
        cout << ManaRing.getName() << " +" << ManaRing.getLevel() << endl;
    }
    cout << "|||||||||| Consumable ||||||||||" << endl;
    if (HpPotion.getAmount() > 0)
    {
        cout << HpPotion.getName() << ": " << HpPotion.getAmount() << endl;
    }
    if (StaminaPotion.getAmount() > 0)
    {
        cout << StaminaPotion.getName() << ": " << StaminaPotion.getAmount() << endl;
    }
    if (ManaPotion.getAmount() > 0)
    {
        cout << ManaPotion.getName() << ": " << ManaPotion.getAmount() << endl;
    }
    if (Campfire.getAmount() > 0)
    {
        cout << Campfire.getName() << ": " << Campfire.getAmount() << endl;
    }
    int itemUse;
    string choice;
    cout << endl << "Do you want to use an item? (Y/N)" << endl;
    bool error;
    int itemUse2;
    bool error2;

    do {
        cin.ignore();
        cin.clear();
        getline(cin, choice);
        for_each(choice.begin(), choice.end(), [](char& wybor1)
            {
                wybor1 = ::tolower(wybor1);
            });
        if (choice == "y" || choice == "yes")
        {
            itemUse = 1;
        }
        else
        {
            if (choice == "n" || choice == "no")
            {
                itemUse = 2;
            }
            else
            {
                itemUse = 0;
            }
        }
        error = 0;
        string choice2;

        switch (itemUse)
        {
        case 1:

            cout << "Which item do you want to use? (type Q if you want to quit)" << endl;
            cin.clear();
            do {
                error2 = 0;

                getline(cin, choice2);
                for_each(choice2.begin(), choice2.end(), [](char& wybor2)
                    {
                        wybor2 = ::tolower(wybor2);
                    });
                if (choice2 == "health potion" || choice2 == "hp")
                {
                    itemUse2 = 1;
                }
                else
                {
                    if (choice2 == "stamina potion" || choice2 == "sp")
                    {
                        itemUse2 = 2;
                    }
                    else
                    {
                        if (choice2 == "mana potion" || choice2 == "mp")
                        {
                            itemUse2 = 3;
                        }
                        else
                        {
                            if (choice2 == "campfire" || choice2 == "cf")
                            {
                                itemUse2 = 4;
                            }
                            else
                            {
                                if (choice2 == "q" || choice2 == "quit")
                                {
                                    itemUse2 = 5;

                                }
                                else
                                {
                                    cout << "Choose a correct option." << endl;
                                    error2 = 1;
                                }


                            }
                        }
                    }
                }

            } while (error2);
            switch (itemUse2)
            {
            case 1:
                if (HpPotion.getAmount() > 0)
                {
                    HpPotion.setAmountRestored((account.getMaxHealth() / 2) + 50);
                    HpPotion.setAmount(HpPotion.getAmount() - 1);
                    int health_before = account.getHealth();
                    account.setHealth(account.getHealth() + HpPotion.getAmountRestored());
                    if (account.getHealth() >= account.getMaxHealth())
                    {
                        account.setHealth(account.getMaxHealth());
                    }
                    cout << "You have restored " << account.getHealth() - health_before << " health." << endl;
                }
                else
                {
                    cout << "You don't have a health potion." << endl;
                }
                break;
            case 2:
                if (StaminaPotion.getAmount() > 0)
                {
                    StaminaPotion.setAmountRestored(account.getMaxStamina());
                    StaminaPotion.setAmount(StaminaPotion.getAmount() - 1);
                    int stamina_before = account.getStamina();
                    account.setStamina(account.getStamina() + StaminaPotion.getAmountRestored());
                    if (account.getStamina() >= account.getMaxStamina())
                    {
                        account.setStamina(account.getMaxStamina());
                    }
                    cout << "You have restored " << account.getStamina() - stamina_before << " stamina." << endl;
                }
                else
                {
                    cout << "You don't have a stamina potion." << endl;
                }
                break;
            case 3:
                if (ManaPotion.getAmount() > 0)
                {
                    ManaPotion.setAmountRestored((account.getMaxMana() / 2) + 5);
                    ManaPotion.setAmount(ManaPotion.getAmount() - 1);
                    int mana_before = account.getMana();
                    account.setMana(account.getMana() + ManaPotion.getAmountRestored());
                    if (account.getMana() >= account.getMaxMana())
                    {
                        account.setMana(account.getMaxMana());
                    }
                    cout << "You have restored " << account.getMana() - mana_before << " mana." << endl;
                }
                else
                {
                    cout << "You don't have a mana potion." << endl;
                }
                break;
            case 4:
                if (battle == 0)
                {
                    if (Campfire.getAmount() > 0)
                    {

                        Campfire.setAmount(Campfire.getAmount() - 1);
                        account.setHealth(account.getMaxHealth());
                        account.setStamina(account.getMaxStamina());
                        account.setMana(account.getMaxMana());
                        cout << "You are fully rested." << endl;
                    }
                    else
                    {
                        cout << "You don't have a campfire." << endl;
                    }

                    
                }
                else if (battle ==1)
                {
                    cout << "You can't use a campfire in a battle." << endl;  
                }
                break;
            case 5:
                break;
                


            }
        case 2:
            break;
        default:
            cout << "Choose a correct option." << endl;
            error = 1;
            break;
        }

    }
    while (error);
    
    return account;
}

player shop(player account)
{
    int axe_level = axe.getLevel() + (rand() % 2 + 1);
    int dagger_level = dagger.getLevel() + (rand() % 2 + 1);
    int wand_level = wand.getLevel() + (rand() % 2 + 1);
    int HpRing_level = HpRing.getLevel() + (rand() % 2 + 1);
    int StaminaRing_level = StaminaRing.getLevel() + (rand() % 2 + 1);
    int ManaRing_level = ManaRing.getLevel() + (rand() % 2 + 1);
    int axe_check, dagger_check, wand_check, hpring_check, spring_check, mpring_check, hppotion_check, sppotion_check, mppotion_check, campfire_check;
    cout << "You see a character in the distance. You approach it as it looks friendlier than anything you saw in a long time." << endl;
    Sleep(500);
    cout << "When you get closer you see a strange looking man leading a donkey that is carrying a lot of items." << endl;
    Sleep(500);
    cout << "\"Welcome stranger! I'm a travelling merchant. Can I help you?\"" << endl;
    Sleep(500);
    cout << "You have no idea how this man ended up here but something in your gut tells you to take a look at his supplies." << endl;
    cout << endl;
    Sleep(500);
    system("PAUSE"); 
 
    system("CLS");
    cout << " ____________________________________________" << endl;
    cout << "|____________________Shop____________________|" << endl;
    cout << "|_____Gold: " << account.getGold() << "_____|" << endl;
    cout << "|||||||||| Gear ||||||||||" << endl;
    cout << "Weapons:" << endl;
    if (axe_check=rand() % 2 == 1)
    {
        
        cout << axe.getName() << " +" << axe_level << " -----> " << axe_level * axe_level * 100 << " gold" << endl;
    }
    if (dagger_check=rand() % 2 == 1)
    {
        
        cout << dagger.getName() << " +" << dagger_level << " -----> " << dagger_level * dagger_level * 100 << " gold" << endl;
    }
    if (wand_check=rand() % 2 == 1)
    {
        
        cout << wand.getName() << " +" << wand_level << " -----> " << wand_level * wand_level * 100 << " gold" << endl;
    }
    cout << "Rings:" << endl;
    if (hpring_check=rand() % 2 == 1)
    {
        
        cout << HpRing.getName() << " +" << HpRing_level << " -----> " << HpRing_level * HpRing_level * 100 << " gold" << endl;
    }
    if (spring_check=rand() % 2 == 1)
    {
        
        cout << StaminaRing.getName() << " +" << StaminaRing_level << " -----> " << StaminaRing_level * StaminaRing_level * 100 << " gold" << endl;
    }
    if (mpring_check=rand() % 2 == 1)
    {
        
        cout << ManaRing.getName() << " +" << ManaRing_level << " -----> " << ManaRing_level * ManaRing_level * 100 << " gold" << endl;
    }
    cout << "|||||||||| Consumable ||||||||||" << endl;
    if (hppotion_check=rand() % 2 == 1)
    {
        
        cout << HpPotion.getName() << " -----> " << HpPotion.getValue() << " gold" << endl;
    }
    if (sppotion_check=rand() % 2 == 1)
    {
        
        cout << StaminaPotion.getName() << " -----> " << StaminaPotion.getValue() << " gold" << endl;
    }
    if (mppotion_check=rand() % 2 == 1)
    {
        
        cout << ManaPotion.getName() << " -----> " << ManaPotion.getValue() << " gold" << endl;
    }
    if (campfire_check=rand() % 2 == 1)
    {
        
        cout << Campfire.getName() << " -----> " << Campfire.getValue() << " gold" << endl;
    }
    cout << endl;
    cout << "Do you want to buy anything? (Y/N)" << endl;
    string choice;
    int itemBuy;
    bool error;
    int itemBuy2;
    bool error2;
    string choice3;
    int error3;
    int itemBuy3;
    
    cin.ignore();
    do {
        
        getline(cin, choice);
        for_each(choice.begin(), choice.end(), [](char& wybor1)
            {
                wybor1 = ::tolower(wybor1);
            });
        if (choice == "y" || choice == "yes")
        {
            itemBuy = 1;
        }
        else
        {
            if (choice == "n" || choice == "no")
            {
                itemBuy = 2;
            }
            else
            {
                itemBuy = 0;
            }
        }
        error = 0;
        string choice2;
        
        switch (itemBuy)
        {
        case 1:
            do {
                cout << "Which item do you want to buy? (type Q if you want to quit)" << endl;
                cin.clear();
                do {
                    error2 = 0;

                    getline(cin, choice2);
                    for_each(choice2.begin(), choice2.end(), [](char& wybor2)
                        {
                            wybor2 = ::tolower(wybor2);
                        });
                    if (choice2 == "axe" && axe_check==1)
                    {
                        itemBuy2 = 1;
                    }
                    else
                    {
                        if (choice2 == "dagger" && dagger_check==1)
                        {
                            itemBuy2 = 2;
                        }
                        else
                        {
                            if (choice2 == "wand" && wand_check==1)
                            {
                                itemBuy2 = 3;
                            }
                            else
                            {
                                if ((choice2 == "health ring" || choice2 == "hp ring")&& hpring_check==1)
                                {
                                    itemBuy2 = 4;
                                }
                                else
                                {
                                    if ((choice2 == "stamina ring" || choice2 == "sp ring") && spring_check==1)
                                    {
                                        itemBuy2 = 5;

                                    }
                                    else
                                    {
                                        if ((choice2 == "mana ring" || choice2 == "mp ring")&& mpring_check==1)
                                        {
                                            itemBuy2 = 6;
                                        }
                                        else
                                        {
                                            if ((choice2 == "health potion" || choice2 == "hp potion")&& hppotion_check==1)
                                            {
                                                itemBuy2 = 7;

                                            }
                                            else
                                            {
                                                if ((choice2 == "stamina potion" || choice2 == "sp potion") && sppotion_check==1)
                                                {
                                                    itemBuy2 = 8;

                                                }
                                                else
                                                {
                                                    if ((choice2 == "mana potion" || choice2 == "mp potion")&& mppotion_check==1)
                                                    {
                                                        itemBuy2 = 9;

                                                    }
                                                    else
                                                    {
                                                        if ((choice2 == "campfire" || choice2 == "cf")&& campfire_check==1)
                                                        {
                                                            itemBuy2 = 10;
                                                        }
                                                        else
                                                        {
                                                            if (choice2 == "quit" || choice2 == "q")
                                                            {
                                                                itemBuy2 = 11;
                                                            }
                                                            else
                                                            {
                                                                cout << "Choose a correct option." << endl;
                                                                error2 = 1;
                                                            }
                                                        }
                                                       
                                               
                                                    }
                                                 }   
                                            }

                                        }
                                    }
                                }
                            }
                        }
                    }

                } while (error2);
                switch (itemBuy2)
                {
                case 1:
                    if (account.getGold() >= axe_level * axe_level * 100)
                    {
                        
                        if (axe_level > axe.getLevel())
                        {
                            axe.setLevel(axe_level);
                            account.setStrength(account.getStrength() + axe.getLevel());
                            account.setGold(account.getGold() - axe_level * axe_level * 100);
                        }
                        else
                        {
                            cout << "You have already bought this item!" << endl;
                        }
                    }
                    else 
                    {
                        cout << "You don't have enough gold!" << endl;
                    }
                    break;
                case 2:
                    if (account.getGold() >= dagger_level * dagger_level * 100)
                    {
                        
                        if (dagger_level > dagger.getLevel())
                        {
                            dagger.setLevel(dagger_level);
                            account.setSpeed(account.getSpeed() + dagger.getLevel());
                            account.setGold(account.getGold() - dagger_level * dagger_level * 100);
                        }
                        else
                        {
                            cout << "You have already bought this item!" << endl;
                        }
                    }
                    else
                    {
                        cout << "You don't have enough gold!" << endl;
                    }
                    break;
                case 3:
                    if (account.getGold() >= wand_level * wand_level * 100)
                    {
                        
                        if (wand_level > wand.getLevel())
                        {
                            wand.setLevel(wand_level);
                            account.setMana(account.getStrength() + (wand.getLevel()*10));
                            account.setGold(account.getGold() - wand_level * wand_level * 100);
                        }
                        else
                        {
                            cout << "You have already bought this item!" << endl;
                        }
                    }
                    else
                    {
                        cout << "You don't have enough gold!" << endl;
                    }
                    break;
                case 4:
                    if (account.getGold() >= HpRing_level * HpRing_level * 100)
                    {
                       
                        if (HpRing_level > HpRing.getLevel())
                        {
                            HpRing.setLevel(HpRing_level);
                            account.setMaxHealth(HpRing_level);
                            account.setGold(account.getGold() - HpRing_level * HpRing_level * 100);
                        }
                        else
                        {
                            cout << "You have already bought this item!" << endl;
                        }
                    }
                    else
                    {
                        cout << "You don't have enough gold!" << endl;
                    }
                    break;
                case 5:
                    if (account.getGold() >= StaminaRing_level * StaminaRing_level * 100)
                    {
                       
                        if (StaminaRing_level > StaminaRing.getLevel())
                        {
                            StaminaRing.setLevel(StaminaRing_level);
                            account.setMaxStamina(StaminaRing_level);
                            account.setGold(account.getGold() - StaminaRing_level * StaminaRing_level * 100);
                        }
                        else
                        {
                            cout << "You have already bought this item!" << endl;
                        }
                    }
                    else
                    {
                        cout << "You don't have enough gold!" << endl;
                    }
                    break;
                case 6:
                    if (account.getGold() >= ManaRing_level * ManaRing_level * 100)
                    {
                        
                        if (ManaRing_level > ManaRing.getLevel())
                        {
                            ManaRing.setLevel(ManaRing_level);
                            account.setMaxMana(account.getMaxMana() + (ManaRing.getLevel()*10));
                            account.setGold(account.getGold() - ManaRing_level * ManaRing_level * 100);
                        }
                        else
                        {
                            cout << "You have already bought this item!" << endl;
                        }
                    }
                    else
                    {
                        cout << "You don't have enough gold!" << endl;
                    }
                    break;
                case 7:
                    if (account.getGold() >= HpPotion.getValue())
                    {
                        HpPotion.setAmount(HpPotion.getAmount() + 1);
                        account.setGold(account.getGold() - HpPotion.getValue());
                         
                    }
                    else
                    {
                        cout << "You don't have enough gold!" << endl;
                    }
                    break;
                case 8:
                    if (account.getGold() >= StaminaPotion.getValue())
                    {
                        StaminaPotion.setAmount(StaminaPotion.getAmount() + 1);
                        account.setGold(account.getGold() - StaminaPotion.getValue());

                    }
                    else
                    {
                        cout << "You don't have enough gold!" << endl;
                    }
                    break;
                case 9:
                    if (account.getGold() >= ManaPotion.getValue())
                    {
                        ManaPotion.setAmount(ManaPotion.getAmount() + 1);
                        account.setGold(account.getGold() - ManaPotion.getValue());

                    }
                    else
                    {
                        cout << "You don't have enough gold!" << endl;
                    }
                    break;
                case 10:
                    if (account.getGold() >= Campfire.getValue())
                    {
                        Campfire.setAmount(Campfire.getAmount() + 1);
                        account.setGold(account.getGold() - Campfire.getValue());

                    }
                    else
                    {
                        cout << "You don't have enough gold!" << endl;
                    }
                    break;
                case 11:
                    break;
                }
                cout << "Gold left: " << account.getGold() << endl;
                cout << "Do you want to buy something else? (Y/N)" << endl;
                do {
                    
                    error3 = 0;
                    
                    getline(cin, choice3);
                    for_each(choice3.begin(), choice3.end(), [](char& wybor1)
                        {
                            wybor1 = ::tolower(wybor1);
                        });
                    if (choice3 == "y" || choice3 == "yes")
                    {
                        itemBuy3 = 1;
                    }
                    else
                    {
                        if (choice3 == "n" || choice3 == "no")
                        {
                            itemBuy3 = 0;
                        }
                        else
                        {
                            cout << "Choose a correct option." << endl;
                            error3 = 1;
                        }
                    }

                } while (error3);
            }while (itemBuy3);
            break;
        case 2:
            break;
        default:
            cout << "Choose a correct option." << endl;
            error = 1;
            break;
        }

    } while (error);

   

    return account;
}


  