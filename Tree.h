#ifndef TREE_H
#define TREE_H
#include <iostream>
using namespace std; 
#include "State.h"
#include <stack>

class Tree {

private:
State* root = nullptr; 
stack<State*> v;

public:

Tree(State* s) {
    root = s;
}

void printPath();

void getParent(State* s);

int getDepth() {
    return v.size() - 1;
}

};

#endif