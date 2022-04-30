#include "State.h"

// g++ main.cpp State.cpp
 int State::getDistance(int val, int x, int y) {    // calculates euclidean distance using specific value of misplaced tile and its true position. 
                                                    // uses equation sqrt((y2 - y1)^2 + (x2-x1)^2)
        if(val == 1) {
            return sqrt(pow(x, 2) + pow(y, 2)); 
            // return abs(x) + abs(y);                  <- manhattan euristic 
        }

        else if(val == 2) {
            return sqrt(pow(x, 2) + pow(y-1, 2));
            // return abs(x) + abs(y-1);
        }

        else if(val == 3) {
            return sqrt(pow(x, 2) + pow(y-2, 2));
            // return abs(x) + abs(y-2);
        }

        else if(val == 4) {
            return sqrt(pow(x-1, 2) + pow(y, 2));
            // return abs(x-1) + abs(y);
        }

        else if(val == 5) {
            return sqrt(pow(x-1, 2) + pow(y-1, 2));
            // return abs(x-1) + abs(y-1);
        }

        else if(val == 6) {
            return sqrt(pow(x-1, 2) + pow(y-2, 2));
            // return abs(x-1) + abs(y-2);
        }

        else if(val == 7) {
            return sqrt(pow(x-2, 2) + pow(y, 2));
            // return abs(x-2) + abs(y);
        }

         else if(val == 8) {
            return sqrt(pow(x-2, 2) + pow(y-1, 2));
           // return abs(x-2) + abs(y-1);
        }

        else {
            return 0;
        }
        
    }

    State::State() {        // default constructor for nodes which sets up goal state and default initial state. Used when "1" is chosen
         int count = 0;
         for(unsigned int i = 0; i < 3; ++i) {
            for(unsigned int j = 0; j < 3; ++j) {
                ++count;
                goal[i][j] = count;
            }
        }

         goal[2][2] = 0;

        for(unsigned int i = 0; i < 3; ++i) {
            for(unsigned int j = 0; j < 3; ++j) {
                initial[i][j] = goal[i][j];
            }

        }

        initial[2][2] = 5;
        initial[1][2] = 0;
        initial[1][1] = 8;
        initial[2][1] = 6;

        blankX = 1;
        blankY = 2;

    }

    State::State(int start[3][3]) {         // constructor used for when user enters their own values
       
      // State();
      int count = 0;
         for(unsigned int i = 0; i < 3; ++i) {
            for(unsigned int j = 0; j < 3; ++j) {
                ++count;
                goal[i][j] = count;
            }
        }
         
         goal[2][2] = 0;

       setInitial(start);

    }

    State::State(State* s) {            // constructor used for when creating new children nodes
       // State();

        int count = 0;
        for(unsigned int i = 0; i < 3; ++i) {
            for(unsigned int j = 0; j < 3; ++j) {
                ++count;
                goal[i][j] = count;
            }
        }

         goal[2][2] = 0;

        Copy(this, s);
    }

    void State::setInitial(int start[3][3]) {       // modifies initial state of node array to match user input
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

    int State::MisplacedTile() {                    // counts how many misplaced tiles there are in array by comparing each index to corresponding index in goal state
        int count = 0;
        for(unsigned i = 0; i < 3; ++i) {
            for(unsigned j = 0; j < 3; ++j) {
                if(initial[i][j] != goal[i][j]) {
                    count += 1;
                }
            }
        }
        return count;
    }


    int State::Euclidean() {                        // uses get distance function to get total euclidean heuristic of all misplaced tiles
        int count = 0;
        for(unsigned i = 0; i < 3; ++i) {
            for(unsigned j = 0; j < 3; ++j) {
                 if(initial[i][j] != goal[i][j]) {
                    count += getDistance(initial[i][j],i,j);
                }
            }
        }
        return count;
    }



    bool State::comparison() {                      // comapres current state of array to goal state to see if goal was reached

        for(unsigned i = 0; i < 3; ++i) {
            for(unsigned j = 0; j < 3; ++j) {
                if(initial[i][j] != goal[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }


    void State::print() {                           // prints out array 
        for(unsigned i = 0; i < 3; ++i) {
            for(unsigned j = 0; j < 3; ++j) {
               cout << initial[i][j] << " ";
            }
            cout << endl;
        }
}

void State::left() {                                // left operator (Note: [X][Y] -> [row][column] -> [vertical][horizontal])
    int holder = initial[blankX][blankY-1];
    initial[blankX][blankY-1] = 0;
    initial[blankX][blankY] = holder;
    blankY = blankY - 1;
    ++cost;
}

void State::right() {                               // right operator
    int holder = initial[blankX][blankY+1];
    initial[blankX][blankY+1] = 0;
    initial[blankX][blankY] = holder;
    blankY = blankY + 1;
    ++cost;
}

void State::up() {                                  // up operator
    int holder = initial[blankX-1][blankY];
    initial[blankX-1][blankY] = 0;
    initial[blankX][blankY] = holder;
    blankX = blankX - 1;
    ++cost;
}

void State::down() {                               // down operator
    int holder = initial[blankX+1][blankY];
    initial[blankX+1][blankY] = 0;
    initial[blankX][blankY] = holder;
    blankX = blankX + 1;
    ++cost;
}

void State::SetCost() {                             // adds up cost and heuristic based on which algorithm was chosen 
    

    if(SearchChoice == 1) {
        Heuristic = cost;
    }

    else if(SearchChoice == 2) {
        Heuristic = MisplacedTile() + cost;
    }

    else if(SearchChoice == 3){
        Heuristic = Euclidean() + cost;
    }
}


bool Compare_State(State* s1, State* s2) {                      // compares the arrasy of two states to see if they are the same or not
         
         for(unsigned i = 0; i < 3; ++i) {
            for(unsigned j = 0; j < 3; ++j) {
                if(s1->initial[i][j] != s2->initial[i][j]) {
                    return false;
                }
            }
        }
        return true;
}

void Copy(State* s1, State* s2) {                               // copies the array of one state over to another state along with indexes for the blank square, value signifying algorithm chosen, and cost of the state 

    s1->blankX = s2->blankX;
    s1->blankY = s2->blankY;
    s1->SearchChoice = s2->SearchChoice;
    s1->cost = s2->cost;
    s1->setParent(s2);

    for(unsigned i = 0; i < 3; ++i) {
        for(unsigned j = 0; j < 3; ++j) {
            s1->initial[i][j] = s2 ->initial[i][j];
        }
    }
}

bool State::explore(vector<State*>& v) {                        // checks to see if state has already been explored using Compare State function
    for(int i = 0; i < v.size(); ++i) {
        if(Compare_State(this, v.at(i))) {
            return true;
        }
    }

    return false;
}











