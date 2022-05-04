//Tic Tac Toe Array "Grd" Setup code and testing stuff from in person lesson.
#include <iostream>
#include "Board_Piece.H"

//Step 1 define a datatype or something to represent the grid pieces.
	//It needs to hold 3 States: NULL (/empty), Piece type O, Piece type X; <Enum does this.
//The idea is with this defined data type is that I am able to assign this to each of the "cells" in the 3x3 grid
	//THen By calling the value I am able to call it as needed to then track where each player has placed down their pieces.

int main(void )
{
	//To keep track of the array's dimensions.
	int collums= 5;		
	int rows= 5;

	//Current methods of declaring 3 rows for the grid: As it stands there are 3, 3 element long arrays which are "used" as a grid.
		//Declared from the heap as they have a long life time.
	piece_identifier* board_row_0= new piece_identifier[rows ];
	
	int collums= 3;		
	int rows= 5;
	
		//declare - trial of passing nothing in as a value	
	/*piece_identifier* board_row_0= new piece_identifier[rows ];	//1D [ 0, 0, 0 ];
	piece_identifier* board_row_1= new piece_identifier[rows ];
	piece_identifier* board_row_2= new piece_identifier[rows ];*/

	//Define the game board; Holds each of the subrows, so it can be accesed from a single part.
	piece_identifier** game_board= new piece_identifier*[collums ];
		//Declares the rows.
	//game_board[0 ]= board_row_0;
	//game_board[3 ]= new piece_identifier[rows ];	//Test of 
	for( int x= 0; x< rows; x++ )
	{
		game_board[x ]= new piece_identifier[rows ];
	}
	
	//Declare the game boards rows to all be set to to a grid of "nothing".
		//Used to access each row at a time.
	for(int current_collum=0; current_collum< collums; current_collum++ )
	{
			//Used to access each element of the parent row.
		for(int current_row=0; current_row< rows; current_row++ )
		{
				//Automated way to full up the game_board with a linear pattern
			switch(current_row )
			{
				case 1:
					game_board[current_collum ][current_row ]= nought;
					break;
				case 2:
					game_board[current_collum ][current_row ]= cross;
					break;
				default:
					game_board[current_collum ][current_row ]= nothing;
					break;
			}
		}
	}
	
	//Test Output Section- Verifies the grd is correctly output; Outdated needs to be replaced by the new system.

	
	//Output section
	for(int current_collum=0; current_collum< collums; current_collum++ )
	{
		for(int current_row=0; current_row< rows; current_row++ )
		{	
			std::cout<<"Current "<<current_collum <<", " <<current_row <<" is: " <<game_board[current_collum ][current_row ] <<std::endl;
		}
		std::cout<<"" <<std::endl;
	}
	
	//Create a function to check the grid
	//std::cout<<"Test" <<std::endl;	//Verifies that it works independatly of the other elements.
	//game_board[0][0]= cross;

	//Causes faults with dynamic method, need to look into it.
	//Cleanup code, now deletes subcomponents row by row.
	/*for(int x=0; x< rows; x++ )
	{
		delete[] game_board[x ];
		game_board[x ]= NULL;
	}*/
	
	//Cleans up the game_board itself.
	delete[] game_board;
	game_board= NULL;

	return 0;	
}