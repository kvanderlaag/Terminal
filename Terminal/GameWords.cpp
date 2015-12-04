#include "GameWords.h"



GameWords::GameWords(Word* baseWord, std::vector<Word>* dict) :
	baseWord_(new Word(*baseWord))
{
	int keyCount = 0;
	for (Word w : *dict) {
		gameWords_.insert(std::pair<int, Word*>(keyCount++, new Word(w)));
	}

}

GameWords::GameWords(const GameWords& other) : 
	baseWord_(new Word(other.GetBaseWord())),
	gameWords_(other.GetGameWords())
{

}


GameWords::~GameWords()
{
}

Word GameWords::GetBaseWord() const
{
	return *(baseWord_.get());
}

std::map<int, Word*> GameWords::GetGameWords() const
{
	return gameWords_;
}

void GameWords::Print() const {
	std::cout << baseWord_->str() << "\n---\n";
	for (std::pair<int, Word*> wP : gameWords_) {
		std::cout << wP.second->str() << " | Likeness: " << wP.second->GetLikeness() << "\n";
	}
}