/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/
#pragma once

template<typename T>
class Singleton {
public:
  static T* InstanceUnique() {
    static T instanceUnique;
    return &instanceUnique;
  }
};
