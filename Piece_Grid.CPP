//Tic Tac Toe Array "Grd" Setup code and testing stuff from in person lesson.
#include <iostream>
#include "Board_piece.CPP"

int main(void )
{
	//To keep track of the array's dimensions.
	int game_board_collums= 3;		
	int game_board_rows= 3;

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
	//piece_identifier* board_row_0= new piece_identifier[rows ];

	//Define the game board; Holds each of the subrows, so they can be accesed from a single part.
	piece_identifier** game_board= new piece_identifier*[game_board_collums ];
		//Declares the rows. //game_board[0 ]= board_row_0; //game_board[3 ]= new piece_identifier[rows ];	//Old methods
	//Iterative approach to have a dynamic size during runtime.
	for( int creation_row= 0; creation_row< game_board_rows; creation_row++ )
	{
		game_board[creation_row ]= new piece_identifier[game_board_collums ];
	}
	
	//Used to set default values for the grid.
		//Used to access each row at a time.
	for(int setting_row= 0; setting_row< game_board_rows; setting_row++ )
	{
			//Used to access each element of the parent row.
		for(int setting_collum= 0; setting_collum< game_board_collums; setting_collum++ )
		{
				//Automated way to full up the game_board with a linear pattern
			/*switch(current_row )
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
			}*/
			game_board[setting_row ][setting_collum ]= nothing;
		}
	}
	//Grid Output Section -Main Loop:
	for(int output_row= 0; output_row< game_board_rows; output_row++ )
	{
		//General Border Creation
		for(int border_row= 0; border_row< game_board_rows; border_row++ )
		{
			std::cout<<border_chunk <<border_divider;
		}
		std::cout<<"" <<std::endl;

		//Gameboard Piece Printing.
		for(int output_collum= 0; output_collum< game_board_collums; output_collum++ )
		{
			//Used to print out each of the piece's layer, side by side, then break line.
			for(int current_layer= 0; current_layer< OUTPUT_LINES; current_layer++ )
			{
				//switch(game_board[output_row ][output_collum ] )
				switch(1 )
				{
					case cross:
						break;
			
					case nought:
						break;
	
					default:
						break;
				}
			}
		std::cout<<"" <<std::endl;

		}
	}

	//End Border
	for(int border_row= 0; border_row< game_board_rows; border_row++ )
	{
		std::cout<<border_chunk <<border_divider;
	}

	std::cout<<"" <<std::endl;
	
	
	//Cleans up the game_board itself.
	delete[] game_board;
	game_board= NULL;

	return 0;	
}