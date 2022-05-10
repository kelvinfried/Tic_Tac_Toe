#include <iostream>
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
		//Name Section
		for(int x= 0; x< 2; x++ )
		{
			//
			std::string temp_name, confirmed_name, char_segment;
			std::cout<<"Please enter your name and press enter when done: " <<std::endl;
			
			//Assign input to a vairable
			std::cin>> temp_name;
			//Trim down name.
				//Test to see if strings have a escape character in c++
	
			std::cout<<"" <<std::endl;

			//Upon confirming the name is correct
			int cull_amount= 16;
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
		}	


		//Set the piece type.

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