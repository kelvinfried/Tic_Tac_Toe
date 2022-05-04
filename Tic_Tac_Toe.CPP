#include <iostream>

int main(void )
{
	//This is the outro branch
		//If the condition check returns a true for one player or another 
		//a output should referance this

	//Generic Output statement.
		//Place holder vairables, will be replaced.
	int game_count= 1;	//take the "Game count tracker."
	int player_score= 1;	//Takes the score from the player class.
	int player_number= 0;	//Takes the number of the player~ Could also be piece  type
	std::string player_name= "Steve"; //Takes the name from the players class.

	std::cout<<"The winner of the set of: " <<game_count <<" games." <<std::endl;
	std::cout<<"Is the person who scored a total of " <<player_score <<" wins." <<std::endl;

	std::cout<<"Congratualtions player " <<player_number <<": " <<player_name <<std::endl;
	std::cout<<"You win." <<std::endl;

	
	return 0;
}