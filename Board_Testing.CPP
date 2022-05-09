//Tic Tac Toe Array "Grd" Setup code and testing stuff from in person lesson.
#include "Board.CPP"

//==================############################--------------------------=================
int main(void )
{
//Keep hold of the piece data.	-Passed in board piece type.
	Piece Nothing;
	Piece Nought(nought );
	Piece Cross(cross );

//Assing one of these to the player class.
	//Used for passing the piece data between functions
	Piece* Pieces=new Piece[3 ];
	//Assigning the values.
		Pieces[0 ]= Nothing;
		Pieces[1 ]= Nought;
		Pieces[2 ]= Cross;
	Board* Board_Class= new Board();
	Board_Class->Default();

	int input_1= 1;
	int input_2= 1;
	int points_so_far= 0;

	Board_Class->Default(true );
	Board_Class->Output('t' );

	Board_Class->Commit(&(input_1 ), &(input_2 ), &(points_so_far ) );
	Board_Class->Output('t' );

	Board_Class->Expand();
	Board_Class->Expand('t' );
	Board_Class->Output('t' );
	
	Board_Class->Shrink();
	Board_Class->Shrink('t' );
	Board_Class->Output('t' );

	delete Board_Class;

	return 0;
}