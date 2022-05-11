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

		int points_so_far;
		
	public:
		//-----------------------------------------Constructor:
			//Default
		Player(void );
		
			//Over Ridden
		Player(std::string* start_name, piece_identifier* new_Piece );
		
		//-----------------------------------------Destructor: 
		//Will be used to automatically clean up the dynamic data types and null their points.
		~Player(void );	

		//Public Functions
		//-----------------------------------------Getters and Setters:
		//----------------------Player Statistics
		//Now returns a string pointer, so it will carry the memory address of the name so it can be printed.
		std::string* Get_Name(void );
		//To Set their name after created 
		void Set_Name(std::string* new_name );

		//Return the win count
		int* Get_Win_Count(void );
		//Upon winning incriment the win counter to update it
		void Incriment_Win_Count(void );

		//----------------------Piece
		//Used to get the entire piece out of the class.
		Piece* Get_Piece(void );
		//----------------------Points
		int* Get_Points(void );

		piece_identifier* Get_Type(void );
		//Used to set the piece after the player is created, done as with my current method I cannot use anything other than the default constructor.
		void Set_Type(int* new_piece );
		//Needed as the player class is private
		std::string* Get_Piece_Output(void );

		//----------------------Stats
		void Get_Stats(void );
		//Overloaded
		void Get_Stats(int* overload_int );
		//Overloaded now- Debug	Version
		void Get_Stats(char overload_char );

		//----------------------Player Inputs
		//Input Handling.
		int* Get_Inputs(void );
		//Passes both inputs into the input for the player.
		void Set_Inputs(int* input_1, int* input_2 );
};
#endif