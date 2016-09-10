// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(28497, 17471);
    ASSERT_EQ(308, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(64503, 45749);
    ASSERT_EQ(340, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(1219, 12794);
    ASSERT_EQ(268, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(451, 88807);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(55877, 3492);
    ASSERT_EQ(340, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(4716, 7726);
    ASSERT_EQ(262, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(86635, 55848);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(14798, 2874);
    ASSERT_EQ(276, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(32013, 6022);
    ASSERT_EQ(308, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(75224, 82345);
    ASSERT_EQ(351, v);}



// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}


