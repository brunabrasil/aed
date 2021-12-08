#include "funSearchProblem.h"
#include <algorithm>
FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------

// TODO
int FunSearchProblem::facingSun(const vector<int> & values) {
    int count =0;
    int highest=0;
    for(auto i: values){
        if(i>highest){
            count++;
            highest=i;
        }
    }
    return count;
}

// TODO
int FunSearchProblem::squareR(int num) {

    int left=1;
    int right=num/2;
    int ans;
    while(left<=right){
        int middle= (left+right)/2;
        int square= middle * middle;
        if(square<num){
            left=middle+1;
            ans=middle;
        } else if (square>num){
            right=middle-1;
            ans=middle;
        }
        else{
            return middle;
        }
    }
    return ans;
}

// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    vector<int>copy =values;
    sort(copy.begin(), copy.end());
    copy.erase(unique(copy.begin(),copy.end()));
    int count = 0;
    for(auto x: copy){
        if(x<0)
            continue;
        else if(x>count)
            return count;
        else
            count++;
    }
    return count;
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {

}

