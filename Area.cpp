/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/

#include "Area.hpp"

/* 
 * Rôle : Obetenir l'intance unique de la classe PileL
 * @ rl un pointeur de type PileL.
 */
MyArea::MyArea(){
  rl = PileL::getInstance();
 }
// destructeur
MyArea::~MyArea(){}

/*
 * Rôle: Mettre à jour les informations sur rl
 * @ info un pointeur de type PileL.
 */
void MyArea::update (PileL *info) {
  this->rl=info;
}
/*
 * Rôle: Transfert d'une abscisse cartésienne au pixel correspondant.
 */
double MyArea::transX(const double x) {
  return (WIDTH/2)+x;
}
/*
 * Rôle: Transfert d'une ordonné cartésienne au pixel correspondant.
 */
double MyArea::transY(const double y) {
  return (HEIGHT/2)-y;
}
/*
 * Rôle: Tracer un robot sur l'interface graphique. 
 * @ cr une référence de type Cairo::RefPtr<Cairo::Context>
 */
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
/*
 * Rôle : Tracer un axe sur l'interface graphique.
 * @ cr une référence de type Cairo::RefPtr<Cairo::Context>
 */
void MyArea::axe(const Cairo::RefPtr<Cairo::Context>& cr) {
  cr->set_line_width(2.0);
  int xc=WIDTH/2;
  int yc=HEIGHT/2;
 // tracer des lignes vertes à partir du centre de la fenêtre 
  cr->save(); 
  cr->set_source_rgb(0.7, 0.7, 0.7); 
  // une abscisse 
  cr->move_to(50, yc); 
  cr->line_to(WIDTH-WIDTH*5/60, yc); 
  // une flèche 
  cr->line_to(WIDTH-WIDTH/10 , yc-HEIGHT/60); 
  cr->move_to(WIDTH-WIDTH*5/60, yc); 
  cr->line_to(WIDTH-WIDTH/10 , yc+HEIGHT/60); 
  // une ordonnée 
  cr->move_to(xc, HEIGHT-HEIGHT*5/60); 
  cr->line_to(xc, HEIGHT*5/60); 
  cr->line_to(xc-WIDTH/60 , HEIGHT/10); 
  cr->move_to(xc, HEIGHT*5/60); 
  cr->line_to(xc+WIDTH/60 , HEIGHT/10); 
  cr->stroke();
}
/*
 * Rôle: Tracer la trajectoire du robot sur l'interface graphique.
 * @ cr une référence de type Cairo::RefPtr<Cairo::Context>
 */
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
/*
 * Rôle: Appeler les méthodes à tracer.
 * @ cr une référence de type Cairo::RefPtr<Cairo::Context>
 */
bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  //Gtk::Allocation allocation = get_allocation();
  const int width  = WIDTH;
  const int height = HEIGHT;
  axe(cr);
  if(rl->sommet().getRobotStatus())
    drawRobot(cr);
  drawLine(cr);
  return true;
}
