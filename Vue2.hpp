#pragma once

#include <iostream>
#include "Observer.hpp"
#include "PileL.hpp"

class Vue2 : public Observer<PileL> {
public:
  void update (PileL *info) override {
    for(auto x:info->getList())
      std::cout<<x;
    std::cout<<std::endl;
  }
};
 
