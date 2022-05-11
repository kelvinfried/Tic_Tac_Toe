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
	Game_class->Piece_Trial();
	Game_class->Row_Setup();
	Game_class->Players_Output();
		//Set up board

	//Round Count setup
	Game_class->Set_Rounds();
	

	//Main Game Loop
	/*bool* main_game_loop= new bool();
	main_game_loop[0 ]= ((Game_class->Get_Rounds()[0 ] )!= (Game_class->Get_Rounds('t' )[0 ] ) );

	//bool* current_round= new bool();
	//int* current_turn= new int(0 );
	int* current_player= new int(0 );

	bool holdy_thing;*/

	int current_turn= 0;
	int current_player= -1;
	bool win_tracker= false;
	bool game_tracker= true;


	//Outer loop for each round
	for(int* current_round= new int(0 ); current_round[0 ]< (Game_class->Get_Rounds()[0 ] ); current_round[0 ]++ )
	{
		//Reset every round.
		win_tracker= false;
		current_turn= -1;
		game_tracker= true;

		//Inner loop for the main game logic.
		while(game_tracker )
		{
			current_turn++;

			//Used to keep track of which player is going to play
			if(current_turn== 0 )
			{
				current_player= 0;
			}
			
			else
			{
				current_player= current_turn;
				current_player= current_player;
				current_player= current_player% 2;
			}

			//Formatted game State (Output):
			Game_class->Board_Output();

			std::cout<<"Current player is: " <<current_player <<std::endl;

			//Input
				//Get
			Game_class->Board_Insertion_Intro(&(current_player ) );
				//Pass onto board.
			Game_class->Board_Insertion(&(current_player ) );

			//Output Again:
			std::cout<<"" <<std::endl;
			std::cout<<"After placing your piece:" <<std::endl;
			Game_class->Board_Output();

			//win_tracker= Game_class->Win_Check(&(current_player ) );
			//Done to ensure the correct board is used in checking.
			win_tracker= Game_class->Win_Check((Game_class->Get_Board() ), &(current_player ) );

			if(win_tracker )
			{
				game_tracker= false;
				break;
			}
		
			else
			{
				//std::cout<<"" <<std::endl;
				//std::cout<<"No win." <<std::endl;
			}
		}
		
		//Since they won their value needs to be updated.
		Game_class->Incriment_Rounds(&(current_player ) );
	}

	//Win Output.
	Game_class->Win_Screen();
	
	
	//Clean up
	delete Game_class;
	Game_class= NULL;

	//Temp
	/*delete main_game_loop;
	main_game_loop= NULL;

	delete current_turn;
	current_turn= NULL;

	delete current_round;
	current_round= NULL;

	delete current_player;
	current_player= NULL;*/
	
	return 0;
}