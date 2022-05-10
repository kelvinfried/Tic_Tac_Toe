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

	int input_1= 0;
	int input_2= 1;
	int input_3= 2;
	int input_4= 3;
	int points_so_far= 0;

	Board_Class->Default( );
	//std::cout<<"Default state" <<std::endl;
	//Board_Class->Output(Pieces );

	/*//"Automated" Insertion Checks:
	for(int x= 1; x< Board_Class->Get_Rows(); x++ )
	{
		//Draw 3 pieces 
		//Board_Class->Insertion(&(Cross ), &(input_1 ), &(x ) ); 
		//Board_Class->Insertion(&(Cross ), &(input_1 ), &(x ) ); 
		Board_Class->Output(Pieces );
	}
	//Board_Class->Insertion(&(Cross ), &(input_2 ), &(input_2 ) );
	//Board_Class->Insertion(&(Cross ), &(input_3 ), &(input_2 ) );
	//Board_Class->Insertion(&(Cross ), &(input_4 ), &(input_2 ) );*/

/*//horizontal testing part
	std::cout<<"" <<std::endl;
	std::cout<<"" <<std::endl;
	std::cout<<"Output part:" <<std::endl;
	Board_Class->Output(Pieces );


	//std::cout<<"" <<std::endl;
	//std::cout<<"Edited state" <<std::endl;
	//Board_Class->Output(Pieces );

	int temp_1= input_2;
	temp_1--;

	int temp_2= input_2;
	temp_2--;

	int temp_3= input_3;
	temp_3--;

	//std::cout<<"input 1 lines up with array index: " <<temp_1;
	//std::cout<<"input 2 lines up with array index: " <<temp_2;
	std::cout<<"" <<std::endl;
	std::cout<<"" <<std::endl;

	Board_Class->Horizontal_Check(&(temp_1 ), &(input_1 ), &(Pieces[2 ] ), &(points_so_far ) );

	if(points_so_far== 3 )
	{
		std::cout<<"Non Stinkers wins so far: " <<points_so_far <<std::endl;
	}

	else
	{
		std::cout<<"UnPogr: "<< points_so_far <<std::endl;
	}*/

/*//Vertical Testing Part
	int temp_1= input_2;
	temp_1--;

	int temp_2= input_2;
	temp_2--;

	int temp_3= input_3;
	temp_3--;

	Board_Class->Insertion(&(Cross ), &(input_2 ), &(input_2 ) );
	Board_Class->Insertion(&(Cross ), &(input_2 ), &(input_3 ) );
	//Board_Class->Insertion(&(Cross ), &(input_2 ), &(input_4 ) );


	std::cout<<"" <<std::endl;
	std::cout<<"Edited state" <<std::endl;
	Board_Class->Output(Pieces );

	//Board_Class->Vertical_Check(&(input_1 ), &(input_1 ), &(Pieces[2 ] ), &(points_so_far ) );
	Board_Class->Horizontal_Check(&(temp_1 ), &(temp_1 ), &(Pieces[2 ] ), &(points_so_far ), 't' );

	if(points_so_far== 3 )
	{
		std::cout<<"Non Stinkers wins so far: " <<points_so_far <<std::endl;
	}

	else
	{
		std::cout<<"UnPogr: "<< points_so_far <<std::endl;
	}*/

/*//Linear testing Part -1
	int temp_1= input_2;
	temp_1--;

	int temp_2= input_2;
	temp_2--;

	int temp_3= input_3;
	temp_3--;

	Board_Class->Insertion(&(Cross ), &(input_2 ), &(input_2 ) );
	Board_Class->Insertion(&(Cross ), &(input_3 ), &(input_3 ) );
	Board_Class->Insertion(&(Cross ), &(input_4 ), &(input_4 ) );

	Board_Class->Output(Pieces );

	Board_Class->Linear_Check(&(input_3 ), &(input_3 ), &(Cross ), &(points_so_far ) );

	if(points_so_far== 3 )
	{
		std::cout<<"Non Stinkers wins so far: " <<points_so_far <<std::endl;
	}

	else
	{
		std::cout<<"UnPogr: "<< points_so_far <<std::endl;
	}*/

/*//Linear testing Part -2
	int temp_1= input_2;
	temp_1--;

	int temp_2= input_2;
	temp_2--;

	int temp_3= input_3;
	temp_3--;

	/*Board_Class->Insertion(&(Cross ), &(input_4 ), &(input_4 ) );
	Board_Class->Insertion(&(Cross ), &(input_3 ), &(input_3 ) );
	Board_Class->Insertion(&(Cross ), &(input_2 ), &(input_2 ) );

	//Board_Class->Insertion(&(Cross ), &(input_2 ), &(input_4 ) );
	//Board_Class->Insertion(&(Cross ), &(input_3 ), &(input_3 ) );
	//Board_Class->Insertion(&(Cross ), &(input_4 ), &(input_2 ) );

	//Board_Class->Insertion(&(Cross ), &(input_2 ), &(input_2 ) );
	//Board_Class->Insertion(&(Cross ), &(input_3 ), &(input_2 ) );
	//Board_Class->Insertion(&(Cross ), &(input_4 ), &(input_2 ) );
	//Board_Class->Output(Pieces );


	bool check= Board_Class->Check(&(input_1 ), &(input_1 ), &(Cross ), &(points_so_far ) );

	if(check )
	{
		std::cout<<"Gaming " <<std::endl;
	}
		
	else
	{
		std::cout<<"Lmao " <<std::endl;
	}
	//bool test_case= Board_Class->Check(&(input_3 ), &(input_3 ), &(Cross ), &(points_so_far ) );
	//Board_Class->Linear_Check(&(input_2 ), &(input_2 ), &(Cross ), &(points_so_far ), 't' );
	//Board_Class->Linear_Check(&(input_2 ), &(input_2 ), &(Cross ), &(points_so_far ) );

	if(points_so_far== 3 )
	{
		std::cout<<"Non Stinkers wins so far: " <<points_so_far <<std::endl;
	}

	else
	{
		std::cout<<"UnPogr: "<< points_so_far <<std::endl;
	}

	if(test_case )
	{
		std::cout<<"Win Moment" <<std::endl;
	}

	else
	{
		std::cout<<"Not Win Moment" <<std::endl;
	}*/

//Player class testing 
	std::string name= "Test_Player";
	piece_identifier cross_piece= cross;
	//Define the player classes in memory
	//Player* Player_Class= new Player[0 ]();
	//Player* Player_Class= new Player[2 ]();
		//Have to pass values above if creating like this; Can only make use of one constructor.
		//Default
		//Player_Class[0 ]= new Player();
		//Overloaded
		//Player_Class[0 ]= new Player(&(name ), &(cross_piece )  );

	//Create a defualt player.
	Player* Player_Class= new Player[2 ]();

	std::cout<<"First class is: " <<std::endl;
	Player_Class[0 ].Get_Stats();
	std::cout<<"" <<std::endl;
	std::cout<<"Second class is: " <<std::endl;
	Player_Class[1 ].Get_Stats();
	
	delete Board_Class;

	delete[] Pieces;
	Pieces= NULL;


	return 0;
}