/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/

#pragma once

#include "Observer.hpp"
#include <list>

template <typename T>
class Observable{
private:
  std::list<Observer<T> *> list_observers;

public:
  void notifyObservers(T *info) {
    for (auto obs : this->list_observers)
      obs->update(info);
  }

  void addObserver( Observer<T> * observer) {
    this->list_observers.push_back(observer);
  }
};
