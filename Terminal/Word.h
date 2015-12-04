#pragma once

#include <string>

class Word
{
private:
	std::string word;
	int length;
	int likeness;
public:
	Word(const Word& other);
	Word(const std::string w);
	Word(const std::string w, const Word* base);
	~Word();
	std::string str() const;
	const int GetLikeness() const;
	const int GetLength() const;
};

