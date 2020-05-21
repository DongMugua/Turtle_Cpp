#pragma once
#include "Observable.hpp"
#include "PileL.hpp"
#include <iostream>
#include <vector>

class Modele : public Observable<PileL> {
private:
  PileL * robot_list;
  
public:
  Modele(){
    robot_list = PileL::getInstance();
    robot_list->setExp("init");
    robot_list->empiler(new Robot(0,0,true));
  }
  
  std::vector<std::string> split(std::string &str);
  bool verifier(std::vector<std::string> &command);
  void set_command(std::string command);
  void avancer(std::string s);
  void reculer(std::string s);
  void angleRegler(std::string s);
  void position(std::string x, std::string y);
  void lever();
  void laisser();
  void line_width(std::string s);
  void undo();
  void cacher();
  void afficher();
  void colorSet(std::string s);
  void RGB(std::string r, std::string g, std::string b);
  void tourner(std::string s);
  void clear();

  void readFile(std::string );
  void runFile(std::string );
  void analyseCommand(std::string &);
  void behavioralCommand(std::vector<std::string> &);
  void siCommand( std::vector<std::string> &);
  void repeterCommand( std::vector<std::string> &);
  void tantqueCommand( std::vector<std::string> &);
  double statusCommand(std::string );

  bool condition(double, std::string, double);
};
