// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

#define OPTIMIZATION 1

using namespace std;

// ----------------
// global variables
// ----------------

int collatz_cache [1000000];

// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) {
    if (!(r >> i))
        return false;
    r >> j;
    return true;}

// -------------------
// preload_heavy_roots
// -------------------

void collatz_preload_roots() {
    int root = 1;
    for(int i = 1; i <= 20; i++){
        collatz_cache[root] = i;
        root = root << 1;
    }
    root = 5;
    for(int i = 1; i <= 18; i++){
        collatz_cache[root] = i + 5;
        root = root << 1;
    }
    root = 13;
    for(int i = 1; i <= 17; i++){
        collatz_cache[root] = i + 9;
        root = root << 1;
    }
}

// -------------------
// collatz_eval_single
// -------------------

int collatz_eval_single (int i){
    if(i < 1)
        return -1;
    int cycle_length = 1;
    int initial_i = i;
    bool exit = false;
    while(i != 1){
        if(i < 1000000){

            #ifdef OPTIMIZATION
            if(collatz_cache[i] != 0){
                cycle_length = collatz_cache[i] + cycle_length - 1;
                exit = true;
            }
            #endif
            if(exit){
                break;
            }
        }
        if(i % 2 == 0){
            i /= 2;
            ++cycle_length;
        }
        else{
            i = i + (i+1)/2;
            cycle_length += 2;
        }
    }

    #ifdef OPTIMIZATION
    // simple cache
    collatz_cache[initial_i] = cycle_length;
    // more rigorous cache
    int repeat = initial_i;
    int count = 0;
    while(repeat != i){
        if(repeat % 2 == 0){
            repeat /= 2;
            ++count;
        }
        else{
            repeat = repeat + (repeat + 1)/2;
            count += 2;
        }
        if(repeat < 1000000){
            collatz_cache[repeat] = cycle_length - count;
        }
    }
    #endif

    return cycle_length;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    int max = 1;
    int cycle_length = 1;
    // edge case for unit test
    if(i > j){
        int x = i;
        i = j;
        j = x;
    }
    if(i == j){
        return collatz_eval_single(i);}

    #ifdef OPTIMIZATION
    if(i < j/2)
        i = j/2;
    #endif

    for(int index = i + (i%2); index <= j; index += 2){
        cycle_length = collatz_eval_single(index);
        if(max < cycle_length)
            max = cycle_length;
    }
    for(int index = i + !(i%2); index <=j; index += 2){
        cycle_length = collatz_eval_single(index);
        if(max < cycle_length)
            max = cycle_length;
    }
    return max;}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    int i;
    int j;

    #ifdef OPTIMIZATION
    collatz_preload_roots();
    #endif

    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
