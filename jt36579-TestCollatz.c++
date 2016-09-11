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

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(1, 10);
  ASSERT_EQ(20, v);
}

TEST(CollatzFixture, eval_2) {
  const int v = collatz_eval(100, 200);
  ASSERT_EQ(125, v);
}

TEST(CollatzFixture, eval_3) {
  const int v = collatz_eval(201, 210);
  ASSERT_EQ(89, v);
}

TEST(CollatzFixture, eval_4) {
  const int v = collatz_eval(900, 1000);
  ASSERT_EQ(174, v);
}

// -----------
// eval_single
// -----------

TEST(CollatzFixture, eval_single_5) {
  const int v = collatz_eval_single(5);
  ASSERT_EQ(6, v);
}

TEST(CollatzFixture, eval_single_1) {
  const int v = collatz_eval_single(1);
  ASSERT_EQ(1, v);
}

TEST(CollatzFixture, eval_single_0) {
  const int v = collatz_eval_single(0);
  ASSERT_EQ(-1, v);
}

TEST(CollatzFixture, eval_single_N1) {
  const int v = collatz_eval_single(-1);
  ASSERT_EQ(-1, v);
}

TEST(CollatzFixture, eval_single_22) {
  const int v = collatz_eval_single(22);
  ASSERT_EQ(16, v);
}

TEST(CollatzFixture, eval_single_2) {
  const int v = collatz_eval_single(2);
  ASSERT_EQ(2, v);
}
TEST(CollatzFixture, eval_single_4) {
  const int v = collatz_eval_single(4);
  ASSERT_EQ(3, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}
