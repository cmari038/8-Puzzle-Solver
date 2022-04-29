#include "Tree.h"

void Tree::printPath() {
    
    State* holder;

    while(v.size() != 0) {
       v.top() -> print();
       cout << endl;
       holder = v.top();
       v.pop();
       delete holder;
    }
}

void Tree::getParent(State* s) {
    v.push(s);

    while(s->getPrev() != nullptr) {
        v.push(s->getPrev());
        s = s->getPrev();
    }
}