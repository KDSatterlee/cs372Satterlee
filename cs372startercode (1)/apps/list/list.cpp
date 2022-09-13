#include <iostream>
#include "List.hpp"

void printItem(int &item) {
  std::cout << item << " ";
}


int main() {
  List<int> aListOfIntegers;
  if (aListOfIntegers.empty()) {
    std::cout << "Yep, the new list is empty. " << std::endl;
  }
  for (int i = 3; i >= 0; i--) {
    aListOfIntegers.push_front(i);
  }
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  std::cout << "Test iterators: Mutable -> ";
  for (auto iter = aListOfIntegers.begin();
            iter != aListOfIntegers.end();
            ++iter) {
              std::cout << *iter << " ";
            }
    std::cout << std::endl;

   std::cout << "Test iterators: const -> ";
  for (auto iter = aListOfIntegers.cbegin();
            iter != aListOfIntegers.cend();
            ++iter) {
              std::cout << *iter << " ";
            }
    std::cout << std::endl;
    
   std::cout << "test iterators: Mutabke rev -> ";
    for(auto iter = aListOfIntegers.rbgin();
        iter != aListOfIntegers.rend();
        --iter){
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Test iterators: const rev -> ";
   for (auto iter = aListOfIntegers.crbegin();
             iter != aListOfIntegers.crend();
             --iter) {
               std::cout << *iter << " ";
             }
    std::cout << std::endl;
    
    auto iter = aListOfIntegers.begin();
    
    aListOfIntegers.erase(iter);
    
    for (auto iter = aListOfIntegers.cbegin();
              iter != aListOfIntegers.cend();
              ++iter) {
                std::cout << *iter << " ";
              }
    
    aListOfIntegers.insert(iter, 1);
    
    for (auto iter = aListOfIntegers.cbegin();
              iter != aListOfIntegers.cend();
              ++iter) {
                std::cout << *iter << " ";
              }
    
    std::cout << *iter;
    
  
  std::cout << std::endl;
  for (int i = 0; i < 3; i++) {
    int datum = aListOfIntegers.back();
    std::cout << datum << " ";
    aListOfIntegers.pop_back();
  }
  std::cout << std::endl;
  if (!aListOfIntegers.empty()) {
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
  }
  aListOfIntegers.push_back(42);
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;
  return 0;
}
