#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Trie.h"
#include "WordsFinder.h"

using namespace std;

//Function to trim the leading and trailing whitespaces
string trim(string& str) {
    string whitespace = " \t";
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == string::npos)
        return "";

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);

}

//Function to extract separate words from the input string
void parseInput(string inputString, vector<string>& listOfWords) {
    istringstream ss(inputString);

    while (ss) {
        string word;
        ss >> word;
        if(word != "")
            listOfWords.push_back(word);
    }
}

//Function to read words from the dictionary and form Trie
void readWordsAndFormTrie(unique_ptr<Trie>& trie) {
    string line, word;
    ifstream filestream("../src/dictionary.txt");
    if (filestream.is_open()) {
        while (std::getline(filestream, line)) {
            istringstream linestream(line);
            while (linestream >> word) {
                trie->insert(word);
            }
        }
    }
    else
        cout << "File Not Found\n";
}

int main() {
    //Pointer to hold the structure in memory
    unique_ptr<Trie> trie = make_unique<Trie>();
    vector<string> listOfWords;
    string inputString;

    //Read words from the dictionary and store in a trie
    readWordsAndFormTrie(trie);

    cout << "Kindly enter space separated list of words that you want to search in the dictionary. Press enter when done. \n";
    getline(cin, inputString);

    if (inputString.find(',') != string::npos) {
        cout << "Please don't use commas in the input. Enter space separated words \n";
        getline(cin, inputString);
    }

    parseInput(inputString, listOfWords);

    //Spawn multiple threads to find the words in the dictionary
    WordsFinder finder;
    finder.spawnThreads(move(trie), listOfWords);
    
    return 0;
}                                                                                                                                                                                                                             