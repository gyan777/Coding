#include <iostream>
#include <string>
#include <map>

using namespace std;


class WordDictionary {

private:
  struct trieNode {
    //public:
    bool endOfWord = false;
    map<char, trieNode*> charMap;
    //trieNode () {
    // endOfWord = false;
    //}
  };
  
  trieNode *root;
  
public:

  WordDictionary() {
    root = new trieNode();
  }

  void addWord(string word) {
    trieNode *currNode = root;
    for (int i = 0; i < word.length(); i++) {
      if (currNode->charMap.count(word[i]) == 0) { 
	currNode->charMap[word[i]] = new trieNode();
      }
      currNode = currNode->charMap[word[i]];	    
    }
    currNode->endOfWord = true;
  }

  bool findWord (trieNode *startNode, const string& word, int ptr) {
    trieNode *currNode = startNode;
    for (int i = ptr; i < word.length(); i++) {
      if (word[i] == '.') {
	for (auto k : currNode->charMap) {
	  if (findWord (k.second, word, i+1)) {
	    return true;
	  }
	}
	return (false);
      } else if (currNode->charMap.count(word[i]) > 0) {
	currNode = currNode->charMap[word[i]];
      } else {
	return (false);
      }
    }
    return(currNode->endOfWord);      
  }
    
  bool search(string word) {
    return (findWord(root, word, 0));
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main (int argc, char **argv) {
  WordDictionary* obj = new WordDictionary();
  obj->addWord("a");
  //obj->addWord("and");
  //obj->addWord("an");
  //obj->addWord("add");      

  //  bool param_2 = obj->search("a");
  //if (param_2) {
  //  cout << "true\n";
  //} else {
  //  cout << "false\n";
  //}
  
  //bool param_3 = obj->search(".at");
  //if (param_3) {
  //  cout << "true\n";
  //} else {
  //  cout << "false\n";
  // }
  
  bool param_4 = obj->search(".a");
  if (param_4) {
    cout << "true\n";
  } else {
    cout << "false\n";
  }
  

}


