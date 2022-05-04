#include <iostream>
#include "Board_Piece_Type.H"
#ifndef BOARD_PIECE_H
#define BOARD_PIECE_H

class Board_Piece
{
	private:
		std::string output[3 ];
		piece_identifier type;

	public: 
	//Constructor
		//Default
		Board_Piece(void );

		Board_Piece(piece_identifier type_selected );
	
};
#endif