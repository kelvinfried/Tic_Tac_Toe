#include <iostream>
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
//Private since the class will be embedded into the game class, not inherited
	private:
	//Attrubutes
		std::string* name;
		
	public:
	//Getters and Setters - Function Prototypes
		//Name
		std::string* Get_Name(void );
		void Set_Name(std::string* new_name );
		
	//Constructor- Called upon object creation
		//Default
	Player(void );
	
		//Over Ridden
	Player(std::string* new_name );
	
	//Destructor- Called upon object deletion
	~Player(void );	
};
#endif