#include "Trie.h"

TrieNode::TrieNode(bool b) : endOfWord(b) {
	memset(children, 0, sizeof(children));
}

Trie::Trie() {
	_root = new TrieNode();
}

//Function to insert a word in Trie 
void Trie::insert(string word) {
	TrieNode* temp = _root;

	for (int i = 0; i < word.size(); i++) {
		if (temp->children[word[i] - 'a'] == NULL) {
			TrieNode* newNode = new TrieNode();
			temp->children[word[i] - 'a'] = newNode;
		}

		temp = temp->children[word[i] - 'a'];
	}

	temp->endOfWord = true;
}

//Function to determine if a word is present in Trie or not
bool Trie::search(string word) {
	//Convert input to all lowercase
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	TrieNode* temp = _root;
	for (int i = 0; i < word.size(); i++) {
		if (temp->children[word[i] - 'a'] == NULL)
			return false;

		temp = temp->children[word[i] - 'a'];
	}
	return(temp!= NULL && temp->endOfWord);
}

//Function to determine if Trie contains this prefix
bool Trie::startsWith(string prefix) {
	auto temp = _root;
	//TODO: Return a unique pointer to memory location containing all the words starting with this prefix
	for (int i = 0; i < prefix.size();i++) {
		if (temp->children[prefix[i] - 'a'] == NULL)
			return false;

		temp = temp->children[prefix[i] - 'a'];
	}

	return true;
}

