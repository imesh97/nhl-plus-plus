/*
CS3307 INDIVIDUAL ASSIGNMENT (request.h)
Request class header

by: Imesh Nimsitha
2023/02/07
*/

#ifndef REQUEST_H
#define REQUEST_H

#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <curl/curl.h>
#include "json.hpp"
#include "game.h"

struct MemoryStruct
{
	char *memory;
	size_t size;
};

class Request
{
	private:
		std::string url;
		MemoryStruct chunk;

	public:
		Request(std::string url);
		~Request();
		bool execute();
		std::string result();
		std::vector<Game> parse();
		static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

#endif
