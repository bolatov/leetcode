#include <vector>
#include <iostream>

using namespace std;

class TrieNode {
    vector<TrieNode *> children = vector<TrieNode *>(256);

  public:
    // Initialize your data structure here.
    TrieNode() {}
    TrieNode *getChild(char ch) { return this->children[(int)ch]; }
    void addChild(char ch, TrieNode *trieNode) {
        this->children[ch] = trieNode;
    }
};

class Trie {
  public:
    Trie() { this->root = new TrieNode(); }

    // Inserts a word into the trie.
    void insert(string word) {
        word += '$';
        TrieNode *n = root;
        for (char ch : word) {
            if (!n->getChild(ch)) {
                TrieNode *child = new TrieNode();
                n->addChild(ch, child);
            }
            n = n->getChild(ch);
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        word += '$';
        TrieNode *n = root;
        for (char ch : word) {
            if (!n->getChild(ch))
                return 0;
            n = n->getChild(ch);
        }
        return 1;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *n = root;
        for (char ch : prefix) {
            if (!n->getChild(ch))
                return 0;
            n = n->getChild(ch);
        }
        return 1;
    }

  private:
    TrieNode *root;
};

int main() {
    // Your Trie object will be instantiated and called as such:
    Trie trie;
    trie.insert("banana");
    trie.insert("anana");
    trie.insert("nana");
    trie.insert("ana");
    printf("banana -> %d, %d\n", trie.search("anana"), trie.startsWith("nan"));
    return 0;
}