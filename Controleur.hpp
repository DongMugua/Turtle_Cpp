#pragma once
#include "Vue.hpp"
#include "Modele.hpp"

class Controleur {
private:
  Vue *v = new Vue;
  Modele * m = new Modele;

public:
  Controleur(Modele *mm, Vue *vv) : m(mm), v(vv) {
    v->addExitListener(this);
    v->addCommandListener(this);
    v->menu_a2_Listener(this);
    v->menu_b2_Listener(this);
    v->menu_b11_Listener(this);
    v->menu_b12_Listener(this);
    v->menu_b13_Listener(this);
    v->readFileListener(this);
    v->runFileListener(this);
  }

  void on_button_exit() {
    v->on_button_close();
    delete m;
    delete v;
  }

  void on_button_command() {
    m->set_command(v->getCommand());
  }

  void on_menu_undo(){
    m->set_command("undo");
  }

  void on_menu_clear(){
    m->set_command("clear");
  }

  void on_read_file() {
    m->readFile(v->getDialogCommand());
  }

  void on_read_file1() {
    m->readFile("text");
  }
  
  void on_read_file2() {
    m->readFile("text2");
  }
  
  void on_read_file3() {
    m->readFile("text3");
  }
  void on_run_file() {
    m->runFile(v->getDialogText());
  }  
};
