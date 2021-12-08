#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"

using testing::Eq;

TEST(test, facingsun){
    EXPECT_EQ(0, FunSearchProblem::facingSun(vector<int>({})));
    EXPECT_EQ(2, FunSearchProblem::facingSun(vector<int>({3, 10, 10, 2, 1})));
    EXPECT_EQ(1, FunSearchProblem::facingSun(vector<int>({10, 8, 7, 5})));
    EXPECT_EQ(3, FunSearchProblem::facingSun(vector<int>({2, 3, 8})));
}

TEST(test, squareR){
    EXPECT_EQ(1, FunSearchProblem::squareR(1));
    EXPECT_EQ(1, FunSearchProblem::squareR(2));
    EXPECT_EQ(1, FunSearchProblem::squareR(3));
    EXPECT_EQ(2, FunSearchProblem::squareR(4));
    EXPECT_EQ(2, FunSearchProblem::squareR(5));
    EXPECT_EQ(2, FunSearchProblem::squareR(6));
    EXPECT_EQ(2, FunSearchProblem::squareR(7));
    EXPECT_EQ(2, FunSearchProblem::squareR(8));
    EXPECT_EQ(3, FunSearchProblem::squareR(9));
    EXPECT_EQ(3, FunSearchProblem::squareR(10));
    EXPECT_EQ(3, FunSearchProblem::squareR(11));
    EXPECT_EQ(3, FunSearchProblem::squareR(12));
    EXPECT_EQ(3, FunSearchProblem::squareR(13));
    EXPECT_EQ(3, FunSearchProblem::squareR(14));
    EXPECT_EQ(3, FunSearchProblem::squareR(15));
    EXPECT_EQ(4, FunSearchProblem::squareR(16));
}

TEST(test, missingvalue){

}

TEST(test, minPages){
    EXPECT_EQ(60, FunSearchProblem::minPages(vector<int>({10, 20, 30, 40}), 2));
}
