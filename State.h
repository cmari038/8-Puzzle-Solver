//#IFNDEF "STATE_H"
//#DEFINE "STATE_H"

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

    int getDistance(int val, int x, int y);



    public:

    // setters
    State();
    void setInitial(int start[3][3]);
    int MisplacedTile();
    int Euclidean();
    int SetCost();
    
    // operators
    bool comparison();
    
    State* left();
    State* right();
    State* up();
    State* down(); 

    //print

    void print();

};

//#endif