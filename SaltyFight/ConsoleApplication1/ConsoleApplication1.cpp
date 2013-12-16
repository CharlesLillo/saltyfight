//Charles Lillo

#include "stdafx.h"
#include "iostream"
#include "vector"
#include <string>

/*TODO DONT USE STD NAMESPACE \
1. Create specific class constructors
2. Create interface menu
3. User Validation
4. Make more todo's
5. Move Character class to its own file linked w/ header file
*/


//Character Class template
class Character
{
public:
	//Default Constructor
	Character::Character();
	//Other Constructors
	Character::Character(std::string name);
	//Class enum so they are static
	enum Classes{PEASANT, WARRIOR, ROUGE, WIZARD};
	//Setters for character equipment and skills
	void setName(std::string name);
	void setCharClass(std::string charClass);
	void setSkills(std::vector<std::string>);
	void setEquipment(std::string equipment []);
	void setLevel(int level);
	//Getters
	std::string getName();
	std::string getCharClass();
	int getLevel();
	std::vector<std::string> getSkills();
	
private:
	//Primary Attributes
	std::string name;
	Classes charClass;
	int level;
	std::vector<std::string> skills;
	//Gear
	struct equipment{
		std::string helm;
		std::string chest;
		std::string legs;
		std::string weapon;
	};
	//Struct intialization
	equipment Equipment;
};

//Initializes enum strings
static std::string ClassesStrings[] = {"PEASANT", "WARRIOR", "ROUGE", "WIZARD"};


//Default character name constructor (probably won't be used later on)
Character::Character(std::string name){
		this->name = name;
		charClass = Classes::PEASANT;
		level = 1;
		//Uses dynamic allocation of vector class
		skills.resize(4);
		//Adds basic skills to vector
		skills.push_back("Punch");
		skills.push_back("Kick");
		skills.push_back("Heal");
		skills.push_back("Run");
		
		Equipment.helm = "Smaller Sack";
		Equipment.chest = "Bigger Sack";
		Equipment.legs = "Potato Sack";
		Equipment.weapon = "Potato";
};

std::string Character:: getName(){
	return name;
}
std::string Character::getCharClass()
{
	return ClassesStrings[charClass];
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::string name_input;
	std::cout << "Welcome to SALTYFIGHT V.0.0\nPlease enter a character name to get started." << std::endl;
	std::getline(std::cin, name_input);
	Character starter(name_input);
	std::cout << "You entered: " << starter.getName() << std::endl;
	std::cout << "Your class is : " << starter.getCharClass() << std::endl;
	//Here we should hand off the execution to a menu thread

	system("pause");
	return 0;
}

