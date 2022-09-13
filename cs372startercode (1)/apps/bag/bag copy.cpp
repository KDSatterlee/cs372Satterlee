//
// Author: Kurtis Satterlee
//
#include "bag.hpp"
#include <chrono>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
int main() {
    Bag<string> test;
    string test2;
         cout << "Please eneter something to put in the bag then press x to stop" << endl;
    do{
 
        cin>> test2;
      if(test2 != "x" && "X" ){
        cout<<endl;
        test.insert(test2);
        test.count(test2);
        }
    
    }while(test2 != "x");
    cout << "Stor bag has " << test.size() << "\n";
    
    test.pop();
            
    return 0;
}
