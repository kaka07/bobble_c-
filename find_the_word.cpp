#include<bits/stdc++.h>
using namespace std;

const int alphaSize = 256;

//Define a structure TrieNode 
struct TrieNode {

	//size of the TrieNode should not be greater than 256
	TrieNode* children[alphaSize];

	int frequency; //How many times the word is present in the dictionary

	bool isEndOfWord; //to check if the word has ended or not

	//TrieNode constructor

	TrieNode() { 
		frequency = 0;
		isEndOfWord = false;
		for(int i = 0; i<alphaSize; ++i) {
			children[i] = nullptr;
		}
	}
};

class Trie {
	//Root node
	TrieNode *root;
public:
	Trie() {
		//Instantiating root node
		root = new TrieNode();
	}

	TrieNode *makeNode() {
		return new TrieNode();
	}

	//Function to add items in the trie
	void add(string &str, int freq) {
		int n = (int)str.size();

		//Making a TrieNode type current variable pointing to the root itself
		TrieNode *curr = root;

		for(int i = 0; i<n; ++i) {
			int charIndex = (int)str[i];
			//if the current variable is not null
			if(curr->children[charIndex] != nullptr) {
				curr = curr->children[charIndex];
			}		
			else {
				TrieNode *newNode = makeNode();
				curr->children[charIndex] = newNode;
				curr = newNode;
			}
		}
		curr->isEndOfWord = true;
		curr->frequency = freq;
	}

	pair<bool, int> search(string &str) {
		int n = (int)str.size();
		TrieNode *curr = root;
		pair<bool, int> notFound = {false, 0};

		for(int i = 0; i<n; ++i) {
			int charIndex = (int)str[i];
			if(curr->children[charIndex] == nullptr) {
				return notFound;
			}
			curr = curr->children[charIndex];
		}
		if(curr->isEndOfWord) 
			return {true, curr->frequency};

		return notFound;
	}
};

int main()	{
	int freq, n;
	string tmp;

	Trie dictionary;

	cin >> n;
	for(int i = 0; i<n; ++i) {
		cin >> tmp >> freq;
		dictionary.add(tmp, freq);
	}
	cin >> tmp;
	pair<bool, int> match = dictionary.search(tmp);
	if(match.first) {
		cout << "YES, "<< match.second << '\n';
	}
	else {
		printf("NO\n");
	}
}