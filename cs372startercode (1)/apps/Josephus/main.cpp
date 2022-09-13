

#include <iostream>
#include "Josephus.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    int M,N;
    Josephus Jose;
    cout<< "Welcome to Josephus Promblem. "<< endl;
    cout<< "Please input M for passing times:" <<endl;
    cin >> M;
    cout<< "Please input N for number of people:" << endl;
    cin >> N;
    if (M <0 || N<1) {
        cout<< "M must not smaller than 0, and N must not smaller than 1!" <<endl;
        return -1;
    }

    Jose.createJose(N);
    cout <<"There are" << N <<"people. The order of people:"<<endl;
    Jose.printJose();
    cout <<"The order of quit the game:"<<endl;
    Jose.deleteJose(M,N);


    return 0;
}
