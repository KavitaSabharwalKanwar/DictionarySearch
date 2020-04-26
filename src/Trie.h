#pragma once

#include <string.h>
#include <iostream>
#include <algorithm>

using namespace::std;

class TrieNode {
public:
	TrieNode* children[26];
	bool endOfWord;
	TrieNode(bool b = false);
};

//Data Structure to contain all the dictionary words
class Trie
{
private:
	//Containment
	TrieNode* _root;
public:
	Trie();
	void insert(string word);
	bool search(string word);
	//This function is not being used. Has been added for completion
	bool startsWith(string prefix);
};

