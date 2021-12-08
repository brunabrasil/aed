#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

template <class T>
class MyVector {
    vector<T> values;
public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};


// exception EmptyVector
class EmptyVector
{ };

// methods
template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

//---------------------------------

// TODO
template <class T>
T MyVector<T>::max() const {
    vector<T> vetor = getValues();
    if(values.size()==0) throw EmptyVector();
    T vmax = vetor[0];
    for(auto x: vetor){
        if(x>vmax)
            vmax=x;
    }
    return vmax;
}

// TODO
template<class T>
bool MyVector<T>::hasDuplicates() const {
    if(values.size()<=1)
        return false;

	vector<T> teste = getValues();
    sort(teste.begin(), teste.end());
    for(auto it= teste.begin(); it<teste.end()-1; it++){
        if(*it == *(it+1)){
            return true;
        }
    }
    return false;
}

// TODO
template<class T>
void MyVector<T>::removeDuplicates() {
    if(values.size()<=1)
        return;

    vector<T> teste = getValues();
    sort(teste.begin(), teste.end());
    set<T> dic;
    for(auto it= teste.begin(); it<teste.end()-1; it++){
        if(*it == *(it+1)){
           dic.insert(*(it+1));
        }
    }
    for(auto it: dic){
        auto it1=find(values.begin(), values.end(), it);
        while(true){
            it1= find(it1+1, values.end(), it);
            if(it1==values.end())
                break;
            values.erase(it1);
            it1--;
        }
    }
}

