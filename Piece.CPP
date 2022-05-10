#include "Piece.H"

//-----------------------------------------Constructor:
Piece::Piece(void )
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
Piece::Piece(piece_identifier type_selected )
{
	//Sets the value of the players piece.
	type= type_selected;

	//Switch statment to set parameters.
	switch(type_selected )
	{
		//Definitions formatted to make them easy to work with.
			//Can call the lines in a more flexable manner.
			//Braces to prevent error in the console.
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

//Public Functions
//-----------------------------------------Getters and Setters:
//----------------------Player Statistics
std::string* Piece::Get_Output(void )
{
	return (output );
}

//Returns the type of the piece
piece_identifier* Piece::Get_Type(void )
{
	return &(type );
}
//Used to set the pieces type after the class is created
void Piece::Set_Type(int* type_selected )
{
	//Change output
	//Switch statment to set parameters.
	switch(type_selected[0 ] )
	{
		//Definitions formatted to make them easy to work with.
			//Can call the lines in a more flexable manner.
			//Braces to prevent error in the console.
			//Nought Piece type.
		case nought:
		{
			//std::cout<<"Nought" <<std::endl;
			//Change display
			type= nought;

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
			//Change display
			type= cross;
			//std::cout<<"cross" <<std::endl;

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
			//Change display
			type= nothing;
			//std::cout<<"nothing" <<std::endl;

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