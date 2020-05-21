#pragma once

template<typename T>
class Singleton {
public:
  static T* InstanceUnique() {
    static T instanceUnique;
    return &instanceUnique;
  }
};
