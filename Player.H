#ifndef PLAYER_H
#define PLAYER_H

#include "Piece.CPP"

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
		Piece* Piece_class;

		//To store inputs
		//Array to store input 1 and 2.
		int* inputs;
		
	public:
		//Constructor- Called upon object creation
			//Default
		Player(void );
		
			//Over Ridden
		Player(std::string* start_name, piece_identifier* new_Piece );
		
		//Destructor- //Will be used for when the vairables are made dynamic because of their lifespans
		~Player(void );	

		//Public Functions
		//-----------------------------------------Getters and Setters:
		//----------------------Player Statistics
		//Name- Now returns a string pointer, so it will carry the memory address of the name so it can be printed.
		std::string* Get_Name(void );
		void Set_Name(std::string* new_name );

		//Wins
		int* Get_Win_Count(void );
		//does not require any parameters as it can only go up by one.
		void Incriment_Win_Count(void );

		//Piece
		piece_identifier* Get_Type(void );
		void Set_Type(piece_identifier* new_piece );

		//Output- Used only for debug.
		void Get_Stats(void );

		//----------------------Player Inputs
		//Input Handling.
		int* Get_Inputs(void );
		void Set_Input(int* new_input, int input_number );

};
#endif