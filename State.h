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
    State* prev = nullptr;
    
    int getDistance(int val, int x, int y);
    void setInitial(int start[3][3]);
    void SetCost();

    public:

    int Euclidean();
    int MisplacedTile();

    // setters and constructors
    State();
    State(int start[3][3]); // start
    State(State* s); // expansion

    void setSearchChoice(int val) {
        SearchChoice = val;
    }

    void setParent(State* s) {
          prev = s;  
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

    State* getPrev() {
        return prev;
    }

    //comparisons
    friend bool Compare_State(State* s1, State* s2);
    friend void Copy(State* s1, State* s2);
    
    // operators
    bool comparison();
    void left();
    void right();
    void up();
    void down(); 

    void print();
    
    int C() { return cost;}
    
    int getHeuristic() {
        if(SearchChoice == 1) {
            return 0;
        }

        else if(SearchChoice == 2) {
            return MisplacedTile();
        }

        else {
            return Euclidean();
        }
    }

    bool explore(vector<State*>& v);
};

#endif