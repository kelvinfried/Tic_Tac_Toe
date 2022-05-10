#ifndef PIECE_H
#define PIECE_H

#include "Type.H"

class Piece
{
	private:
		//Used to store the 3 lines that store the ASCII Art
		std::string output[3 ];

		//Stores the piece type.
		piece_identifier type;


	public:
	//-----------------------------------------Constructor:
		//Default
		Piece(void );
		//Overloaded
		Piece(piece_identifier type_selected );

		//Public Functions
		//-----------------------------------------Getters and Setters:
		//----------------------Player Statistics
		//To return the string array which holds the piece output.
		std::string* Get_Output(void );

		//Returns the type of the piece
		piece_identifier* Get_Type(void );
		//Used to set the pieces type after the class is created
		void Set_Type(piece_identifier* new_piece );
};
#endif