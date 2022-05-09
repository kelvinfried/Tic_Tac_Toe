#include "Player.H"

//Constructors
	//Default
Player::Player(void )
{
//Attrubutes
	//Used  to store the name passed by the player.
	name= new std::string("Player_name" );

	//Keeps track of how many wins each player has
	win_count= new int(0 );

	//Shows which piece the player has using the piece identifier data type
	Piece= new Piece(nothing );

	//To store inputs
	input_1= 0;
	input_2= 0;
};

	//Overridden
Player::Player(std::string* start_name, int piece )
{
//Attrubutes
	//Used  to store the name passed by the player.
	name= new std::string(start_name[0 ] );

	//Keeps track of how many wins each player has
	win_count= new int(0 );	

	//Shows which piece the player has using the piece identifier data type
	Piece= new Piece(piece );

	//To store inputs
	input_1= 0;
	input_2= 0;
};

//Destructor
Player::~Player(void )
{
//Relinquish memory and null the pointer
	//Name
	delete name;
	name= NULL;
	
	//Wins
	delete win_count;
	win_count= NULL;
	
	//Piece_type
	delete Piece;
	Piece= NULL;
}


//Getters and Setters
	//Name
std::string* Player::Get_Name(void )
{
	//Returns the pointer
	return name;
}

void Player::Set_Name(std::string* new_name )
{
	//Added dereferancing so the pointer is not overwritten but the value is.
	name[0 ]= new_name[0 ];
}

	//Win count
int* Player::Get_Win_Count(void )
{
	return win_count;
}

void Player::Incriment_Win_Count(void )
{
	//Incriment wins up by one.
	//(win_count[0 ] )++;
	(win_count[0 ] )+= 1;
}

	//Piece
piece_identifier* Player::Get_Type(void )
{
	return &(type );
}

	//Input handling
int Player::Get_Input_1(void )
{
	return input_1;
}

void Player::Set_Input_1(int new_input )
{
	input_1= new_input;
}

int Player::Get_Input_2(void )
{
	return input_2;
}

void Player::Set_Input_2(int new_input )
{
	input_2= new_input;
}



//Debug	-Used for when there will be more than one player assigned to the pointer
void Player::Get_Stats(void )
{
	std::cout<<"Player Stats block:" <<std:endl;
	std::cout<<"Player name is: " <<name[0 ] <<std::endl;
	std::cout<<"Player win count is: " <<win_count[0 ] <<std::endl;
	std::cout<<"Player piece type is: " <<piece_type[0 ] <<std::endl;
}


