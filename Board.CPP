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

		//Output('t');
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
//-----------------------------------------Getters:
//Used to pass these values in to other areas used later on in the game.
int Board::Get_Rows(void )
{
	return rows;
}

int Board::Get_Collums(void )
{
	return collums;
}


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
			//std::cout<<"Row is: " <<setting_row <<" Collum is: " <<setting_collum <<std::endl;
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
	if((rows!=5 )|| (collums!= 5) )
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
			}
		}

		for(int z= 0; z< previous_rows; z++ )
		{
			//std::cout<<"Delete: row number" <<z <<std::endl;
			delete[] board[z ];
		}

		board= new_board;
		//Null the pointer
		new_board= NULL;
	}

	else
	{
		std::cout<<"Invlaid Grow." <<std::endl;
	}
}

//----------------------Board Decrease In Size:
//To delete a specified collum. //Used first
void Board::Deincriment_Collum(void )
{
	collums--;
}

//To delete a specifed row
void Board::Deincriment_Row(void )
{
	rows--;
}


//Combines the two seperate deleting methods into one function.
void Board::Shrink(void )
{
	if((rows!= 2 )|| (collums!= 2 ) )
	{
		Deincriment_Collum();
		Deincriment_Row();

		//Create a smaller board
		piece_identifier** new_board= new piece_identifier*[collums ];
		for(int creation_row= 0; creation_row< rows; creation_row ++ )
		{
			//std::cout<<"Row number: " <<creation_row <<std::endl;
			//std::cout<<"" <<std::endl;
			new_board[creation_row ]= new piece_identifier[collums ];
		}


		//transfter then clean up
		int previous_rows= rows;
		previous_rows++;

		for(int x= 0; x< rows; x++ )
		{
			for(int y= 0;y< collums; y++ )
			{
				new_board[x ][y ]= board[x ][y ];
			}
		}

		for(int x= 0; x< previous_rows; x++ )
		{
			delete[] board[x ];
		}
		

		board= new_board;
		//Null the pointer
		new_board= NULL;
	}

	else
	{
		std::cout<<"Invlaid shrink." <<std::endl;
	}
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

				case nothing:
					std::cout<<Pieces[nothing ].Get_Output()[current_layer ] <<border_parts[0 ];
					break;

				default:
					std::cout<<"Invalid";
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
bool Board::Input_Sanitization(int* test_data, int* upper_limit )
{
	//Used to see if the test data is within the bounds of the array
		//Upper limit set to equal to so the player inputs value with a 1 index, rather than 0 to make it more intuitive.
	if((-1< test_data[0 ] )&& (test_data[0 ] <upper_limit[0 ] ) )
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
//overloaded
//Test case weight against upper limit //Updated to have a bool return, to be used directly with if statments.
bool Board::Input_Sanitization(int* test_data, int* upper_limit, char overload_char )
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
	//std::cout<<"Value on board is: " <<value_on_board <<std::endl;

	//If there is nothing on the board in that place, allow the user to place their type of piece.
	if(value_on_board== nothing )
	{	
		//Allows for insertion.
		//std::cout<<"true, there is not a placed piece on the board." <<std::endl;
		return true;
	}

	else 
	{
		//std::cout<<"false, there is a placed piece on the board" <<std::endl;
		return false;
	}
}

//----------------------Draw Input to the board:
//The actual insertion into the board, incorporates the checks and if valid will draw onto the board.
void Board::Insertion(Piece* Piece, int* current_row, int* current_collum )
{
	std::cout<<"Placing pieces:" <<current_row[0 ] <<" and " <<current_collum[0 ] <<std::endl;
	//Input Checking First- Check attempted Row and Collum Against the boards bounds to see if it is valid.
	bool check_1= Input_Sanitization(current_row, &(rows ), true);
	bool check_2= Input_Sanitization(current_collum, &(collums ), true );

	if(check_1 && check_2 )
	{
		//Offset the input to match board index;
		int current_row_1= current_row[0 ];
		current_row_1--;

		int current_collum_1= current_collum[0 ];
		current_collum_1--;

		//Insertion Checking, to see if it is valid on the board
		if(Insertion_Trial(&(current_row_1 ), &(current_collum_1 ) ) )
		{
			//Writing the piece type to the board to be displayed.
			//std::cout<<"Piece written to board index [" <<current_row_1 <<", " <<current_collum_1 <<"]" <<std::endl;
			board[current_row_1 ][current_collum_1 ]= Piece[0 ].Get_Type()[0 ];
		}

		else	
		{
			std::cout<<"Insertion not valid for numbers: " <<current_row[0 ] <<" and "<<current_collum[0 ] <<std::endl;
		}
	}

	else
	{
		//std::cout<<"Out of range for: " <<current_row[0 ] <<" and "<<current_collum[0 ] <<std::endl;
	}
}


//-----------------------------------------Tracking Array Set Up Section:
//----------------------For Setting Defaults Across the board:
//To clean out the int Arry and reset its value.
void Board::Default(bool overload_bool )
{
	int length= 2* rows;

	for(int x= 0; x< length; x++ )
	{
		//Set to minus one to not cause any conflicts when adding a 0, 0 array position; shows an element is defualt.
		keyed_positions[x ]= -1;
	}
}


//-----------------------------------------Array Size Management Section:
//Called before the Expand function so the correct row value is passed into the function.
void Board::Expand(char overload_char )
{
	int length= rows;
	length*= 2;

	//Create a smaller array
	int* new_array= new int[length ];


	//transfter then clean up
	int previous_length= length;
	previous_length-= 2;

	for(int x= 0; x< length; x++ )
	{
		//Transfer old ones over
		if(x< previous_length )
		{
			new_array[x ]= keyed_positions[x ];
		}

		//Set default for new ones.
		else
		{
			new_array[x ]= -1;
		}
	}
	//Clean up and adjust points.
	delete[] keyed_positions;
	
	keyed_positions= new_array;
	//Null the pointer
	new_array= NULL;
}

//Called before the Expand function so the correct row value is passed into the function.
void Board::Shrink(char overload_char )
{
	//Fetch current size to figure out how many elements are required.
	int length= rows;
	length*= 2;

	//Create a smaller array
	int* new_array= new int[length ];

	//transfter then clean up
	int previous_length= rows;
	previous_length+= 2;

	for(int x= 0; x< length; x++ )
	{
		new_array[x ]= keyed_positions[x ];
	}
	//Clean up and adjust points.
	delete[] keyed_positions;
	
	keyed_positions= new_array;
	//Null the pointer
	new_array= NULL;
}


//-----------------------------------------Output Section:
//----------------------Output Segments:
void Board::Output(char overload_char )
{
	std::cout<<"" <<std::endl;
	std::cout<<"Keyed_Output" <<std::endl;
	
	int counter= 0;
	int current_collum= 0;
	int current_row= 0;

	int length= rows;
	length*= 2;

	for(int x=0; x< length; x+= 2 )
	{
		counter++;

		current_row= x;

		current_collum= current_row;
		current_collum++;

		std::cout<<"The '" <<counter <<"' has a value of:";
		std::cout<<keyed_positions[current_row ] <<" and " <<keyed_positions[current_collum ] <<std::endl;
	}
}

//-----------------------------------------Array Insertion/ Input:
//Input was checked before so its not needed. Now inputs are checked against the array to see if it already has been index to not count it again.
bool Board::Insertion_Check(int* current_row, int* current_collum )
{
	//Used to not modify the iterative value.
	int array_value_x, array_value_y;
	int check_1, check_2;

	int length= rows;
	length*= 2;

	//To iterate the lenght of the 
	for(int element= 0; element< length; element +=2 )
	{
		array_value_x= element;
		array_value_y= array_value_x;
		array_value_y++;

		check_1=  keyed_positions[array_value_x ];
		check_2= keyed_positions[array_value_y ];

		//Match found exit
		if((current_row[0 ]== check_1 )&& (current_collum[0 ]== check_2 ) )
		{
			//A match was found so therefore the input is invalid from the game board.
			return false;
		}
		
		else
		{
		}
	}
	//Moved this to not make the check die early as it returns a value - Used to say there are no mathces from the array
	return true;
}

//Used for inserting the value into the correct slot.
void Board::Insertion(int* current_row, int* current_collum, int* points_so_far )
{
	//Insert the value in the next free slot.
	//Next free slot is points so far * 2; Then ++ for the second value.
	int element, element_1;

	//To not divide by 0
	switch(points_so_far[0 ] )
	{
		case 0:
			element= 0;
			break;

		default:
			element= points_so_far[0 ];
			element*= 2;
			break;
	}
	//Set values to be passed into the array for placement
	element_1= element;
	element_1++;

	keyed_positions[element ]= current_row[0 ];
	keyed_positions[element_1 ]= current_collum[0 ];
	//std::cout<<"Elment is: " <<element <<" Elment 1 is: " <<element_1 <<std::endl;
}

//Used to above functions to create one function way for check and insertion.
void Board::Commit(int* current_row, int* current_collum, int* points_so_far )
{
	bool check= Insertion_Check(current_row, current_collum );

	if(check )
	{
		Insertion(current_row, current_collum, points_so_far );
		//Incriments points to update it for the next value to be passed in.
		points_so_far[0 ]++;
		//std::cout<<"incriment point" <<std::endl;

		//Output('t' );
	}

	else
	{
		;
	}
}

//-----------------------------------------Win Checks:
//Note input must be handeled before it is passed
//Horizontal_Check for if the player has placed "row" number of their pieces in a row on the collums.
void Board::Vertical_Check(int* start_row, int* start_collum, Piece* Piece, int* points_so_far )
{	
	//Out of "Board" Bounds check;
	bool bound_check= Input_Sanitization(start_row, &(rows ) );

	//In the Boards Bounds 
	if(bound_check )
	{
		//Reads the piece on the board
		piece_identifier board_piece= board[(start_row[0 ] ) ][(start_collum[0 ] ) ];

		//Checks if the piece on the board is the same as the one passed in by the player.
		if(board_piece== Piece->Get_Type()[0 ] )
		{
			//Stores function output.
			bool commit_test= Insertion_Check(start_row, start_collum );
			//Check to see if the piece is valid against the previously keyed pieces.
			if(commit_test )
			{
				//Begin commit into the board.
				Commit(start_row, start_collum, points_so_far );
				

				//offset vairables 
				int next_row= start_row[0 ];
				next_row++;

				int previous_row= start_row[0 ];
				previous_row--;

				std::cout<<"Called next set" <<std::endl;
				Vertical_Check(&(next_row ), start_collum, Piece, points_so_far );
				Vertical_Check(&(previous_row ), start_collum, Piece, points_so_far );
			}

			else
			{
				std::cout<<"Test commit failed: " <<std::endl;
			}
		}

		//If the piece type does not match
		else
		{
			std::cout<<"Piece value does not match, board: " <<board_piece <<" while player input is: " <<Piece->Get_Type()[0 ] <<std::endl;
		}
	}
	
	//Outside of the Board Bounds.
	else
	{
		std::cout<<start_row[0 ] <<" is out of bounds." <<std::endl;
	}
}

//Vertical check, for checking  if the player has placed "row" number of theur pieces in a collum on the rows;
void Board::Horizontal_Check(int* start_row, int* start_collum, Piece* Piece, int* points_so_far, char overload_char )
{
	//Out of "Board" Bounds check;
	bool bound_check= Input_Sanitization(start_collum, &(collums ) );

	//In the Boards Bounds 
	if(bound_check )
	{
		//Reads the piece on the board
		piece_identifier board_piece= board[(start_row[0 ] ) ][(start_collum[0 ] ) ];

		//Checks if the piece on the board is the same as the one passed in by the player.
		if(board_piece== Piece->Get_Type()[0 ] )
		{
			//Stores function output.
			bool commit_test= Insertion_Check(start_row, start_collum );
			//Check to see if the piece is valid against the previously keyed pieces.
			if(commit_test )
			{
				//Begin commit into the board.
				Commit(start_row, start_collum, points_so_far );
				

				//offset vairables 
				int next_collum= start_collum[0 ];
				next_collum++;

				int previous_collum= start_collum[0 ];
				previous_collum--;

				std::cout<<"Called next set" <<std::endl;
				Horizontal_Check(start_row, &(next_collum ), Piece, points_so_far, 't' );
				Horizontal_Check(start_row, &(previous_collum ), Piece, points_so_far, 't' );
			}

			else
			{
				std::cout<<"Test commit failed: " <<std::endl;
			}
		}

		//If the piece type does not match
		else
		{
			std::cout<<"Piece value does not match, board: " <<board_piece <<" while player input is: " <<Piece->Get_Type()[0 ] <<std::endl;
		}
	}
	
	//Outside of the Board Bounds.
	else
	{
		std::cout<<start_collum[0 ] <<" is out of bounds." <<std::endl;
	}
}

//Linear check, checks for diagonals. i.e x -> y or y -> x
void Board::Linear_Check(int* start_row, int* start_collum, Piece* Piece, int* points_so_far )
{
	//Out of "Board" bounds check:
	bool bound_check_x= Input_Sanitization(start_row, &(rows ) );
	bool bound_check_y= Input_Sanitization(start_collum, &(collums ) );

	//In the boards bounds
	if(bound_check_x && bound_check_y )
	{
		//Reads the piece on the board
		piece_identifier board_piece= board[(start_row[ 0 ] ) ][(start_collum[0 ] ) ];

		//Checks if the piece on the board is the same as the one passed in by the player.
		if(board_piece== Piece->Get_Type()[0 ] )
		{
			//Stores function output.
			bool commit_test= Insertion_Check(start_row, start_collum );

			if(commit_test )
			{
				//Begin commit into the board.
				Commit(start_row, start_collum, points_so_far );

				//offset vairables 
					//"Forward"
				int next_row= start_row[0 ];
				next_row++;

				int next_collum= start_collum[0 ];
				next_collum++;

					//"Backwards"
				int previous_row= start_row[0 ];
				previous_row--;

				int previous_collum= start_collum[0 ];
				previous_collum--;

				std::cout<<"Called next set" <<std::endl;
				Linear_Check(&(next_row ), &(next_collum ), Piece, points_so_far );
				Linear_Check(&(previous_row ), &(previous_collum ), Piece, points_so_far );
			}
			
			else
			{
				std::cout<<"Test commit failed: " <<std::endl;
			}
		}

		else
		{
			std::cout<<"Piece value does not match, board: " <<board_piece <<" while player input is: " <<Piece->Get_Type()[0 ] <<std::endl;
		}
	}
		
	//Outside of the boards bound:
	else
	{
		std::cout<<start_row[0 ] <<", " <<start_collum[0 ] <<" is out of bounds." <<std::endl;
	}
}

//Linear check, checks for diagonals. i.e y -> x and reverse
void Board::Linear_Check(int* start_row, int* start_collum, Piece* Piece, int* points_so_far, char overload_char )
{
	//Out of "Board" bounds check:
	bool bound_check_x= Input_Sanitization(start_row, &(rows ) );
	bool bound_check_y= Input_Sanitization(start_collum, &(collums ) );

	//In the boards bounds
	if(bound_check_x && bound_check_y )
	{
		//Reads the piece on the board
		piece_identifier board_piece= board[(start_row[ 0 ] ) ][(start_collum[0 ] ) ];

		//Checks if the piece on the board is the same as the one passed in by the player.
		if(board_piece== Piece->Get_Type()[0 ] )
		{
			//Stores function output.
			bool commit_test= Insertion_Check(start_row, start_collum );

			if(commit_test )
			{
				//Begin commit into the board.
				Commit(start_row, start_collum, points_so_far );

				//offset vairables 
					//"Forward"
				int next_row= start_row[0 ];
				next_row++;

				int next_collum= start_collum[0 ];
				next_collum++;

					//"Backwards"
				int previous_row= start_row[0 ];
				previous_row--;

				int previous_collum= start_collum[0 ];
				previous_collum--;

				std::cout<<"Called next set" <<std::endl;
				Linear_Check(&(previous_row ), &(next_collum ), Piece, points_so_far, 't' );
				Linear_Check(&(next_row ), &(previous_collum ), Piece, points_so_far, 't' );
			}
			
			else
			{
				std::cout<<"Test commit failed: " <<std::endl;
			}
		}

		else
		{
			std::cout<<"Piece value does not match, board: " <<board_piece <<" while player input is: " <<Piece->Get_Type()[0 ] <<std::endl;
		}
	}
		
	//Outside of the boards bound:
	else
	{
		std::cout<<start_row[0 ] <<", " <<start_collum[0 ] <<" is out of bounds." <<std::endl;
	}
}

//Combines all the checks into one function with additional information.
void Board::Check(int* start_row, int* start_collum, Piece piece, int* points_so_far, char overload_char )
{
}
