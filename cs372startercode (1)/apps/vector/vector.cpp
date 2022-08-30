//
// File:   myvectest.cpp
// Author: Your Glorious Instructor
// Purpose:
// Determine behavior and performance of capacity increate in STL vector.
//
#include "myVector.hpp"
#include <chrono>
#include <vector>
#include <iostream>

class VecTester {
private:
    Vector<int> testVector;
    std::vector<int> testVector2 =  std::vector<int>();
    
    void fillVector(size_t cap) {
        for (int i = 0 ; i < cap; ++i) { testVector[i] = i; }
    }
  void fillVector2(size_t cap) {
        for (int i = 0 ; i < cap; ++i) { testVector[i] = i; }
    }
   
public:
    void tester() {
        size_t oldCap = testVector.capacity();
        std::cout << "Starting capacity: " << oldCap << std::endl;
        for (int i = 0; i <= 10000; i++) {
            auto start = std::chrono::steady_clock::now();
            testVector.push_back(i);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elaspedSeconds = end - start;
            int newCap = testVector.capacity();
            if (oldCap != newCap) {
                std::cout << " Capacity after add "
                << oldCap
                << " Time: "
                << elaspedSeconds.count() << " seconds"
                << std::endl;
                oldCap = newCap;
            }
                
        }
    }
void tester2() {
        size_t oldCap = testVector2.capacity();
        std::cout << "Starting capacity: " << oldCap << std::endl;
        for (int i = 0; i <= 10000; i++) {
            auto start = std::chrono::steady_clock::now();
            testVector2.push_back(i);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elaspedSeconds = end - start;
            int newCap = testVector2.capacity();
            if (oldCap != newCap) {
                std::cout << " Capacity after add "
                << oldCap
                << " Time: "
                << elaspedSeconds.count() << " seconds"
                << std::endl;
                oldCap = newCap;
            }
                
        }
    }
};

int main() {
    VecTester testingObject;
    std::cout << "Starting test: " << std::endl;
    testingObject.tester();
    std::cout << std::endl;
    std::cout << "Starting test 2 for stl vector" <<std::endl;
    testingObject.tester2();
    return 0;
}
