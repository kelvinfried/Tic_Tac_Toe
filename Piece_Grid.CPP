//Tic Tac Toe Array "Grd" Setup code and testing stuff from in person lesson.
#include <iostream>

//Step 1 define a datatype or something to represent the grid pieces.
	//Requirements are:
		//Holds 3 States: NULL (/empty), Piece type O, Piece type X;
			//I think trying out ENUM would be a valid thing to use for this case, as bool values would be outside of the scope
//The idea is with this defined data type is that I am able to assign this to each of the "cells" in the 3x3 grid
	//THen By calling the value I am able to call it as needed to then track where each player has placed down their pieces.
enum piece_identifier
{
	//If nothing is on the grid place, show nothing
	nothing= 0,
	//Show a circle
	nought= 1,
	//Show an cross
	cross= 2
};

int main(void )
{
	//Declare a vairable with my enum type
	//piece_identifier holding_variable;
		//Then need to set the starting value for it manually, it does not take up the enum types first vairable;
		//dynamic array -2D
			//value to pass in to declare the size.
	//int array_dimension_0= 1;
	//int array_dimension_1= 1;
		//declare
	//piece_identifier* dynamic_array_2d= new piece_identifier[array_dimension_0 ][array_dimension_1 ]( );
	//Set up for pointer to pointer for a 2D array as the above causes issues with the compiler.
		//guidance give by Lecturer: Merhdad
	//piece_identifier* dynamic_array_row= new piece_identifier[array_dimension_0 ];
	//piece_identifier** dynamic_array_collum= new piece_identifier*[array_dimension_1 ];
	//piece_identifier** dynamic_array_collum= &(piece_identifier*[array_dimension_1 ] );
	
	//piece_identifier* dynamic_array_2d= new piece_identifier[3 ][3 ];
	//int array[1 ][1 ]= {{ 0 }, {0 } };
	//int* pntArray[1 ] = {&array[0 ] };
	
	/*int const array_x= 2;
	int const array_y= 2;
	
	int* array_pointer= new int[array_x ][array_y ];
	
	int array[2 ][1 ];
	
	array[0 ][ 0 ]= 1;
	array[1 ][ 0 ]= 1;
	
	int* point_to_array[2 ][1 ];
	
	point_to_array= &array;
	
	int size1= 0;
	int size2= 0;
	
	point_to_array[0 ][0 ]= 1;*/

	
	
	//piece_identifier* dynamic_2d_array[3 ]= new piece_identifier[3 ];
	int collums= 3;		
	int rows= 5;
	
		//declare - trial of passing nothing in as a value	
	piece_identifier* board_row_0= new piece_identifier[rows ];	//1D [ 0, 0, 0 ];
	piece_identifier* board_row_1= new piece_identifier[rows ];
	piece_identifier* board_row_2= new piece_identifier[rows ];
		//declare
	//piece_identifier** board_collum=  new piece_identifier*[3 ];
	//This will be the board, it will hold 3 rows
	piece_identifier** game_board= new piece_identifier*[collums ];
		//define	- ;
	game_board[0 ]= board_row_0;
	game_board[1 ]= board_row_1;
	game_board[2 ]= board_row_2;
	
	//Declare values "to default". - Create a "nothing" grid.
	for(int current_collum=0; current_collum< collums; current_collum++ )
	{
		for(int current_row=0; current_row< rows; current_row++ )
		{
			//game_board[current_collum ][current_row ]= nothing;
			//std::cout<<"Current "<<current_collum <<", " <<current_row <<" is: " <<game_board[current_collum ][current_row ] <<std::endl;
			//game_board[current_collum ][current_row ]= nothing;
			switch(current_row )
				{
				case 1:
					game_board[current_collum ][current_row ]= nought;
					break;
				case 2:
					game_board[current_collum ][current_row ]= cross;
					break;
				default:
					game_board[current_collum ][current_row ]= nothing;
					break;
				}
		}
	}
	
	
	//Output section
	for(int current_collum=0; current_collum< collums; current_collum++ )
	{
		///std::cout<<"" <<std::endl;
		for(int current_row=0; current_row< rows; current_row++ )
		{	
			std::cout<<"Current "<<current_collum <<", " <<current_row <<" is: " <<game_board[current_collum ][current_row ] <<std::endl;
		}
		std::cout<<"" <<std::endl;
	}
	
	//Create a function to check the grid
	
	//cleanup code
	delete[] board_row_0;
	board_row_0= NULL;
	delete[] board_row_1;
	board_row_1= NULL;
	delete[] board_row_2;
	board_row_2= NULL;
	
	delete[] game_board;
	game_board= NULL;


	return 0;
}