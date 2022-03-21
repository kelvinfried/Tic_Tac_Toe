#include <iostream>
//Setup and call player class
#include "Player.CPP"

//Test Definition of the class.
//All attributes must be set before The 'main games' run time.
/*class Player
{
	private:
	//Attributes
		//Used  to store the name passed by the player.
		std::string name;	
		//Keeps track of how many wins each player has
		int wins;
		//Shows which piece the player has 0= O, 0!= X;
		bool piece;
		
	public:
	//Getters and Setters
		//Name
		std::string Get_Name(void )
		{
			return name;
		}
		
		void Set_Name(std::string new_name )
		{
			name= new_name;
		}
		
		//Wins
		int Get_Wins(void )
		{
			return wins;
		}
			//does not require anything to be passed in as it can only go up by one.
		void Incriment_Win(void )
		{
			wins++;
		}
		
		//Piece
		bool Get_Piece(void )
		{
			return piece;
		}
		
		void Set_Piece(bool new_piece )
		{
			piece= new_piece;
		}
		
	//Constructor
		//Default, for now
		Player()
		{
			name= "Player_name";
			wins= 0;
			piece= 0;
		}
		
	//Destructor
		//Will be used for when the vairables are made dynamic because of their lifespans
		~Player()
		{
		}
};*/
/*class Player
{
	private:
	//Attributes	-All dynamic, so the attributes are just pointers
		//Used  to store the name passed by the player.
		std::string* name;	
		
	public:
	//Getters and Setters
		//Name- Now returns a string pointer, so it will carry the memory address of the name so it can be printed.
		std::string* Get_Name(void )
		{
			//return name[0 ];
			return name;
		}
			
		void Set_Name(std::string* new_name )
		{
			//Added dereferancing so the pointer is not overwritten but the value is.
			name[0 ]= new_name[0 ];
		}

	//Constructor
		//Default, for now
		Player()
		{
			//name[0 ]= "Player_name";	//Forgot to define the string in memory correctly before using it.
			name= new std::string("Player_name" );
		}
		
	//Destructor
		//Will be used for when the vairables are made dynamic because of their lifespans
		~Player()
		{
			//Relinquish memory and null the pointer
			delete name;
			name= NULL;
		}
};*/


int main(void )
{
//This is the intro segment of the program
	/*//Intro Text
	std::cout<<"#----Tic Tac Toe Console Application----#" <<std::endl <<std::endl;
	std::cout<<"Welcome to Tic Tac Toe." <<std::endl;
	std::cout<<"This is a 2 Player game and will require you and your opponent to swap after every turn for the game to function." <<std::endl <<std::endl <<std::endl;
	//Rules Section
	std::cout<<"#----The rules are as follows----#" <<std::endl;
	std::cout<<"As stated this is a two player game, in which you and your opponent take turns to play a move." <<std::endl;
	std::cout<<"Each turn you will have one action, which is to place your piece onto an empty place in the grid, with the goal to line up 3 pieces horizontally, vertically or diagonally." <<std::endl;
	std::cout<<"As a player you can choose one of two piece styles, these being an 'X' and an 'O'." <<std::endl;
	std::cout<<"The grid is comprised of 3x 3 initially empty spaces, which progressivly get filled as the game progress, with the goal of it being the first one to reach 3 consecutive pieces as mentioned above, You can only place your pieces within this grind." <<std::endl <<std::endl;
	//Control Scheme
	std::cout<<"#----The Control scheme----#" <<std::endl;
	std::cout<<"There will be prompts onto the console telling you what to do when interacting with the game and you must follow them to progress." <<std::endl;
	std::cout<<"For example entering the position you wish to select, there will be a prompt and until a valid position is passed in" <<std::endl;*/
	
//Data input phase

//Testing the class
	Player test;
	
	//Dynamic version of the "test" object, using the default constructor
	Player* player_pointer= new Player();
	
//Name Test
	//std::cout<<"The players name is " <<test.Get_Name() <<" and has a win count of " <<test.Get_Wins() <<" using the " <<test.Get_Piece() <<std::endl;
	/*std::cout<<"The players name is " <<*test.Get_Name() <<std::endl <<std::endl;
	
	std::string new_name= "KelvinFried";
	test.Set_Name(&new_name );	
	//On compile G++ tells me that i need to specify that it needs to be a memory address when passing it in.
	std::cout<<"The players name is " <<*test.Get_Name() <<std::endl;*/
//Win Test Part 1
	//std::cout<<"The players number of wins is " <<*(test.Get_Win_Count() ) <<std::end;	//Causes issues with cout
	/*int win_count= *test.Get_Win_Count();
	std::cout<<"win count is " <<win_count <<std::endl;
	
	test.Incriment_Win_Count();
	
	win_count= *test.Get_Win_Count();
	std::cout<<"win count is " <<win_count <<std::endl;
	win_count= *test.Get_Win_Count();
	std::cout<<"win count is " <<win_count <<std::endl;
	//std::cout<<"The players number after an incriment is wins is " <<*test.Get_Wins() <<std::end;	//Raises error
	
	test.Set_Win_Count(&(win_count+= 1 ) );
	std::cout<<"win count is " <<win_count <<std::endl;
	
	test.Incriment_Win_Count();
	std::cout<<"win count is " <<test.Get_Win_Count()[0 ] <<std::endl;*/
//Win Test Part 2
	/*std::cout<<"Win count is " <<test.Get_Win_Count()[0 ] <<std::endl;
	//Incriment
	for(int i= 0; i<4; i++ )
	{
		test.Incriment_Win_Count();
		std::cout<<"Win count is " <<test.Get_Win_Count()[0 ] <<std::endl;
	}*/
	
//Piece type
/*	if(test.Get_Piece_Type()[0 ]== true )
	{
		std::cout<<"The players current piece type is X" <<std::endl;
	}
	
	else
	{
		std::cout<<"The players current piece type is O" <<std::endl;
	}
	
	bool tru= true;
	test.Set_Piece_Type(&tru );
	
	if(test.Get_Piece_Type()[0 ]== true )
	{
		std::cout<<"The players current piece type is X" <<std::endl;
	}
	
	else
	{
		std::cout<<"The players current piece type is O" <<std::endl;
	}*/
	
	//Output	-Static
	std::cout<<"Player stats block:" <<std::endl;
	std::cout<<"Their name should be 'Player_name' and is: " <<test.Get_Name()[0 ] <<std::endl;
	std::cout<<"Their win count should be '0' and is: " <<test.Get_Win_Count()[0 ] <<std::endl;
	std::cout<<"Their piece type should be '0' and is: " <<test.Get_Piece_Type()[0 ] <<std::endl <<std::endl;
	
	//Output	-Dynmaic
	std::cout<<"Player ''2'' stats block:" <<std::endl;
	std::cout<<"Their name should be 'Player_name' and is: " <<player_pointer[0 ].Get_Name()[0 ] <<std::endl;
	std::cout<<"Their win count should be '0' and is: " <<player_pointer[0 ].Get_Win_Count()[0 ] <<std::endl;
	std::cout<<"Their piece type should be '0' and is: " <<player_pointer[0 ].Get_Piece_Type()[0 ] <<std::endl <<std::endl;
	
	
	
	return 0;
}