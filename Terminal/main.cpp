#include "Word.h"
#include "Dictionary.h"
#include "GameWords.h"

#include <memory>
#include <iostream>

int main(int argc, char** argv) {
	std::unique_ptr<Dictionary> dict(new Dictionary());
	std::string input;
	dict->Load();
	while (input != "q" && input != "quit") {
		GameWords gW = dict->GenerateGame(Dictionary::master);
		gW.Print();
		std::cout << "\n";

		std::cin >> input;
		std::cout << "\n";
	}
	
	return 0;
}