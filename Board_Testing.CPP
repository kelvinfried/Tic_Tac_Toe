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
	//std::cout<<"Default state" <<std::endl;
	//Board_Class->Output(Pieces );

	//"Automated" Insertion Checks:
	for(int x= 1; x< 6; x++ )
	{
		//Draw 3 pieces 
		//Board_Class->Insertion(&(Cross ), &(input_1 ), &(x ) ); 
		Board_Class->Insertion(&(Cross ), &(x ), &(input_1 ) ); 
	}

	//std::cout<<"" <<std::endl;
	//std::cout<<"Edited state" <<std::endl;
	//Board_Class->Output(Pieces );

	int temp_1= input_1;
	temp_1--;

	int temp_2= input_2;
	temp_2--;

	//std::cout<<"input 1 lines up with array index: " <<temp_1;
	//std::cout<<"input 2 lines up with array index: " <<temp_2;
	std::cout<<"Rows value is: " <<Board_Class->Get_Rows() <<std::endl;
	bool check= Board_Class->Horizontal_Check(&(temp_1 ), &(temp_2 ), &(Pieces[2 ] ), &(points_so_far ) );
	
	if(check )
	{
		std::cout<<"Non Stinkers wins so far: " <<points_so_far <<std::endl;
	}

	else
	{
		std::cout<<"UnPogr: "<< points_so_far <<std::endl;
	}
	delete Board_Class;

	delete[] Pieces;
	Pieces= NULL;


	return 0;
}