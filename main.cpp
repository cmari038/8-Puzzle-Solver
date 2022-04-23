#include <iostream>
using namespace std;
#include "State.h"
#include <vector>


int main() {

    int input; 
    string algorithm;
    int board[3][3];
    vector<State*> frontier;
    vector<State*> explored;
    vector<int> cost;
    

    cout << "Welcome to 862232299 8 puzzle solver." << endl;
    cout << "Type 1 to use a default puzzle, or 2 to enter your own puzzle." << endl; 

    cin >> input;

    if(input == 1) {

    }

    else if(input == 2) {
        cout << "Enter your puzzle, use a zero to represent the blank" << endl << "Enter the first row, use space or tabs between numbers" << endl; 

        for(unsigned i = 0; i < 3; ++i) {
            cin >> input;
            board[0][i] = input;
        }

        cin.clear();

        cout << "Enter the second row, use space or tabs between numbers" << endl;

        for(unsigned i = 0; i < 3; ++i) {
            cin >> input;
            board[1][i] = input;
        }

        cin.clear();

        cout << "Enter the third row, use space or tabs between numbers" << endl;

        for(unsigned i = 0; i < 3; ++i) {
            cin >> input;
            board[2][i] = input;
        }

        cin.clear();

       cout << "Enter your choice of algorithm" << endl << "Uniform Cost Search" << endl << "A* with the Misplaced Tile heuristic" << endl << "A* with the the Euclidean distance heuristic" << endl;

      //  cin >> algorithm;

      //State* state = new State(board);
      //state->print();
    

    }

    return 0;
}