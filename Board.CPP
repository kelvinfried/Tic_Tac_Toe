#include "Board.H"

//Constructors
	//Default
	Board::Board(void )
	{
		//Rows
		rows= 3;

		//Collums 
		collums= 3;

		//Board
		//Declared from heap due to long life time and to be dynamic: Holds each of the rows,
		//so they can be accesed from a location. 
		board= new piece_identifier*[collums];
		//Declares the rows, Iterative approach to have a dynamic size during runtime.
		for(int creation_row= 0; creation_row< rows; creation_row ++ )
		{
			board[creation_row ]= new piece_identifier[collums];
		}

		//Border Parts ~Dya 
		char space_character= 'X';
		char divider_character='_';
		//To allow the spacing character to be passed into functions.
		border_parts= new char[2 ];
			//Declare
		border_parts[0 ]= space_character;
		border_parts[1 ]= divider_character;

		//Keyed Positions ~Dya
		int length= rows * 2;
		keyed_positions=new int[length ];
			//Set Default
		for(int x=0; x< length; x++ )
		{
			keyed_positions[x ]= -1;
		}
	};

	//Overloaded
	Board::Board(int input_rows, int input_collums )
	{
		//Rows
		rows= input_rows;

		//Collums 
		collums= input_collums;

		//Board
		//Declared from heap due to long life time and to be dynamic: Holds each of the rows,
		//so they can be accesed from a location. 
		board= new piece_identifier*[collums];
		//Declares the rows, Iterative approach to have a dynamic size during runtime.
		for(int creation_row= 0; creation_row< rows; creation_row ++ )
		{
			board[creation_row ]= new piece_identifier[collums];
		}

		//Border Parts ~Dya 
		char space_character= 'X';
		char divider_character='_';
		//To allow the spacing character to be passed into functions.
		border_parts= new char[2 ];
			//Declare
		border_parts[0 ]= space_character;
		border_parts[1 ]= divider_character;

		//Keyed Positions ~Dya
		int length= rows * 2;
		keyed_positions=new int[length ];
			//Set Default
		for(int x=0; x< length; x++ )
		{
			keyed_positions[x ]= -1;
		}
	};

//Destructors 
	Board::~Board(void )
	{
		//Clean board
		for(int x=0; x< rows; x++ )
		{
			delete[] board[x ];
		}
		board= NULL;

		delete[] border_parts;
		border_parts= NULL;

		delete[] keyed_positions;
		keyed_positions= NULL;
		
	}

//Public Functions
//-----------------------------------------Board Set Up Section:
//Creates the board and returns it.
piece_identifier** Board::Setup(void )
{
	board= new piece_identifier*[collums ];
		//Declares the rows, Iterative approach to have a dynamic size during runtime.
	for(int creation_row= 0; creation_row< rows; creation_row ++ )
	{
		board[creation_row ]= new piece_identifier[collums ];
	}

	return board;
}
//----------------------For Setting Defaults Across the board:
//Sets the default value for the entire board. -Takes in the board, and the number of rows, collums
void Board::Default(void )
{
	//Used to access each row at a time.
	for(int setting_row= 0; setting_row< rows; setting_row++ )
	{
		//Used to access each collum of the current row.
		for(int setting_collum= 0; setting_collum< collums; setting_collum++ )
		{
			board[setting_row ][setting_collum ]= nothing;
		}
	}
}

//Overloaded function, used to fill the board with the passed in piece type.
void Board::Default(Piece* piece )
{
	//Used to access each row at a time.
	for(int setting_row= 0; setting_row< rows; setting_row++ )
	{
		//Used to access each collum of the current row.
		for(int setting_collum= 0; setting_collum< collums; setting_collum++ )
		{
			board[setting_row ][setting_collum ]= piece[0 ].Get_Type()[0 ];
		}
	}
}

//----------------------For Board Expansion
//To add anoter row, the current row, overload_char is only for overloading. Used first.
void Board::Incriment_Row(void )
{
	rows++;
}

//To add another collum to the end.
void Board::Incriment_Collum(void )
{
	collums++;
}


//-----------------------------------------Board Size Management Section:
//----------------------Board Increase In Size:
//Rewritten expansion.
void Board::Expand(void )
{
	Incriment_Collum();
	Incriment_Row();

	//Create a new larger board
	piece_identifier** new_board= new piece_identifier*[collums ];
	for(int creation_row= 0; creation_row< rows; creation_row ++ )
	{
		//std::cout<<"Row number: " <<creation_row <<std::endl;
		//std::cout<<"" <<std::endl;
		new_board[creation_row ]= new piece_identifier[collums ];
	}


	//transfter then clean up
	int previous_rows= rows;
	previous_rows--;

	int previous_collums= collums;
	previous_collums--;

	/*std::cout<<"old rows is "<< previous_rows;
	std::cout<<"old collums is "<< previous_collums <<std::endl;
	std::cout<<"new rows is "<< rows;
	std::cout<<"new collums is "<< collums <<std::endl;*/

	for(int x= 0; x< rows; x++ )
	{
		for(int y= 0; y< collums; y++ )
		{
			if((x< previous_rows )&& (y< previous_collums ) )
			{
				/*std::cout<<"X is currently" <<x <<" against the previous x of: " <<previous_rows <<std::endl;
				std::cout<<"Y is currently: " <<y <<" against the previous Y of: " <<previous_collums <<std::endl;
				std::cout<<"9 times~" <<std::endl;*/
				new_board[x ][y ]= board[x ][y ];
			}

			else
			{
				//std::cout<<"7 times" <<std::endl;
				new_board[x ][y ]= nothing;
			}

			//Delete the row after it was copied
			if(x< previous_rows )
			{
				//std::cout<<"Delete" <<std::endl;
				//delete[] board[x ];
			}
			/*//When within the original range, copy values over
			if((x< previous_rows )|| (y< previous_rows ) )
			{
				std::cout<<"9 times~" <<std::endl;
				new_board[x ][y ]= board[x ][y ];
			}
			//Set default.
			else
			{
				std::cout<<"7 times" <<std::endl;
				new_board[x ][y ]= nothing;
			}*/
		}
	}
	board= new_board;
	//Null the pointer
	new_board= NULL;
}

//----------------------Board Decrease In Size:
//To delete a specified collum. //Used first
void Board::Deincriment_Collum(void )
{
	collums--;
}

void Board::Remove(void )
{
	//Updates the size tracking value 
	Deincriment_Collum();

	for(int current_row= 0; current_row< rows; current_row++ )
	{
		//I am unable to delete indivudal collum elements so they're just set to nothing.
			//To delete elemnents and rezise the array I seem to need to use vectors for this.
		board[current_row ][collums ]= nothing;
		//std::cout<<"nothing" <<std::endl;
	}
}

//To delete a specifed row
void Board::Deincriment_Row(void )
{
	rows--;
}

void Board::Remove(int current_row )
{
	//Updates the size tracking value 
	Deincriment_Row();

	//Delething rows is something I can do to save on memory when the parts are no longer being drawn.
	/*for(int current_collum= 0; current_collum< collums; current_collum++ )	{
		delete board[current_row ][current_collum ];
	}*/
	delete board[current_row ];
}

//Combines the two seperate deleting methods into one function.
void Board::Shrink(void )
{
	Remove();
	Remove(rows );
}


//-----------------------------------------Output Section:
//----------------------Output Segments:
//Outputs the board border.
void Board::Output_Border(void )
{
	//for iterating across the row
	for(int current_collum= 0; current_collum< collums; current_collum++ )
	{
		//Used to print out the middle spaces. Uses char unlike the string before.
		for(int middle= 0; middle< OUTPUT_LINES; middle++ )
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

//Outputs the passed in row of the board
void Board::Output_Row(Piece* Pieces, int* current_row )
{
	//Used to traverse between the 3 layers that the output is stored in.
	for(int current_layer= 0; current_layer< OUTPUT_LINES; current_layer++ )
	{
		//Used to determin how many pieces there are on on row.
		for(int current_collum= 0; current_collum< collums; current_collum++ )
		{
			//To tell which line of the piece it should use-Ended with a space 
			switch(board[current_row[0 ] ][current_collum] )
			{
				case cross:
					std::cout<<Pieces[cross ].Get_Output()[current_layer ] <<border_parts[0 ];
					break;

				case nought:
					std::cout<<Pieces[nought ].Get_Output()[current_layer ] <<border_parts[0 ];
					break;

				default:
					std::cout<<Pieces[nothing ].Get_Output()[current_layer ] <<border_parts[0 ];
					break;
			}
		}
		//Breaks the line for the next output statement.
		std::cout<<"" <<std::endl;
	}
}

//----------------------Outputs Whole:
void Board::Output(Piece* Pieces )
{
	//Main Part
	for(int current_row=0; current_row< rows; current_row++ )
	{
		//Top border creation
		Output_Border();

		//Grid Output Section:
		//Output_Row(&(current_row ), collums, OUTPUT_LINES, border_parts, board, Pieces );
		Output_Row(Pieces, &(current_row ) );
	}

	//Bottom Border.
	Output_Border();
}


//-----------------------------------------Input Handling Section:
//----------------------Handle Input:
//Test case weight against upper limit //Updated to have a bool return, to be used directly with if statments.
bool Board::Input_Sanitization(int* test_data, int* upper_limit )
{
	//Used to see if the test data is within the bounds of the array
		//Upper limit set to equal to so the player inputs value with a 1 index, rather than 0 to make it more intuitive.
	if((0< test_data[0 ] )&& (test_data[0 ] <=upper_limit[0 ] ) )
	{
		//Valid inputted number
		return true;
	}

	else
	{
		//Invalid number.
		return false;
	}
}

//To ensure that the insertion is valid before doing it.
bool Board::Insertion_Trial(int* current_row, int* current_collum )
{
	piece_identifier value_on_board= board[current_row[0 ] ][current_collum[0 ] ];
	std::cout<<"Value on board is: " <<value_on_board <<std::endl;

	//If there is nothing on the board in that place, allow the user to place their type of piece.
	if(value_on_board== nothing )
	{	
		//Allows for insertion.
		std::cout<<"true, there is not a placed piece on the board." <<std::endl;
		return true;
	}

	else 
	{
		std::cout<<"false, there is a placed piece on the board" <<std::endl;
		return false;
	}
}

//----------------------Draw Input to the board:
//The actual insertion into the board, incorporates the checks and if valid will draw onto the board.
void Board::Insertion(Piece* Piece, int* current_row, int* current_collum )
{
	//Input Checking First- Check attempted Row and Collum Against the boards bounds to see if it is valid.
	if((Input_Sanitization(current_row, &(rows ) ) )&& (Input_Sanitization(current_collum, &(collums ) ) ) )
	{
		//Offset the input to match board index;
		current_row[0 ]--;
		current_collum[0 ]--;

		//Insertion Checking, to see if it is valid on the board
		if(Insertion_Trial(current_row, current_collum ) )
		{
			//Writing the piece type to the board to be displayed.
			std::cout<<"Piece written to board index [" <<current_row <<", " <<current_collum <<std::endl;
			board[current_row[0 ] ][current_collum[0 ] ]= Piece[0 ].Get_Type()[0 ];
		}

		else	
		{
			std::cout<<"Insertion not valid, insertion denyed" <<std::endl;;
		}
	}

	else
	{
		std::cout<<"Insertion not valid, input out of range." <<std::endl;
	}
}