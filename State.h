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
    
    // helper functions for cost calculations
    int getDistance(int val, int x, int y);
    void setInitial(int start[3][3]);
    void SetCost();

    public:

    int Euclidean(); // calculates euclidean
    int MisplacedTile();    // calculates misplaced tile

    // constructors
    State();
    State(int start[3][3]); 
    State(State* s);


    //setters
    void setSearchChoice(int val) { //sets search choice equal to value based on algorithm chosen
        SearchChoice = val;
    }

    void setParent(State* s) {  // sets prev pointer equal to parent node
          prev = s;  
    }

    //getter
    int getTotalCost() {    // gets total heuristic and cost value
        SetCost();
        return Heuristic;
    }

    int getBlankX() {   // gets value for blank index
        return blankX;
    }

    int getBlankY() {
        return blankY;
    }

    State* getPrev() {  // gets parent
        return prev;
    }

    //friend functions
    friend bool Compare_State(State* s1, State* s2);    // compares nodes
    friend void Copy(State* s1, State* s2);     // copies array of one state into another
    
    // operators
    bool comparison();
    void left();
    void right();
    void up();
    void down(); 

    // prints out array of state
    void print();
    
    int C() { return cost;}
    
    // gets total heuristic depending on SearchChoice 
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

    // checks to see if node has already been explored.
    bool explore(vector<State*>& v);
};

#endif