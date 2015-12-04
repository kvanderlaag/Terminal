#include "Word.h"
#include "Dictionary.h"
#include "GameWords.h"

#include <memory>
#include <iostream>

int main(int argc, char** argv) {
	std::unique_ptr<Dictionary> dict(new Dictionary());

	dict->Load();
	GameWords gW = dict->GenerateGame(Dictionary::novice);
	gW.Print();
	std::cout << "\n";

	std::string s;
	std::cin >> s;
	
	return 0;
}