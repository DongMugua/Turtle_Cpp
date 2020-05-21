#pragma once

#include <gtkmm.h>
#include <iostream>

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  void fill_buffers();

  //Signal handlers:
  void on_button_quit();
  void on_button_buffer1();
  void on_button_buffer2();

  //Child widgets:
  Gtk::Box m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TextView m_TextView;

  Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1, m_refTextBuffer2;

  Gtk::ButtonBox m_ButtonBox;
  Gtk::Button m_Button_Quit, m_Button_Buffer1, m_Button_Buffer2;
};

t
