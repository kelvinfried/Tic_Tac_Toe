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
	std::cout<<"Default state" <<std::endl;
	Board_Class->Output(Pieces );

	//Insertion Checks:
	for(int x= 1; x< 6; x++ )
	{
		//Draw 3 pieces 
		//Board_Class->Insertion(&(Cross ), &(input_1 ), &(x ) ); 
		Board_Class->Insertion(&(Cross ), &(x ), &(input_1 ) ); 
	}

	std::cout<<"" <<std::endl;
	std::cout<<"Edited state" <<std::endl;
	Board_Class->Output(Pieces );

	delete Board_Class;

	return 0;
}