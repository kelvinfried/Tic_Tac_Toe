#include "Game.H"

//-----------------------------------------Constructor:
Game::Game(void )
{
	Board_class= new Board();

	Player_class= new Player[2 ];

	number_of_rounds= 3;
	round_counter= 3;
}


//-----------------------------------------Destructor:
Game::~Game(void )
{
	delete Player_class;
	Player_class= NULL;
}


//Public Functions
//-----------------------------------------Input Handling Section:
//----------------------Handle Input:
//Used to test against if the players input is within the correct range for the pieces assignment.
bool Game::Input_Sanitization(int* test_data )
{
	if((0< test_data[0 ] )&& (test_data[0 ] <3) )
	{
		//Valid inputted number
		return true;
	}

	else
	{
		//Invalid number.
		return false;
	}
}
//Overloaded
//Used to test against if the players input is within the correct range for the row number.
bool Game::Input_Sanitization(int* test_data, char overload_char )
{
	if((1< test_data[0 ] )&& (test_data[0 ] <6) )
	{
		//Valid inputted number
		return true;
	}

	else
	{
		//Invalid number.
		return false;
	}
}


//-----------------------------------------Getters and Setters:
//----------------------Player Statistics
//Used to set player names.
void Game::Name_Trial(int* iteration_count )
{
	//Used to hold original input name.
	std::string temp_name= "";
	//Used to hold the input to tell if the player accepts their name or not.
	std::string confirmation_string= "";
	//Used to hold the final sanitized name.
	std::string confirmed_name= "";
	//Used to store the current part of the string that will be analysed.
	std::string current_string_part= "";

	//Used to number the player consistantly (in outputs)
	int player_number= iteration_count[0 ];
	player_number++;

	//Used to define the max amount of character a name can be
	int cull_amount= 16;

	//Used to keep the player into the loop until they're happy with their input.
	bool confirmation= true;

	bool case_1= false;

	while(confirmation )
	{
		
		std::cout<<"" <<std::endl;
		std::cout<<"Player "<<player_number <<" Please enter your name and press enter when done: " <<std::endl;
		//Assign input to a vairable
		std::cin>> temp_name;

		//Lets the player commit to their 
		std::cout<<"" <<std::endl;
		std::cout<<"Is this the name you wanted: " <<temp_name <<".?" <<std::endl;
		std::cout<<"Press 'y' to agree, 'n' to disagree " <<std::endl;
		std::cin>>confirmation_string;
		
		//Setup boolean values
		case_1= ( (confirmation_string[0 ] )==int('y') );

		//Confirmation
		if(case_1 )
		{
			//Set to false to stop the looping.
			std::cout<<"Name accepted., your name is: " <<temp_name <<std::endl;
			confirmation= false;	
		}

		//Not what they wanted.
		else
		{
			//Looops back,
			//std::cout<<"Not what you wanted." <<std::endl;
		}
	}

	//Upon confirming the name is correct
	//Trim down name. (//Tested to see if strings have a escape character in c++)
	for(int y= 0; y< cull_amount; y++ )
	{
		current_string_part= temp_name[y ];
		//If it is a escape character value do not carry on as that would be redudant/ cause a segment error.
		if(int(current_string_part[0 ] ) != 0 )
		{
			//Assigns the current character from the string to
			confirmed_name+= current_string_part;
			//std::cout<<y <<"th value is: " <<temp_name[y ] <<std::endl;
			//std::cout<<y <<"th value is: " <<int(temp_name[y ] ) <<std::endl;
			//std::cout<<"Confirmed name is now: " <<confirmed_name <<std::endl;
		}

		else
		{
			//std::cout<<"Null character met, die time" <<std::endl;
			y= cull_amount;
		}
	}

	//Assign the name to the player class
	Player_class[iteration_count[0 ] ].Set_Name(&(confirmed_name ) );
}

//Used to set the players piece type
void Game::Piece_Trial(void )
{
	//Used to store the players "inputs" 
	int player_1, player_2;
	//Used to Keep the player inside of a loop until their input is correct 
	bool input_check= true;

	//Used to check for which piece assignment should be used
	bool piece_check;
	
	//Player 1's loop
	while(input_check )
	{
		std::cout<<Player_class[0 ].Get_Name()[0 ] <<" please, select your piece type:";
		std::cout<<" Noughts '1' or Crosses '2';" <<std::endl;
		//Pass input to vairable
		std::cin>>player_1;

		//If it is true carry on to the next player.
		if( Input_Sanitization(&(player_1 ) ) )
		{
			input_check= false;
		}

		else
		{
			;
		}

	}
	//Reset the loop value for the next player.
	input_check= true;	

	while(input_check )
	{
		std::cout<<Player_class[1 ].Get_Name()[0 ]<<" please, select your piece type:";
		std::cout<<" Noughts '1' or Crosses '2';" <<std::endl;

		std::cin>>player_2;

		if( Input_Sanitization(&(player_2 ) ) )
		{
			input_check= false;
		}

		else 
		{
			;
		}
	}

	//If there is conflict the game cannot work so a check needs to be made.
	piece_check= (player_1!= player_2 );

	//If they're not equal- "Normal case"
	if(piece_check )
	{
		//Pass in enum
		Player_class[0 ].Set_Type(&(player_1 ) );
		Player_class[1 ].Set_Type(&(player_2 ) );
	}

	//If they're equal- "Abnormal case"
	else
	{
		//Generate a random number
		srand(time(NULL ) );

		//Mod 2 to return 1 or 0; Which is then incrimented to get within the right range.
		player_1= rand()%2;
		player_1++;

		//Based on what the 1st players value is, the second player gets the "opposite" 
		switch(player_1 )
		{
			case 1:
				player_2= 2;		
				break;

			default:
				player_2= 1;
				break;
		}

		//Commit these piece values.
		Player_class[0 ].Set_Type(&(player_1 ) );
		Player_class[1 ].Set_Type(&(player_2 ) );
	}

	std::cout<<"" <<std::endl;
}

//----------------------Board Statistics
int* Game::Row_Setup(void )
{
	//Used to hold the size for the board
	int size;

	bool check= false;
	//To keep it itearting and work with the input sanitization function
	while(check!= true )
	{
		std::cout<<"" <<std::endl;
		std::cout<<"Please enter how many rows and collums you want to start with, from 2- 5:" <<std::endl;
		//holds the input 
		std::cin>>size;
		
		//Checks it.
		check= Input_Sanitization(&(size ), 't' );
	}

	switch(size )
	{
		case 2:
		case 3:
		case 4:
			break;

		default:
			break;
	}

}

//----------------------Rules Output 
//Used to print out the rules segment
void Game::Intro_Output(void )
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

	std::cout<<"Each turn you will an action, which is to place your piece onto an";
	std::cout<<" empty place in the grid" <<std::endl;
	std::cout<<"With the goal to line up 3 pieces horizontally, vertically or diagonally." <<std::endl;

	std::cout<<"As a player you can choose one of two piece styles, these being an 'X' and";
	std::cout<<" an 'O'."<<std::endl;

	std::cout<<"The grid is initially comprised of 3x 3 empty spaces, which progressivly get";
	std::cout<<" filled as the game progress. " <<std::endl;
	std::cout<<"The goal is to be the first one to reach 3 (or more) consecutive pieces " <<std::endl;

	//Control Scheme
	std::cout<<"" <<std::endl;
	std::cout<<"" <<std::endl;
	std::cout<<"#----The Control scheme----#" <<std::endl;
	std::cout<<"There will be prompts telling you what to do when interacting";
	std::cout<<" with the game and you must follow them to progress." <<std::endl;
	std::cout<<"For example entering a position on the board," <<std::endl;
	std::cout<<"" <<std::endl;
	std::cout<<"" <<std::endl;
}

//----------------------Player Output
//Used to ouput the two players stats bars.
void Game::Players_Output(void )
{
		int player_1= 1;
		int player_2= 2;

		std::cout<<"" <<std::endl;
		Player_class[0 ].Get_Stats(&(player_1 ) );
		for(int x= 0; x< 2; x++ )
		{
			std::cout<<"--#---#---#---#--";
		} 
		std::cout<<"" <<std::endl;
		Player_class[1 ].Get_Stats(&(player_2 ) );
}

//----------------------Board Output

//-----------------------------------------Player Inputs:
//----------------------Player;

//----------------------Board;