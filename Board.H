#ifndef BOARD_H
#define BOARD_H

#include "Piece.CPP"
#include <iostream>
class Board 
{
	private:
		//Used to store the physical game board it self.
		piece_identifier** board; 
		int rows;
		int collums;
		const int OUTPUT_LINES {3};
		char* border_parts;
		int* keyed_positions;
		

	public:
		//Constructors
			//Default
		Board(void );
			//Used to set a custom size at the start
		Board(int rows, int collums );

		//Destructors 
		~Board(void );


		//-----------------------------------------Board Set Up Section:
		piece_identifier** Setup(void );

		//----------------------For Setting Defaults Across the board:
		//Sets the default value for the entire board. -Takes in the board, and the number of rows, collums
		void Default(void );

		//Overloaded function, used to fill the board with the passed in piece type.
		void Default(Piece* piece);

		//----------------------For Board Expansion:
		//To add anoter row, the current row, overload_char is only for overloading. Used first.
		void Incriment_Row(void );
		void Default(char overload_char );

		//To add another collum to the end.
		void Incriment_Collum(void );
		void Default(int overload_int );


		//-----------------------------------------Board Size Management Section:
		//----------------------Board Increase In Size:
		//Used first, to add new collums to the board.
		void New_Collum(void );

		//To add a new row to the board, row is set to nothing.
		void New_Row(void );

		//Combines the two seperate expansion functions into on neat package.
		void Expand(void );

		//----------------------Board Decrease In Size:
		//To delete a specified collum. //Used first
		void Deincriment_Collum(void );
		void Remove(void );

		//To delete a specifed row
		void Deincriment_Row(void );
		void Remove(int current_row );

		//Combines the two seperate deleting methods into one function.
		void Shrink(void );

		//-----------------------------------------Output Section:
		//----------------------Output Segments:
		//Outputs the board border.
		void Output_Border(void );

		//Outputs the passed in row of the board
		void Output_Row(Piece* Pieces, int* current_row );

		//----------------------Outputs Whole:
		void Output(Piece* Pieces );


		//-----------------------------------------Input Handling Section:
		//----------------------Handle Input:
		//Test case weight against upper limit //Updated to have a bool return, to be used directly with if statments.
		bool Input_Sanitization(int* test_data, int* upper_limit );

		//To ensure that the insertion is valid before doing it.
		bool Insertion_Trial(int* current_row, int* current_collum );

		//----------------------Draw Input to the board:
		//The actual insertion into the board, incorporates the checks and if valid will draw onto the board.
		void Insertion(Piece* Piece, int* current_row, int* current_collum );


		//-----------------------------------------Win Check:
		//void Check(int* start_row, int* start_collum, int* rows, int* collums, piece_identifier piece_type, piece_identifier** board, int** keyed_positions, int* points_so_far);
	};
#endif