//
//  bag.hpp
//  Asss1
//
//  Created by Kurtis Satterlee on 8/30/22.
//

#ifndef bag_hpp
#define bag_hpp

#include <stdio.h>
#pragma once
#include <iostream>
#include "myVector.hpp"

template <typename Thing>
class Bag {
public:
  void insert(Thing aThing) {
    bagContents.push_back(aThing);
    bagSize++;
  }
 Thing &pop() {
    Thing aThing;
    int test =-1;
    while(test != -1){
      for(int x = 0; x < bagContents.size(); x++){
        std::cout<<"Item number: " << x << " "<< bagContents[x] << std::endl;
      }
    if (bagContents.size() > 0) {
      std::cout<<"please type the the number that you wish to pull out the bag or enter -1 to end: ";
      std:: cin >> test;
      if(test > bagContents.size()){
        std:: cout << "error: the number you type is beiger then the bag size             please try another number";
      }
      else
      
       bagContents[test]= - test;;
       
       
    }
    else {
      std::cerr << "Can't pop out of an empty bag" << std::endl;
    }
      }
    return aThing;
  }
  int size() {
    return bagSize;
  }
  void count(Thing aThing) {
    //int bagCount = 0;
    for (int i = 0 ; i < bagSize; i++) {
      if (bagContents[i] == aThing) {
          std::cout<<"Item number: " << i << " "<< bagContents[i] << std::endl;
        //bagCount++;
      }
    }
    //return bagCount;
  }
private:
  Vector<Thing> bagContents;
  int bagSize = 0;
};


#endif /* bag_hpp */
