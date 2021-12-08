#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------

int FunSearchProblem::facingSun(const vector<int> & values) {
    int count = 0;
    int highest_yet = 0;
    for (auto & v : values) {
        if (v > highest_yet) {
            highest_yet = v;
            ++count;
        }
    }
    return count;
}

int FunSearchProblem::squareR(int num) {
    if (num <= 1) {
        return num;
    }
    int left = 1;
    int right = num / 2;
    int ans;
    while (left <= right) {
        int middle = (left + right) / 2;
        int square = middle * middle;
        if (square < num) {
            left = middle + 1;
            ans = middle;
        } else if (square > num) {
            right = middle - 1;
        } else {
            return middle;
        }
    }
    return ans;
}

// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    return 0;
}

int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    int maximum = 0;
    int sum = 0;
    for (auto & v : values) {
        maximum = max(maximum, v);
        sum += v;
    }
    int left = maximum;
    int right = sum;
    while (left < right) {
        int middle = left + (right - left) / 2;

        sum = 0;
        int students = 1;
        for (auto & v : values) {
            sum += v;
            if (sum > middle) {
                sum = v;
                ++students;
            }
        }

        if (students <= numSt) right = middle;
        else left = middle + 1;
    }
    return left;
}

