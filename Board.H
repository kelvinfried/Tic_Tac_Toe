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
		const int OUTPUT_LINES;
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
		piece_identifier** Setup(piece_identifier** board, int* rows, int* collums );

		//----------------------For Setting Defaults Across the board:
		//Sets the default value for the entire board. -Takes in the board, and the number of rows, collums
		void Default(piece_identifier** board, int* rows, int* collums );

		//Overloaded function, used to fill the board with the passed in piece type.
		void Default(piece_identifier** board, Piece* piece, int* rows, int* collums );

		//----------------------For Board Expansion:
		//To add anoter row, the current row, overload_char is only for overloading. Used first.
		void Default(piece_identifier** board, int* rows, int* collums, char overload_char );

		//To add another collum to the end.
		void Default(piece_identifier** board, int* rows, int* collums, int overload_int );


		//-----------------------------------------Board Size Management Section:
		//----------------------Board Increase In Size:
		//Used first, to add new collums to the board.
		void New_Collum(piece_identifier** board, int* rows, int* collums );

		//To add a new row to the board, row is set to nothing.
		void New_Row(piece_identifier** board, int* rows, int* collums );

		//Combines the two seperate expansion functions into on neat package.
		void Expand(piece_identifier** board, int* rows, int* collums );

		//----------------------Board Decrease In Size:
		//To delete a specified collum. //Used first
		void Remove(piece_identifier** board, int* rows, int* collums );

		//To delete a specifed row
		void Remove(piece_identifier** board, int* rows);

		//Combines the two seperate deleting methods into one function.
		void Shrink(piece_identifier** board, int* rows, int* collums );

		//-----------------------------------------Output Section:
		//----------------------Output Segments:
		//Outputs the board border.
		void Output_Border(int* collums, const int* OUTPUT_LINES, char* border_parts );

		//Outputs the passed in row of the board
		void Output_Row(piece_identifier** board, Piece* Pieces, int* current_row, int* collums, const int* OUTPUT_LINES, char* border_parts );

		//----------------------Outputs Whole:
		void Output(piece_identifier** board, Piece* Pieces, int* rows, int* collums, const int* OUTPUT_LINES, char* border_parts  );


		//-----------------------------------------Input Handling Section:
		//----------------------Handle Input:
		//Test case weight against upper limit //Updated to have a bool return, to be used directly with if statments.
		bool Input_Sanitization(int* test_data, int* upper_limit );

		//To ensure that the insertion is valid before doing it.
		bool Insertion_Trial(piece_identifier** board, int* current_row, int* current_collum );

		//----------------------Draw Input to the board:
		//The actual insertion into the board, incorporates the checks and if valid will draw onto the board.
		void Insertion(piece_identifier** board, Piece* Piece, int* rows, int* collums, int* current_row, int* current_collum );


		//-----------------------------------------Win Check:
		void Check(int* start_row, int* start_collum, int* rows, int* collums, piece_identifier piece_type, piece_identifier** board, int** keyed_positions, int* points_so_far);


		//-----------------------------------------Clean Up:
		//To Destory the board.
		void Wipe(piece_identifier** board, int* rows );

};
#endif