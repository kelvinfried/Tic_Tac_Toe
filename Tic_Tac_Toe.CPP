#include <stdlib.h>
#include <time.h>
//Setup and call player class
//#include "Board.CPP"

#include "Game.CPP"

//Most of this will be converted into functions of the "Game".
int main(void )
{
	Game* Game_class= new Game();

	//Game_class->Intro_Output();

	/*Game_class->Players_Output();

	for(int x= 0; x< 2; x++ )
	{
		Game_class->Name_Trial(&(x ) );
	}

	Game_class->Players_Output();

	Game_class->Piece_Trial( );

	Game_class->Players_Output();*/

	//Game_class->Row_Setup();

	//Game_class->Set_Rounds();
	//std::cout<<"Value: "<< Game_class->Get_Rounds()[0 ]<<std::endl;

	//std::cout<<"Current round value is: " <<Game_class->Get_Rounds('t' )[0 ] <<std::endl;
	//Game_class->Incriment_Rounds();
	//std::cout<<"Current round value is: " <<Game_class->Get_Rounds('t' )[0 ] <<std::endl;

	//Intro Segment of the game.
	Game_class->Intro_Output();

	for(int x= 0; x< 2; x++ )
	{
		Game_class->Name_Trial(&(x ) );
	}
	Game_class->Piece_Trial();

	Game_class->Players_Output();

	Game_class->Row_Setup();
	
	//Main Game Loop


	//Clean up
	delete Game_class;
	Game_class= NULL;
	
	return 0;
}