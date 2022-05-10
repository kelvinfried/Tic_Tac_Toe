#include <iostream>
#include <stdlib.h>
#include <time.h>
//Setup and call player class
#include "Board.CPP"

//Most of this will be converted into functions of the "Game".
int main(void )
{
//This is the intro segment of the program
	//Intro Text
	std::cout<<"#----Tic Tac Toe Console Application----#" <<std::endl <<std::endl;
	std::cout<<"Welcome to Tic Tac Toe." <<std::endl;
	std::cout<<"This is a 2 Player game and will require you and your opponent to swap";
	std::cout<<" after every turn for the game to function." <<std::endl <<std::endl <<std::endl;

	//Rules Section
	std::cout<<"#----The rules are as follows----#" <<std::endl;
	std::cout<<"As stated his is a two player game, in which you and your opponent take turns to";
	std::cout<<" play a move." <<std::endl;

	std::cout<<"Each turn you will have one action, which is to place your piece onto an";
	std::cout<<" empty place in the grid, with the goal to line up 3 pieces horizontally,";
	std::cout<<" vertically or diagonally." <<std::endl;

	std::cout<<"As a player you can choose one of two piece styles, these being an 'X' and";
	std::cout<<" an 'O'."<<std::endl;

	std::cout<<"The grid is comprised of 3x 3 initially empty spaces, which progressivly get";
	std::cout<<" filled as the game progress, with the goal of it being the first one to reach";
	std::cout<<" 3 (or more) consecutive pieces as mentioned above, You can only place your";
	std::cout<<" pieces within this grid." <<std::endl <<std::endl;

	//Control Scheme
	std::cout<<"#----The Control scheme----#" <<std::endl;
	std::cout<<"There will be prompts onto the console telling you what to do when interacting";
	std::cout<<" with the game and you must follow them to progress." <<std::endl;
	std::cout<<"For example entering the position you wish to select, there will be a prompt";
	std::cout<<" and until a valid position is passed in" <<std::endl;

	//Define the Players.
	Player* Player_Class= new Player[2 ]();

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
					std::cout<<"Not what you wanted." <<std::endl;
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
					std::cout<<"Confirmed name is now: " <<confirmed_name <<std::endl;
				}

				else
				{
					std::cout<<"Null character met, die time" <<std::endl;
					y= cull_amount;
				}
			}

			//Assign the name to the player class
			Player_Class[x ].Set_Name(&(confirmed_name ) );
		}	

		std::cout<<"" <<std::endl;
		Player_Class[0 ].Get_Stats();
		Player_Class[1 ].Get_Stats();*/

		//Set the piece type.
		int player_1, player_2;
		bool piece_check;

		int player_1_piece;
		int player_2_piece;

		//std::cout<<Player_Class[0 ].Get_Name()[0 ] <<" please, select your piece type:"
		std::cout<<" Noughts '1' or Crosses '2';" <<std::endl;

		std::cin>>player_1;

		//std::cout<<Player_Class[1 ].Get_Name()<<" please, select your piece type:"
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

			Player_Class[0 ].Set_Type(&(player_1_piece ) );
			Player_Class[1 ].Set_Type(&(player_2_piece ) );
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

			Player_Class[0 ].Set_Type(&(player_1_piece ) );
			Player_Class[1 ].Set_Type(&(player_2_piece ) );
		}

		std::cout<<"" <<std::endl;
		Player_Class[0 ].Get_Stats();
		Player_Class[1 ].Get_Stats();

	//Game Parameters:
		//Number of Rounds

		//Number of starting rows

		//x, y or z.
	
//Data input phase


	//Clean up
	delete[] Player_Class;
	Player_Class= NULL;

	return 0;
}