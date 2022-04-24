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
    void SetCost(int val);
    

    public:

    // setters
    State();
    State(int start[3][3]);
    int MisplacedTile();
    int Euclidean();

    //getter
    int getTotalCost(int val) {
        SetCost(val);
        return Heuristic;
    }

    int getBlankX() {
        return blankX;
    }

    int getBlankY() {
        return blankY;
    }

    bool CompareArrayVal(int x, int y) {
        return goal[x][y] == initial[x][y];
    }
    
    // operators
    bool comparison();
    void operators();
    State* left();
    State* right();
    State* up();
    State* down(); 

    //print

    void print();

};

#endif