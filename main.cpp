#include <iostream>
using namespace std;
#include "State.h"
#include <vector>


int min(vector<int>& v) {
    int val = v.at(0);
    int index;

    for(unsigned i = 0; i < v.size(); ++i) {
        if(v.at(i) < val) {
            val = v.at(i);
            index = i;
        }
    }

    return index;
}


int main() {

    int input; 
    string algorithm;
    int board[3][3];
    vector<State*> frontier;
    vector<State*> explored;
    vector<int> cost;
    int choice;
    State* state = nullptr;
    bool goal = false;
    

    cout << "Welcome to 862232299 8 puzzle solver." << endl;
    cout << "Type 1 to use a default puzzle, or 2 to enter your own puzzle." << endl; 

    cin >> input;

    if(input == 1) {

        state = new State();
        
    }

    else if(input == 2) {
        cout << "Enter your puzzle, use a zero to represent the blank" << endl << "Enter the first row, use space or tabs between numbers" << endl; 

        cin.clear();

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

        state = new State(board);
    }
    

        cin.clear();

        cout << "Enter your choice of algorithm" << endl << "Uniform Cost Search" << endl << "A* with the Misplaced Tile heuristic" << endl << "A* with the the Euclidean distance heuristic" << endl;

        cin >> algorithm;

        if(algorithm == "Uniform Cost Search") {
            choice = 1;
        }

        else if(algorithm == "A* with the Misplaced Tile heuristic") {
            choice = 2;
        }

        else {
            choice = 3;
        }

       //state->print();

        // search 

      State* holder = nullptr;

       frontier.push_back(state);

       while(!goal) {

           if(frontier.size() == 0) {
               cout << "Failure" << endl;
               goal = true;
           }

           explored.push_back(state);
           //delete frontier.at(min(cost));

           if(state->comparison()) {  // check if it's goal
               goal = true;
           }

           else { // expand

                if(state->getBlankX() != 0) { // left operator

                    if(!state->CompareArrayVal(state->getBlankX() - 1, state->getBlankY())) {
                        holder = state->left();
                        frontier.push_back(holder);
                        cost.push_back(holder->getTotalCost(choice)); }

                }

                 if(state->getBlankX() != 2) { // right operator
                    
                    if(!state->CompareArrayVal(state->getBlankX() + 1, state->getBlankY())) {
                        holder = state->right();
                        frontier.push_back(holder);
                        cost.push_back(holder->getTotalCost(choice)); }

                }

                 if(state->getBlankY() != 0) { // up operator

                    if(!state->CompareArrayVal(state->getBlankX(), state->getBlankY() + 1)) {
                        holder = state->up();
                        frontier.push_back(holder);
                        cost.push_back(holder->getTotalCost(choice)); }

                }

                 if(state->getBlankY() != 2) { // down operator

                    if(!state->CompareArrayVal(state->getBlankX(), state->getBlankY() - 1)) {
                        holder = state->down();
                        frontier.push_back(holder);
                        cost.push_back(holder->getTotalCost(choice)); }

                }

                state = frontier.at(min(cost));


            }



        }

    

    return 0;
}