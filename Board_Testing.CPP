//Tic Tac Toe Array "Grd" Setup code and testing stuff from in person lesson.
#include "Board.CPP"
//-----------------------------------------Tracking Array Set Up Section:
//Creates the array and (also sets default values) returns it.
int* Setup(int* keyed_positions, int* rows )
{
	/*//Used to keep track of the length of the 
	//int keyed_length= 2* board_collums; 
	int keyed_length= 5; 
	//Array to store already discovered positions.
		//A 1D Array, segmented by every 2 elements, as that is what is needed, much simpler this way.
	int* keyed_positions_pointer= new int[keyed_length ];
	//Sets a defualt value for the arrray.
	for(int creation= 0; creation< keyed_length; creation ++ )
	{
		keyed_positions_pointer[creation ]= 0;
	}*/

	//Has to be double the rows count, to hold 2 data points per position on the grid.
	int length= 2* rows[0 ];

	keyed_positions= new int[length ];

	for(int x=0; x< length; x++ )
	{
		//Sets the values to their default, not 0 as that conflicts with the board's 0,n parts.
		keyed_positions[x ]= -1;
	}

	return keyed_positions;
}

//----------------------For Setting Defaults Across the board:
//To clean out the int Arry and reset its value.
void Default(int* keyed_positions, int* rows )
{
	int length= 2* rows[0 ];

	for(int x= 0; x< length; x++ )
	{
		//Set to minus one to not cause any conflicts when adding a 0, 0 array position; shows an element is defualt.
		keyed_positions[x ]= -1;
	}
}

//-----------------------------------------Array Size Management Section:
//Called before the Expand function so the correct row value is passed into the function.
void Expand(int* keyed_positions, int* rows )
{
	int keyed_row= rows[0 ];
	keyed_row*= 2;

	int keyed_collum= keyed_row;
	keyed_collum++;

	//std::cout<<"row value is:" <<keyed_row;
	//std::cout<<"   ,collum value is: " <<keyed_collum <<std::endl;
	std::cout<<"Row value is: " <<rows[0 ] <<std::endl;
	std::cout<<"keyed row value is: " <<keyed_row <<std::endl;
	std::cout<<"keyed collum value is: " <<keyed_collum <<std::endl;

	/*keyed_positions[keyed_row ]= -1;
	keyed_positions[keyed_collum ]= -1;*/

	//std::cout<<"done" <<std::endl;
}



//-----------------------------------------Output Section:
void Output(int* keyed_positions, int* rows )
{
	std::cout<<"" <<std::endl;
	std::cout<<"Keyed_Output" <<std::endl;
	
	int counter= 0;
	int current_collum= 0;
	int current_row= 0;

	int length= rows[0 ];
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
	//Used Itearate the correct number of times to parse the values in the array.
	/*for(int x= 0; x< rows[0 ]; x++ )
	{
		
		int current_row= x;
		current_row*= 2;

		int current_collum= x;
		current_collum++;

		//std::cout<<"The " <<x <<"th (" <<current_row <<", " <<current_collum <<")  value has a position of: ";
		//std::cout<<"[ "<< keyed_positions[current_row ] <<", " <<keyed_positions[current_collum ] <<" ]" <<std::endl;
	}*/

	/*old code 
	for(int x= 0; x< lenght; x++ )
	{
		for(int y= 0; y< two; y++ )
		{
			std::cout<<"The [ " <<x <<", "<<y <<" ] is: ";
			std::cout<<keyed_positions[(x+ y ) ] <<std::endl; 
		}
	}*/

	/*int half_itr= (iteration_length[0 ] ) /2;

	for(int x= 0; x< half_itr; x++ )
	{
		for(int y= 0; y< 2; y++ )
		{
			std::cout<<"The " <<x <<", " <<y <<" value is: ";
			std::cout<<keyed_positions_pointer[(x+ y ) ] <<std::endl;
		}
	}*/
}


//-----------------------------------------Array Insertion/ Input:
//Input was checked before so its not needed. Now inputs are checked against the array to see if it already has been index to not count it again.
bool Insertion_Trial(int* keyed_positions, int* rows, int* current_row, int* current_collum )
{
	std::cout<<"" <<std::endl;
	std::cout<<"Insertion Trial" <<std::endl;


	//Used Itearate the correct number of times to parse the values in the array.
	for(int x= 0; x< rows[0 ]; x++ )
	{
		int keyed_row= x;
		keyed_row*= 2;

		int keyed_collum= x;
		keyed_collum++;

		if((keyed_positions[keyed_row ]== current_row[0 ] )&& ( keyed_positions[keyed_collum ]== current_collum[0 ] ) )
		{
			std::cout<<"The value is already in the array" <<std::endl;
			return false;
		}

		else
		{
		}
	}
	
	std::cout<<"The value is not already in the array" <<std::endl;
	return true;
}

//bool Keyed_Position_Insertion_Check(int* keyed_positions_pointer, int* current_row, int* current_collum, int* iteration_length )
bool Keyed_Position_Insertion_Check(int* keyed_positions_pointer, int* current_row, int* current_collum, int* number_of_rows, int* iteration_length )
{
	//Used to not modify the iterative value.
	int array_value= 0;

	//To iterate the lenght of the 
	for(int element= 0; element< iteration_length[0 ]; element +=2 )
	{
		array_value= element;

		int check_1=  keyed_positions_pointer[array_value ];
		int check_2= keyed_positions_pointer[array_value+= 1 ];

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
void Keyed_Position_Insertion(int* keyed_positions_pointer, int* current_row, int* current_collum, int* number_of_rows, int* points_so_far )
{
	//Insert the value in the next free slot.
	//Next free slot is points so far * 2; Then ++ for the second value.
	int element= 0;

	//To not divide by 0
	switch(points_so_far[0 ] )
	{
		case 0:
			element= 0;
			break;
		default:
			//std::cout<< "before: " << points_so_far[0 ] <<std::endl;
			element= points_so_far[0 ];
			element*= 2;
			//std::cout<< "After: " << points_so_far[0 ] <<std::endl;
			break;
	}

	std::cout<<"element is: "<<element <<std::endl;

	keyed_positions_pointer[element ]= current_row[0 ];
	keyed_positions_pointer[element ++ ]= current_collum[0 ];
}


void Keyed_Position_Commit(int* keyed_positions_pointer, int* current_row, int* current_collum, int* number_of_rows, int* iteration_length, int* points_so_far )
{
	/*bool check= Keyed_Position_Insertion_Check(keyed_positions_pointer, current_row, current_collum, number_of_rows, iteration_length );
	
	//If it is a valid number commit it to the array.
	if(check )
	{
		Keyed_Position_Insertion(keyed_positions_pointer, current_row, current_collum, number_of_rows, points_so_far );

		//Forgot to dereferance it.
		points_so_far[0 ]++;	
		std::cout<<"print test, points so far is :" <<points_so_far[0 ] <<std::endl;
	}

	else
	{
		;
	}

	Keyed_Output(keyed_positions_pointer, iteration_length );*/
}

//==================############################--------------------------=================
int main(void )
{
	/*//Testing stage inputs for the player character 
	//Vairables
	int input_1= 0;
	int input_2= 0; 

	//These would be general and shared between the loop
	bool input_1_test= 0;
	bool input_2_test= 0;

	bool loop= true;
	bool input= true;

	//Used to keep track of the length of the 
	//int keyed_length= 2* board_collums; 
	int keyed_length= 5; 
	//Array to store already discovered positions.
		//A 1D Array, segmented by every 2 elements, as that is what is needed, much simpler this way.
	int* keyed_positions_pointer= new int[keyed_length ];
	//Sets a defualt value for the arrray.
	for(int creation= 0; creation< keyed_length; creation ++ )
	{
		keyed_positions_pointer[creation ]= 0;
	}

	Output(&(board_rows ), &(board_collums ), &(OUTPUT_LINES ), border_array, board, Pieces );

//Test condition for insertion.
//void Key_Position_Default(int* keyed_positions_pointer, int* iteration_length )
	Key_Position_Default(keyed_positions_pointer, &(keyed_length ) );
	int points_so_far= 0;

	int value_1= 0;
	int value_2= 0;

	//Commit a set of lengths
	for(int x=0; x< keyed_length; x +=2 )
	{
		//std::cout<< "print x: " <<x <<std::endl;
		value_1= x;
		value_2= x;
		value_2++ ;
		std::cout<<"Value 1= "<<value_1 <<std::endl;
		std::cout<<"Value 2 = "<<value_2 <<std::endl;

		Keyed_Position_Commit(keyed_positions_pointer, &(value_1 ), &(value_2 ), &(board_rows ), &(keyed_length ), &(points_so_far ) );
	}

	return 0;	*/

	//To keep track of the array's dimensions.
	int collums= 8;		
	int rows= 8;

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
	piece_identifier** board= new piece_identifier*[collums];
		//Declares the rows, Iterative approach to have a dynamic size during runtime.
	for(int creation_row= 0; creation_row< rows; creation_row ++ )
	{
		board[creation_row ]= new piece_identifier[collums];
	}

	//inht* keyed_positions= Setup(keyed_positions, &(rows ) );
	int length_1= (rows* 2 ) + 1;

	length_1= 2* rows;

	int* keyed_positions= new int[length_1 ];

	for(int x=0; x< length_1; x++ )
	{
		//Sets the values to their default, not 0 as that conflicts with the board's 0,n parts.
		keyed_positions[x ]= -1;
	}

	//Default(keyed_positions, &(rows ) );

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

	/*while(loop )
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
	}*/

//Test 3 Checkout board printing.
	//Expand(keyed_positions, &(rows ) );
	//Expand(keyed_positions, &(rows ) );
	Output(board, Pieces, &(rows ), &(collums ), &(OUTPUT_LINES ), border_parts );

	for(int x= 0; x< 5; x++ )
	{
		std::cout<<"This is the " <<x <<"th iteration" <<std::endl;
		Expand(board, &(rows ), &(collums ) );
		//Output(keyed_positions, &(rows ) );
		Output(board, Pieces, &(rows ), &(collums ), &(OUTPUT_LINES ), border_parts );
	}

	//Expand(keyed_positions, &(rows ) );
	//std::cout<<"makes it outside, row count is "<< rows <<std::endl;


	/*std::cout<<"Before: " <<std::endl;
	Output(keyed_positions, &(rows ) );


	//Expand(keyed_positions, &(rows ) );
	Expand(board, &(rows ), &(collums ) );

	keyed_positions[6 ]= 1;
	keyed_positions[7 ]= 4;

	Output(keyed_positions, &(rows ) );


/*	keyed_positions[3 ]= 2;
	keyed_positions[0 ]= 1;
	std::cout<<"After: " <<std::endl;
	std::cout<<" " <<std::endl;
	Output(keyed_positions, &(rows ) );*/

	/*delete[] keyed_positions;
	keyed_positions= NULL;*/

	Wipe(board, &(rows ) );

	//delete[] board;
	board= NULL;
	std::cout<<"Board gone." <<std::endl;


	delete[] keyed_positions;
	keyed_positions= NULL;
	std::cout<<"Keyed gone" <<std::endl;

	delete[] border_parts;
	border_parts= NULL;

	delete[] Pieces;
	Pieces= NULL;

	std::cout<< "DIE" <<std::endl;
	return 0;
}