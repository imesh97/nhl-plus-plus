/*
CS3307 INDIVIDUAL ASSIGNMENT (game.cpp)
Game class for storing NHL schedule data

by: Imesh Nimsitha
2023/02/07
*/

#include "game.h"

/*
CONSTRUCTOR: Game
Initializes Game object with default values
@param None
@return None
*/
Game::Game()
{
    this->homeTeam = ""; // default: empty string
    this->awayTeam = "";
    this->homeScore = 0; // default: score 0
    this->awayScore = 0;
};

/*
CONSTRUCTOR: Game
Initializes Game object with given values
@param Home team name (string), Away team name (string), Home team score (int), Away team score (int)
@return None
*/
Game::Game(std::string homeName, std::string awayName, int homeScore, int awayScore)
{
    this->homeTeam = homeName; // set values to given parameters
    this->awayTeam = awayName;
    this->homeScore = homeScore;
    this->awayScore = awayScore;
};

/*
DESTRUCTOR: Game
Empty destructor for Game object
@param None
@return None
*/
Game::~Game(){
    // empty (no dynamic memory needs to be freed)
};

/*
FUNCTION: Get home team name
Access home team name string
@param None
@return Home team name (string)
*/
std::string Game::getHomeTeam()
{
    return this->homeTeam;
};

/*
FUNCTION: Set home team name
Modify home team name string
@param New name (string)
@return None (void)
*/
void Game::setHomeTeam(std::string name)
{
    this->homeTeam = name;
};

/*
FUNCTION: Get away team name
Access away team name string
@param None
@return Away team name (string)
*/
std::string Game::getAwayTeam()
{
    return this->awayTeam;
};

/*
FUNCTION: Set away team name
Modify away team name string
@param New name (string)
@return None (void)
*/
void Game::setAwayTeam(std::string name)
{
    this->awayTeam = name;
};

/*
FUNCTION: Get home team score
Access home team name score
@param None
@return Home team score (int)
*/
int Game::getHomeScore()
{
    return this->homeScore;
};

/*
FUNCTION: Set home team score
Modify home team name score
@param New score (int)
@return None (void)
*/
void Game::setHomeScore(int newScore)
{
    this->homeScore = newScore;
};

/*
FUNCTION: Get away team score
Access away team name score
@param None
@return Away team score (int)
*/
int Game::getAwayScore()
{
    return this->awayScore;
};

/*
FUNCTION: Set away team score
Modify away team name score
@param New score (int)
@return None (void)
*/
void Game::setAwayScore(int newScore)
{
    this->awayScore = newScore;
};
