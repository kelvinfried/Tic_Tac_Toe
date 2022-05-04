//Tic Tac Toe Array "Grd" Setup code and testing stuff from in person lesson.
#include <iostream>
#include "Board_Piece.H"

int main(void )
{
	//To keep track of the array's dimensions.
	int collums= 5;		
	int rows= 5;

	//Declared from the heap as they have a long life time.
	piece_identifier* board_row_0= new piece_identifier[rows ];

	//Define the game board; Holds each of the subrows, so they can be accesed from a single part.
	piece_identifier** game_board= new piece_identifier*[collums ];
		//Declares the rows. //game_board[0 ]= board_row_0; //game_board[3 ]= new piece_identifier[rows ];	//Old methods
	//Iterative approach to have a dynamic size during runtime.
	for( int x= 0; x< rows; x++ )
	{
		game_board[x ]= new piece_identifier[rows ];
	}
	
	//Declare the game boards rows to all be set to to a grid of "nothing". (Default Values)
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

	
	//Cleans up the game_board itself.
	delete[] game_board;
	game_board= NULL;

	return 0;	
}