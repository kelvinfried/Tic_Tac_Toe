#ifndef GAME_H
#define GAME_H

#include "Board.CPP"

#include <stdlib.h>
#include <time.h>

class Game
{
	private:
		//Attrubutes
		Board* Board_class;

		Player* Player_class;

		int number_of_rounds;
		int round_counter;

		
	public:
		//-----------------------------------------Constructor:
		Game(void );

		//Game(int param );
		//-----------------------------------------Destructor: 
		//Will be used to automatically clean up the dynamic data types and null their points.
		~Game(void );

		//Public Functions
		//-----------------------------------------Input Handling Section:
		//----------------------Handle Input:
		bool Input_Sanitization(int* test_data );
		//-----------------------------------------Getters and Setters:
		//----------------------Player Statistics
		//Used to set player names.
		void Name_Trial(int* iteration_count );
		
		//Used to set the players piece type
		void Piece_Trial(void );
	
		//----------------------Board Statistics
		void Row_Setup(void );

		//----------------------Rules Output 
		//Used to print out the rules segment
		void Intro_Output(void );

		//----------------------Player Output
		//Used to ouput the two players stats bars.
		void Players_Output(void );

		//----------------------Board Output

		//-----------------------------------------Player Inputs:
		//----------------------Player;

		//----------------------Board;

		
};		

#endif