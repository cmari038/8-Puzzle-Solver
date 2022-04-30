#include <iostream>
using namespace std;
#include "State.h"
#include <vector>
#include <algorithm>
#include <queue>
#include "Tree.h"


bool CostComparison(State* s1, State* s2) { // comparator used to edit sort based on cost. Learned from geeksforgeeks.org and cpluplus.com
        return s1->getTotalCost() < s2->getTotalCost();
}
 

int main() {

    int input; 
    int board[3][3];
    vector<State*> frontier; 
    vector<State*> explored;
    int depth;
    int maxNodes = 1; 
    int expndNodes = 1;
    State* state = nullptr;
    bool Goal = false;
    int fail = 0;
    Tree* tree;
    

    // General inputs to start program
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


        tree = new Tree(state);

        cin.clear();

        cout << "Enter your choice of algorithm" << endl << "Uniform Cost Search" << endl << "A* with the Misplaced Tile heuristic" << endl << "A* with the the Euclidean distance heuristic" << endl;

        cin >>input;

        state->setSearchChoice(input);

        // search algorithm  

      State* holder = nullptr;

     // Putting start state into frontier

       frontier.push_back(state);
       cout << "Expanding node" << endl;
       state->print();

       while(!Goal) {
            
            // checking to see if frontier is empty which means all nodes have been explored and goal does not exist
           if(frontier.size() == 0) {
               cout << "Failure" << endl;
               fail = 1;
               Goal = true;
           }

         // Putting node with the smallest cost into explored
           explored.push_back(state);
           
         // Rmoving node with smallest cost from frontier. Smallest cost will always be the first node in frontier.
           frontier.erase(frontier.begin()); 
           
        //   check if state we removed from frontier is goal
           if(state->comparison()) {  
                Goal = true;
           }

           else { // expansion of node with the lowest cost into children nodes that can be created from all possible moves

                // move blank left
                if(state->getBlankY() != 0) {

                    holder = new State(state);  // copy initial state of node with smallest cost into a new memory location
                    holder -> left();   // modify node's initial state based on move operator
                   
                    if(!holder->explore(explored)) {    //if new node is not in the explored vector, push into frontier
                        frontier.push_back(holder); 
                    }

                    else {  // if new node has already been explored, delete it
                        delete holder;
                    }
                }

                if(state->getBlankY() != 2) {

               //  Right operator

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

                 // Up operator

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

               //    Down operator
                   holder = new State(state);
                   holder -> down();
                   
                    if(!holder->explore(explored)) {
                        frontier.push_back(holder); 
                    }

                    else {
                        delete holder;
                    }
                } 

                if(frontier.size() > maxNodes) {    // constantly updates maxNodes with the largest number of nodes found in frontier
                    maxNodes = frontier.size();
                }
                
                sort(frontier.begin(), frontier.end(), CostComparison);     //sorts all nodes in frontier ffrom lowest cost to highest cost
                state = frontier.at(0);         //sets state equal to node at beginning of frontier since it has lowest cost
                cout << "The best state to expand with g(n) = " << state->C() << " and h(n) = " << state->getHeuristic() << endl;   // prints out cost and heuristic for smallest node
                state -> print();
                cout << "Expanding this node..." << endl;
                ++expndNodes;   //keeps track of how many nodes we have expanded 
            }


       } 

    
        if(Goal == true && fail == 0) {         // once goal is found
                tree->getParent(state);
                state->print();
                cout << "Goal!!!" << endl;
                cout << endl;
                cout << "To solve this problem, the search algorithm expanded a total of " << expndNodes << " nodes." << endl;
                cout << "The maximum number of nodes in the queue at any one time: " << maxNodes << endl;
                cout << "The depth of the goal node was " << tree->getDepth() << endl;
                cout << endl;
                cout << "Pathway:" << endl;
                tree->printPath();
                
        } 

    

    return 0;
}