#include "State.h"

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
            for(unsigned int j = 0; j < 3; ++i) {
                cout << initial[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
}

State* State::left() {
    int holder = initial[blankX - 1][blankY];
    initial[blankX-1][blankY] = 0;
    initial[blankX][blankY] = holder;
    blankX = blankX - 1;
    return this;
}

State* State::right() {
    int holder = initial[blankX + 1][blankY];
    initial[blankX + 1][blankY] = 0;
    initial[blankX][blankY] = holder;
    blankX = blankX + 1;
    return this;
}

State* State::up() {
    int holder = initial[blankX][blankY+1];
    initial[blankX][blankY + 1] = 0;
    initial[blankX][blankY] = holder;
    blankY = blankY + 1;
    return this;
}

State* State::down() {
    int holder = initial[blankX][blankY - 1];
    initial[blankX][blankY - 1] = 0;
    initial[blankX][blankY] = holder;
    blankY = blankY - 1;
    return this;
}

void State::SetCost(int val) {
    if(val == 1) {
        Heuristic = 1;
    }

    else if(val == 2) {
        Heuristic = MisplacedTile() + 1;
    }

    else {
        Heuristic = Euclidean() + 1;
    }
}







