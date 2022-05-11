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
	
		Piece* Pieces_class;

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
		//Used to test against if the players input is within the correct range for the pieces assignment.
		bool Input_Sanitization(int* test_data );
		//Overloaded
		//Used to test against if the players input is within the correct range for the row number.
		bool Input_Sanitization(int* test_data, char overload_char );
		//Overloaded
		//Used to test against for the round count
		bool Input_Sanitization(int* test_data, bool* overload_bool );
		//-----------------------------------------Getters and Setters:
		//----------------------Game Statistics
		//To get the number of rounds there are in total.
		int* Get_Rounds(void );
		//Used during setup to define how many rounds the game will have.
		void Set_Rounds(void );

		//To get the current round counter
		int* Get_Rounds(char overload_char );
		//To increase the round counters current value.
		void Incriment_Rounds(void );
		//Used to also adjust the player score
		void Incriment_Rounds(int* current_player );

		//----------------------Player Statistics
		//Used to set player names.
		void Name_Trial(int* iteration_count );
		
		//Used to set the players piece type
		void Piece_Trial(void );
	
		//----------------------Board Statistics
		void Row_Setup(void );
		
		piece_identifier** Get_Board(void );

		//----------------------Rules Output 
		//Used to print out the rules segment
		void Intro_Output(void );

		//----------------------Player Output
		//Used to ouput the two players stats bars.
		void Players_Output(void );

		//----------------------Board Output
		//Outputs the board.
		void Board_Output(void );

		//-----------------------------------------Player Inputs:
		//----------------------Player;

		//----------------------Board;
		void Board_Insertion_Intro(int* iteration_count );

		void Board_Insertion(int* iteration_count );
		
		bool Win_Check(piece_identifier** game_board, int* iteration_count );
		
		void Win_Screen(void );
};		

#endif