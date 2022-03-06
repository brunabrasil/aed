// AED 2021/2022 - Aula Pratica 08
// Pedro Ribeiro (DCC/FCUP) [12/12/2021]

#include "funWithHashTables.h"
#include "hashTable.h"

#include <vector>
#include <iostream>
#include <cctype>


// Exemplo de função de hash para ints
unsigned FunWithHashTables::hashInt(const int& i) {
  return i;
}

// Exemplo de função de hash para strings
unsigned FunWithHashTables::hashString(const string& s) {
  hash<string> h;
  return h(s);
}

// ----------------------------------------------------------
// Exercicio 1: Tabelas de Dispersão
// ----------------------------------------------------------

// ..............................
// d) Contando diferentes somas de pares
// TODO

int FunWithHashTables::sumPairs(const vector<int>& numbers) {
    int size=numbers.size();
    HashTable<int> answer(size, hashInt);
    for (int i = 0; i < numbers.size()-1; ++i) {
        for (int j = i+1; j < numbers.size() ; ++j) {
            if(answer.getNumEmpty()<=1){
                size*=2;
                answer.rehash(size);
            }
            answer.insert(numbers[i]+numbers[j]);
        }
    }
    return answer.getNumActive();

}

// ----------------------------------------------------------
// Exercicio 2: Um padrão no DNA
// ----------------------------------------------------------
// TODO
int FunWithHashTables::dnaMotifs(string dna, int k, unordered_set<string>& motifs) {
    unordered_map<string , int> map;
    int m=0;
    for (int i = 0; i <= dna.length()-k; ++i) {
        pair<string, int> in(dna.substr(i,k), 1);
        if(!map.insert(in).second){
            map[dna.substr(i,k)]++;
            m=max(m, map[dna.substr(i,k)]);
        }
    }
    for(auto x: map){
        if(x.second==m){
            motifs.insert(x.first);
        }
    }
    return m;
}


// ----------------------------------------------------------
// Exercicio 3: Torre de Babel
// ----------------------------------------------------------
// TODO

vector<string> split(string in){
    vector<string> words;
    string str="";
    for (int i = 0; i <= in.length(); ++i) {
        if(isalpha(in[i])){
            str+=tolower(in[i]);
        }
        else{
            words.push_back(str);
            str.clear();
        }
    }
    return words;
}

void FunWithHashTables::findLanguage(string text, const unordered_map<string, vector<string>>& dict, unordered_map<string, int>& answer) {
    vector<string> w= split(text);
    unordered_multimap<string, string> d;
    for(auto x: dict){
        for(auto y: x.second){
            pair<string, string> in(y, x.first);
            d.insert(in);
        }
        answer.insert(pair<string, int>(x.first,0));
    }
    for(auto z: w){
        auto range = d.equal_range(z);
        for(auto it=range.first; it!=range.second; it++){
            answer[it->second]++;
        }
    }
}

// ----------------------------------------------------------
// Exercicio 4: Palavras Alienígenas
// ----------------------------------------------------------
// TODO

vector<string> makeWords(int l){
    string load;
    vector<string> v;
    if(v.empty()){
        for(char c = 'a'; c <= 'z'; c++){
            load = c;
            v.push_back(load);
        }
    }
    int i=0;
    bool stop=false;
    while (!stop){
        for(char c=v[i][v[i].length()-1]+1; c<='z'; c++){
            load = v[i] + c;
            if(load.length()>l){
                stop= true;
                break;
            }
            v.push_back(load);
        }
        i++;
    }
    return v;
}
unordered_map<string, int> makeMap(vector<string> v){
    unordered_map<string, int> ret;
    int i = 1;
    for(auto w: v){
        ret.insert(pair<string, int>(w,i));
        i++;
    }
    return ret;
}
void FunWithHashTables::wordIndex(const vector<string> &words, vector<int>& answer) {
    vector<string> v= makeWords(5);
    unordered_map<string, int> map = makeMap(v);
    for(auto w: words){
        answer.push_back(map.find(w)->second);
    }
}
