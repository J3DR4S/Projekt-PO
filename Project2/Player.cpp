#include "Player.h"
#include <limits>

player::player(string name, int level = 1, int EXP = 0)
{
    setName(name);
    setLevel(level);
    setEXP(EXP);
    setMaxHealth(0);
    setHealth(playerMaxHealth);
    setDamage();
    setEXPReq();
	setAtributes();
	playerCreator();
	setMana(playerMaxMana);
	setMaxStamina(0);
	setStamina(playerMaxStamina);
}

void player::setName(string name)
{
    playerName = name;
}
string player::getName()
{
    return playerName;
}

void player::setRace(string race)
{
    playerRace = race;
}
string player::getRace()
{
    return playerRace;
}

void player::setClass(string Class)
{
    playerClass = Class;
}
string player::getClass()
{
    return playerClass;
}


void player::setLevel(int level)
{
    playerLevel = level;
}
int player::getLevel()
{
    return playerLevel;
}

void player::setHealth(int health)
{
	if (health > getMaxHealth())
	{
		health = getMaxHealth();
	}
    playerHealth = health;
}
void player::setMaxHealth(int HpRingLevel)
{
    playerMaxHealth = ((100 * getLevel())+(HpRingLevel*100));
}
int player::getHealth()
{
    return playerHealth;
}
int player::getMaxHealth()
{
    return playerMaxHealth;
}

void player::setSpeed(int speed)
{
    playerSpeed = speed;
}
int player::getSpeed()
{
    return playerSpeed;
}

void player::setStrength(int strength)
{
    playerStrength = strength;
}
int player::getStrength()
{
    return playerStrength;
}

void player::setMaxStamina(int StaminaRingLevel)
{
    playerMaxStamina = (5 * getLevel())+(StaminaRingLevel*5);
}
int player::getMaxStamina()
{
    return playerMaxStamina;
}
void player::setStamina(int stamina)
{
	if (stamina > getMaxStamina())
	{
		stamina = getMaxStamina();
	}
    playerStamina = stamina;
}
int player::getStamina()
{
    return playerStamina;
}

void player::setMaxMana(int MaxMana)
{
    playerMaxMana = MaxMana;
}
int player::getMaxMana()
{
    return playerMaxMana;
}
void player::setMana(int mana)
{
    playerMana = mana;
}
int player::getMana()
{
    return playerMana;
}


void player::setDamage()
{
    playerDamage = (30 * getLevel());
}
int player::getDamage()
{
    return playerDamage;
}

int player::getEXP()
{
    return playerEXP;
}
void player::setEXP(int EXP)
{
    playerEXP = EXP;
}
int player::getEXPReq()
{
    return playerEXPReq;
}
void player::setEXPReq()
{
    playerEXPReq = 70 + ((getLevel() * getLevel()) * 35);
}

void player::setGold(int gold)
{
	playerGold = gold;
}
int player::getGold()
{
	return playerGold;
}

void player::nothing()
{
	cout << "Nothing interesting happens as you continue to walk." << endl;
}

void player::setAtributes()
{
    for (int i = 0; i < 5; i++)
    {
        int x;
        x = rand() % 3;
        switch (x)
        {
        case 1:
            setSpeed(getSpeed() + 1);
            break;
        case 2:
            setStrength(getStrength() + 1);
            break;
        default:
            setMaxMana(getMaxMana() + 10);
            break;
        }

    }
}

void player::playerCreator()
{
	system("CLS");
	int race,clas;
	cout << "Choose your race:" << endl;
	cout << "1.Human" << endl << "2.Elf" << endl << "3.Orc" << endl;
	
	bool error;
	do {
		error = 0;
		cin >> race;
		switch (race)
		{
		case 1:
			setRace("Human");
			setSpeed(getSpeed()+1);
			break;
		case 2:
			setRace("Elf");
			setMaxMana(getMaxMana()+10);
			break;
		case 3:
			setRace("Orc");
			setStrength(getStrength()+1);
			break;
		default:
			cout << "Choose a correct option." << endl;
			error = 1;
			
			break;
		}
	} while (error);
	system("CLS");
	cout << "Choose your class:" << endl;
	cout << "1.Warrior" << endl << "2.Wizard" << endl << "3.Rogue" << endl;
	
	do {
		error = 0;
		cin >> clas;
		switch (clas)
		{
		case 1:
			setClass("Warrior");
			setStrength(getStrength()+3);
			break;
		case 2:
			setClass("Wizard");
			setMaxMana(getMaxMana()+30);
			break;
		case 3:
			setClass("Rogue");
			setSpeed(getSpeed()+3);
			break;
		default:
			cout << "Choose a correct option." << endl;
			error = 1;
			
			break;
		}
	} while (error);
	system("CLS");

}

void player::playerStatus()
{
		system("CLS");
		cout << " _________________________________________________" << endl;
		cout << "|____________________Character____________________|" << endl;
		cout << "Name: " << getName() << endl;
		cout << "HP: " << getHealth() << "/" << getMaxHealth() << endl;
		cout << "Stamina: " << getStamina() << "/" << getMaxStamina() << endl;
		cout << "Mana: " << getMana() << "/" << getMaxMana() << endl;
		cout << "Strength: " << getStrength() << endl;
		cout << "Speed: " << getSpeed() << endl;
		cout << "Race: " << getRace() << endl;
		cout << "Class: " << getClass() << endl;
		cout << endl;
		cout << "Level: " << getLevel() << endl;
		cout << "EXP: " << getEXP() << "/" << getEXPReq() << endl;
		playerOrigin();
		useAbilities(0);
		system("PAUSE");
}

void player::playerOrigin()
{
	cout << " ______________________________________________" << endl;
	cout << "|____________________Origin____________________|" << endl;
	int klasa, rasa;
	if (getRace() == "Human")
	{
		rasa = 1;
	}
	else
	{
		if (getRace() == "Elf")
		{
			rasa = 2;
		}
		else
		{
			rasa = 3;
		}
	}
	if (getClass() == "Warrior")
	{
		klasa = 1;

	}
	else
	{
		if (getClass() == "Wizard")
		{
			klasa = 2;
		}
		else
		{
			klasa = 3;
		}
	}
	switch (rasa)
	{
	case 1:
		switch (klasa)
		{
		case 1:
			cout << "Origin story of human warrior." << endl;
			setClassAbilities(1);
			setRaceAbilities(1);
			break;
		case 2:
			cout << "Origin story of human wizard." << endl;
			setClassAbilities(2);
			setRaceAbilities(1);
			break;
		default:
			cout << "Origin story of human rogue." << endl;
			setClassAbilities(3);
			setRaceAbilities(1);
			break;
		}
		break;
	case 2:
		switch (klasa)
		{
		case 1:
			cout << "Origin story of elven warrior." << endl;
			setClassAbilities(1);
			setRaceAbilities(2);
			break;
		case 2:
			cout << "Origin story of elven wizard." << endl;
			setClassAbilities(2);
			setRaceAbilities(2);
			break;
		default:
			cout << "Origin story of elven rogue." << endl;
			setClassAbilities(3);
			setRaceAbilities(2);
			break;
		}
		break;
	default:
		switch (klasa)
		{
		case 1:
			cout << "Origin story of orcish warrior." << endl;
			setClassAbilities(1);
			setRaceAbilities(3);
			break;
		case 2:
			cout << "Origin story of orcish wizard." << endl;
			setClassAbilities(2);
			setRaceAbilities(3);
			break;
		default:
			cout << "Origin story orcish rogue." << endl;
			setClassAbilities(3);
			setRaceAbilities(3);
			break;
		}
	}
}

void player::setClassAbilities(int ability) // 1 - czlowiek, 2-elf, 3 ork ##### 1-wojownik, 2-czarodziej, 3-lotr
{
	playerClassAbilities = ability;
}
int player::getClassAbilities()
{
	return playerClassAbilities;
}

void player::setRaceAbilities(int ability)
{
	playerRaceAbilities = ability;
}
int player::getRaceAbilities()
{
	return playerRaceAbilities;
}

void player::duel()
{
	int option;
	int error=1;
	cout << "You meet a friendly knight and he offers you a duel. Will you take it? (1.Yes/2.No)" << endl;
	cin >> option;
	while (error)
	{
		switch (option)
		{
		case 1:
			int chance;
			chance = rand() % 100 + 1;
			if ((getStrength() * 5) > chance)
			{
				cout << "You have won the duel and your physical stats increase." << endl;
				setStrength(getStrength() + 1);
				setSpeed(getSpeed() + 1);
			}
			else
			{
				setEXP(0);
				cout << "You lose your consciousness and forget everything you learned." << endl;
			}
			error = 0;
			break;
		case 2:
			cout << "You don't want to risk it. You say goodbye and walk away." << endl;
			error = 0;
			break;
		default:
			cout << "Choose a correct option." << endl;
			break;
		}

	}
}


void player::book()
{
	cout << "You find a mysterious book, but the closer you get to it the greater danger you feel. Do you want to read the book? (1.Yes/2.No)" << endl;
	int option;
	int error = 1;
	cin >> option;
	while (error)
	{
		switch (option)
		{
		case 1:
		int chance;
		chance = rand() % 1000 + 1;
		if ((getMaxMana() * 5) > chance)
		{
			setMaxMana(getMaxMana()+getMaxMana()/2);
			setMana(getMaxMana());
			cout << "This book is an amazing source of secret knowledge." << endl;
		}
		else
		{
			setHealth(1);
			setStamina(1);
			setMana(1);
			cout << "The content of the book is beyond any of your skill and it leaves you in a terrible state." << endl;
		}
		error = 0;
		break;
		case 2:
			cout << "You don't want to risk it and walk away." << endl;
			error = 0;
			break;
		default:
			cout << "Choose a correct option." << endl;
			break;
		}

	}
}

void player::useAbilities(int battle)
{
	cout << " _________________________________________________" << endl;
	cout << "|____________________Abilities____________________|" << endl;
	cout << "|__________Mana: " << getMana() << "__________|" << endl;
	cout << "|||||||||| Racial ||||||||||" << endl;

	switch (getRaceAbilities())
	{
	case 1:
		cout << "> Blood Money" << " [5 Mana]" << endl;
		cout << "Spend any amount of gold and deal damage equal to it. " << endl;
		break;
	case 2:
		cout << "> Energy Conversion" << " ["<<getMaxMana()/2<<" Mana]" << endl;
		cout << "Spend half of your max mana to regain half of your max health and regain full stamina." << endl;
		break;
	case 3:
		cout << "> Battle Furry" << " [20 Mana + 5 Stamina]" << endl;
		cout << "Set your current health to half of your max health and attack for double damage." << endl;
		break;
	default:
		break;
	}
	cout << "||||||||||Class||||||||||" << endl;
	int ClassLevel;
	ClassLevel = getLevel() / 5;
	if (ClassLevel >= 1)
	{
		switch (getClassAbilities())
		{
		case 1:
			cout << "> Power Strike " << power_strike<< "/3 [10 Mana]" << endl;
			cout << "Spend 10 mana to gain 1 power strike charge. After gaining 3 charges spend them all to deal critical damage." << endl;
			break;
		case 2:
			cout << "> Arcane Missle" << " [50 Mana]" << endl;
			cout << "Deal damage equal to your current mana." << endl;
			break;
		case 3:
			cout << "> Lifesteal" << " [50 Mana]" << endl;
			cout << "Deal damage to the enemy based on your speed and max mana. Then heal for half of damage dealt." << endl;
		}
		if (ClassLevel >= 2)
		{
			switch (getClassAbilities())
			{
			case 1:
				cout << "> Patch Up" << " [20 Mana]" << endl;
				cout << "Heal for half of your health." << endl;
				break;
			case 2:
				cout << "> Arcane Blast" << " [100 Mana]" << endl;
				cout << "Deal damage equal to your max mana." << endl;
				break;
			case 3:
				cout << "> Pickpocket" << " [100 Mana]" << endl;
				cout << "Steal between 1-100 gold from your enemy. Then deal that much damage to him." << endl;
			}
			if (ClassLevel >= 3)
			{
				switch (getClassAbilities())
				{
				case 1:
					cout << "> Last Stand" << " [50 Mana]" << endl;
					cout << "Set your health to 1 point. Then deal critical damage to the enemy." << endl;
					break;
				case 2:
					cout << "> Arcane Explosion" << " [" << getMaxMana()<< " Mana]" << endl;
					cout << "Spend all of your mana. Then deal critical damage to the enemy." << endl;
					break;
				case 3:
					cout << "> Assasination" << " [200 Mana]" << endl;
					cout << "Deal high damage to your enemy based on your speed and max mana. 20 % chance to deal critical damage." << endl;
				}

			}
		}

	}
	if (battle == 1)
	{
		setAbilityDamage(0);
		int abilityUse;
		string choice;
		cout << "Do you want to use an ability? (Y/N)" << endl;
		bool error;
		int abilityUse2;
		bool error2;
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
		getline(cin, choice);
		do {
			error = 0;
			
			
			for_each(choice.begin(), choice.end(), [](char& wybor1)
				{
					wybor1 = ::tolower(wybor1);
				});
			if (choice == "y" || choice == "yes")
			{
				abilityUse = 1;
			}
			else
			{
				if (choice == "n" || choice == "no")
				{
					abilityUse = 2;
				}
				else
				{
					abilityUse = 0;
				}
			}
			if (abilityUse == 0)
			{
				cout << "Choose a correct option." << endl;
				error = 1;
				
				getline(cin, choice);
				
			}
		} while (error);
		string choice2;

		switch (abilityUse)
		{
		case 1:
			int warunek = 1;
			cout << "Which ability do you want to use? (type Q if you want to quit)" << endl;
			cin.clear();
			
				do {
					while(warunek){
					error2 = 1;
					getline(cin, choice2);
					for_each(choice2.begin(), choice2.end(), [](char& wybor2)
						{
							wybor2 = ::tolower(wybor2);
						});
					switch (getRaceAbilities())
					{
					case 1:
						if (choice2 == "blood money" || choice2 == "1")
						{
							if (getMana() >= 5)
							{
								HumanAbility();
								setMana(getMana() - 5);
								warunek = 0;

							}
							else
							{
								cout << "You don't have enough mana." << endl;
							}
							error2 = 0;
						}
						break;
					case 2:
						if (choice2 == "energy conversion" || choice2 == "1")
						{
							if (getMana() >= (getMaxMana()/2))
							{
								ElfAbility();
								setMana(getMana() - (getMaxMana()/2));
								warunek = 0;

							}
							else
							{
								cout << "You don't have enough mana." << endl;
							}
							error2 = 0;
						}
						break;
					case 3:
						if (choice2 == "battle fury" || choice2 == "1")
						{
							if (getMana() >= 20 && getStamina() >= 5)
							{
								OrcAbility();
								setMana(getMana() - 20);
								setStamina(getStamina() - 5);
								warunek = 0;
								
							}
							else if (getMana() < 20)
							{
								cout << "You don't have enough mana." << endl;
							}
							else
							{
								cout << "You don't have enough stamina." << endl;
							}
							error2 = 0;
						}
						break;
					}
					if (ClassLevel >= 1)
					{
						switch (getClassAbilities())
						{
						case 1:
							if (choice2 == "power strike" || choice2 == "2")
							{
								if (getMana() >= 10)
								{
									WarriorAbility1();
									setMana(getMana() - 10);
									warunek = 0;
									
								}
								else
								{
									cout << "You don't have enough mana." << endl;
								}
								error2 = 0;
							}
							else if (ClassLevel >= 2)
							{
								if (choice2 == "patch up" || choice2 == "3")
								{
									if (getMana() >= 20)
									{
										WarriorAbility2();
										setMana(getMana() - 20);
										warunek = 0;

									}
									else
									{
										cout << "You don't have enough mana." << endl;
									}
									error2 = 0;
								}
								else if (ClassLevel >= 3)
								{
									if (choice2 == "last stand" || choice2 == "4")
									{
										if (getMana() >= 50)
										{
											WarriorAbility3();
											setMana(getMana() - 50);
											warunek = 0;

										}
										else
										{
											cout << "You don't have enough mana." << endl;
										}
										error2 = 0;
									}
								}
							}break;
						case 2:
							if (choice2 == "arcane missle" || choice2 == "2")
							{
								if (getMana() >= 50)
								{
									WizardAbility1();
									setMana(getMana() - 50);
									warunek = 0;
									
								}
								else
								{
									cout << "You don't have enough mana." << endl;
								}
								error2 = 0;
							}
							else if (ClassLevel >= 2)
							{
								if (choice2 == "arcane blast" || choice2 == "3")
								{
									if (getMana() >= 100)
									{
										WizardAbility2();
										setMana(getMana() - 100);
										warunek = 0;
									}
									else
									{
										cout << "You don't have enough mana." << endl;
									}
									error2 = 0;
								}
								else if (ClassLevel >= 3)
								{
									if (choice2 == "arcane explosion" || choice2 == "4")
									{
										if (getMana() == getMaxMana())
										{
											WizardAbility3();
											setMana(0);
											warunek = 0;
										}
										else
										{
											cout << "You don't have enough mana." << endl;
										}
										error2 = 0;
									}
								}
							}break;
						case 3:
							if (choice2 == "lifesteal" || choice2 == "2")
							{
								if (getMana() >= 50)
								{
									RogueAbility1();
									setMana(getMana() - 50);
									warunek = 0;
								}
								else
								{
									cout << "You don't have enough mana." << endl;
								}
							}
							else if (ClassLevel >= 2)
							{
								if (choice2 == "pickpocket" || choice2 == "3")
								{
									if (getMana() >= 100)
									{
										RogueAbility2();
										setMana(getMana() - 100);
										warunek = 0;
									}
									else
									{
										cout << "You don't have enough mana." << endl;
									}
								}
								else if (ClassLevel >= 3)
								{
									if (choice2 == "assasination" || choice2 == "4")
									{
										if (getMana() >= 200)
										{
											RogueAbility3();
											setMana(getMana() - 200);
											warunek = 0;
										}
									}
								}
							}break;
						}

					}if (choice2 == "q")
						{
						warunek = 0;
						error2 = 0;
							break;
						}
					else if (error2 == 1)
					{
						cout << "Choose a correct option." << endl;
					}
				
				}
				
			} while (error2);
		}
	}
}

void player::setAbilityDamage(int damage)
{
	playerAbilityDamage = damage;
}
int player::getAbilityDamage()
{
	return playerAbilityDamage;
}

void player::HumanAbility() // Blood Money (spend gold to deal damage)
{
	
	int money;
	int warunek = 1;
	cout << "How much gold do you want to spend? (Gold available: "<< getGold()<<")" << endl;
	do {
		cin >> money;
		if (money <= getGold())
		{
			setAbilityDamage(money);
			setGold(getGold() - money);
			warunek = 0;
		}
		else 
		{
			cout << "You don't have this much gold!" << endl;
		}
	} while (warunek);
}

void player::ElfAbility() // Energy Conversion (spend mana to regain health and stamina)
{
	setHealth(getHealth() + (getMaxHealth() / 2));
	setStamina(getMaxStamina());

}

void player::OrcAbility() // Fury (set Hp to half of MaxHP, and deal double damage)
{
	setHealth(getMaxHealth() / 2);
	setAbilityDamage(2*((getLevel() * (rand() % 5 + 1)) + (getLevel() * getStrength())));
}

void player::WarriorAbility1() // power strike load 3 times then insta kill
{
	power_strike += 1;
	if (power_strike >= 3)
	{
		power_strike = 0;
		setAbilityDamage(1000000);
	}
}
void player::WarriorAbility2() // Patch Up Heal half of your health
{
	setHealth(getHealth() + (getMaxHealth() / 2));
	setAbilityDamage(0);
}
void player::WarriorAbility3() // Last Stand set hp to 1, instakill the enemy
{
	setHealth(1);
	setAbilityDamage(1000000);
}

void player::WizardAbility1() // Damage equal to your current mana
{
	setAbilityDamage(getMana());

}
void player::WizardAbility2() // Damage equal to your max mana
{
	setAbilityDamage(getMaxMana());
}
void player::WizardAbility3() // If you have full mana spend it all to insta kill an enemy
{
	setAbilityDamage(1000000);
}

void player::RogueAbility1() //Life Steal
{
	setAbilityDamage((getMaxMana()/10)+(5 * getSpeed()));
	setHealth((getHealth() + getAbilityDamage())/2);
	if (getHealth() >= getMaxHealth())
	{
		setHealth(getMaxHealth());
	}
}
void player::RogueAbility2() // Gold Steal
{
	setAbilityDamage(rand() % 100 + 1);
	setGold(getGold() + getAbilityDamage());
}
void player::RogueAbility3() // Assasination
{
	int x = rand() % 5 + 1;
	if (x == 1)
	{
		setAbilityDamage(1000000);
		cout << "Critical Hit!" << endl;
	}
	else
	{
		setAbilityDamage(getLevel() * getMana() * getSpeed() / 5);
	}
}