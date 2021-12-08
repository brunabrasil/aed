#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    if(products.size()>k){
        for(int i=0; i<products.size()-1;i++){
            Product temp= products[i];
            for(int j=i+1; j<products.size();j++){
                if(products[i].getPrice()>products[j].getPrice()){
                    products[i]=products[j];
                    products[j]=temp;
                }
                else if(products[i].getPrice()==products[j].getPrice()){
                    if(products[i].getWeight()>products[j].getWeight()){
                        products[i]=products[j];
                        products[j]=temp;
                    }

                }
            }
        }
        products.erase(products.begin()+k, products.end());
    }
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    auto len = values.size();
    if(values.size()<nc) return -1;
    vector<unsigned> copy=values;
    sort(copy.begin(), copy.end());
    unsigned min = copy[len-1] - copy[0];
    for(int i=0; i<len-nc;i++){
        unsigned diff = copy[i+nc-1] - copy[i];
        if(diff<min){
            min=diff;
        }
    }
    return min;
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    int i = 0, j = 0, np=0, maximo=0;

    while(i<arrival.size() && j < departure.size()){
        if(arrival[i] <= departure[j]){
            np++;
            maximo= max(np, maximo);
            i++;
        }
        else{
            --np;
            j++;
        }
    }
    return maximo;
}


// TODO

void pairNutsBolts(vector<Piece>::iterator leftN, vector<Piece>::iterator rightN, vector<Piece>::iterator leftB, vector<Piece>::iterator rightB){


    const auto medianN =
}
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
    pairNutsBolts(nuts.begin(), nuts.end()-1, bolts.begin(), bolts.end()-1);


}

