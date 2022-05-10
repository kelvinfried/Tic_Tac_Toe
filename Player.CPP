#include "Player.H"

//-----------------------------------------Constructor:
	//Default
Player::Player(void )
{
//Attrubutes
	//Used  to store the name passed by the player.
	name= new std::string("Player_name" );

	//Keeps track of how many wins each player has
	win_count= new int(0 );

	//Shows which piece the player has using the piece identifier data type
	Piece_class= new Piece();

	//To store inputs
	//Array to store input 1 and 2.
	inputs= new int[2 ];
};

//Overridden
Player::Player(std::string* start_name, piece_identifier* new_Piece )
{
//Attrubutes
	//Used  to store the name passed by the player.
	name= new std::string(start_name[0 ] );

	//Keeps track of how many wins each player has
	win_count= new int(0 );	

	//Shows which piece the player has using the piece identifier data type
	Piece_class= new Piece(new_Piece[0 ] );

	//To store inputs
	inputs[0 ]= 0;
	inputs[1 ]= 0;
};

//-----------------------------------------Destructor:
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
	delete Piece_class;
	Piece_class= NULL;
}


//Public Functions
//-----------------------------------------Getters and Setters:
//----------------------Player Statistics
//----------------------Name
//To return their name, used for outputs for the stats part of the UI.
std::string* Player::Get_Name(void )
{
	//Returns the pointer
	return name;
}

//To Set their name after created
void Player::Set_Name(std::string* new_name )
{
	//Added dereferancing so the pointer is not overwritten but the value is.
	name[0 ]= new_name[0 ];
}

//----------------------Win Count
//Return the win count
int* Player::Get_Win_Count(void )
{
	return win_count;
}

//Upon winning incriment the win counter to update it
void Player::Incriment_Win_Count(void )
{
	//Incriment wins up by one.
	//(win_count[0 ] )++;
	(win_count[0 ] )+= 1;
}

//----------------------Piece Type
piece_identifier* Player::Get_Type(void )
{
	return (Piece_class->Get_Type() );
}

//Used to set the piece after the player is created, done as with my current method I cannot use anything other than the default constructor.
void Player::Set_Type(int* new_piece )
{
	Piece_class->Set_Type(new_piece );
}

//----------------------Piece Output
//Needed as the player class is private
std::string* Player::Get_Piece_Output(void )
{
	return Piece_class->Get_Output();
}

//----------------------Stats Output
//Formatted output of the player stats
void Player::Get_Stats(void )
{
	std::cout<<"###_Player-1: " <<name[0 ] <<"_##_Win-Count: " <<win_count[0 ];
	
	
	switch(Get_Type()[0 ] )
	{
		case cross:
			std::cout<<"_#_Piece-Type: Cross__" <<std::endl;
			break;

		case nought:
			std::cout<<"_#_Piece-Type: Nought__" <<std::endl;
			break;

		default:
			std::cout<<"_#_Piece-Type: Nought__" <<std::endl;
			break;
	}
}

void Player::Get_Stats(int* overload_int )
{
	std::cout<<"###_Player-" <<overload_int[0 ] <<": " <<name[0 ] <<"_##_Win-Count: " <<win_count[0 ];
	
	
	switch(Get_Type()[0 ] )
	{
		case cross:
			std::cout<<"_#_Piece-Type: Cross__" <<std::endl;
			break;

		case nought:
			std::cout<<"_#_Piece-Type: Nought__" <<std::endl;
			break;

		default:
			std::cout<<"_#_Piece-Type: Nought__" <<std::endl;
			break;
	}
}

//Debug	-Used for when there will be more than one player assigned to the pointer
void Player::Get_Stats(char overload_char )
{
	std::cout<<"Player Stats block:" <<std::endl;
	std::cout<<"Player name is: " <<name[0 ] <<std::endl;
	std::cout<<"Player win count is: " <<win_count[0 ] <<std::endl;
	std::cout<<"Player piece type is: " <<Piece_class->Get_Type()[0 ] <<std::endl;
}

//----------------------Player Inputs
//Input handling
int* Player::Get_Inputs(void )
{
	return inputs;
}

//Passes both inputs into the input for the player.
void Player::Set_Inputs(int input_1, int input_2 )
{
	inputs[0 ]= input_1;
	inputs[1 ]= input_2;
}