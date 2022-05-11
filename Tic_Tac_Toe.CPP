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


	//Outer loop for each round
	for(int* current_round= new int(0 ); current_round[0 ]< (Game_class->Get_Rounds()[0 ] ); current_round[0 ]++ )
	{
		//Reset every round.
		win_tracker= false;
		current_turn= -1;

		//Inner loop for the main game logic.
		while(true )
		{
			current_turn++;

			//Used to keep track of which player is going to play
			current_player= current_turn;
			current_player= current_player% 2;

			//Formatted game State (Output):
			Game_class->Board_Output();

			std::cout<<"Current player is: " <<current_player <<std::endl;

			//Input
			Game_class->Board_Insertion_Intro(&(current_player ) );
			Game_class->Board_Insertion(&(current_player ) );

			//Output Again:
			std::cout<<"" <<std::endl;
			std::cout<<"After placing your piece:" <<std::endl;
			Game_class->Board_Output();

			win_tracker=Game_class->Win_Check(&(current_player ) );

			if(win_tracker )
			{
				break;
			}
		
			else
			{
				std::cout<<"" <<std::endl;
				std::cout<<"No win." <<std::endl;
			}
		}
	}
	//Outer loop for each round.
	/*while(main_game_loop[0 ] )
	{
		//Inner loop for each round itself.
		while(current_round[0 ] )
		{
			holdy_thing= false;

			//Used to keep track of the current turn
			current_turn[0 ]++;
	
			//Used to keep track of which players turn it currently is
			current_player[0 ]= current_turn[0 ];
			current_player[0 ]%= 2;
	
			std::cout<<"Current player is:" << current_player[0] <<std::endl;

			//Formatted output of the game state
			Game_class->Board_Output();

			
			//Input
			Game_class->Board_Insertion_Intro(current_player );
			Game_class->Board_Insertion(current_player );

			std::cout<<"" <<std::endl;
			std::cout<<"After placing your piece:" <<std::endl;
			Game_class->Board_Output();

			holdy_thing= Game_class->Win_Check(current_player );
			
			//Win Check
			//Check(int* start_row, int* start_collum, Piece* Piece, int* points_so_far );
			//Win condition
			if(current_turn[0 ]== 2 )
			{
				current_round[0 ]= false;;
			}

			else
			{
				;
			}
		}

		//Update the number of rounds value
		Game_class->Incriment_Rounds();
		//Update the value so it can be checked again.
		main_game_loop[0 ]= ((Game_class->Get_Rounds()[0 ] )!= (Game_class->Get_Rounds('t' )[0 ] ) );
	}*/

	//Win Output.
	std::cout<< "You win " <<std::endl;


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