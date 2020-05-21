/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/


#pragma once

template <typename T>
class Observer{
public:
  virtual void update(T *info) = 0;
};
