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
		//-----------------------------------------Getters and Setters:
		//----------------------Player Statistics
		void Name_Trial(int* iteration_count );
	
		//----------------------Board Statistics

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