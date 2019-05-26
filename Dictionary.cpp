//Lili Chen

void Dictionary::loadWords(string filename)
{
	std::ifstream infile(filename);

	string line;
	while (infile >> line)
	{
		words.insert(line);
	}

	infile.close();
}

bool Dictionary::check(string word)
{
	return (words.find(word) != words.end());
}

string Dictionary::suggest(string word)
{
	string result = "";
	for (string w: words)
	{
		if (compare(word, w)) result = result + w + ", ";
	}
	return result;
}

bool Dictionary::compare(string a, string b)
{
	if (a.length() == b.length())
	{
		bool oneMismatch = false;
		for (int i = 0; i < a.length(); i++)
		{
			// a single letter is replaced by the other letter
			if (a.at(i) != b.at(i))
			{
				if (!oneMismatch)
				{
					if (i == a.length() - 1) return true;
					// two neighboring letters swapped their positions
					if (a.at(i) == b.at(i + 1) && a.at(i + 1) == b.at(i)) i++;
					oneMismatch = true;
				}
				else return false;
			}
		}
		return true;
	}
	else if (a.length() - b.length() == 1)
	{
		// a single extra letter appears in the word
		bool oneMismatch = false;
		for (int i = 0; i < b.length(); i++)
		{
			if (!oneMismatch)
			{
				if (a.at(i) != b.at(i))
				{
					oneMismatch = true;
					if (a.at(i + 1) != b.at(i))	return false;
				}
			}
			else
			{
				if (a.at(i + 1) != b.at(i))	return false;
			}
		}
		return true;

	}
	else if (a.length() - b.length() == -1)
	{
		// a single letter is missing somewhere in the word
		bool oneMismatch = false;
		for (int i = 0; i < a.length(); i++)
		{
			if (!oneMismatch)
			{
				if (a.at(i) != b.at(i))
				{
					oneMismatch = true;
					if (a.at(i) != b.at(i + 1))	return false;
				}
			}
			else
			{
				if (a.at(i) != b.at(i + 1))	return false;
			}
		}
		return true;
	}
	else return false;
}

void Dictionary_UnOrdered::loadWords(string filename)
{
	std::ifstream infile(filename);

	string line;
	while (infile >> line)
	{
		words.insert(line);
	}

	infile.close();
}

bool Dictionary_UnOrdered::check(string word)
{
	return (words.find(word) != words.end());
}

string Dictionary_UnOrdered::suggest(string word)
{
	string result = "";
	for (string w : words)
	{
		if (compare(word, w)) result = result + w + ", ";
	}
	return result;
}