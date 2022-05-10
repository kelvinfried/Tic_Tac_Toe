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