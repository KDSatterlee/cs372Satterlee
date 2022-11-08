//References:https://www.boost.org/doc/libs/1_52_0/libs/graph/doc/kevin_bacon.html
//https://web.stanford.edu/class/archive/cs/cs110/cs110.1202/static/assignments/Assignment-1-Six-Degrees-of-Kevin-Bacon.pdf
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Graph.h"
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int splitFirst(string aline, string& first, string& rest) {
    first = rest = "";
    if (aline == "") return 0;
    string next;
    istringstream iss(aline);
    iss >> first;
    iss >> rest;
    if (rest == "") return 1;
    iss >> next;
    while (iss && next != "") {
        rest = rest + " " + next;
        iss >> next;
    }
    return 2;
}

int main(int argc, char** argv) {
 
    vector<int> actorID;
    vector<int> movieID;
    vector<int> relationMovieID;
    vector<int> relationActorID;
    vector<string> actorName;
    vector<string> movieTitle;
    string aline, first, second;
    int iFirst, iSecond;
   
    Graph Fullgraph(actorID.size());
    
    int a1, a2;
    for (int i = 0; i < relationActorID.size(); i++) {
        for (int j = i + 1; j < relationActorID.size(); j++) {
            if (relationMovieID[i] == relationMovieID[j]) {
                if (relationActorID[i] != relationActorID[j]) {
                    for (int k = 0; k < actorID.size(); k++) {
                        if (relationActorID[i] == actorID[k])
                            a1 = k;
                    }
                    for (int l = 0; l < actorID.size(); l++) {
                        if (relationActorID[j] == actorID[l]) {
                            a2 = l;
                        }
                    }
                    if (Fullgraph.hasEdge(a1, a2) == false) {
                        Fullgraph.addEdge(a1, a2, relationMovieID[i]);
                    }
                }
            }
        }
    }
    bool found_name = false;
    int baconsource, inputNumber, tempGetEdgeVal, intMovName, savedj;
    string checkinput, inputName;
    for (int m = 0; m < actorName.size(); m++) {
        if (actorName[m] == "Kevin Bacon") {
            baconsource = m;
        }
    }
    vector<int> distance(actorID.size(), -1);
    vector<int> go_through(actorID.size(), -1);
    Fullgraph.BFS(baconsource, distance, go_through);

    int biggest = 0;
    int biggestID;
    int amtOfPeoplewithFarthest = 0;
    vector<string> people;
    
    for (int i = 0; i < actorID.size(); i++) {
        if (biggest < distance[i]) {
            biggest = distance[i];
            biggestID = i;
        }
    }
    
    for (int i = 0; i < actorID.size(); i++) {
        if (distance[i] == biggest) {
            people.push_back(actorName[i]);
            amtOfPeoplewithFarthest++;
        }
    }
   
    if (people.size() != 0) {
        cout << "Consider searching these people!" << endl;
        for (int i = 0; i < amtOfPeoplewithFarthest; i++) {
            cout << "Highest distance away(" << biggest << "): " << people[i] << endl;
        }
        cout << "------------------------------------------------------------------------------------" << endl;
    }

 
    cout << "************************************************************************************" << endl;
    cout << "The Bacon number of an actor is the number of degrees of separation he/she has from Bacon." << endl << "Those actors who have worked directly with Kevin Bacon in a movie have a Bacon number of 1." << endl;
    cout << "This application helps you find the Bacon number of an actor." << endl << "Enter \"exit\" to quit the program." << endl;
    cout << "Please enter an actor's name (case-sensitive): ";
    getline(cin, checkinput);
    cout << endl;
    cout << "************************************************************************************" << endl;
    cout << endl;

    while (true) {
        for (int i = 0; i < actorName.size(); i++) {
            if (checkinput == actorName[i]) {
                inputName = actorName[i];
                inputNumber = i;
                found_name = true;
            }
        }
        if (found_name == false) {
            if (checkinput == "exit" || checkinput == "Exit")
                break;
            else {
                cout << "Invalid input, please try again..." << endl << endl;
            }
        }
        else if (distance[inputNumber] == -1) {
            cout << actorName[inputNumber] << " does not have a relationship to " << actorName[baconsource] << endl << endl;
        }
        else {
            if (baconsource != inputNumber)
            
            {
                cout << "The Kevin Bacon number of " << actorName[inputNumber] << " is: " << distance[inputNumber] << "." << endl;
                if (distance[inputNumber] != 1) {
                    savedj = inputNumber;
                    for (int j = inputNumber; go_through[j] != baconsource; j = go_through[j]) {
                        tempGetEdgeVal = Fullgraph.getEdge(j, go_through[j]);
                        for (int p = 0; p < movieID.size(); p++) {
                            if (movieID[p] == tempGetEdgeVal) {
                                intMovName = p;
                            }
                        }
                        cout << actorName[j] << " appeared in " << movieTitle[intMovName] << " with " << actorName[go_through[j]] << endl;
                        savedj = j;
                    }
                    tempGetEdgeVal = Fullgraph.getEdge(go_through[savedj], go_through[go_through[savedj]]);
                    for (int p = 0; p < movieID.size(); p++) {
                        if (movieID[p] == tempGetEdgeVal) {
                            intMovName = p;
                        }
                    }
                    
                    cout << actorName[go_through[savedj]] << " appeared in " << movieTitle[intMovName] << " with " << actorName[baconsource] << endl << endl;
                }
                else
                {
                    tempGetEdgeVal = Fullgraph.getEdge(inputNumber, baconsource);
                    for (int p = 0; p < movieID.size(); p++)
                    
                    
                    {
                        if (movieID[p] == tempGetEdgeVal)
                        
                        {
                            intMovName = p;
                        }
                    }
                    cout << actorName[inputNumber] << " appeared in ";
                    cout << movieTitle[intMovName] << " with " << actorName[baconsource] << endl;
                    cout << endl;
                }
            }
            else {
                cout << actorName[baconsource] << " has a distance of 0 from themself" << endl << endl;
            }
        }
        cout << "************************************************************************************" << endl;
        cout << "The Bacon number of an actor is the number of degrees of separation he/she has from Bacon." << endl << "Those actors who have worked directly with Kevin Bacon in a movie have a Bacon number of 1." << endl;
        cout << "This application helps you find the Bacon number of an actor." << endl << "Enter \"exit\" to quit the program." << endl;
        cout << "Please enter an actor's name (case-sensitive): ";
        getline(cin, checkinput);
        cout << endl;
        cout << "************************************************************************************" << endl;
        cout << endl;
        found_name = false;
    }
    return 0;
}
