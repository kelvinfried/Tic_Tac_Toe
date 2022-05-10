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
//-----------------------------------------Getters and Setters:
//----------------------Player Statistics
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

	//Used to define the max amount of character a name can be
	int cull_amount= 16;

	//Used to keep the player into the loop until they're happy with their input.
	bool confirmation= true;

	bool case_1= false;

	while(confirmation )
	{
		std::cout<<"" <<std::endl;
		std::cout<<"Player "<<iteration_count[0 ] <<" Please enter your name and press enter when done: " <<std::endl;
		//Assign input to a vairable
		std::cin>> temp_name;

		//Lets the player commit to their 
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

//----------------------Board Statistics

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
		std::cout<<"" <<std::endl;
		Player_class[0 ].Get_Stats();
		for(int x= 0; x< 2; x++ )
		{
			std::cout<<"--#---#---#---#--";
		} 
		std::cout<<"" <<std::endl;
		Player_class[1 ].Get_Stats();
}

//----------------------Board Output

//-----------------------------------------Player Inputs:
//----------------------Player;

//----------------------Board;