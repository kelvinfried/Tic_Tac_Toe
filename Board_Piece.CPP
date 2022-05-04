#include "Board_Piece.H"

//Getters
std::string* Board_piece::Get_Output(void )
{
	return (output );
}

piece_identifier* Board_piece::Get_Type(void )
{
	return &(type );
}

//Constructor
Board_piece::Board_piece(void )
{
	//If nothing is passed in, which is an error; The default value will be the "nothing" piece.
	type= nothing;

	//Set values
	std::string line_9= "___";
	std::string line_10= "___";
	std::string line_11= "___";
	//Pass into array.
	output[0 ]= line_9;
	output[1 ]= line_10;
	output[2 ]= line_11;
}

//Over-Ridden Constuctor.
Board_piece::Board_piece(piece_identifier type_selected )
{
	//Sets the value of the players piece.
	type= type_selected;

	/*if(type_selected== nought)
	{
		std::string line_3= "_#_";
		std::string line_4= "#_#";
		std::string line_5= "_#_";

		output[0 ]= line_3;
		output[1 ]= line_4; 
		output[2 ]= line_5;
	}

	else if(type_selected== cross)
	{
		std::string line_6= "#_#";
		std::string line_7= "_#_";
		std::string line_8= "#_#";

		output[0 ]= line_6;
		output[1 ]= line_7;
		output[2 ]= line_8;
	}

	else
	{
		std::string line_0= "___";
		std::string line_1= "___";
		std::string line_2= "___";

		output[0 ]= line_0;
		output[1 ]= line_1;
		output[2 ]= line_2;
	}*/
	//Switch statment to set parameters.
	switch(type_selected )
	{
		//Definitions formatted to make them easy to work with.
			//Can call the lines in a more flexable manner.
			//Nought Piece type.
		case nought:
		{
			std::string line_3= "_#_";
			std::string line_4= "#_#";
			std::string line_5= "_#_";

			output[0 ]= line_3;
			output[1 ]= line_4; 
			output[2 ]= line_5;
			break;
		}

			//Cross Piece type.
		case cross:
		{
			std::string line_6= "#_#";
			std::string line_7= "_#_";
			std::string line_8= "#_#";

			output[0 ]= line_6;
			output[1 ]= line_7;
			output[2 ]= line_8;
			break;
		}

			//Nothing Piece type.
		default:
		{
			std::string line_0= "___";
			std::string line_1= "___";
			std::string line_2= "___";

			output[0 ]= line_0;
			output[1 ]= line_1;
			output[2 ]= line_2;
			break;
		}
	}
}