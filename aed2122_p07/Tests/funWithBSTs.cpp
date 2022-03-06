// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2021]

#include <set>
#include <map>
#include <algorithm>
#include "funWithBSTs.h"
#include "bst.h"

// ----------------------------------------------------------
// Exercicio 1: Colecao de Cromos
// ----------------------------------------------------------
// TODO

int FunWithBSTs::newBag(const vector<int>& collection, const vector<int>& bag) {
    int count = 0;
    set<int> cards;
    for(auto card: collection){
        cards.insert(card);
    }
    for(auto card: bag){
        if(cards.insert(card).second) count++;
    }
    return count;
}

// ----------------------------------------------------------
// Exercicio 2: Batalha de Pokemons
// ----------------------------------------------------------
// TODO

int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {
    vector<int> aCards, bCards;
    for (auto x: alice) {
        aCards.push_back(x);
    }
    for (auto y: bruno) {
        bCards.push_back(y);
    }
    while (!aCards.empty() && !bCards.empty()) {

        sort(aCards.begin(), aCards.end(), greater<int>());
        sort(bCards.begin(), bCards.end(), greater<int>());
        auto a = aCards[0];
        auto b = bCards[0];
        if (a > b) {
            bCards.erase(bCards.begin());
            aCards.erase(aCards.begin());
            aCards.push_back(a - b);
        }
        else if (a < b) {
            bCards.erase(bCards.begin());
            aCards.erase(aCards.begin());
            bCards.push_back(b - a);
        }
        else if (a == b) {
            bCards.erase(bCards.begin());
            aCards.erase(aCards.begin());
        }
    }
    return aCards.size() - bCards.size();
    }

    //outra forma:
/*
int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {
    int ret;
    multiset<int> aliceCards, brunoCards;
    for(auto card : alice)
        aliceCards.insert(card);
    cout << endl;
    for (auto card : bruno)
        brunoCards.insert(card);

    multiset<int>::iterator aliceMove;
    multiset<int>::iterator brunoMove;

    while(!aliceCards.empty() && !brunoCards.empty()){
        aliceMove = --aliceCards.end();
        brunoMove = --brunoCards.end();

        if(*aliceMove > *brunoMove){
            aliceCards.erase(aliceMove);
            aliceCards.insert(*aliceMove - *brunoMove);
            brunoCards.erase(brunoMove);
        }
        else if(*aliceMove < *brunoMove){
            brunoCards.erase(brunoMove);
            brunoCards.insert(*brunoMove-*aliceMove);
            aliceCards.erase(aliceMove);
        }
        else{
            aliceCards.erase(aliceMove);
            brunoCards.erase(brunoMove);
        }
    }

    if(aliceCards.empty()){
        if(brunoCards.empty())
            return 0;
        else return -brunoCards.size();
    }
    else return aliceCards.size();
}*/

// ----------------------------------------------------------
// Exercicio 3: Reviews Cinematograficas
// ----------------------------------------------------------

// ..............................
// a) Contando Filmes
// TODO

int FunWithBSTs::numberMovies(const vector<pair<string, int>>& reviews) {
    set<string> movies;
    for(auto m: reviews){
        movies.insert(m.first);
    }

    return movies.size();
}

// ..............................
// b) O filme com mais reviews
// TODO

void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {
    map<string, int> movies;

    m = 0, n = 0;
    for(auto x : reviews){
        pair<string , int> in(x.first, 1);
        pair<map<string, int>:: iterator, bool>it = movies.insert(in);
        if(it.second == false)
            movies[x.first]++;
        if(m<movies[x.first]) m=movies[x.first];
    }
    for (auto x : movies){
        if (x.second == m) n+=1;
    }
}
//outra forma:
/*
void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {
    map<string, int> movies;
    string name;
    m = 1;
    n = 0;
    int revCount = 0;

    for(const auto& review : reviews){
        name = review.first;
        pair<string, int> in(name, 1);
        pair<map<string,int>::iterator, bool> it = movies.insert(in);
        if(!it.second){
            revCount = ++it.first->second;
            if(revCount > m){
                m = revCount;
                n = 1;
            }
            else if(revCount == m)
                n++;
        }
        else{
            if(m == 1) n++;
        }
    }
}*/

// ..............................
// c) Os melhores filmes
// TODO
vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {
    vector<string> answer;
    map<string, double> counter;
    map<string, double> number;
    for(auto x: reviews){
        if(!counter.insert(pair<string,int> (x.first, 1.0)).second)
            counter[x.first]++;
        if(!number.insert(pair<string,int> (x.first, x.second)).second)
            number[x.first]+=x.second;
    }
    for(auto y: counter){
        number[y.first]=number[y.first]/ counter[y.first];
        if(number[y.first]>=k)
            answer.push_back(y.first);
    }
    return answer;
}

//outra forma:

/*
vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {
    vector<string> answer;
    map<string, pair<int, double>>movies;
    string name;
    for(auto review: reviews){
        pair<string, pair<int, double>> in(review.first, pair<int, double> (review.second, 1));
        pair<map<string, pair<int, double>>:: iterator, bool> it = movies.insert(in);
        if(!it.second){
            it.first->second.first += review.second;
            it.first->second.second++;
        }
    }
    for (auto movie: movies){
        if(movie.second.first/movie.second.second >=k)
            answer.push_back(movie.first);
    }
    return answer;
}
*/