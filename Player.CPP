#include "Player.H"

//Getters and Setters
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

//Constructors
	//Default
Player::Player(void )
{
	name= new std::string("Player_name" );
};
	//Overridden
Player::Player(std::string* new_name )
{
	//Forgot to dereferace the passed in name.
	name= new std::string(new_name[0 ] );
};

//Destructor
Player::~Player(void )
{
	//Relinquish memory and null the pointer
	delete name;
	name= NULL;
}