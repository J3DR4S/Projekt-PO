
#include <string>

using namespace std;


class item
{
public:
	item() {};
	item(string, int, int) ;
	void setName(string);
	string getName();
	void setLevel(int);
	int getLevel();
	void setValue(int);
	int getValue();
	string itemName;
	int itemValue;
	int itemLevel;
	

};

