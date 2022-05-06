//Tic Tac Toe Array "Grd" Setup code and testing stuff from in person lesson.
#include "Board.CPP"

//To clean out the int Arry for keeping track of found spaces.
void Key_Position_Default(int* keyed_positions_pointer, int* iteration_length )
{
	for(int x= 0; x< iteration_length[0 ]; x++ )
	{
		//Set to minus one to not cause any conflicts when adding a 0, 0 array position.
		keyed_positions_pointer[x ]= -1;
	}
}

//Assuming the input passed all checks it will then be checked against the array to see if it has already been indeex by the program to not count it again.
bool Keyed_Position_Insertion_Check(int* keyed_positions_pointer, int* current_row, int* current_collum, int* number_of_rows, int* iteration_length )
{
	//To iterate the lenght of the 
	for(int element= 0; element< iteration_length[0 ]; element +=2 )
	{
		int check_1=  keyed_positions_pointer[element ];
		int check_2= keyed_positions_pointer[element+ 1 ];

		//Match found exit
		if((current_row[0 ]== check_1 )&& (current_collum[0 ]== check_2 ) )
		{
			return false;
		}
		
		else
		{
			return true;
		}
	}
}


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
		default:
			element= (points_so_far[0 ] )* 2;
	}

	keyed_positions_pointer[element ]= current_row[0 ];
	keyed_positions_pointer[element ++ ]= current_collum[0 ];
}

void Keyed_Output(int* keyed_positions_pointer,  int* iteration_length )
{
	std::cout<<"" <<std::endl;
	std::cout<<"Keyed_Output" <<std::endl;
	
	int half_itr= (iteration_length[0 ] ) /2;

	for(int x= 0; x< half_itr; x++ )
	{
		for(int y= 0; y< 2; y++ )
		{
			std::cout<<"The " <<x <<", " <<y <<" value is: ";
			std::cout<<keyed_positions_pointer[(x+ y ) ] <<std::endl;
		}
	}
}

void Keyed_Position_Commit(int* keyed_positions_pointer, int* current_row, int* current_collum, int* number_of_rows, int* iteration_length, int* points_so_far )
{
	bool check= Keyed_Position_Insertion_Check(keyed_positions_pointer, current_row, current_collum, number_of_rows, iteration_length );
	
	//If it is a valid number commit it to the array.
	if(check )
	{
		Keyed_Position_Insertion(keyed_positions_pointer, current_row, current_collum, number_of_rows, points_so_far );

		points_so_far++;	
	}

	else
	{
		;
	}

	Keyed_Output(keyed_positions_pointer, iteration_length );
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
	char* border_array= new char[2 ];
	//Declare
		border_array[0 ]= space_character;
		border_array[1 ]= divider_character;

	//Declared from heap due to long life time and to be dynamic: Holds each of the rows, so they can be accesed from a single part
	piece_identifier** board= new piece_identifier*[board_collums ];
		//Declares the rows, Iterative approach to have a dynamic size during runtime.
	for(int creation_row= 0; creation_row< board_rows; creation_row ++ )
	{
		board[creation_row ]= new piece_identifier[board_collums ];
	}

	//Set default board values
	Default(&(board_rows ), &(board_collums ), board );

//Testing stage inputs for the player character 
	//Vairables
	int input_1= 0;

	int input_2= 0; 

	//These would be general and shared between the loop
	bool input_1_test= 0;
	bool input_2_test= 0;

	bool loop= true;
	bool input= true;

	//Array to key positions already discorvered.
		//2 Positions for one row (x) and one collum (y) value.
	/*int** keyed_positions_pointer= new int*[2 ];
		//Declares the rows, with an iterative apporach:
	for(int creation_row= 0; creation_row< board_rows; creation_row ++ )
	{
		keyed_positions_pointer[creation_row ]= new int[2 ];
	}
	//eDfine values for the array.
	for(int creation_row= 0; creation_row< board_rows; creation_row ++ )
	{
		for(int two= 0; two< 2 ; two ++ )
		{
			keyed_positions_pointer[creation_row ][two ]= 0;
		}
	}*/

	//Used to keep track of the length of the 
	int keyed_length= 2* board_collums; 
	//Array to store already discovered positions.
		//A 1D Array, segmented by every 2 elements, as that is what is needed, much simpler this way.
	int* keyed_positions_pointer= new int[keyed_length ];
	//Sets a defualt value for the arrray.
	for(int creation= 0; creation< keyed_length; creation ++ )
	{
		keyed_positions_pointer[creation ]= 0;
	}

	//Output(&(board_rows ), &(board_collums ), &(OUTPUT_LINES ), border_array, board, Pieces );

	/*//Main loop prototype to check input.
	while(loop )
	{
		while(input )
		{
			//Output block
			std::cout<<"" <<std::endl;
			std::cout<<"" <<std::endl;
			std::cout<<"Please enter 2 vlaue seperated by a space. Input 99 to quit playing." <<std::endl;
			//Takes a user input
			std::cin>> input_1 >> input_2; 

			//Input checking:
			input_1_test= Input_Sanitization(&(board_rows ), &(input_1 ) );
			input_2_test= Input_Sanitization(&(board_rows ), &(input_2 ) );
			
			//Exit clause
			if((input_1== 99 )|| (input_2== 99 ) )
			{
				input= false;
				loop= false;
			}
			
			else if((input_1_test== 1 )|| (input_2_test== 1 ) )
			else if((input_1_test )|| (input_2_test ) )
			{
				input= false;
			}

			else
			{
				input_1= 0;
				input_2= 0;
			}
		}

		//Resets it goes back to the input section.
		input= true;

		//Deincriment the values to make the index 0, with the index 1 board layout.
		input_1 --;
		input_2 --;

		//Output section
		if(loop== true )
		{
			Insertion(&(input_1 ), &(input_2 ), board, Cross );
			std::cout<<"Update: " <<std::endl;

			Output(&(board_rows ), &(board_collums ), &(OUTPUT_LINES ), border_array, board, Pieces );
		}

		else
		{
		}
	}*/

/*	//Test 1
	int value_1= 1;
	int value_2 =1;

//bool Keyed_Position_Insertion_Check(int* keyed_positions_pointer, int* current_row, int* current_collum, int* number_of_rows, int* iteration_length )
	if(Keyed_Position_Insertion_Check(keyed_positions_pointer, &(value_1 ), &(value_2 ), &(board_rows ), &(keyed_length ) )== true )
	{
		std::cout<<"Gammer" <<std::endl;
	}

	else
	{
		std::cout<<"Not Gamer" <<std::endl;
	}*/
//Test condition for insertion.
//void Key_Position_Default(int* keyed_positions_pointer, int* iteration_length )
	Key_Position_Default(keyed_positions_pointer, &(keyed_length ) );
	int points_so_far= 0;

	//Commit a set of lengths
	for(int x=0; x< keyed_length; x++ )
	{
		int value_1= x;
		int value_2= x;

		Keyed_Position_Commit(keyed_positions_pointer, &(value_1 ), &(value_2 ), &(board_rows ), &(keyed_length ), &(points_so_far ) );
	}
//Automated fill.
	/*int value_1= 1;
	int value_2= 1;

	for(int x= 0; x< 3; x++ )
	{
		int value_1= x;
		int value_2= x;

		if(Keyed_Position_Insertion_Check(keyed_positions_pointer, &(value_1 ), &(value_2 ), &(board_rows ), &(keyed_length ) )== true )
		{
			std::cout<<"Gammer" <<std::endl;
		}

		else
		{
			std::cout<<"Not Gamer" <<std::endl;
		}
	}*/

//Trying to trigger conflict.
	/*value_1= 1;
	value_2= 1;

	//bool Keyed_Position_Insertion_Check(int* keyed_positions_pointer, int* current_row, int* current_collum, int* number_of_rows, int* iteration_length )
	if(Keyed_Position_Insertion_Check(keyed_positions_pointer, &(value_1 ), &(value_2 ), &(board_rows ), &(keyed_length ) )== true )
	{
		std::cout<<"Gmmer" <<std::endl;
	}

	else
	{
		std::cout<<"Not Gamer" <<std::endl;
	}*/

	//Clean up section
	delete[] border_array;
	border_array= NULL;

	delete[]  keyed_positions_pointer;
	keyed_positions_pointer= NULL;

	//Correct Deletion for the rows of the array, unlike before, prevent memory leak.
	/*for(int deletion= 0; deletion< board_rows; deletion ++ )
	{
		delete board[deletion ];
	}*/
	//void Board_Wipe(int* rows, piece_identifier** array )
	//Function used to delete the board rows.
	Board_Wipe(&(board_rows ), board );

	//Cleans up the game_board itself.
	delete[] board;
	board= NULL;

	return 0;	
}