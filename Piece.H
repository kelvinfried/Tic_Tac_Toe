#ifndef PIECE_H
#define PIECE_H

#include "Type.H"
#include <iostream>

class Piece
{
	private:
		//Used to store the 3 lines that store the ASCII Art
		std::string output[3 ];

		//Stores the piece type.
		piece_identifier type;


	public:
	//Constructor
		//Default
		Piece(void );

		Piece(piece_identifier type_selected );

	//Getters
		std::string* Get_Output(void );

		piece_identifier* Get_Type(void );
};
#endif