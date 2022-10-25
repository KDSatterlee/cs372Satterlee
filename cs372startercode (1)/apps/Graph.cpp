//
//  main.cpp
//  ass6
//
//  Created by Kurtis Satterlee on 10/17/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "AdjMatrixGraph.hpp"
#include "AdjListGraph.hpp"
#include "Graph.hpp"

using namespace std;
int main() {
    // insert code here...
    vector<int> main;
    AdjMatrixGraph<int> agraph;
    AdjListGraph<int> ngraph;
    int count;
    int tmp;
    
    ifstream myfile ("list_of_nodes", ios::in);
    
    
    while (!myfile) {
            myfile >> tmp;
        agraph.addNode(tmp);
        }
    
    agraph.neighbors(myfile);
    ngraph.neighbors(myfile);
    
    return 0;
}
