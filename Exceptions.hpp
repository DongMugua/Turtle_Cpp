/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/

#pragma once
#include <exception>

class CrossBorder : public std::exception {
public:
  const char *what() const noexcept override {
    return "️⚠️The brush has crossed the border‼️";
  }
};

class MissCommand: public std::exception {
public:
  const char *what() const noexcept override {
    return "️⚠️Missing command‼️";
  }
};

class CommandError: public std::exception {
public:
    const char *what() const noexcept override {
      return "⚠️Command error‼️";
    }
};
class FormatError1: public std::exception {
public:
  const char *what() const noexcept override {
    return "️⚠️Please enter in the format below: si ... alors ...‼️";
  }
};

class FormatError2: public std::exception {
public:
  const char *what() const noexcept override {
    return"️⚠️Please enter in the format below: repeter ... n fois‼️";
  }
};

class FormatError3: public std::exception {
public:
  const char *what() const noexcept override {
    return"️⚠️Please enter in the format below: tantque ... faire ...‼️";
  }
};

class FormatError4: public std::exception {
public:
  const char *what() const noexcept override {
    return"️⚠️Please enter in the correct format‼️";
  }
};

class ColorError: public std::exception {
public:
  const char *what() const noexcept override {
    return"⚠️Please enter in the format below: black, white, blue...‼️";
  }
};

class ConditionError:public std::exception {
public:
  const char *what() const noexcept override {
    return"⚠️Please enter the operator like: > < = ....‼️";
  }
};

class FichierError:public std::exception {
public:
  const char *what() const noexcept override {
    return"⚠️Can't find fichier...‼️";
  }
};
