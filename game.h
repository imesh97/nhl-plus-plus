/*
CS3307 INDIVIDUAL ASSIGNMENT (game.h)
Game class header

by: Imesh Nimsitha
2023/02/07
*/

#ifndef GAME_H
#define GAME_H

#include <string>

class Game
{
    private:
        std::string homeTeam, awayTeam;
        int homeScore, awayScore;

    public:
        Game();
        Game(std::string homeName, std::string awayName, int homeScore, int awayScore);
        ~Game();
        std::string getHomeTeam();
        void setHomeTeam(std::string name);
        std::string getAwayTeam();
        void setAwayTeam(std::string name);
        int getHomeScore();
        void setHomeScore(int newScore);
        int getAwayScore();
        void setAwayScore(int newScore);
};

#endif
