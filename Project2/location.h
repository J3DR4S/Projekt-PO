#pragma once
#include <string>

using namespace std;

class location
{
public:
	location(int);
	void setNumber();
	int getNumber();
	void setLevel(int);
	int getLevel();
	void setName(int, int);
	string getName();
	void setDescription(int, int);
	string getDescription();
	

private:
	string locationName;
	string locationDescription;
	string locationNames[4][3] = { {"cave", "orchard", "cornfield"} ,{"forest","swamp","abandoned residence"}, {"abandoned castle","ancient ruins", "underground dungeon" }, {"necromancer tower", "catacombs", "gnoll fortress"} };
	int locationNumber;
	int locationLevel;
	string locationDescriptions[4][3] = { {"cave description", "orchard description", "cornfield description"} ,{"forest description","swamp description","abandoned residence description"}, {"abandoned castle description","ancient ruins description", "underground dungeon description" }, {"necromancer tower description", "catacombs description", "gnoll fortress description"} };
};

