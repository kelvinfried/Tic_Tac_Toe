//CPP Program
#include <iostream>

int main() 
{
//Definitions of pieces in an accesable way.
	std::string  null_0= "___";
	std::string  null_1= "___";
	std::string  null_2= "___";
	std::string null_array[3 ]= 
		{null_0, null_1, null_2 };

	std::string  nought_0= "_#_";
	std::string  nought_1= "#_#";
	std::string  nought_2= "_#_";
	std::string nought_array[3 ]= 
		{nought_0, nought_1, nought_2 };

	std::string  cross_0= "#_#";
	std::string  cross_1= "_#_";
	std::string  cross_2= "#_#";
	std::string cross_array[3 ]= 
		{cross_0, cross_1, cross_2 };

	const int THREE= 3;
	
	//Next step.
		//Based on the types in the grid it needs to be adaptable 
		//Basic idea is that every turn the current grid layout needs to be read.
			//This reading will act as a way to store the values obtained for it
				//i.e. [0][0]= null, [0][1]= cross, [0][2]= noughtt;
		//Make the thing adaptable based on the size of the grid
	//Rewrite stored parts_into chunks:
	std::string border_chunk= "XXX";
	char border_divider= '_';
	char space_character= 'X';

	//Specifies how large the grid is.
	int grid_x_length= 5;
	int grid_y_length= 1;

	enum piece_identifier
	{
		nothing= 0,
		nought= 1,
		cross= 2
	};

	//Creates a point to a dynamic array that will change its depth to match the grids num of elements
	piece_identifier* piece_row_type= new piece_identifier[grid_y_length ]; 

	//Main Loop
	for(int down= 0; down< grid_x_length; down++ )
	{
		//Border Creation
		for(int across= 0; across< grid_y_length; across++ )
		{
			std::cout<<border_chunk <<border_divider;
		}
		std::cout<<"" <<std::endl;

		//Indexes the current row to an array so it can be read.
		for(int across= 0; across< grid_y_length; across++ )
		{
			piece_row_type[across ]= nothing;
		}

		//Iterates the exact amount of times needed to print all the lines per each type.-
		for(int current_layer= 0; current_layer< THREE; current_layer++ )
		{
			//Then iterates the length of the row to draw each element line by line as it should.
			for(int across= 0; across< grid_y_length; across++ )
			{
				switch(piece_row_type[across ] )
				{
					//You can use either the enum value or what value is assigned literally.
					case cross:
						std::cout<<cross_array[current_layer ]<< space_character;
						break;
					case nought:
						std::cout<<nought_array[current_layer ]<< space_character;
						break;
					default:
						std::cout<<null_array[current_layer ]<< space_character;
						break;	
				}
			}
			std::cout<<"" <<std::endl;	//Used to break line between each of the entire lines.

		}

		//Border Creation for the last output line.
		if((down+= 1)== grid_x_length )
		{
			for(int across= 0; across< grid_y_length; across++ )
			{
				//Border Creation
				std::cout<<border_chunk <<border_divider;
			}
		}
	}


	return 0;
}