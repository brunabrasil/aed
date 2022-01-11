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

    const long lenN = rightN - leftN;
    if(lenN < 2) return;
    //const auto &medianN = leftN + lenN / 2;
    const auto center = leftN + lenN / 2;
    //const auto &medianB = leftB + (center-leftN);
    /*for(vector<Piece>::iterator i = leftB ; i <= rightB; i++){
        if(i->getDiameter()==medianN->getDiameter()){
            swap(*i, *medianB);
        }
    }*/
    if (center->getDiameter() < leftN->getDiameter())
        swap(*center, *leftN); //swap elements if order incorrect
    if (rightN->getDiameter() < leftN->getDiameter())
        swap(*leftN, *rightN); //swap elements if order incorrect
    if (rightN->getDiameter() < center->getDiameter())
        swap(*center, *rightN); //swap elements if order incorrect
    swap(*center, *rightN); //puts pivot in position right-1
    const auto & medianN = (rightN-1);

    if (center->getDiameter() < leftB->getDiameter())
        swap(*center, *leftB); //swap elements if order incorrect
    if (rightB->getDiameter() < leftB->getDiameter())
        swap(*leftB, *rightB); //swap elements if order incorrect
    if (rightB->getDiameter() < center->getDiameter())
        swap(*center, *rightB); //swap elements if order incorrect
    swap(*center, *rightB); //puts pivot in position right-1
    const auto & medianB = (rightB-1);

    auto &iN = leftN, &jN = rightN, &iB = leftB, &jB = rightB;
    auto xN = *medianN, xB = *medianB;
    --jB;
    --jN;

    for(;;){
        while ((++iN)->getDiameter() < xB.getDiameter());
        while((--jN)->getDiameter() > xB.getDiameter());
        if(iN < jN)
            swap(*iN, *jN);
        else break;
    }
    for(;;){
        while ((++iB)->getDiameter() < xN.getDiameter());
        while((--jB)->getDiameter() > xN.getDiameter());
        if(iB < jB)
            swap(*iB, *jB);
        else break;
    }
    //reset pivot
    swap(*iN, *(rightN -1));
    swap(*iB, *(rightB -1));

    pairNutsBolts(leftN, iN-1, leftB, iB-1);
    pairNutsBolts(iN + 1, rightN, iB-1, rightB);
}
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
    pairNutsBolts(nuts.begin(), nuts.end()-1, bolts.begin(), bolts.end()-1);


}

