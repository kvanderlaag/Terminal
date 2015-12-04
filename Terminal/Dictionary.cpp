#include "Dictionary.h"



Dictionary::Dictionary()
{
}


Dictionary::~Dictionary()
{
}

void Dictionary::Load()
{
	std::cout << "Loading dictionaries.\n";
	std::map<int, std::string>* wordList;
	std::stringstream len;
	for (int i = 5; i <= 10; i++) {
		switch (i) {
		case 5:
			wordList = &novice_words_;
			len.str("");
			len << "words/" << 5 << ".txt";
			break;
		case 6:
			wordList = &intermediate_words_;
			len.str("");
			len << "words/" << 6 << ".txt";
			break;
		case 7:
			wordList = &advanced_words_;
			len.str("");
			len << "words/" << 7 << ".txt";
			break;
		case 8:
			wordList = &expert_words_;
			len.str("");
			len << "words/" << 8 << ".txt";
			break;
		case 9:
			wordList = &master9_words_;
			len.str("");
			len << "words/" << 9 << ".txt";
			break;
		case 10:
			wordList = &master10_words_;
			len.str("");
			len << "words/" << 10 << ".txt";
			break;
		default:
			wordList = &novice_words_;
			len.str("words/");
			len << 10;
			len << ".txt";
		}

		int wordLength = 0;
		int keyCount = 0;
		std::ifstream inFile(len.str(), std::ifstream::in);
		if (inFile.good()) {
			std::stringstream str;
			char c = 0;
			while (inFile.good()) {
				c = inFile.get();
				if (c == ' ' || c == '\t' || c == '\n') {
					if (wordLength == 0) {
						wordLength = str.str().length();
					}
					if (str.str().length() != wordLength) {
						std::cout << "Error, words are not of similar length. Dictionary is malformed.\n";
						*wordList = std::map<int, std::string>();
						return;
					}
					wordList->insert(std::pair<int, std::string>(keyCount, str.str()));
					keyCount++;
					str.str("");

				}
				else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
					str << c;
				}
			}
		}
		else {
			std::cout << "Error opening file " << len.str() << std::endl;
			return;
		}
		
	}
	


}

GameWords Dictionary::GenerateGame(difficulty diff)
{
	std::cout << "Generating game.\n";
	Word baseWord = Word(GetWord(diff));
	int wordLength = baseWord.GetLength();

	std::map<int, std::string> tempWords;

	switch (wordLength) {
	case 5:
		tempWords = novice_words_;
		break;
	case 6:
		tempWords = intermediate_words_;
		break;
	case 7:
		tempWords = advanced_words_;
		break;
	case 8:
		tempWords = expert_words_;
		break;
	case 9:
		tempWords = master9_words_;
		break;
	case 10:
		tempWords = master10_words_;
		break;
	}

	std::vector<Word> likenesses[10];
	for (std::pair<int, std::string> wordPair : tempWords) {
		Word w = Word(wordPair.second, &baseWord);
		likenesses[w.GetLikeness()].push_back(w);
	}

	for (int i = 0; i < wordLength; i++) {

	}
	
	int maxWords = 7;
	std::vector<Word> gameWords = std::vector<Word>();

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine engine(seed);
	for (int i = 0; i < wordLength; i++) {
		std::uniform_int_distribution<int> QuantityDistr(0, 3);
		int random = std::min(maxWords, QuantityDistr(engine));
		maxWords -= random;

		for (int j = 0; j < random; j++) {
			std::uniform_int_distribution<int> PositionDistr(0, likenesses[i].size());
			int pos = PositionDistr(engine);
			std::vector<Word>::iterator iter = likenesses[i].begin();
			std::advance(iter, pos);
			gameWords.push_back(*iter);
			likenesses[i].erase(iter);
		}
	}

	return GameWords(&baseWord, &gameWords);
}

std::string Dictionary::GetWord(difficulty diff)
{
	std::map<int, std::string>* words;
	switch (diff) {
	case novice:
		words = &novice_words_;
		break;
	case intermediate:
		words = &intermediate_words_;
		break;
	case advanced:
		words = &advanced_words_;
		break;
	case expert:
		words = &expert_words_;
		break;
	case master:
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine engine(seed);
		std::uniform_int_distribution<int> distr(0, 1);
		int randomdiff = distr(engine);
		if (randomdiff = 0)
			words = &master9_words_;
		else
			words = &master10_words_;
	}
		break;
	default:
		return "";
		break;
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine engine(seed);
	std::uniform_int_distribution<int> distr(0, words->size() - 1);
	int random = distr(engine);
	std::map<int, std::string>::iterator iter = words->begin();
	std::advance(iter, random);
	std::string word = iter->second;
	return word;
}

/*
Word* Dictionary::GetWord(int likeness) {
	if (likeness >= wordLength_ || likenesses_.at(likeness).empty()) {
		return nullptr;
	}
	std::vector<Word*>::iterator iter = likenesses_.at(likeness).begin();
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine engine(seed);
	std::uniform_int_distribution<int> distr(0, likenesses_.at(likeness).size() - 1);
	int random = distr(engine);
	std::advance(iter, random);
	Word* ret = *iter;
	likenesses_.at(likeness).erase(iter);
	return ret;
}

const int Dictionary::GetWordLength() const
{
	return wordLength_;
}
*/

/*
const bool Dictionary::IsEmpty() const
{
	return words_.empty();
}

void Dictionary::Print() const {
	for (size_t i = 0; i < words_.size(); i++) {
		std::cout << words_.at(i);
		std::cout << '\n';
	}
}
*/