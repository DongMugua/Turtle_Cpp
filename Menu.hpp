/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/


#pragma once

#include <gtkmm/menu.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/separatormenuitem.h>
#include <gtkmm/menubar.h>
#include <gdkmm/rgba.h>

class MyMenu:public Gtk::Window{
  
public:
  
  Gtk::MenuBar *menuBar=new Gtk::MenuBar;
  Gtk::MenuItem menuItem_1,menuItem_2,menuItem_3,menuItem_4;
  Gtk::Menu subMenu_1,subMenu_2,subMenu_3,subMenu_1_b;
  Gtk::MenuItem a_1,b_1,c_1,d_1,
                b_1_1,b_1_2,b_1_3,
                a_2,b_2,
                a_3,b_3;
  Gtk::SeparatorMenuItem separeLine1,separeLine2,separeLine3,separeLine4,
                         separeLine5,separeLine6,separeLine7,separeLine8;
  //  Gdk::RGBA *c = new Gdk::RGBA();
  
  MyMenu(){
    // c->set_red(256);
    //  c->set_green(256);
    //  c->set_blue(256);
    //  separeLine1.override_color(*c);
    
    menuItem_1.set_label("File");
    menuItem_2.set_label("Edit");
    menuItem_3.set_label("Help");
    
    menuBar->append(menuItem_1);
    menuBar->append(menuItem_2);
    menuBar->append(menuItem_3);

    menuItem_1.set_submenu(subMenu_1);
    menuItem_2.set_submenu(subMenu_2);
    menuItem_3.set_submenu(subMenu_3);
    
    a_1.set_label("New File...");
    d_1.set_label("Open File...");
    b_1.set_label("Open Existe File...");
    c_1.set_label("Exit");
    
    subMenu_1.append(a_1);
    subMenu_1.append(separeLine1);
    subMenu_1.append(d_1);
    subMenu_1.append(separeLine5);
    subMenu_1.append(b_1);
    subMenu_1.append(separeLine2);
    subMenu_1.append(c_1);

    b_1_1.set_label("File_1");
    b_1_2.set_label("File_1");
    b_1_3.set_label("File_1");   
    b_1.set_submenu(subMenu_1_b);
    
    subMenu_1_b.append(b_1_1);
    subMenu_1_b.append(separeLine6);
    subMenu_1_b.append(b_1_2);
    subMenu_1_b.append(separeLine7);
    subMenu_1_b.append(b_1_3);
    subMenu_1_b.append(separeLine8);
    
    a_2.set_label("Undo");
    b_2.set_label("Clear");  
    subMenu_2.append(a_2);
    subMenu_2.append(separeLine3);
    subMenu_2.append(b_2);

    a_3.set_label("About the command");
    b_3.set_label("About the programmable robot");  
    subMenu_3.append(a_3);
    subMenu_3.append(separeLine4);
    subMenu_3.append(b_3);
  }
};
