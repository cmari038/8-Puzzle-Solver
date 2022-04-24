#include "State.h"

// g++ main.cpp State.cpp
 int State::getDistance(int val, int x, int y) {

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

    State::State() {
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

        initial[0][2] = 5;
        initial[1][0] = 3;
        initial[1][1] = 4;

    }

    State::State(int start[3][3]) {
       
       State();
       setInitial(start);

    }

    State::State(State* s) {
        State();
        Copy(this, s);
    }

    void State::setInitial(int start[3][3]) {
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

    int State::MisplacedTile() {
        int count = 0;
        for(unsigned i = 0; i < 3; ++i) {
            for(unsigned j = 0; j < 3; ++j) {
                if(initial[i][j] != goal[i][j]) {
                    ++count;
                }
            }
        }
        return count;
    }


    int State::Euclidean() {
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



    bool State::comparison() {

        for(unsigned i = 0; i < 3; ++i) {
            for(unsigned j = 0; j < 3; ++j) {
                if(initial[i][j] != goal[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }


    void State::print() {
        for(unsigned i = 0; i < 3; ++i) {
            for(unsigned j = 0; j < 3; ++j) {
               cout << initial[i][j] << " ";
            }
            cout << endl;
        }
}

void State::left() {
    int holder = initial[blankX][blankY-1];
    initial[blankX][blankY-1] = 0;
    initial[blankX][blankY] = holder;
    blankY = blankY - 1;
    ++cost;
}

void State::right() {
    int holder = initial[blankX][blankY+1];
    initial[blankX][blankY+1] = 0;
    initial[blankX][blankY] = holder;
    blankY = blankY + 1;
    ++cost;
}

void State::up() {
    int holder = initial[blankX+1][blankY];
    initial[blankX+1][blankY] = 0;
    initial[blankX][blankY] = holder;
    blankX = blankX + 1;
    ++cost;
}

void State::down() {
    int holder = initial[blankX-1][blankY];
    initial[blankX-1][blankY] = 0;
    initial[blankX][blankY] = holder;
    blankX = blankX - 1;
    ++cost;
}

void State::SetCost() {
    

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


bool Compare_State(State* s1, State* s2) {
         
         for(unsigned i = 0; i < 3; ++i) {
            for(unsigned j = 0; j < 3; ++j) {
                if(s1->initial[i][j] != s2->initial[i][j]) {
                    return false;
                }
            }
        }
        return true;
}

/*State* State::operators(string move) {
            if(blankX != 0 && move == "left") { // left operator
              
                return left();       
            }

            else if(blankX != 2 && move == "right") { // right operator
               
                return right();   
            }

            else if(blankY != 0 && move == "up") { // up operator
               
                return up();
            }

            else if(blankY != 2 && move == "down") { // down operator

                return down();  
            }
 
            return nullptr;             
} */

void Copy(State* s1, State* s2) {

    s1->blankX = s2->blankX;
    s1->blankY = s2->blankY;
    s1 -> SearchChoice = s2->SearchChoice;

    for(unsigned i = 0; i < 3; ++i) {
        for(unsigned j = 0; j < 3; ++j) {
            s1->initial[i][j] = s2 ->initial[i][j];
        }
    }
}











