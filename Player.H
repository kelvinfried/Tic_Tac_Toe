#include <iostream>
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
//Private since the class will be embedded into the game class, not inherited
	private:
	//Attrubutes
		//Used  to store the name passed by the player.
		std::string* name;
		//Keeps track of how many wins each player has
		int* win_count;
		//Shows which piece the player has 0= O, 0!= X;
		bool* piece_type;
		
	public:
	//Getters and Setters - Function Prototypes
		//Name- Now returns a string pointer, so it will carry the memory address of the name so it can be printed.
		std::string* Get_Name(void );
		void Set_Name(std::string* new_name );
		//Wins
		int* Get_Win_Count(void );
		//does not require any parameters as it can only go up by one.
		void Incriment_Win_Count(void );
		//Piece
		bool* Get_Piece_Type(void );
		void Set_Piece_Type(bool* new_piece );
		
	//Constructor- Called upon object creation
		//Default
	Player(void );
	
		//Over Ridden
	Player(std::string* start_name, bool* start_piece_type );
	
	//Destructor- //Will be used for when the vairables are made dynamic because of their lifespans
	~Player(void );	
};
#endif