#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

//-----------------------------------------------------------------

void Game::addKid(const Kid k1) {
    this->kids.push_back(k1);
}

list<Kid> Game::getKids() const {
    return (this->kids);
}

void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}
/*
Kid Game::loseGame(string phrase) {
    int num_words = numberOfWords(phrase);
    list<Kid> kids_in_game(kids);
    auto it = kids_in_game.begin();
    while (kids_in_game.size() > 1) {
        for (int i = 1; i < num_words; ++i) {
            ++it;
            if (it == kids_in_game.end()) it = kids_in_game.begin();
        }
        it = kids_in_game.erase(it);
        if (it == kids_in_game.end()) it = kids_in_game.begin();
    }
    return kids_in_game.front();
}
*/
Kid Game::loseGame(string phrase) {
    int num_words = numberOfWords(phrase);
    list<Kid> kids_in_game(kids);
    int idx = 0;
    while (kids_in_game.size() > 1) {
        idx = (idx + num_words - 1) % kids_in_game.size();
        kids_in_game.erase(next(kids_in_game.begin(), idx));
    }
    return kids_in_game.front();
}

list<Kid> Game::removeOlder(unsigned id) {
    list<Kid> cool_kids;
    for (auto it = kids.begin(); it != kids.end(); ) {
        if (it->getAge() > id) {
            cool_kids.push_back(*it);
            it = kids.erase(it);
        } else ++it;
    }
    return cool_kids;
}

queue<Kid> Game::rearrange() {
    list<Kid> muchachas, muchachos;
    for (const auto & k : kids) {
        auto & l = (k.getSex() == 'f') ? muchachas : muchachos;
        l.push_back(k);
    }
    int n = muchachas.size();
    int m = muchachos.size();
    queue<Kid> kicked;
    if (!n || !m) return kicked;
    int ratio = (n < m) ? m / n : n / m;
    auto & shorter = (n < m) ? muchachas : muchachos;
    auto & longer = (n < m) ? muchachos : muchachas;
    kids.clear();
    for (const auto & k : shorter) {
        kids.push_back(k);
        for (int i = 0; i < ratio; ++i) {
            kids.push_back(longer.front());
            longer.pop_front();
        }
    }
    for (const auto & k : longer) {
        kicked.push(k);
    }
    return kicked;
}

bool Game::operator==(Game& g2) {
	return kids == g2.kids;
}

list<Kid> Game::shuffle() const {
    list<Kid> to_shuffle(kids);
    list<Kid> shuffled;
    while (to_shuffle.size()) {
        int idx = rand() % to_shuffle.size();
        auto it = next(to_shuffle.begin(), idx);
        shuffled.push_back(*it);
        to_shuffle.erase(it);
    }
	return (shuffled);
}
