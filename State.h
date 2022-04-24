#ifndef STATE_H
#define STATE_H

#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <stdlib.h>

class State {
    
    private:
    int goal[3][3];
    int initial[3][3];

    int Heuristic;
    int cost = 0;
    int blankX;
    int blankY;

    int SearchChoice; 

    
    int getDistance(int val, int x, int y);
    void setInitial(int start[3][3]);
    void SetCost();
    int MisplacedTile();
    int Euclidean();
    

    public:

    // setters and constructors
    State();
    State(int start[3][3]); // start
    State(State* s); // expansion

    void setSearchChoice(int val) {
        SearchChoice = val;
    }

    //getter
    int getTotalCost() {
        SetCost();
        return Heuristic;
    }

    int getBlankX() {
        return blankX;
    }

    int getBlankY() {
        return blankY;
    }

    //comparisons
    friend bool Compare_State(State* s1, State* s2);
    friend void Copy(State* s1, State* s2);
    
    // operators
    bool comparison();
    State* operators(string move);
    State* left();
    State* right();
    State* up();
    State* down(); 

    //print

    void print();

};

#endif