#ifndef STATE_H
#define STATE_H

#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

class State {
    
    private:
    int goal[3][3];
    int initial[3][3];
    int Heuristic;
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