#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
//Private since the class will be embedded into the game class, not inherited
	private:
	//Attrubutes
		//Used  to store the name passed by the player.
		std::string* name;

		//Keeps track of how many wins each player has
		int* win_count;

		//Shows which piece the player has using the piece identifier data type
		Piece* Piece;

		//To store inputs
		int input_1;
		int input_2;
		
	public:
		//Constructor- Called upon object creation
			//Default
		Player(void );
		
			//Over Ridden
		Player(std::string* start_name, int piece );
		
		//Destructor- //Will be used for when the vairables are made dynamic because of their lifespans
		~Player(void );	

	//Getters and Setters - Function Prototypes
		//Name- Now returns a string pointer, so it will carry the memory address of the name so it can be printed.
		std::string* Get_Name(void );
		void Set_Name(std::string* new_name );

		//Wins
		int* Get_Win_Count(void );

		//does not require any parameters as it can only go up by one.
		void Incriment_Win_Count(void );

		//Piece
		piece_identifier* Player::Get_Type(void );

		//Output- Used only for debug.
		void Get_Stats(void );

		//Input Handling.
		int Get_Input_1(void );
		void Set_Input_1(int new_input );

		int Get_Input_2(void );
		void Get_Input_2(int new_input );
		
};
#endif