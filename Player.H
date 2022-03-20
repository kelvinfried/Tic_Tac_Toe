#include <iostream>
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
//Private since the class will be embedded into the game class, not inherited
	private:
	//Attrubutes
		std::string* name;
		int* win_count;
		
	public:
	//Getters and Setters - Function Prototypes
		//Name
		std::string* Get_Name(void );
		void Set_Name(std::string* new_name );
		//Wins
		int* Get_Win_Count(void );
		//void Incriment_Win_Count(void );
		void Incriment_Win_Count(void );
		
	//Constructor- Called upon object creation
		//Default
	Player(void );
	
		//Over Ridden
	Player(std::string* start_name );
	
	//Destructor- Called upon object deletion
	~Player(void );	
};
#endif