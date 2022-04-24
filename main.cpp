#include <iostream>
using namespace std;
#include "State.h"
#include <vector>
#include <algorithm>
#include <queue>


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

bool CostComparison(State* s1, State* s2) { // comparator used to sort. Learned from geeksforgeeks.org and cpluplus.com
        return s1->getTotalCost() < s2->getTotalCost();
}
 

int main() {

    int input; 
    string algorithm;
    int board[3][3];
    vector<State*> frontier;
    vector<State*> explored;
    int choice;
    State* state = nullptr;
    bool goal = false;
    bool fail = false;
    

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
        cout << endl;
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

        state->setSearchChoice(choice);

        // search 

      State* holder = nullptr;

      cout << "Putting start state into frontier" << endl;

       frontier.push_back(state);

      // while(!goal || !fail) {

           if(frontier.size() == 0) {
               cout << "Failure" << endl;
               fail = true;
           }

           cout << "Putting state into explored" << endl;
           explored.push_back(state);
           
           cout << "Remove state from frontier" << endl;
           frontier.erase(frontier.begin()); //remove node from frontier

           
           if(state->comparison()) {  // check if it's goal
               goal = true;
           }

           else { // expand

           cout << "Expansion" << endl;

                if(state->getBlankY() != 0) {

                    cout << "left" << endl;
                    holder = new State(state);
                    holder -> left();
                   
                    if(!Compare_State(holder, explored.back())) {
                        frontier.push_back(holder); 
                        holder -> print();
                        cout << endl;
                    }

                    else {
                        delete holder;
                    }
                }

                if(state->getBlankY() != 2) {

                    cout << "right" << endl;

                    holder = new State(state);
                    holder -> right();
                   
                    if(!Compare_State(holder, explored.back())) {
                        frontier.push_back(holder); 
                        holder -> print();
                    }

                    else {
                        delete holder;
                    }
                }

                if(state->getBlankX() != 0) {

                    cout << "up" << endl;

                    holder = new State(state);
                    holder -> up();
                   
                    if(!Compare_State(holder, explored.back())) {
                        frontier.push_back(holder); 
                        holder -> print();
                    }

                    else {
                        delete holder;
                    }
                }

                if(state->getBlankX() != 2) {

                   cout << "down" << endl;
                   holder = new State(state);
                   holder -> down();
                   
                    if(!Compare_State(holder, explored.back())) {
                        frontier.push_back(holder); 
                        holder -> print();
                    }

                    else {
                        delete holder;
                    }
                } 

                sort(frontier.begin(), frontier.end(), CostComparison); 
                state = frontier.at(0);
             // state -> print();

            }


      // } 

    
        if(goal == true) {
                state->print();
        } 

    

    return 0;
}