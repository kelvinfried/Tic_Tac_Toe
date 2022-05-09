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

		//-----------------------------------------Getters:
		//Used to pass these values in to other areas used later on in the game.
		int Get_Rows(void );

		int Get_Collums(void );

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
		//Combines the two seperate expansion functions into on neat package.
		void Expand(void );

		//----------------------Board Decrease In Size:
		//To delete a specified collum. //Used first
		void Deincriment_Collum(void );

		//To delete a specifed row
		void Deincriment_Row(void );

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


		//-----------------------------------------Tracking Array Set Up Section:
		//----------------------For Setting Defaults Across the board:
		//To clean out the int Arry and reset its value.
		void Default(bool overload_bool );


		//-----------------------------------------Array Size Management Section:
		//Used to expand the array size to match the board size.
		void Expand(char overload_char );

		//Used to shrink the array size to match the board size.
		void Shrink(char overload_char );


		//-----------------------------------------Output Section:
		//----------------------Output Segments:
		void Output(char overload_char );


		//-----------------------------------------Array Insertion/ Input:
		//Input was checked before so its not needed. Now inputs are checked against the array to see if it already has been index to not count it again.
		bool Insertion_Check(int* current_row, int* current_collum );

		//Used for inserting the value into the correct slot.
		void Insertion(int* current_row, int* current_collum, int* points_so_far );

		//Used to above functions to create one function way for check and insertion.
		void Commit(int* current_row, int* current_collum, int* points_so_far );


		//-----------------------------------------Win Checks:
		//Horizontal_Check for if the player has placed "row" number of their pieces in a row on the collums.
		void Horizontal_Check(int* start_row, int* start_collum, Piece* Piece, int* points_so_far );

		//Vertical check, for checking  if the player has placed "row" number of theur pieces in a collum on the rows;
		void Vertical_Check(int* start_row, int* start_collum, Piece piece, int* points_so_far, char overload_char );

		//Linear check, checks for diagonals. i.e x -> y or y -> x
		void Linear_Check(int* start_row, int* start_collum, Piece piece, int* points_so_far, char overload_char );

		//Combines all the checks into one function with additional information.
		void Check(int* start_row, int* start_collum, Piece piece, int* points_so_far, char overload_char );
};
#endif