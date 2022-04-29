#include "Tree.h"

void Tree::printPath() {    // goes through stack printing out the array of each state in stack 
    
    State* holder;

    while(v.size() != 0) {
       v.top() -> print();
       cout << endl;
       holder = v.top();
       v.pop();
       delete holder;
    }
}

void Tree::getParent(State* s) {    // adds goal node and all its ancestors to stack until original initial node is reached
    v.push(s);

    while(s->getPrev() != nullptr) {
        v.push(s->getPrev());
        s = s->getPrev();
    }
}