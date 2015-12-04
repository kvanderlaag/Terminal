#pragma once

#include "Word.h"

#include <memory>
#include <map>
#include <string>
#include <vector>
#include <iostream>

class GameWords
{
private:
	std::unique_ptr<Word> baseWord_;
	std::map<int, Word*> gameWords_;
public:
	GameWords(const GameWords& other);
	GameWords(Word* baseWord, std::vector<Word>* dict);
	~GameWords();

	Word GetBaseWord() const;
	std::map<int, Word*> GetGameWords() const;

	void Print() const;
};

