//Tic Tac Toe Array "Grd" Setup code and testing stuff from in person lesson.
#include <iostream>
#include "Board_piece.CPP"


void Game_Piece_Output(void )
{
}

//Outputs a border.
void Game_Piece_Output_Border(int* collums, const int* OUTPUT_LINES, char* components )
{
	for(int current_collum= 0; current_collum< collums[0 ]; current_collum++ )
	{
		for(int piece_counter=0; piece_counter< 3; piece_counter++ )
		{
			std::cout<<components[0 ];
		}
		std::cout<<components[1 ];
	}
	//Used to break the line.
	std::cout<<"" <<std::endl;
}

//Outputs the grid
void Game_Piece_Output_Grid(int* rows, int* collums, const int* OUTPUT_LINES, char* components, piece_identifier** game_board, Board_piece* Board_pieces )
{
	for(int current_layer= 0; current_layer< OUTPUT_LINES[0 ]; current_layer++ )
	{
		//Used to create each segment based on the number of collums.
		for(int current_collum= 0; current_collum< collums[0 ]; current_collum++ )
		{
			//Used to tell which output will be used.
			//switch(game_board[current_layer ][current_collum] )
			switch(game_board[0 ][0 ] )
			{
				case cross:
					//std::cout<<Board_pieces[nothing ].Get_Output()[current_layer ] <<components[0 ];
					std::cout<<Board_pieces[2 ].Get_Output()[current_layer ] <<components[0 ];
					break;

				case nought:
					//std::cout<<Board_pieces[nought ].Get_Output()[current_layer ] <<components[0 ];
					std::cout<<Board_pieces[1 ].Get_Output()[current_layer ] <<components[0 ];
					break;

				default:
					//std::cout<<Board_pieces[cross ].Get_Output()[current_layer ] <<components[0 ];
					std::cout<<Board_pieces[0 ].Get_Output()[current_layer ] <<components[0 ];
					//std::cout<<"___" <<components[0 ];
					break;
			}

		}
		std::cout<<"" <<std::endl;
	}
}

//Main Function for outputting the formatted game grid
void Game_Piece_Output_Block(int* rows, int* collums, const int* OUTPUT_LINES, char* components, piece_identifier** game_board, Board_piece* Board_pieces )
{
	//Top border creation
	Game_Piece_Output_Border(collums, OUTPUT_LINES, components );

	//Grid
	Game_Piece_Output_Grid(rows, collums, OUTPUT_LINES, components, game_board, Board_pieces);

	//Bottom Border.
	Game_Piece_Output_Border(collums, OUTPUT_LINES, components );
}


int main(void )
{
	//To keep track of the array's dimensions.
	int game_board_collums= 3;		
	int game_board_rows= 3;

	//Keep hold of the piece data.	-Passed in board piece type.
	Board_piece Nothing;
	Board_piece Nought(nought );
	Board_piece Cross(cross );

	//Used for passing the piece data between functions
	Board_piece* Board_pieces=new Board_piece[3 ];

	Board_pieces[0 ]= Nothing;
	Board_pieces[1 ]= Nought;
	Board_pieces[2 ]= Cross;


	//Stores how many lines the output has, used for printing.
	constexpr int OUTPUT_LINES= 3;

	//Used for spacing out the output for the program.
	std::string border_chunk= "XXX";
	char border_divider= '_';
	char space_character= 'X';

	char space_character_1= 'X';
	char divider_character='_';

	//
	char* border_array_pointer= new char[2 ];

	border_array_pointer[0 ]= space_character_1;
	border_array_pointer[1 ]= divider_character;

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
	
	//Set Default Values:
		//Used to access each row at a time.
	for(int setting_row= 0; setting_row< game_board_rows; setting_row++ )
	{
			//Used to access each element of the parent row.
		for(int setting_collum= 0; setting_collum< game_board_collums; setting_collum++ )
		{
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
		for(int current_layer= 0; current_layer< OUTPUT_LINES; current_layer++ )
		{
			//Used to print out each of the piece's layer, side by side, then break line.
			for(int output_collum= 0; output_collum< game_board_collums; output_collum++ )
			{
				//std::cout<< current_layer <<std::endl;
				switch(game_board[output_row ][output_collum ] )
				//switch(cross )
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
	}

	//End Border
	for(int border_row= 0; border_row< game_board_rows; border_row++ )
	{
		std::cout<<border_chunk <<border_divider;
	}

	std::cout<<"" <<std::endl;
	

	std::cout<<"Border test creation" << std::endl;

	/*//void Game_Piece_Output_Border(int* collums, int* OUTPUT_LINES, char* components )

	Game_Piece_Output_Border(&(game_board_collums ), &(OUTPUT_LINES ), border_array_pointer );
	std::cout<<"" <<std::endl;
	std::cout<<"Test string." <<std::endl;*/

//void Game_Piece_Output_Grid(int* rows, int* collums, const int* OUTPUT_LINES, char* components, piece_identifier** game_board, Board_piece* Board_pieces )
	Game_Piece_Output_Grid(&(game_board_rows ), &(game_board_collums ), &(OUTPUT_LINES ), border_array_pointer, game_board, Board_pieces );

//void Game_Piece_Output_Block(int* rows, int* collums, const int* OUTPUT_LINES, char* components, piece_identifier** game_board, Board_piece* Board_pieces )
	//Game_Piece_Output_Block(&(game_board_rows ), &(game_board_collums ), &(OUTPUT_LINES ), border_array_pointer, game_board, Board_pieces );

	delete[] border_array_pointer;
	border_array_pointer= NULL;

	//Cleans up the game_board itself.
	delete[] game_board;
	game_board= NULL;

	return 0;	
}