#include <iostream>
#include "Board_piece_type.H"
#ifndef BOARD_PIECE_H
#define BOARD_PIECE_H

class Board_piece
{
	private:
		std::string output[3 ];
		piece_identifier type;

	public: 
	//Constructor
		//Default
		Board_piece(void );

		Board_piece(piece_identifier type_selected );
	
	//Getters
		std::string* Get_Output(void );

		piece_identifier Get_Type(void );
};
#endif