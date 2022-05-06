#include "Board.CPP"
//To clean out the int Arry for keeping track of found spaces.
void Key_Position_Default(int* keyed_positions_pointer, int* iteration_length )
{
	for(int x= 0; x< iteration_length[0 ]; x++ )
	{
		//Set to minus one to not cause any conflicts when adding a 0, 0 array position; shows an element is defualt.
		keyed_positions_pointer[x ]= -1;
	}
}

//Assuming the input passed all checks it will then be checked against the array to see if it has already been indeex by the program to not count it again.
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

		//Forgot to dereferance it.
		points_so_far[0 ]++;	
		std::cout<<"print test, points so far is :" <<points_so_far[0 ] <<std::endl;
	}

	else
	{
		;
	}

	Keyed_Output(keyed_positions_pointer, iteration_length );
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

	
	int* keyed_length= new int(collums* 2 );

	int* keyed_positions= new int[keyed_length[0 ] ];
	Key_Position_Default(keyed_positions, keyed_length );
	
	int points_so_far= 0;

	int value_1= 0;
	int value_2= 0;

	//commit one length
	Keyed_Position_Commit(keyed_positions, &(value_1 ), &(value_2 ), &(collums ), keyed_length, &(points_so_far ) );

	return 0;
}
