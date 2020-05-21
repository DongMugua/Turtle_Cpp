/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/
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
 
