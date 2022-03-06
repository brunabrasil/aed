#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

BST<WordMean> Dictionary::getWords() const {
	return words;
}

// ---------------------------------------------

//TODO
void Dictionary::readFile(ifstream &f) {
    string word, meaning;
    while(getline(f,word)){
        getline(f, meaning);
        WordMean w(word, meaning);
        words.insert(w);
    }

}

//TODO

string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {
    WordMean findMean(word1, "");
    iteratorBST<WordMean> it = words.begin();
    while(it!=words.end()){
        if((*it)==findMean) return (*it).getMeaning();
        else{
            if(it==words.begin()){
                previous=(*it);
            }
            else{
                previous=next;
            }
            it++;
            next=(*it);
            if(findMean<(*it)) break;
        }
    }
    return "word not found";
}

//TODO
bool Dictionary::update(string word1, string mean1) {
    WordMean findMean(word1, "");
    iteratorBST<WordMean> it = words.begin();
    while(it!=words.end()){
        if((*it)==findMean){
            (*it).setMeaning(mean1);
            return true;
        }
        else
            it++;
    }
    WordMean w= WordMean(word1, mean1);
    words.insert(w);
    return false;

}

//TODO
void Dictionary::print() const {
    words.printTree();

}
