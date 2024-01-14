/*
    A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
    There are various applications of this data structure, such as autocomplete and spellchecker.
    Implement the Trie class:

    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false 
    otherwise.
    
    Example 1:
    Input
    ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
    [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
    Output
    [null, null, true, false, true, null, true]
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i=0;i<26;i++) 
            children[i] = NULL;
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL)
            child = root->children[index];
        else  {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }  
    void insert(string word) {
        return insertUtil(root, word);
    }
    
    bool searchUtil(TrieNode* root, string word) {
        if(word.size() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[index] != NULL)
            child = root->children[index];
        else 
            return false;
        
        return searchUtil(child, word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool prefixUtil(TrieNode* root, string word) {
        if(word.size() == 0)
            return true;

        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[index] != NULL)
            child = root->children[index];
        else 
            return false;
        
        return prefixUtil(child, word.substr(1));
    }
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};
