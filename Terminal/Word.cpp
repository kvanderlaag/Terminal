#include "Word.h"

Word::Word(const Word& other) :
	word(other.str()),
	likeness(other.GetLikeness()),
	length(other.GetLength())
{

}

Word::Word(const std::string w) :
	word(w),
	likeness(w.length()),
	length(w.length())
{

}

Word::Word(const std::string w, const Word* base) :
	word(w)
{
	likeness = 0;
	int i = 0;
	std::string baseStr = base->str();
	for (std::string::iterator it = baseStr.begin(); it != baseStr.end(); it++) {
		if (word.at(i) == *it) {
			likeness++;
		}
		i++;
	}
	
}


Word::~Word()
{
}

std::string Word::str() const {
	return word;
}

const int Word::GetLikeness() const {
	return likeness;
}

const int Word::GetLength() const {
	return length;
}