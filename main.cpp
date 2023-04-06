/*
CS3307 INDIVIDUAL ASSIGNMENT (main.cpp)
For running the program and displaying output

by: Imesh Nimsitha
2023/02/07
*/

#include "request.h"
#include "game.h"

/*
FUNCTION: Main
Executes the API request and outputs schedule data
@param None
@return 0 if successful execution, exits if error
*/
int main()
{
	std::string fetchUrl = "https://statsapi.web.nhl.com/api/v1/schedule?season=20222023&gameType=R"; // fetch 2022-23 regular season games only
	Request api(fetchUrl);																			  // create new api request object with url

	bool req = api.execute(); // execute request
	if (!req)
	{ // if request error -> print then exit program
		std::cerr << "ERROR: Unable to connect to the NHL Stats API." << std::endl;
		exit(1);
	};

	std::vector<Game> games = api.parse(); // get vector of game objects
	for (unsigned int i = 0; i < games.size(); i++)
	{ // iterate through games and print scores
		std::cout << games[i].getHomeTeam() << " vs. " << games[i].getAwayTeam() << ": ";
		std::cout << games[i].getHomeScore() << " - " << games[i].getAwayScore() << std::endl;
	}

	return 0;
};
