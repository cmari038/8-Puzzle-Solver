#include <iostream>
using namespace std;
#include "State.h"
#include <vector>
#include <algorithm>
#include <queue>


bool CostComparison(State* s1, State* s2) { // comparator used to edit sort. Learned from geeksforgeeks.org and cpluplus.com
        return s1->getTotalCost() < s2->getTotalCost();
}
 

int main() {

    int input; 
    int board[3][3];
    vector<State*> frontier;
    vector<State*> explored;
    int depth;
    int maxNodes = 0;
    int expndNodes = 1;
    State* state = nullptr;
    bool Goal = false;
    int fail = 0;
    

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

        cin >>input;

        state->setSearchChoice(input);

        // search 

      State* holder = nullptr;

     // cout << "Putting start state into frontier" << endl;

       frontier.push_back(state);

       while(!Goal) {

           if(frontier.size() == 0) {
               cout << "Failure" << endl;
               fail = 1;
               Goal = true;
           }

         //  cout << "Putting state into explored" << endl;
           explored.push_back(state);
           
         //  cout << "Remove state from frontier" << endl;
           frontier.erase(frontier.begin()); //remove node from frontier
           
           cout << "check if it is goal:" << state->comparison() << endl;
           if(state->comparison()) {  // check if it's goal
                cout << "true" << endl;
                Goal = true;
           }

           else { // expand

           cout << "Expansion" << endl;

                if(state->getBlankY() != 0) {

                //    cout << "left" << endl;
                    holder = new State(state);
                    holder -> left();
                   
                    if(!holder->explore(explored)) {
                        frontier.push_back(holder); 
                    }

                    else {
                        delete holder;
                    }
                }

                if(state->getBlankY() != 2) {

               //     cout << "right" << endl;

                    holder = new State(state);
                    holder -> right();
                   
                    if(!holder->explore(explored)) {
                        frontier.push_back(holder); 
                    }

                    else {
                        delete holder;
                    }
                }

                if(state->getBlankX() != 0) {

                 //   cout << "up" << endl;

                    holder = new State(state);
                    holder -> up();
                   
                    if(!holder->explore(explored)) {
                        frontier.push_back(holder); 
                    }

                    else {
                        delete holder;
                    }
                }

                if(state->getBlankX() != 2) {

               //    cout << "down" << endl;
                   holder = new State(state);
                   holder -> down();
                   
                    if(!holder->explore(explored)) {
                        frontier.push_back(holder); 
                    }

                    else {
                        delete holder;
                    }
                } 

                if(frontier.size() > maxNodes) {
                    maxNodes = frontier.size();
                }
                
                sort(frontier.begin(), frontier.end(), CostComparison); 
                state = frontier.at(0);
                cout << "The best state to expand with g(n) " << state->C() << "and h(n) " << state->getHeuristic() << endl;
                state -> print();
                cout << "Expanding this node..." << endl;
                ++expndNodes;
            }


       } 

    
        if(Goal == true && fail == 0) {
                state->print();
                cout << "Goal!!!" << endl;
                cout << endl;
                cout << "To solve this problem, the search algorithm expanded a total of " << expndNodes << " nodes." << endl;
                cout << "The maximum number of nodes in the queue at any one time: " << maxNodes << endl;
                cout << "The depth of the goal node was " << endl;
        } 

    

    return 0;
}