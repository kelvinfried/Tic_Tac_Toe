#include "Player.H"

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

/*void Player::Set_Win_Count(int* new_win_count )
{
	win_count[0 ]= new_win_count[0 ];
}*/

void Player::Incriment_Win_Count(void )
{
	//Incriment wins up by one.
	//wins[0 ]++;
	//(win_count[0 ] )++;
	(win_count[0 ] )+= 1;
}

	//Piece

//Constructors
	//Default
Player::Player(void )
{
	name= new std::string("Player_name" );
	//This is always the same regardless of the input so it stays as zero
	win_count= new int(0 );
};
	//Overridden
Player::Player(std::string* start_name )
{
	//Forgot to dereferace the passed in name.
	name= new std::string(start_name[0 ] );
	win_count= new int(0 );	
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
}
