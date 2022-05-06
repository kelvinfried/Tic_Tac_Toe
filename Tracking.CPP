#include "Board.CPP"
//To clean out the int Arry for keeping track of found spaces.
//Keyed position is the integer array that holds the positions for the placed pieces in sets of 2 i.e. [ [1, 1], .... ]
//row is how many of these pairs there will be are
void Keyed_Position_Default(int* keyed_positions, int* rows )
{
	int iteration_length= rows[0 ];
	iteration_length= iteration_length* 2;

	for(int x= 0; x< iteration_length; x++ )
	{
		//Set to minus one to not cause any conflicts when adding a 0, 0 array position; shows an element is defualt.
		keyed_positions[x ]= -1;
	}
}

//Checks to see that the passed values are not counted for.
//If they are it returns false, else it means they are new and need to be inserted.
//Tests the current x and y valeus of the grid against existing ones, points so far is to cull unnessasary comparisons
bool Keyed_Position_Check(int* keyed_positions, int* current_row, int* current_collum, int* points_so_far )
{
	int array_value= 0;

	int check_1= 0;
	int check_2= 0;

	//To iterate the length of the currently filled out 
	int iteration_length= points_so_far[0 ];
	iteration_length= iteration_length* 2;

	//To iterate the length of the array, check every value.
	for(int element= 0; element< iteration_length; element+= 2 )
	{
		std::cout<<"Array_Value is: " <<element <<std::endl;
		array_value= element;
		
		//Used to extract the values in the array for comparision to see if they exist already.
		check_1= keyed_positions[array_value ];
		check_2= keyed_positions[array_value++ ];
		
		if((current_row[0 ]== check_1 )&& (current_collum[0 ]== check_2 ) )
		{
			return false;
		}
	}

	return true;
}

//Used for inserting the values into their correct positions once verified.
//Pass in the array, row and collum you want to pass in, how many points the player has so far to find where to place it.
void Keyed_Position_Insertion(int* keyed_positions, int* current_row, int* current_collum, int* points_so_far )
{
	//Define
	int element, element_1;
	//Declare 
	//Assigns its value then doubles it to get to the correct index.
	element= points_so_far[0 ];
	element*= 2;
	//Assigns its value then adds one to 
	element_1= element;
	element_1++;

	//Verify values.
	std::cout<<"Element is: " <<element <<std::endl;
	std::cout<<"Row is: " <<current_row[0 ] <<std::endl;
	std::cout<<"Element 1 is: " <<element_1 <<std::endl;
	std::cout<<"Collum is: " <<current_collum[0 ] <<std::endl;
	
	//Pass in the new values.
	keyed_positions[element ]= current_row[0 ];
	keyed_positions[element_1 ]= current_collum[0 ];

//incriment the value to update it.
	points_so_far[0 ]++;
}

//An output of the state of the array, internal use only
void Keyed_Output(int* keyed_positions,  int* rows )
{
	//Spacing output
	int iteration_length= rows[0 ];
	iteration_length= iteration_length* 2;

	int element, element_1;

	std::cout<<"" <<std::endl;

	for(int x= 0; x< iteration_length; x+= 2 )
	{
		element= x;

		element_1= x;
		element_1++;

		std::cout<<"The value is: ";
		std::cout<<keyed_positions[element ] <<", " <<keyed_positions[element_1 ] <<std::endl;
	}
}

//Packaged function to put all the subfunctions in one neat package
void Keyed_Position_Commit(int* keyed_positions, int* current_row, int* current_collum, int* points_so_far )
{
	//Used to verify the input is valid.
	bool check= Keyed_Position_Check(keyed_positions, current_row, current_collum, points_so_far );
	
	if(check )
	{
		Keyed_Position_Insertion(keyed_positions, current_row, current_collum, points_so_far );

		std::cout<<"Points so far is now: " <<points_so_far[0 ] <<std::endl;
	}

	else 
	{
		std::cout<<"Fail on check" <<std::endl;
	}
}

//Overloaded used for outputs.
void Keyed_Position_Commit(int* keyed_positions, int* current_row, int* current_collum, int* points_so_far, int* rows )
{
	//Used to verify the input is valid.
	bool check= Keyed_Position_Check(keyed_positions, current_row, current_collum, points_so_far );
	
	if(check )
	{
		Keyed_Position_Insertion(keyed_positions, current_row, current_collum, points_so_far );

		std::cout<<"Points so far is now: " <<points_so_far[0 ] <<std::endl;
	}

	else 
	{
		std::cout<<"Fail on check" <<std::endl;
	}

	Keyed_Output(keyed_positions, rows );
}


int main(void )
{
	int collums= 3;
	int rows= 3;

	//Declared from heap due to long life time and to be dynamic: Holds each of the rows, so they can be accesed from a single part
	piece_identifier** board= new piece_identifier*[collums ];
		//Declares the rows, Iterative approach to have a dynamic size during runtime.
	for(int creation_row= 0; creation_row< rows; creation_row ++ )
	{
		board[creation_row ]= new piece_identifier[collums ];
	}
	//Set default board values
	Default(&(rows ), &(collums ), board );

	
	//int* keyed_length= new int(collums* 2 );
	//Code for handling the Keyed Positions
	int* keyed_positions= new int[(rows* 2 ) ];
	Keyed_Position_Default(keyed_positions, &(rows ) );
	
	int points_so_far= 0;

	int value_1= 0;
	int value_2= 1;

	//before
	//Keyed_Output(keyed_positions, keyed_length );
	std::cout<<"" <<std::endl;

	//commit one length
	//Keyed_Position_Commit(keyed_positions, &(value_1 ), &(value_2 ), &(collums ), keyed_length, &(points_so_far ) );
	Keyed_Position_Commit(keyed_positions, &(value_1 ), (&value_2 ), &(points_so_far ), &(rows ) ); 


	value_1= 2;
	value_2= 2;
	Keyed_Position_Commit(keyed_positions, &(value_1 ), (&value_2 ), &(points_so_far ), &(rows ) ); 

	//Test of a duplicate- Handles it correclty.
	value_1= 2;
	value_2= 2;
	Keyed_Position_Commit(keyed_positions, &(value_1 ), (&value_2 ), &(points_so_far ), &(rows ) ); 

	//Test of board expansion.
	Expand(&(rows ), &(collums ), board );
	value_1= 2;
	value_2= 2;
	Keyed_Position_Commit(keyed_positions, &(value_1 ), (&value_2 ), &(points_so_far ), &(rows ) );


	
//Clean up section
	delete[]  keyed_positions;
	keyed_positions= NULL;

	//Function used to delete the board rows.
	Board_Wipe(&(rows ), board );

	//Cleans up the game_board itself.
	delete[] board;
	board= NULL;

	return 0;	
}
