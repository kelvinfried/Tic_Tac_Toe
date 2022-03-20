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

void Player::Incriment_Win_Count(void )
{
	//Incriment wins up by one.
	//wins[0 ]++;
	//(win_count[0 ] )++;
	(win_count[0 ] )+= 1;
}
	//Piece
bool* Player::Get_Piece_Type(void )
{
	return piece_type;
}

void Player::Set_Piece_Type(bool* new_piece_type )
{
	piece_type[0 ]= new_piece_type[0 ];
}


//Constructors
	//Default
Player::Player(void )
{
	name= new std::string("Player_name" );
	//This is always the same regardless of the input so it stays as zero
	win_count= new int(0 );
	piece_type= new bool(false );
};
	//Overridden
Player::Player(std::string* start_name, bool* piece_type )
{
	//Forgot to dereferace the passed in name.
	name= new std::string(start_name[0 ] );
	win_count= new int(0 );	
	piece_type= new bool(piece_type[0 ] );
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
	delete piece_type;
	piece_type= NULL;
}
