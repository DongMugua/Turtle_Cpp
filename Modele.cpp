/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*
* La fonction de modèle est pour controler le robot.
*
*/

#include <cmath>
#include <algorithm>
#include <functional>
#include <iterator>
#include <exception>
#include <fstream>
#include "Modele.hpp"
#include "Exceptions.hpp"

#define WIDTH 600
#define HEIGHT 600

// Cette fonction est pour vérifier si la chaine de caractère est un nombre
bool Modele::verifier(std::vector<std::string> &v) {
  try{
    if (v.size()<2) {
      throw MissCommand();
    }
  }
  catch(const MissCommand &error) {
    robot_list->setExp("Please entry command after \""+v[0]+"\".");
    return false;
  }
  
  std::vector<std::string>::iterator it=v.begin();
  for (it=v.begin()+1;it<v.end();it++) {
    try{
      // Pour vérifier le caractère est nombre, point, plus oumoins.
      if( std::find_if(it->begin(),it->end(), [] (int x) { return  (x<48 || x>57) && x!=45 && x!=43 && x!=46; }) != it->end()) {
	throw CommandError(); 
	//return false;
      }
    }
    catch(const CommandError &error) {
      robot_list->setExp("Please entry number after \""+v[0]+"\".");
      return false;
    }
    
  }
  return true;
}


// Cette fonction est pour séparer le chaîne de caractères par espace.
std::vector<std::string> Modele::split(std::string &str) {
  std::vector<std::string> res;
  char *cstr = new char[str.length()+1];
  strcpy(cstr, str.c_str());
  
  char * p = std::strtok (cstr," ");
  while (p!=0) {
    res.push_back(p);
    p = std::strtok(NULL," ");
  }
  delete[] cstr;
  return res;
}

// C'est pour distinguer la opération.
bool Modele::condition(double c1, std::string condition, double nom) {
  try {
    if(condition==">")
      return c1>nom;
    else if(condition=="<")
      return c1<nom;
    else if(condition=="=")
      return c1==nom;
    else if(condition==">=")
      return c1>=nom;
    else if(condition=="<=")
      return c1<=nom;
    else if(condition=="!=")
      return c1!=nom;
    else
      throw ConditionError();
  }
  catch(const ConditionError &error) {
    robot_list->setExp(error.what());
  }
}

// Cette fonction est pour faire le robot avancer.
void Modele::avancer(std::string s) {
  Robot * robot = new Robot(robot_list->sommet(),true); // Créer un robot qui est égale à le sommet de pile.
  double x = robot_list->sommet().getX();
  double y = robot_list->sommet().getY();
  double angle = robot_list->sommet().getAngle();
  double dst = atof(s.c_str());
  robot->setX(x+dst*cos(angle));
  robot->setY(y+dst*sin(angle));
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour faire le robot reculer.
void Modele::reculer(std::string s) {
  Robot * robot = new Robot(robot_list->sommet(),true);
  double x = robot_list->sommet().getX();
  double y = robot_list->sommet().getY();
  double angle = robot_list->sommet().getAngle();
  double dst = atof(s.c_str());
  robot->setX(x-dst*cos(angle));
  robot->setY(y-dst*sin(angle));
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour changer l'angle.
void Modele::angleRegler(std::string s) {
  Robot * robot = new Robot(robot_list->sommet(),true);
  double des = atof(s.c_str());
  robot->setAngle(des);
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour positionner la robot.
void Modele::position(std::string x, std::string y){
  Robot *robot = new Robot(robot_list->sommet(),true);
  double x_des = atof(x.c_str());
  double y_des = atof(y.c_str());
  robot->setX(x_des);
  robot->setY(y_des);
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour lever le stylo.
void Modele::lever() {
  Robot * robot = new Robot(robot_list->sommet(),true);
  robot->setStyloStatus(false);
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour laisser le stylo.
void Modele::laisser() {
  Robot * robot = new Robot(robot_list->sommet(),true);
  robot->setStyloStatus(true);
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour changer la largeur de stylo.
void Modele::line_width(std::string s){
  Robot * robot = new Robot(robot_list->sommet(),true);
  double des = atof(s.c_str());
  robot->setLineWidth(des);
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour annuler l'étape précédente
void Modele::undo() {
  if(robot_list->getList().size()>1)
    robot_list->depiler();
}

// Cette fonction est pour cacher le robot.
void Modele::cacher() {
  Robot * robot = new Robot(robot_list->sommet(),true);
  robot->setRobotStatus(false);
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour affichier le robot.
void Modele::afficher() {
  Robot * robot = new Robot(robot_list->sommet(),true);
  robot->setRobotStatus(true);
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour changer la couleur que nous avnos met.
void Modele::colorSet(std::string s) {
  Robot * robot = new Robot(robot_list->sommet(),true);
  try{
    if (s=="black") {
      std::cout<<"black"<<std::endl;
      robot->setColor(0,0,0);
    } else if (s=="white") {
      robot->setColor(1,1,1);
    } else if (s=="blue") {
      robot->setColor(0,0,1);
    } else if (s=="green") {
      robot->setColor(0,1,0);
    } else if (s=="yellow") {
      robot->setColor(1,1,0);
    } else if (s=="red") {
      robot->setColor(1,0,0);
    } else if (s=="pink") {
      robot->setColor(1,0.7529,0.7960);
    } else if (s=="violet") {
      robot->setColor(0.9333,0.5098,0.9333);
    } else if (s=="orange") {
      robot->setColor(1,0.64706,0.47843);
    } else{
      throw ColorError();
    }
  }
  catch(const ColorError &error) {
    robot_list->setExp(error.what());
  }
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour changer la couleur à partir de RGB paramètre.
void Modele::RGB(std::string r, std::string g, std::string b){
  Robot * robot = new Robot(robot_list->sommet(),true);
  double r_ = atof(r.c_str());
  double g_ = atof(g.c_str());
  double b_ = atof(b.c_str());
  robot->setColor(r_,g_,b_);
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour faire le robot tourner.
void Modele::tourner(std::string a) {
  Robot * robot = new Robot(robot_list->sommet(),true);
  double des = atof(a.c_str());
  double ang = robot->getAngle();
  robot->setAngle(ang*180/PI+des);
  robot_list->empiler(robot);
  delete robot;
}

// Cette fonction est pour nettoyer tous les command.
void Modele::clear() {
  int size = robot_list->getList().size();
  for(int i=0;i<size-1;i++)
    robot_list->depiler();
}

// Cette fonction est pour vérifier la variable.
double Modele::statusCommand(std::string command) {
  try {
    if(command =="angle")
      return robot_list->sommet().getAngle()*180/PI;
    else if(command == "x")
      return robot_list->sommet().getX();
    else if(command == "y")
      return robot_list->sommet().getY();
    else
      throw FormatError4();
  } catch(const FormatError4 &error) {
    robot_list->setExp(error.what());
  }
}

// Cette fonction est pour vérifier et apeler choisir la command.
void Modele::behavioralCommand(std::vector<std::string> &command) {
  try{
    if(command[0] == "avancer") {
      if(verifier(command))
	avancer(command[1]);
    } else if(command[0] == "reculer") {
      if(verifier(command))
	reculer(command[1]);
    } else if(command[0] == "angle") {
      if(verifier(command))
	angleRegler(command[1]);;
    } else if(command[0] == "position") {
      if(verifier(command))
	position(command[1],command[2]);
    } else if(command[0] == "lever" ) {
      lever();
    } else if(command[0] == "laisser" ) {
      laisser();
    } else if(command[0] == "undo" ) {
      undo();
    } else if(command[0] == "width") {
      if(verifier(command))
	line_width(command[1]);
    } else if(command[0] == "color") {
      colorSet(command[1]);
    } else if(command[0] == "rgb") {
      if(verifier(command))
	RGB(command[1],command[2],command[3]);
    } else if(command[0] == "tourner") {
      if(verifier(command))
	tourner(command[1]);
    } else if(command[0] == "clear") {
      clear();
    } else if(command[0] == "cacher") {
      cacher();
    } else if(command[0] == "afficher") {
      afficher();
    } else {
      throw CommandError();
    }
  }
  catch(const CommandError &error) {
    robot_list->setExp(error.what());
  }	
}

// Cette fonction est pour réaliser la command si...alors...
void Modele::siCommand( std::vector<std::string> & command){
  std::vector<std::string> cmd;
  // trouver "alors" et enregistre la commande dans un vecteur.
  auto alors=std::find(command.begin(),command.end(),"alors"); 
  try{
    if (alors!=command.end()) {
      alors = alors +1;
      for(;alors < command.end(); alors++){
	cmd.push_back(*alors);
      }
      std::vector<std::string> nombre;
      nombre.push_back(command[2]);
      nombre.push_back(command[3]);
      // la réalisation de si..alors..
      if(verifier(nombre)) { 
	if(condition(statusCommand(command[1]),command[2], atof(command[3].c_str())))
	  behavioralCommand(cmd);
      }
    } else {
      throw FormatError1();
    }
  }
  catch(const FormatError1 &error) {
    robot_list->setExp(error.what());
  }
}

// Cette fonction est pour réaliser la command reprter ... n fois
void Modele::repeterCommand(std::vector<std::string> &command) {
  std::vector<std::string> cmd;
  std::vector<std::string>::iterator it;
  // trouver "fois" et enregistre la commande dans un vecteur.
  auto fois=std::find(command.begin(),command.end(),"fois");
  try{
    if(fois != command.end()) {
      for(it=command.begin()+1;it<fois-1;it++)
	cmd.push_back(*it);
      
      std::string s = *(fois-1);
      double l = atof(s.c_str());
      for(int i=0;i<l;i++)
	behavioralCommand(cmd);
    } else {
      throw FormatError2();
    }
  }
  catch(const FormatError2 &error) {
    robot_list->setExp(error.what());
  }
}

// Cette fonction est pour réaliser la command tantque ... faire ...
void Modele::tantqueCommand(std::vector<std::string> &command) {
  std::vector<std::string> cmd;
  auto faire=std::find(command.begin(),command.end(),"faire");
  try{
    if(faire != command.end()){
      faire = faire +1;
      for(;faire < command.end(); faire++){
	cmd.push_back(*faire);
      }
      
      std::vector<std::string> nombre;
      nombre.push_back(command[2]);
      nombre.push_back(command[3]);
      int i=0;
      if(verifier(nombre)) { 
	while(condition(statusCommand(command[1]),command[2], atof(command[3].c_str()))) {
	  if(abs(robot_list->sommet().getX()) <= WIDTH/2
	     && abs(robot_list->sommet().getY()) <= HEIGHT/2
	     && i<10000) {
	    i++;
	    behavioralCommand(cmd);
	  }
	  else {
	    if(i>=10000)
	      robot_list->setExp("Vous avez atteint le nombre maximal d'exécution de boucles: 1000");
	    break;
	  }
	}
      }      
    } else {
      throw FormatError3();
    }
  }
  catch(const FormatError3 &error) {
    robot_list->setExp(error.what());
  }
}

// Cette fonction est pour analyser la premier mot de la commmand
// afin de vérifier la propriété de la command.
void Modele::analyseCommand(std::string &cmd) {
  std::transform(cmd.begin(),cmd.end(),cmd.begin(), [] (unsigned char c) {return std::tolower(c);});
  std::vector<std::string> commandVector = split(cmd);
  
  if (commandVector[0] == "si" ) {
    siCommand(commandVector);
  } else if(commandVector[0] == "repeter"){
    repeterCommand(commandVector);
  } else if(commandVector[0] == "tantque") {
    tantqueCommand(commandVector);
  } else {
    behavioralCommand(commandVector);
  } 
}

// Cette fonction est pour lire un fichier.
void Modele::readFile(std::string in) {
  std::string line;
  std::ifstream ios(in);
  try{
    if (!ios.is_open()) {
      throw FichierError();
    }
    // lire la fichier ligne par ligne
    while (!ios.eof()) {
      getline(ios,line);
      set_command(line);
    }
    ios.close();
  }
  catch(const FichierError &error) {
      robot_list->setExp(error.what());
      notifyObservers(robot_list);
  }
}

// Cette fonction est pour créer un fichier que nous écrivons et pour
// marcher ce fichier.
void Modele::runFile(std::string text) {
  std::string out = "out.txt";
  std::ofstream oos(out);
  try{
    if (!oos.is_open()) {
      throw FichierError();
    }
    // écrire tous les 
    for (std::string::iterator it = text.begin() ; it != text.end() ; it++)
      oos.put(*it);
    oos.close();
    readFile(out);
  }
  
  catch(const FichierError &error) {
      robot_list->setExp(error.what());
      notifyObservers(robot_list);
  }

}
 
// Cette fonction est pour fonctionner la fonction d'analyser et pour
// empiler la pile
void Modele::set_command(std::string command) {
  bool flag = false;
  if(command!="") {
    robot_list->setExp("✔️Execution successed.");
    analyseCommand(command);
    try{
      while(abs(robot_list->sommet().getX()) > WIDTH/2
	    || abs(robot_list->sommet().getY()) > HEIGHT/2) {
	robot_list->depiler();
	flag = true;
      }
      if (flag)
	throw CrossBorder();
    }
    catch(const CrossBorder &error) {
      robot_list->setExp(error.what());
    }
    notifyObservers(robot_list);
  }
}
