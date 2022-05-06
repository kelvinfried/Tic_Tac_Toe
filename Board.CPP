#include "Board.H"
//-----------------------------------------Set Up Section:
//Sets the default value for the entire board.
//Takes in the number of rows, collums and the board itself to write to
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

//Overloaded function, used to fill the board with the passed in piece type.
void Default(int* rows, int* collums, piece_identifier** board, Piece piece )
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

//Next two are used for when the board expands
//Used to set the default values for a specified row
//Pass in current row which is the current upper limit of the array, overload_char is only to allow you to overload the function to call it.
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

//Sets the default value for a collum 
void Default(int* rows, int* collums, piece_identifier** board, int overload_int )
{
	//Extend exisiting dataset
	for(int setting_row= 0; setting_row< rows[0 ]; setting_row++ )
	{
		board[setting_row ][collums[0 ] ]= nothing;
	}

	collums[0 ]++;
}


//-----------------------------------------Size Management Section:
//Used first, to add new collums; Then we add a new row so the same width is used.
void New_Collum(int* rows, int* collums, piece_identifier** board )
{
	//Set new row to default.
	Default(rows, collums, board, 1 );
}

//To add a new row to the board, row is set to nothing.
void New_Row(int* rows, int* collums, piece_identifier** board )
{
	//Create a new row
	board[rows[0 ] ]= new piece_identifier[collums[0 ] ];
	
	//Set new row to default.
	Default(rows, collums, board, 't' );
}

//Combines the two seperate expansion functions into on neat package.
void Expand(int* rows, int* collums, piece_identifier** board )
{
	New_Collum(rows, collums, board );
	New_Row(rows, collums, board );
}

//To delete a specified collum. //USed first
void Remove_Collum(int* rows, int* collums, piece_identifier** board )
{
	//Updates the size tracking value 
	collums[0 ]--;

	for(int current_row= 0; current_row< rows[0 ]; current_row++ )
	{
		//I am unable to delete indivudal collum elements so they're just set to nothing.
			//To delete elemnents and rezise the array I seem to need to use vectors for this.
		//delete board[current_row ][collums[0 ] ];
		board[current_row ][collums[0 ] ]= nothing;
	}
}

//To delete a specifed row
void Remove_Row(int* rows, int* collums, piece_identifier** board )
{
	rows[0 ]--;

	//Delething rows is something I can do to save on memory when the parts are no longer being drawn.
	delete board[rows[0 ] ];
}

//Combines the two seperate deleting methods into one function.
void Shrink(int* rows, int* collums, piece_identifier** board)
{
	Remove_Collum(rows, collums, board );
	Remove_Row(rows, collums, board );
}


//-----------------------------------------Output Section:
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
void Output_Row(int* current_row, int* collums, const int* OUTPUT_LINES, char* border_parts, piece_identifier** board, Piece* Pieces )
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

//Main Function for outputting the formatted game grid
void Output(int* rows, int* collums, const int* OUTPUT_LINES, char* border_parts, piece_identifier** board, Piece* Pieces )
{
	//Main Part
	for(int current_row=0; current_row< rows[0 ]; current_row++ )
	{
		//Top border creation
		Output_Border(collums, OUTPUT_LINES, border_parts );

		//Grid Output Section:
		Output_Row(&(current_row ), collums, OUTPUT_LINES, border_parts, board, Pieces );
	}

	//Bottom Border.
	Output_Border(collums, OUTPUT_LINES, border_parts );
}


//-----------------------------------------Input Handling Section:
//Generic input sanitization: //Updated to be a bool value returned so it can be used directly with the if statment.
bool Input_Sanitization(int* test_data, int* test_case )
{
	//Used to see if the test case is within the bounds of the array
	if((0< test_case[0 ] )&& (test_case[0 ]<= test_data[0 ] ) )
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
bool Insertion_Trial(int* row, int* collum, piece_identifier** board, Piece piece )
{
	piece_identifier current_value= board[row[0 ] ][collum[0 ] ];

	//If there is nothing on the board in that place, allow the user to place their type of piece.
	if(current_value== nothing )
	{	
		//Allows for insertion.
		std::cout<<"true" <<std::endl;
		return true;
	}

	else 
	{
		std::cout<<"false" <<std::endl;
		return false;
	}
}

//The actual insertion into the board, incorporates the checks and if valid will draw onto the board.
void Insertion(int* row, int* collum, piece_identifier** board, Piece piece )
{
	//To check if the insertion is valid.
	bool check= Insertion_Trial(row, collum, board, piece );

	if(check )
	{
		//Writing the piece type to the board to be displayed.
		board[row[0 ] ][collum[0 ] ]= piece.Get_Type()[0 ];
	}

	else
	{
		//Not valid.
	}
}

//-----------------------------------------Clean Up:
//To Destory the board.
void Board_Wipe(int* rows, piece_identifier** array )
{
	for(int deletion= 0; deletion< rows[0 ]; deletion ++ )
	{
		delete array[deletion ];
	}
}