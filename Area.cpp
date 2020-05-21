/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/



#include "Area.hpp"

MyArea::MyArea(){
  // grace a Singleton, the same thing
  rl = PileL::getInstance();
 }

MyArea::~MyArea(){}

void MyArea::update (PileL *info) {
  this->rl=info;
}
double MyArea::transX(const double x) {
  return (WIDTH/2)+x;
}
double MyArea::transY(const double y) {
  return (HEIGHT/2)-y;
}

void MyArea::drawRobot(const Cairo::RefPtr<Cairo::Context>& cr) { 
  // draw robot
  double x = transX(rl->sommet().getX());
  double y = transY(rl->sommet().getY());
  double angle = rl->sommet().getAngle();
  int  a = 20;
  
  cr->save();
  cr->set_source_rgb(rl->sommet().getColor_R(),rl->sommet().getColor_G(),rl->sommet().getColor_B()); 
  cr->move_to(x,y); 
  cr->line_to(x+(a/sqrt(3))*cos(angle),y-(a/sqrt(3))*sin(angle)); 
  cr->line_to(x-(a/sqrt(3))*cos(angle-60*PI/180),y+(a/sqrt(3))*sin(angle-60*PI/180)); 
  cr->line_to(x,y); 
  cr->line_to(x+(a/sqrt(3))*sin(angle-30*PI/180),y+(a/sqrt(3))*cos(angle-30*PI/180)); 
  cr->line_to(x+(a/sqrt(3))*cos(angle),y-(a/sqrt(3))*sin(angle));
  cr->stroke();
  
} 
void MyArea::axe(const Cairo::RefPtr<Cairo::Context>& cr) {
  cr->set_line_width(2.0);
  int xc=WIDTH/2;
  int yc=HEIGHT/2;
 // draw green linesout from the center of the window 
  cr->save(); 
  cr->set_source_rgb(0.7, 0.7, 0.7); 
  // Axe horizontal 
  cr->move_to(50, yc); 
  cr->line_to(WIDTH-WIDTH*5/60, yc); 
  // fleche 
  cr->line_to(WIDTH-WIDTH/10 , yc-HEIGHT/60); 
  cr->move_to(WIDTH-WIDTH*5/60, yc); 
  cr->line_to(WIDTH-WIDTH/10 , yc+HEIGHT/60); 
  // Axe des ordonnees 
  cr->move_to(xc, HEIGHT-HEIGHT*5/60); 
  cr->line_to(xc, HEIGHT*5/60); 
  cr->line_to(xc-WIDTH/60 , HEIGHT/10); 
  cr->move_to(xc, HEIGHT*5/60); 
  cr->line_to(xc+WIDTH/60 , HEIGHT/10); 
  cr->stroke();
}

void MyArea::drawLine(const Cairo::RefPtr<Cairo::Context>& cr) {
  cr->save();
  cr->move_to(transX(0),transY(0));
  
  for( auto r: rl->getList() ) {
    cr->set_source_rgb(r.getColor_R(),r.getColor_G(),r.getColor_B());
    cr->set_line_width(r.getLineWidth());
    if(r.getStyloStatus()) {
      cr->line_to( transX(r.getX()) , transY(r.getY()) );
    } 
    cr->stroke();
    cr->save();
    cr->move_to( transX(r.getX()) , transY(r.getY()) );
  }
  cr->stroke();

}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  //Gtk::Allocation allocation = get_allocation();
  const int width  = WIDTH;//allocation.get_width();
  const int height = HEIGHT;//allocation.get_height();
  // coordinates for the center of the window
  axe(cr);
  if(rl->sommet().getRobotStatus())
    drawRobot(cr);
  drawLine(cr);
  return true;
}
