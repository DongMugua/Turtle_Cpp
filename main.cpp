/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/


#include <gtkmm.h>

#include "Vue.hpp"
#include "Vue2.hpp"
#include "Modele.hpp"
#include "Controleur.hpp"


int main(int argc,char*argv[])
{
  auto app = Gtk::Application::create(argc,argv);
  Modele *m = new Modele();
  Vue *vg = new Vue();
  Vue2 *vt = new Vue2();
  
  Controleur *c = new Controleur(m,vg);

  m->addObserver(vg);
  m->addObserver(vt);
  
  return app->run(*vg);
}
