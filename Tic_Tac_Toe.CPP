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
	//Player Class setup
	/*Game_class->Intro_Output();

	for(int x= 0; x< 2; x++ )
	{
		Game_class->Name_Trial(&(x ) );
	}
	Game_class->Piece_Trial();

	std::cout<<"Here are the stats so far.." <<std::endl;
	Game_class->Players_Output();
	//Board Setup*/
	Game_class->Row_Setup();
		//Set up board

	//Round Count setup
	//Game_class->Set_Rounds();
	Game_class->Board_Output();

	//Main Game Loop
	bool* main_game_loop= new bool();
	//main_game_loop[0 ]= ((Game_class->Get_Rounds()[0 ] )!= (Game_class->Get_Rounds('t' )[0 ] ) );

	/*while(main_game_loop[0 ] )
	{
		//Formatted output of the game state
		//Game_class->Board_Output();
		



		//Update the number of rounds value
		Game_class->Incriment_Rounds();
		//Update the value so it can be checked again.
		main_game_loop[0 ]= ((Game_class->Get_Rounds()[0 ] )!= (Game_class->Get_Rounds('t' )[0 ] ) );
	}*/


	//Clean up
	delete Game_class;
	Game_class= NULL;
	
	return 0;
}