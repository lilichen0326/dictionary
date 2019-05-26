//Lili Chen
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <set>

using std::string;

class Dictionary
{
public:
	void loadWords(string filename);
	bool check(string word);
	string suggest(string word);
protected:
	std::set<string> words;
	bool compare(string a, string b);
};

class Dictionary_UnOrdered : public Dictionary
{
public:
	void loadWords(string filename);
	bool check(string word);
	string suggest(string word);
protected:
	std::unordered_set<string> words;
};



#include "Dictionary.cpp"

#endif