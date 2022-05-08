#include "Board.H"
//-----------------------------------------Board Set Up Section:
//----------------------For Setting Defaults Across the board:
//Sets the default value for the entire board. -Takes in the board, and the number of rows, collums
void Default(piece_identifier** board, int* rows, int* collums )
{
	//Used to access each row at a time.
	for(int setting_row= 0; setting_row< rows[0 ]; setting_row++ )
	{
		//Used to access each collum of the current row.
		for(int setting_collum= 0; setting_collum< collums[0 ]; setting_collum++ )
		{
			board[setting_row ][setting_collum ]= nothing;
		}
	}
}

//Overloaded function, used to fill the board with the passed in piece type.
void Default(piece_identifier** board, Piece* piece, int* rows, int* collums )
{
	//Used to access each row at a time.
	for(int setting_row= 0; setting_row< rows[0 ]; setting_row++ )
	{
		//Used to access each collum of the current row.
		for(int setting_collum= 0; setting_collum< collums[0 ]; setting_collum++ )
		{
			board[setting_row ][setting_collum ]= piece[0 ].Get_Type()[0 ];
		}
	}
}

//----------------------For Board Expansion
//To add anoter row, the current row, overload_char is only for overloading. Used first.
void Default(piece_identifier** board, int* rows, int* collums, char overload_char )
{
	//Used to access each element of the passed in row
	for(int setting_collum= 0; setting_collum< collums[0 ]; setting_collum++ )
	{
			board[rows[0 ] ][setting_collum ]= nothing;
	}

	//Incriment the value of row to keep it updated.
	rows[0 ]++;
}

//To add another collum to the end.
void Default(piece_identifier** board, int* rows, int* collums, int overload_int )
{
	//Extend exisiting dataset
	for(int setting_row= 0; setting_row< rows[0 ]; setting_row++ )
	{
		board[setting_row ][collums[0 ] ]= nothing;
	}
	//Incriment the value of the collum to keep it updated.
	collums[0 ]++;
}


//-----------------------------------------Board Size Management Section:
//----------------------Board Increase In Size:
//Used first, to add new collums to the board.
void New_Collum(piece_identifier** board, int* rows, int* collums )
{
	//Adds an extra collum to the end of each row, they're set to default. 
	Default(board, rows, collums, 1 );
}

//To add a new row to the board, row is set to nothing.
void New_Row(piece_identifier** board, int* rows, int* collums )
{
	//Create a new row in the array to address it
	board[rows[0 ] ]= new piece_identifier[collums[0 ] ];
	
	//Set new row to default.
	Default(board, rows, collums, 't' );
}

//Combines the two seperate expansion functions into on neat package.
void Expand(piece_identifier** board, int* rows, int* collums )
{
	New_Collum(board, rows, collums );
	New_Row(board, rows, collums );
}

//----------------------Board Decrease In Size:
//To delete a specified collum. //Used first
void Remove(piece_identifier** board, int* rows, int* collums )
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
void Remove(piece_identifier** board, int* rows)
{
	//Updates the size tracking value 
	rows[0 ]--;

	//Delething rows is something I can do to save on memory when the parts are no longer being drawn.
	delete board[rows[0 ] ];
}

//Combines the two seperate deleting methods into one function.
void Shrink(piece_identifier** board, int* rows, int* collums )
{
	Remove(board, rows, collums );
	Remove(board, rows );
}


//-----------------------------------------Output Section:
//----------------------Output Segments:
//Outputs the board border.
void Output_Border(int* collums, const int* OUTPUT_LINES, char* border_parts )
{
	//for iterating across the row
	for(int current_collum= 0; current_collum< collums[0 ]; current_collum++ )
	{
		//Used to print out the middle spaces. Uses char unlike the string before.
		for(int middle= 0; middle< OUTPUT_LINES[0 ]; middle++ )
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
void Output_Row(piece_identifier** board, Piece* Pieces, int* current_row, int* collums, const int* OUTPUT_LINES, char* border_parts )
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

//----------------------Outputs Whole:
void Output(piece_identifier** board, Piece* Pieces, int* rows, int* collums, const int* OUTPUT_LINES, char* border_parts  )
{
	//Main Part
	for(int current_row=0; current_row< rows[0 ]; current_row++ )
	{
		//Top border creation
		Output_Border(collums, OUTPUT_LINES, border_parts );

		//Grid Output Section:
		//Output_Row(&(current_row ), collums, OUTPUT_LINES, border_parts, board, Pieces );
		Output_Row(board, Pieces, &(current_row ), collums, OUTPUT_LINES, border_parts);
	}

	//Bottom Border.
	Output_Border(collums, OUTPUT_LINES, border_parts );
}


//-----------------------------------------Input Handling Section:
//----------------------Handle Input:
//Test case weight against upper limit //Updated to have a bool return, to be used directly with if statments.
bool Input_Sanitization(int* test_data, int* upper_limit )
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
bool Insertion_Trial(piece_identifier** board, int* current_row, int* current_collum )
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
void Insertion(piece_identifier** board, Piece* Piece, int* rows, int* collums, int* current_row, int* current_collum )
{
	//Input Checking First- Check attempted Row and Collum Against the boards bounds to see if it is valid.
	if((Input_Sanitization(current_row, rows ) )&& (Input_Sanitization(current_collum, collums ) ) )
	{
		//Offset the input to match board index;
		current_row[0 ]--;
		current_collum[0 ]--;

		//Insertion Checking, to see if it is valid on the board
		if(Insertion_Trial(board, current_row, current_collum ) )
		{
			//Writing the piece type to the board to be displayed.
			std::cout<<"Piece written to board index [" <<current_row[0 ] <<", " <<current_collum[0 ] <<std::endl;
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

//-----------------------------------------Clean Up:
//To Destory the board.
void Wipe(piece_identifier** board, int* rows )
{
	for(int row_to_delete= 0; row_to_delete< rows[0 ]; row_to_delete ++ )
	{
		delete board[row_to_delete ];
	}
}

int main(void )
{
	//To keep track of the array's dimensions.
	int collums= 3;		
	int rows= 3;

	//Keep hold of the piece data.	-Passed in board piece type.
	Piece Nothing;
	Piece Nought(nought );
	Piece Cross(cross );

//Assing one of these to the player class.
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
	char* border_parts= new char[2 ];
	//Declare
		border_parts[0 ]= space_character;
		border_parts[1 ]= divider_character;

//Declared from heap due to long life time and to be dynamic: Holds each of the rows, so they can be accesed from a single part
	piece_identifier** board= new piece_identifier*[collums ];
		//Declares the rows, Iterative approach to have a dynamic size during runtime.
	for(int creation_row= 0; creation_row< rows; creation_row ++ )
	{
		board[creation_row ]= new piece_identifier[collums ];
	}

/*//Test 1 Output- Then extend and output.
	//Set default board values
	Default(board, &(rows ), &(collums ) );

	std::cout<<"Size 1 is: " <<std::endl;
	Output(board, Pieces, &(rows ), &(collums ), &(OUTPUT_LINES ), border_parts );

	std::cout<<"" <<std::endl;
	std::cout<<"Size 0 is: " <<std::endl;
	Shrink(board, &(rows ), &(collums ) );
	Output(board, Pieces, &(rows ), &(collums ), &(OUTPUT_LINES ), border_parts );

	std::cout<<"" <<std::endl;
	std::cout<<"Size 2 is: " <<std::endl;
	Expand(board, &(rows ), &(collums ) );
	Expand(board, &(rows ), &(collums ) );
	Output(board, Pieces, &(rows ), &(collums ), &(OUTPUT_LINES ), border_parts );*/

//Test 2 Input sanitization/ Main input loop trial.
	Default(board, &(rows ), &(collums ) );

	bool loop= true;

	int input= 0;
	int input_1= 0;

	Piece Piece(cross );

	while(loop )
	{
		std::cout<<"Enter two inputs seperated by a single space" <<std::endl;
		std::cin>>input >>input_1;
		
		//std::cout<<"Input 1 is: " <<input <<" Input 2 is: " <<input_1 <<std::endl;

		switch(input )
		{
			case 99:
				Insertion(board, &(Piece ), &(rows ), &(collums ), &(input ), &(input_1 ) );
				Output(board, Pieces, &(rows ), &(collums ), &(OUTPUT_LINES ), border_parts );
				break;

			case 2:
				std::cout<<"Expand dong" <<std::endl;
				Expand(board, &(rows ), &(collums ) );
				Insertion(board, &(Piece ), &(rows ), &(collums ), &(input ), &(input_1 ) );
				Output(board, Pieces, &(rows ), &(collums ), &(OUTPUT_LINES ), border_parts );
				break;

			case 1:
			case 3:
			case 4:
				Insertion(board, &(Piece ), &(rows ), &(collums ), &(input ), &(input_1 ) );
				Output(board, Pieces, &(rows ), &(collums ), &(OUTPUT_LINES ), border_parts );
				break;

			default:
				std::cout<<"Exit clause" <<std::endl;
				loop= false; 
				break;
		}

		/*if(input!= 99 )
		{
			Insertion(board, &(Piece ), &(rows ), &(collums ), &(input ), &(input_1 ) );
			Output(board, Pieces, &(rows ), &(collums ), &(OUTPUT_LINES ), border_parts );
		}

		else if( (input!= 99 )&& (input== 2 ) )
		{
			std::cout<<"Expand dong" <<std::endl;
			Expand(board, &(rows ), &(collums ) );
			Insertion(board, &(Piece ), &(rows ), &(collums ), &(input ), &(input_1 ) );
			Output(board, Pieces, &(rows ), &(collums ), &(OUTPUT_LINES ), border_parts );
		}

		else		
		{
			std::cout<<"Exit clause" <<std::endl;
			loop= false; 
		}*/

	}

	Wipe(board, &(rows ) );

	return 0;
}