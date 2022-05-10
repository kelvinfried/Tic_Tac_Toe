#include <stdlib.h>
#include <time.h>
//Setup and call player class
//#include "Board.CPP"

#include "Game.CPP"

//Most of this will be converted into functions of the "Game".
int main(void )
{
	//Define the Players.
	//Player* Player_class= new Player[2 ]();

	//Define the Game Class
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

	Game_class->Row_Setup();

	//Game_class->

	
	//Setting Player Vairables:
	//Going to put these parts into their own functions so the stack made functions 
	//Memory can be relinquished once I am done with it.
		/*//Name Section
			//Used when handling the players name
		std::string temp_name, confirmed_name, char_segment, confirmation_string;
		bool confirmation, case_1;
		confirmation= true;

		int cull_amount= 16;

		for(int x= 0; x< 2; x++ )
		{
			//Reset this between the iterations -A for a new name, B so player 2 has some input on their name..
			confirmed_name="";
			confirmation= true;

			while(confirmation )
			{
				std::cout<<"Please enter your name and press enter when done: " <<std::endl;
				//Assign input to a vairable
				std::cin>> temp_name;

				std::cout<<"Is this the name you wanted: " <<temp_name <<".?" <<std::endl;
				std::cout<<"Press 'y' to agree, 'n' to disagree " <<std::endl;
				std::cin>>confirmation_string;
				
				//Setup boolean values
				case_1= ( (confirmation_string[0 ] )==int('y') );

				//Confirmation
				if(case_1 )
				{
					std::cout<<"Name accepted., your name is: " <<temp_name <<std::endl;
					//Set to false to stop the looping.
					confirmation= false;	
				}

				//Not what they wanted.
				else
				{
					//std::cout<<"Not what you wanted." <<std::endl;
				}
			}

			//Upon confirming the name is correct
			//Trim down name. (//Tested to see if strings have a escape character in c++)
			for(int y= 0; y< cull_amount; y++ )
			{
				//Updated
				char_segment= temp_name[y ];

				//If it is a null value do not carry on as that would be redudant.
				if((int(char_segment[0 ] ) ) != 0 )
				{
					//std::cout<<y <<"th value is: " <<temp_name[y ] <<std::endl;
					//std::cout<<y <<"th value is: " <<int(temp_name[y ] ) <<std::endl;
					confirmed_name+= temp_name[y ];
					//std::cout<<"Confirmed name is now: " <<confirmed_name <<std::endl;
				}

				else
				{
					//std::cout<<"Null character met, die time" <<std::endl;
					y= cull_amount;
				}
			}

			//Assign the name to the player class
			Player_class[x ].Set_Name(&(confirmed_name ) );
		}	

		std::cout<<"" <<std::endl;
		Player_class[0 ].Get_Stats();
		Player_class[1 ].Get_Stats();*/

		/*//Set the piece type.
		int player_1, player_2;
		bool piece_check;

		int player_1_piece;
		int player_2_piece;


		std::cout<<Player_class[0 ].Get_Name()[0 ] <<" please, select your piece type:";
		std::cout<<" Noughts '1' or Crosses '2';" <<std::endl;

		std::cin>>player_1;

		std::cout<<Player_class[1 ].Get_Name()[0 ]<<" please, select your piece type:";
		std::cout<<" Noughts '1' or Crosses '2';" <<std::endl;

		std::cin>>player_2;
		//Need to sanitise the inputs at some point.

		//Used to check if a random number will need to be used to sort this out.
		piece_check= (player_1!= player_2 );
		//If they're not equal
		if(piece_check )
		{
			//Pass in enum 
			player_1_piece= player_1;
			player_2_piece= player_2;

			Player_class[0 ].Set_Type(&(player_1_piece ) );
			Player_class[1 ].Set_Type(&(player_2_piece ) );
		}

		//If they're equal.
		{
			//Generate 2 random number % 2
			srand(time(NULL ) );

			//Gives a value that is either 0 or 1
			player_1_piece= rand()%2;
			player_1_piece++;
	
			switch(player_1_piece )
			{
				case 1:
					player_2_piece= 2;		
					break;

				default:
					player_2_piece= 1;
					break;
			}

			Player_class[0 ].Set_Type(&(player_1_piece ) );
			Player_class[1 ].Set_Type(&(player_2_piece ) );
		}

		std::cout<<"" <<std::endl;
		Player_class[0 ].Get_Stats();
		Player_class[1 ].Get_Stats();*/

	//Game Parameters:
		//Number of Rounds

		//Number of starting rows

		//x, y or z.
	
//Data input phase


	//Clean up
	//delete[] Player_class;
	//Player_class= NULL;

	delete Game_class;
	Game_class= NULL;
	
	return 0;
}