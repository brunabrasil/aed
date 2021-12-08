#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    sort(products.begin(), products.end(), [](const Product & p1, const Product & p2){
        auto pr1 = p1.getPrice();
        auto pr2 = p2.getPrice();
        return (pr1 == pr2) ? (p1.getWeight() < p2.getWeight()) : (pr1 < pr2);
    });
    if (products.size() > k) {
        products.erase(products.begin() + k, products.end());
    }

}

int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    auto len = values.size();
    if (nc > len) return -1;
    vector<unsigned> copied(values);
    sort(copied.begin(), copied.end());
    unsigned min = copied[len - 1] - copied[0];
    for (int i = 0; i < len - nc; ++i) {
        unsigned diff = copied[i + nc - 1] - copied[i];
        if (diff < min) {
            min = diff;
        }
    }
    return min;
}

unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    int max_np = 0, np = 0;
    int i = 0, j = 0;
    while (i < arrival.size() && j < departure.size()) {
        if (arrival[i] <= departure[j]) {
            ++np;
            max_np = max(max_np, np);
            ++i;
        } else {
            --np;
            ++j;
        }
    }
    return max_np;
}

void weirdAndRedundantPairSort(vector<Piece>::iterator left1, vector<Piece>::iterator right1,
               vector<Piece>::iterator left2, vector<Piece>::iterator right2) {
    const long & len1 = right1 - left1;
    if (len1 < 2) return;
    const auto & median1 = left1 + len1 / 2;
    const auto & match2 = find_if(left2, right2, [&median1](const Piece & p2){
        return median1->getDiameter() == p2.getDiameter();
    });
    const auto & median2 = left2 + (median1 - left1);
    swap(*match2, *median2);

    auto x1 = *median1;
    auto x2 = *median2;
    auto & i1 = left1;
    auto & i2 = left2;
    auto & j1 = right1;
    --j1;
    auto & j2 = right1;
    --j2;
    for (; ; ) {
        while ((++i1)->getDiameter() < x2.getDiameter());
        while (x2.getDiameter() < (--j1)->getDiameter());
        if (i1 < j1) swap(*i1, *j1);
        else break;
    }
    for (; ; ) {
        while ((++i2)->getDiameter() < x1.getDiameter());
        while (x1.getDiameter() < (--j2)->getDiameter());
        if (i2 < j2) swap(*i2, *j2);
        else break;
    }
    swap(*i1, *(right1 - 1));
    swap(*i2, *(right2 - 1));
    weirdAndRedundantPairSort(left1, i1 - 1, left2, i2 - 1);
    weirdAndRedundantPairSort(i1 + 1, right1, i2 + 1, right2);
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
    weirdAndRedundantPairSort(nuts.begin(), nuts.end() - 1, bolts.begin(), bolts.end() - 1);
}

