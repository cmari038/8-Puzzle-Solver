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

    int getDistance(int val, int x, int y) {

        if(val == 1) {
            return sqrt(pow(x, 2) + pow(y, 2)); 
        }

        else if(val == 2) {
            return sqrt(pow(x, 2) + pow(y-1, 2));
        }

        else if(val == 3) {
            return sqrt(pow(x, 2) + pow(y-2, 2));
        }

        else if(val == 4) {
            return sqrt(pow(x-1, 2) + pow(y, 2));
        }

        else if(val == 5) {
            return sqrt(pow(x-1, 2) + pow(y-1, 2));
        }

        else if(val == 6) {
            return sqrt(pow(x-1, 2) + pow(y-2, 2));
        }

        else if(val == 7) {
            return sqrt(pow(x-2, 2) + pow(y, 2));
        }

         else if(val == 8) {
            return sqrt(pow(x-2, 2) + pow(y-1, 2));
        }
    }



    public:

    // setters
    State() {
        int count = 0;
         for(unsigned int i = 0; i < 3; ++i) {
            for(unsigned int j = 0; j < 3; ++j) {
                ++count;
                goal[i][j] = count;
            }
        }
    }

    void setInitial(int start[3][3]) {
        for(unsigned int i = 0; i < 3; ++i) {
            for(unsigned int j = 0; j < 3; ++j) {

                initial[i][j] = start[i][j];

                if(initial[i][j] == 0) {
                    blankX = i;
                    blankY = j;
                }
            }
        }
    }  

    int MisplacedTile() {
        int count = 0;
        for(unsigned i = 0; i < 2; ++i) {
            for(unsigned j = 0; j < 2; ++j) {
                if(initial[i][j] != goal[i][j]) {
                    ++count;
                }
            }
        }
        return count;
    }

    int Euclidean(int x, int y) {

        int count;

        for(unsigned i = 0; i < 2; ++i) {
            for(unsigned j = 0; j < 2; ++j) {
                 if(initial[i][j] != goal[i][j]) {
                    count += getDistance(initial[i][j],i,j);
                }
            }
        }

        return count;

    }
    int SetCost();
    
    // operators
    bool comparison() {
          
          for(unsigned i = 0; i < 2; ++i) {
            for(unsigned j = 0; j < 2; ++j) {
                if(initial[i][j] != goal[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
    
    State* left();
    State* right();
    State* up();
    State* down(); 

    //print

    void print(int board[3][3], int x, int y) {
    for(unsigned i = 0; i < x; ++i) {
        for(unsigned int i = 0; i < y; ++i) {
            cout << board[x][y] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

};

//#endif