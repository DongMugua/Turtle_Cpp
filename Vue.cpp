/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/
#include "Vue.hpp"
#include "Controleur.hpp"
#include "Robot.hpp"
#include "gtkmm.h"
#define PI 3.1415926535

Vue::Vue():
  box1(Gtk::ORIENTATION_HORIZONTAL),
  box2(Gtk::ORIENTATION_VERTICAL),
  lText("📌️ Current state: (0.0 0.0)     Line width: 1.0     Angle: 90.0     RGB: [0.0 0.0 0.0]     Stylo laisser"),
  lAffiche("😁️Please enter the command..."),
  bExit("Exit"),
  bOK("OK"),
  bDiaOK("   OK   "),
  bDiaCancel("Cancel"),
  bDiaRun("Run"),
  dia("Please entry file name...",*this)
{
  set_title("Drawing Robot");
  set_size_request(WIDTH,HEIGHT);

  entry.property_can_default()=true;
  box1.pack_start(entry);
  box1.pack_start(bOK);
  box1.pack_start(bExit);
  myArea.set_size_request(WIDTH,HEIGHT);

  box2.pack_start(*myMenu.menuBar,0,0);
  lText.set_alignment(0.5,0.5);
  box2.pack_start(lText);
  box2.pack_start(myArea);
  box2.pack_start(box1);
  lAffiche.set_alignment(0,0.5);
  box2.pack_start(lAffiche);
  add(box2);
  show_all_children();
  myMenu.a_1.signal_activate().connect(sigc::mem_fun(this, &Vue::menu_a1_message));
  myMenu.d_1.signal_activate().connect(sigc::mem_fun(this, &Vue::menu_d1_message));
  myMenu.a_3.signal_activate().connect(sigc::mem_fun(this, &Vue::menu_a3_message));
  myMenu.b_3.signal_activate().connect(sigc::mem_fun(this, &Vue::menu_b3_message));
  bDiaCancel.signal_clicked() .connect(sigc::mem_fun(this, &Vue::on_button_diaClose));
}

void Vue::on_button_close() { hide(); }

void Vue::on_button_diaClose() {dia.hide();}

std::string Vue::getCommand() const {
  Glib::ustring text = entry.get_text();
  return text.c_str();
}

std::string Vue::getDialogCommand() {
  Glib::ustring text = entryDia.get_text();
  dia.hide();
  return text.c_str();
}

std::string Vue::getDialogText() {
  Glib::ustring text = buffer->get_text(true);
  return text.c_str();
}

void Vue::changeText(PileL *info){
  Robot x = info->sommet();
  Glib::ustring px = Glib::ustring::format(std::fixed, std::setprecision(1), x.getX());
  Glib::ustring py = Glib::ustring::format(std::fixed, std::setprecision(1), x.getY());
  Glib::ustring lw = Glib::ustring::format(std::fixed, std::setprecision(1), x.getLineWidth());
  Glib::ustring R = Glib::ustring::format(std::fixed, std::setprecision(1), x.getColor_R());
  Glib::ustring G = Glib::ustring::format(std::fixed, std::setprecision(1), x.getColor_G());
  Glib::ustring B = Glib::ustring::format(std::fixed, std::setprecision(1), x.getColor_B());
  Glib::ustring a = Glib::ustring::format(std::fixed, std::setprecision(1), x.getAngle()*180/PI);

  lText.set_text("📌️ Current state:   ("+px+" "+py+")"
		 +"     Line width: "+lw
		 +"     Angle: "+a
		 +"     RGB: ["+R+" "+G+" "+B+"]"
		 +(x.getStyloStatus() ? "     Stylo laisser": "     Stylo lever"));
  
  entry.set_text("");
  entryDia.set_text("");
  lAffiche.set_text(info->getExp());
}

void Vue::update (PileL *info) {
  myArea.update(info);
  myArea.queue_draw();
  changeText(info);
}

void Vue::addExitListener(Controleur *c) {
  bExit.signal_clicked().connect(sigc::mem_fun(*c, &Controleur::on_button_exit));
  myMenu.c_1.signal_activate().connect(sigc::mem_fun(*c, &Controleur::on_button_exit));
}

void Vue::addCommandListener(Controleur *c) {
  bOK.signal_clicked().connect(sigc::mem_fun(*c, &Controleur::on_button_command));
}

void Vue::menu_a1_message() {
  Gtk::Dialog dia("Please write a text :", this);
  dia.remove();
  Gtk::Box *box_ = dia.get_vbox();
  box_->set_orientation(Gtk::ORIENTATION_VERTICAL);
  Gtk::TextView view;
  view.set_size_request(300,500);
  box_->pack_start(view);
  box_->pack_start(bDiaRun);
  buffer = view.get_buffer();
  dia.add(*box_);
  dia.show_all_children();
  dia.run();
  
}

void Vue::menu_b11_Listener(Controleur *c){
  myMenu.b_1_1.signal_activate().connect(sigc::mem_fun(*c,&Controleur::on_read_file1));
}

void Vue::menu_b12_Listener(Controleur *c){
  myMenu.b_1_2.signal_activate().connect(sigc::mem_fun(*c,&Controleur::on_read_file2));
}

void Vue::menu_b13_Listener(Controleur *c){
  myMenu.b_1_3.signal_activate().connect(sigc::mem_fun(*c,&Controleur::on_read_file3));
}

void Vue::menu_a2_Listener(Controleur *c){
  myMenu.a_2.signal_activate().connect(sigc::mem_fun(*c,&Controleur::on_menu_undo));
}

void Vue::menu_b2_Listener(Controleur *c){
  myMenu.b_2.signal_activate().connect(sigc::mem_fun(*c,&Controleur::on_menu_clear));
}

void Vue::menu_a3_message() {
  Gtk::MessageDialog dialog(*this, "Command Guide",false , Gtk::MESSAGE_QUESTION);
  dialog.set_secondary_text("COMMAND....");
  dialog.set_size_request(WIDTH,HEIGHT);
  dialog.run();
}

void Vue::menu_b3_message(){
  Gtk::MessageDialog dialog(*this, "Programmable robot", false , Gtk::MESSAGE_QUESTION);
  dialog.set_secondary_text(" Programmable.....");
  dialog.run();
}

void Vue::menu_d1_message() {
  Gtk::Box *box_ = dia.get_content_area();
  dia.remove();
  box_->set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  box_->pack_start(entryDia);
  box_->pack_start(bDiaOK);
  box_->pack_start(bDiaCancel);
  dia.add(*box_);
  dia.show_all_children();
  dia.run();
}

void Vue::readFileListener(Controleur *c) {
  bDiaOK.signal_clicked().connect(sigc::mem_fun(*c, &Controleur::on_read_file));
}
void Vue::runFileListener(Controleur *c) {
  bDiaRun.signal_clicked().connect(sigc::mem_fun(*c, &Controleur::on_run_file));
}

Vue::~Vue(){}
