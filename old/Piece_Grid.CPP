//Tic Tac Toe Array "Grd" Setup code and testing stuff from in person lesson.
#include "Piece.CPP"

//Function names are placeholders
//Sets the defualt values of the entire board.
void Default(int* rows, int* collums, piece_identifier** board )
{
	//Used to access each row at a time.
	for(int setting_row= 0; setting_row< rows[0 ]; setting_row++ )
	{
		//Used to access each element of the parent row.
		for(int setting_collum= 0; setting_collum< collums[0 ]; setting_collum++ )
		{
			board[setting_row ][setting_collum ]= nothing;
		}
	}
}

//Sets the defualt values for a row
void Default(int* current_row, int* collums, piece_identifier** board, char overload_char )
{
	//Used to access each element of the passed in row
	for(int setting_collum= 0; setting_collum< collums[0 ]; setting_collum++ )
	{
			board[current_row[0 ] ][setting_collum ]= nothing;
	}

	//Incriment the value of row to keep it updated.
	current_row[0 ]++;
}

//Overloaded function, used to put custom pieces  on the map
void Default(int* rows, int* collums, piece_identifier** board, Board_piece piece )
{
	//Used to access each row at a time.
	for(int setting_row= 0; setting_row< rows[0 ]; setting_row++ )
	{
		//Used to access each element of the parent row.
		for(int setting_collum= 0; setting_collum< collums[0 ]; setting_collum++ )
		{
			board[setting_row ][setting_collum ]= piece.Get_Type()[0 ];
		}
	}
}

//To add a new row to the function, only updates the new row.
void New_Row(int* rows, int* collums, piece_identifier** board )
{
	//Create a new row
	board[rows[0 ] ]= new piece_identifier[collums[0 ] ];
	
	//Set new row to default.
	//void Game_Piece_Default(int* rows, int* collums, piece_identifier** game_board, char overload_char )
	Default(rows, collums, board, 't' );
}


//Output Section:
//Outputs the grid border.
void Output_Border(int* collums, const int* OUTPUT_LINES, char* border_parts )
{
	//for iterating across the row
	for(int current_collum= 0; current_collum< collums[0 ]; current_collum++ )
	{
		//Used to print out the middle spaces. Uses char unlike the string before.
		for(int middle= 0; middle< 3; middle++ )
		{
			//Middle part
			std::cout<<border_parts[0 ];
		}
		//Spacer segment
		std::cout<<border_parts[1 ];
	}
	//Used to break the line for the next function.
	std::cout<<"" <<std::endl;
}

//Outputs the row of the game grid passed in.
void Output_Row(int* current_row, int* collums, const int* OUTPUT_LINES, char* border_parts, piece_identifier** board, Piece* piece )
{
	//Used to traverse between the 3 layers that the output is stored in.
	for(int current_layer= 0; current_layer< OUTPUT_LINES[0 ]; current_layer++ )
	{
		//Used to determin how many pieces there are on on row.
		for(int current_collum= 0; current_collum< collums[0 ]; current_collum++ )
		{
			//To tell which line of the piece it should use-Ended with a space 
			switch(board[current_row[0 ] ][current_collum] )
			{
				case cross:
					std::cout<<piece[cross ].Get_Output()[current_layer ] <<border_parts[0 ];
					break;

				case nought:
					std::cout<<Board_pieces[nought ].Get_Output()[current_layer ] <<border_parts[0 ];
					break;

				default:
					std::cout<<Board_pieces[nothing ].Get_Output()[current_layer ] <<border_parts[0 ];
					break;
			}
		}
		//Breaks the line for the next output statement.
		std::cout<<"" <<std::endl;
	}
}

//Main Function for outputting the formatted game grid
void Output(int* rows, int* collums, const int* OUTPUT_LINES, char* border_parts, piece_identifier** game_board, Board_piece* piece )
{
	//Main Part
	for(int current_row=0; current_row< rows[0 ]; current_row++ )
	{
		//Top border creation
		Output_Border(collums, OUTPUT_LINES, border_parts );

		//Grid Output Section:
		Output_Row(&(current_row ), collums, OUTPUT_LINES, border_parts, game_board, Board_piece* piece);
	}

	//Bottom Border.
	Output_Border(collums, OUTPUT_LINES, border_parts );
}


int main(void )
{
	//To keep track of the array's dimensions.
	int board_collums= 3;		
	int board_rows= 3;

	//Keep hold of the piece data.	-Passed in board piece type.
	Piece Nothing;
	Piece Nought(nought );
	Piece Cross(cross );

	//Used for passing the piece data between functions
	Piece* Pieces=new Piece[3 ];
	//Assigning the values.
		Pieces[0 ]= Nothing;
		Pieces[1 ]= Nought;
		Pieces[2 ]= Cross;

	//Stores how many lines the board piece output has, used for printing.
	constexpr int OUTPUT_LINES= 3;

	//Used for spacing out the output for the program.
	char space_character= 'X';
	char divider_character='_';

	//To allow the spacing character to be passed into functions.
	char* border_array= new char[2 ];
	//Declaire
		border_array[0 ]= space_character;
		border_array[1 ]= divider_character;

	//Declared from heap due to long life time and to be dynamic: Holds each of the rows, so they can be accesed from a single part
	piece_identifier** board= new piece_identifier*[board_collums ];
		//Declares the rows. 
		//Iterative approach to have a dynamic size during runtime.
	for( int creation_row= 0; creation_row< game_board_rows; creation_row++ )
	{
		board[creation_row ]= new piece_identifier[board_collums ];
	}

	/*//void Game_Piece_Output_Border(int* collums, int* OUTPUT_LINES, char* components )

	Game_Piece_Output_Border(&(game_board_collums ), &(OUTPUT_LINES ), border_array_pointer );
	std::cout<<"" <<std::endl;
	std::cout<<"Test string." <<std::endl;*/

//void Game_Piece_Output_Grid(int* rows, int* collums, const int* OUTPUT_LINES, char* components, piece_identifier** game_board, Board_piece* Board_pieces )
//void Game_Piece_Output_Grid_Row(int* current_row, int* collums, const int* OUTPUT_LINES, char* components, piece_identifier** game_board, Board_piece* Board_pieces )
	//int two= 2;
	//Game_Piece_Output_Grid_Row(&(two ), &(game_board_collums ), &(OUTPUT_LINES ), border_array_pointer, game_board, Board_pieces );

//void Game_Piece_Output_Block(int* rows, int* collums, const int* OUTPUT1_LINES, char* components, piece_identifier** game_board, Board_piece* Board_pieces )
	//Game_Piece_Output_Block(&(game_board_rows ), &(game_board_collums ), &(OUTPUT_LINES ), border_array_pointer, game_board, Board_pieces );

//void Game_Piece_Output_Block(int* rows, int* collums, const int* OUTPUT_LINES, char* components, piece_identifier** game_board, Board_piece* Board_pieces )
	//Game_Piece_Output_Block(&(game_board_collums ), &(game_board_rows ), &(OUTPUT_LINES ), border_array_pointer, game_board, Board_pieces );

//void Game_Piece_Default(int* rows, int* collums, piece_identifier** game_board )
	/*Game_Piece_Default(&(game_board_rows ), &(game_board_collums ), game_board, Cross );
	std::cout<<"Before:" <<std::endl;
	Game_Piece_Output_Block(&(game_board_collums ), &(game_board_rows ), &(OUTPUT_LINES ), border_array_pointer, game_board, Board_pieces );


//void Game_Piece_New_Row(int* rows, int* collums, piece_identifier** game_board, Board_piece* Board_pieces)
	Game_Piece_New_Row(&(game_board_rows ), &(game_board_collums ), game_board, Board_pieces );

	//Game_Piece_Default(&(game_board_rows ), &(game_board_collums ), game_board, 't' );

	std::cout<<"" <<std::endl;
	std::cout<<"After, rows is equal to= " <<game_board_rows <<std::endl;
//void Game_Piece_New_Row(int* rows, int* collums, piece_identifier** game_board, Board_piece* Board_pieces)
	Game_Piece_Output_Block(&(game_board_collums ), &(game_board_rows ), &(OUTPUT_LINES ), border_array_pointer, game_board, Board_pieces );*/
 

	delete[] border_array_pointer;
	border_array_pointer= NULL;

	//Cleans up the game_board itself.
	delete[] game_board;
	game_board= NULL;

	return 0;	
}