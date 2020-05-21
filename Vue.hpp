#pragma once

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/textview.h>
#include <gtkmm/textbuffer.h>
#include <gtkmm/dialog.h>

#include "Area.hpp"
#include "Observer.hpp"
#include "PileL.hpp"
#include "Menu.hpp"

class Controleur;

class Vue : public Gtk::Window, public Observer<PileL>{
private:
  Gtk::Window win;
  Gtk::Box box1,box2;
  Gtk::Entry entry,entryDia;
  Gtk::Button bExit,bOK,bDiaOK,bDiaCancel,bDiaRun;
  Gtk::Label lText,lAffiche;
  Gtk::Dialog dia;
  Glib::RefPtr<Gtk::TextBuffer> buffer;
  MyArea myArea;
  MyMenu myMenu;

  
public:
  Vue();
  virtual ~Vue();
  void update(PileL *info) override;
  std::string getCommand() const;
  std::string getDialogCommand();
  std::string getDialogText();
  void addExitListener(Controleur *c);
  void addCommandListener(Controleur *c);
  void on_button_close();
  void on_button_diaClose();
  void changeText(PileL*info);
  void on_button_file();
  void menu_a1_message();
  void menu_d1_message();
  void menu_a2_Listener(Controleur *c);
  void menu_b2_Listener(Controleur *c);
  void menu_b11_Listener(Controleur *c);
  void menu_b12_Listener(Controleur *c);
  void menu_b13_Listener(Controleur *c);
  void menu_a3_message();
  void menu_b3_message();
  void readFileListener(Controleur *c);
  void runFileListener(Controleur *c);
};
