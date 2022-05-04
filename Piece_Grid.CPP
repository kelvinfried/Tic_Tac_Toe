//Tic Tac Toe Array "Grd" Setup code and testing stuff from in person lesson.
#include <iostream>
#include "Board_piece.H"

int main(void )
{
	//To keep track of the array's dimensions.
	int collums= 3;		
	int rows= 3;

	//Keep hold of the piece data.	-Passed in board piece type.
	Board_piece Nothing;
	Board_piece Nought(nought );
	Board_piece Cross(cross );

	//Stores how many lines the output has, used for printing.
	constexpr int OUTPUT_LINES= 3;

	//Used for spacing out the output for the program.
	std::string border_chunk= "XXX";
	char border_divider= '_';
	char space_character= 'X';

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
	
	//Used to set default values for the grid.
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
	
	/*//old Output section
	for(int current_collum=0; current_collum< collums; current_collum++ )
	{
		for(int current_row=0; current_row< rows; current_row++ )
		{	
			std::cout<<"Current "<<current_collum <<", " <<current_row <<" is: " <<game_board[current_collum ][current_row ] <<std::endl;
		}
		std::cout<<"" <<std::endl;
	}*/

	//Grid Output Section -Main Loop:
	for(int down= 0; down< collums; down++ )
	{
		//General Border Creation
		for(int across= 0; across< rows; across++ )
		{
			std:;cout<<border_chunk <<border_divider;
		}
		std::cout<<"" <<std::endl;

		//Gameboard Piece Printing
		for(int current_layer= 0; current_layer< OUTPUT_LINES; current_layer++ )
		{
			for(int across= 0; across< rows; across++ )
			{
				switch(game_board[down][across] )
				{
					case cross:
						std::cout<<Cross.Get_Output()[current_layer ] <<space_character;
						break;

					case nought:
						std::cout<<Nought.Get_Output()[current_layer ] <<space_character;
						break;

					default:
						std::cout<<Nothing.Get_Output()[current_layer ] <<space_character;
						break;
				}
			}
		std::cout<<"" <<std::endl;
		}

		//Border Creation for the last output line.
		if((down+= 1)== grid_x_length )
		{
			for(int across= 0; across< grid_y_length; across++ )
			{
				//Border Creation
				std::cout<<border_chunk <<border_divider;
			}
		}
	}

	
	
	//Cleans up the game_board itself.
	delete[] game_board;
	game_board= NULL;

	return 0;	
}