#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> readData(vector<string> words) {
	fstream inputFile;
	string word;
	inputFile.open("Text.txt", ios::in);
	while (inputFile)
	{
		while (getline(inputFile, word, ' ')) {
			words.push_back(word + ' ');
		}
	}
	inputFile.close();
	return words;
}

vector<string> reverse(vector<string> words) {
	vector<string> reversed;

	for (int i = words.size() - 1; i >= 0; i--) {
		if (words[i] == "* ") {
			continue;
		}
		
		if (words[i][words[i].size() - 2] == '.') {
			words[i].insert(0, ".");
			words[i].erase(words[i].size() - 2);
			words[i].insert(words[i].size(), " ");
			reversed.push_back(words[i]);
		}
		else if (words[i][words[i].size() - 2] == ',') {
			words[i].insert(0, ",");
			words[i].erase(words[i].size() - 2, words[i].size() - 2);
			words[i].insert(words[i].size(), " ");
			reversed.push_back(words[i]);
		}
		else {
			reversed.push_back(words[i]);
		}
	}
	return reversed;
}

int main() {
	vector<string> words;
	vector<string> reversed;
	words = readData(words);
	reversed = reverse(words);

	for (int i = 0; i < reversed.size(); i++) {
		cout << reversed[i];
	}
	cout << endl;
	system("pause");
	return 0;
}