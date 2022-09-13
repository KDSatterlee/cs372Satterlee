#pragma once
#include <functional>
#include "List2.hpp"
template <typename T>
class SelfList : public List<T> {
private:
  typename SelfList<T>::iterator findInList(T data) {
    typename SelfList<T>::iterator placeInList = this->begin();
    typename SelfList<T>::iterator endOfList = this->end();
    bool found = false;
    while (!found && placeInList != endOfList) {
      if (*placeInList == data) {
        found = true;
      }
      placeInList++;
    }
    return placeInList;
  }
public:
  typename SelfList<T>::iterator findIt(T data) {
    typename SelfList<T>::iterator whereFound = findInList(data);
    if (whereFound != this->end()) {
      T &temp = *whereFound;
      this->circle(whereFound);
      this->erase(whereFound);
      this->push_front(temp);
    }
    return whereFound;
  }
};
