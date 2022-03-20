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
		bool* piece_type;
		
	public:
	//Getters and Setters - Function Prototypes
		//Name- Now returns a string pointer, so it will carry the memory address of the name so it can be printed.
		std::string* Get_Name(void );
		void Set_Name(std::string* new_name );
		//Wins
		int* Get_Win_Count(void );
		void Incriment_Win_Count(void );
		//Piece
		bool* Get_Piece_Type(void );
		void Set_Piece_Type(bool* new_piece );
		
	//Constructor- Called upon object creation
		//Default
	Player(void );
	
		//Over Ridden
	Player(std::string* start_name, bool* piece_type );
	
	//Destructor- //Will be used for when the vairables are made dynamic because of their lifespans
	~Player(void );	
};
#endif