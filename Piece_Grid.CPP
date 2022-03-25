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
	//Above is incorrect, the idea is the data type itself is piece identifier	
	/*piece_identifier test= nothing;		//Then you assign the "defined keyword" onto it.
		std::cout<<"The value of testing should be 0 if it is nothing: " <<test <<std::endl;
	test= nought;
		std::cout<<"The value of testing should be 0 if it is nothing: " <<test <<std::endl;
	test= cross;
		std::cout<<"The value of testing should be 0 if it is nothing: " <<test <<std::endl <<std::endl;*/

	//Now that I know it works generally, and you can change the assigned value I will try to make a single element array using it.
		//static array
	/*piece_identifier test_array[1 ]=
	{	
		//verified all of the types worked correctly on assignment to the array 
		nothing, nought, cross
	};

	for(int i= 0; i< 1; i++ )
	{
		std::cout<<"The value of the " <<i <<"th array element is: " <<test_array[i ] <<std::endl;
	}
	std::cout<<std::endl;*/

		//dynamic array	-1D
	/*int size_of_array= 10;

	piece_identifier* dynamic_array= new piece_identifier[size_of_array ];
//Then set value	-temp	//set up "random values";
	for (int i= 0; i< size_of_array; i++ )
	{
		switch(i% 3 )
		{
			case 0:
				dynamic_array[i ]= nothing;
				break;
			case 1:
				dynamic_array[i ]= nought;
				break;
			default:
				dynamic_array[i ]= cross;
				break;
		}
		//Value is assigned to the enum data type not the other way around.
	}
	for(int i= 0; i< size_of_array; i++ )
	{
		std::cout<<"The " <<i <<"th value of the array element is: " <<dynamic_array[i ] <<std::endl;
	}*/

		//dynamic array -2D
			//value to pass in to declare the size.
	int array_dimension_0= 1;
	int array_dimension_1= 1;
		//declare
	//piece_identifier* dynamic_array_2d= new piece_identifier[array_dimension_0 ][array_dimension_1 ]( );
	//Set up for pointer to pointer for a 2D array as the above causes issues with the compiler.
		//guidance give by Lecturer: Merhdad
	//piece_identifier* dynamic_array_rows= new piece_identifier[array_dimension_0 ]( );
	//piece_identifier** dynamic_array_collum= new piece_identifier[array_dimension_1 ]( );

	//piece_identifier* dynamic_array_row= new piece_identifier[array_dimension_0 ];
	//piece_identifier** dynamic_array_collum= new piece_identifier*[array_dimension_1 ];
	//piece_identifier** dynamic_array_collum= &(piece_identifier*[array_dimension_1 ] );

	//dynamic_array_row[0 ]= nothing;

	//Read dynamic values
	//std::cout<<"Output is " <<dynamic_array_collum[0 ][0 ] <<std::endl;
	//std::cout<<"Output is " <<dynamic_array_row[0 ] <<std::endl;

	//Define simple pointer to pointer
	/*int* dynamic_int= new int(10 );
	int** pointer_to_pointer_to_int= new int*;

	pointer_to_pointer_to_int= &dynamic_int;

	std::cout<<"Defualt value " <<dynamic_int[0 ] <<std::endl;
	std::cout<<"Defualt value " <<pointer_to_pointer_to_int[0 ][0 ] <<std::endl;*/

	/*//Set values
	for(int x= 0; x< array_dimension_0; x++ )
	{
		for(int y= 0; y< array_dimension_1; y++ )
		{
			//Y is used as we want to access the local level of the array, not which level it is on.
			switch(y% 3 )
				{
				case 0:
					dynamic_array_2d[x ][y ]= nothing;
					break;
				case 1:
					dynamic_array_2d[x ][y ]= nought;
					break;
				default:
					dynamic_array_2d[x ][y ]= cross;
					break;
				}
		}
	}
		
	for(int x= 0; x< array_dimension_0; x++ )
	{
		std::cout<<"" <<std::endl;

		for(int y= o; y< array_dimension_1; y++ )
		{
			std::cout<<"The " <<x <<"th value and the " <<y <<"th value is " <<dynamic_array_2d[x ][y ] <<std::endl;
		}
	}*/

	//Dynamic 2D Array, rows defined with 
	piece_identifier* dynamic_array_row= new piece_identifier[0 ];
		//define
	dynamic_array_row[0 ]= { nought };
	//Declare
	piece_identifier** dynamic_array_collum= new piece_identifier*[0 ];
		//Pass in the mem address
	dynamic_array_collum= &dynamic_array_row;	

	std::cout<<"The value of row 0, collum 0 is " << dynamic_array_collum[0 ][0 ] <<std::endl;
	dynamic_array_collum[1 ][0 ]= {nought };
	std::cout<<"The value of row 1, collum 0 is " << dynamic_array_collum[1 ][0 ] <<std::endl;


	return 0;
}