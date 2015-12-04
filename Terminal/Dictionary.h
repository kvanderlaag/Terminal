#pragma once

#include "Word.h"
#include "GameWords.h"

#include <vector>
#include <map>
#include <string>
#include <random>

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

class Dictionary
{
public:
	enum difficulty
	{
		novice = 5,
		intermediate = 6,
		advanced = 7,
		expert = 8,
		master = 9
	};

	Dictionary();
	~Dictionary();

	void Load();

	GameWords GenerateGame(difficulty diff);
private:
	std::map<int, std::string> novice_words_;
	std::map<int, std::string> intermediate_words_;
	std::map<int, std::string> advanced_words_;
	std::map<int, std::string> expert_words_;
	std::map<int, std::string> master9_words_;
	std::map<int, std::string> master10_words_;

	std::string GetWord(Dictionary::difficulty diff);

};

