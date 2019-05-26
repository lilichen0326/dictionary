//Lili Chen

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <time.h>
#include "Dictionary.h"

using namespace std;
using namespace std::chrono;

void runSet(string dictionary, string checker)
{
	// start time
	auto start = high_resolution_clock::now();

	Dictionary d;
	d.loadWords(dictionary);

	ifstream infile(checker);
	ofstream outputFile("resultForSet.txt");

	string str;

	while (infile >> str)
	{
		//string str = line;
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		if (ispunct(str.at(str.length() - 1))) str.erase(str.length() - 1, 1);
		if (!d.check(str))
		{
			string suggestion = d.suggest(str);
			outputFile << "word spelled wrong: " + str + " The suggestions are: " + suggestion << endl;
		}
	}
	

	// end time
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken for Set is: "
		<< duration.count() << " microseconds" << endl;

	outputFile << "Time taken for Set is: "
		<< duration.count() << " microseconds" << endl;

	outputFile.close();
	infile.close();
}

void runUnOrderedSet(string dictionary, string checker)
{
	// start time
	auto start = high_resolution_clock::now();

	Dictionary_UnOrdered d;
	d.loadWords(dictionary);

	ifstream infile(checker);
	ofstream outputFile("resultForUnOrdered.txt");

	string str;

	while (infile >> str)
	{
		//string str = line;
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		if (ispunct(str.at(str.length() - 1))) str.erase(str.length() - 1, 1);
		if (!d.check(str))
		{
			string suggestion = d.suggest(str);
			outputFile << "word spelled wrong: " + str + " The suggestions are: " + suggestion << endl;
		}
	}

	// end time
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken for UnOrderedSet is: "
		<< duration.count() << " microseconds" << endl;

	outputFile << "Time taken for UnOrderedSet is: "
		<< duration.count() << " microseconds" << endl;

	outputFile.close();
	infile.close();
}

int main()
{
	string checker, dictionary;
	cout << "Enter a text to check and dictionary:" << endl;
	cin >> checker >> dictionary;

	runSet(dictionary, checker);

	runUnOrderedSet(dictionary, checker);
	
}
