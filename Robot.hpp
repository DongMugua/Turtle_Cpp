/**
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*/


#pragma once 
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>

#define PI 3.1415926535

class Robot{ 
private: 
  double x; 
  double y;
  double line_width;
  bool styloStatus;
  bool robotStatus;
  double angle;
  double color_R;
  double color_G;
  double color_B;
public:

  Robot(double x_=0, double y_=0,bool premierPoint = false):
    x(x_), y(y_) {
    if (premierPoint==true) {
      this->x=0;
      this->y=0;
      this->styloStatus=true;
      this->line_width=1;
      this->angle=PI/2;
      this->color_R=0;
      this->color_G=0;
      this->color_B=0;
      this->robotStatus=true;
    }
  }
  
  Robot (const Robot &r,bool t){
    if(t){
      this->x=r.x;
      this->y=r.y;
      this->line_width=r.line_width;
      this->styloStatus=r.styloStatus;
      this->angle=r.angle;
      this->color_R=r.color_R;
      this->color_G=r.color_G;
      this->color_B=r.color_B;
      this->robotStatus=r.robotStatus;
    }
  }
    
  
  double getX() { return this->x; } 
  void setX(double x_) { this->x = x_; } 
  double getY() { return this->y; } 
  void setY(double y_) { this->y = y_; } 
  void setColor(double r, double g, double b) {
    this->color_R=r;
    this->color_G=g;
    this->color_B=b;
  }
  
  bool getStyloStatus() { return this->styloStatus; } 
  void setStyloStatus(bool styloStatus_) { this->styloStatus = styloStatus_;}
  void setLineWidth (double l) { this->line_width = l; }
  double getLineWidth () {return this->line_width;}
  void setAngle(double a) {
    while(a>=360 || a<0) {
      if (a>=360) 
	a-=360;
      else if (a<0)
	a+=360;
    }
    this->angle = PI*a/180;}
  double getAngle() {return angle;}
  double getColor_R() {return color_R;}
  double getColor_G() {return color_G;}
  double getColor_B() {return color_B;}
  void setRobotStatus(bool s) {this->robotStatus = s;}
  bool getRobotStatus() {return this->robotStatus;}
  
  friend std::ostream & operator<<(std::ostream &f,Robot &r) {
    f<<"Current_state: ("<<r.x<<" "<<r.y<<")"<<" Line width: "<<r.line_width<<" Angle: "
     <<r.angle*180/PI<<" RGB: ["<<r.color_R<<" "<<r.color_G<<" "<<r.color_B<<"]"
     <<(r.styloStatus ? " Stylo laisser": " Stylo lever")<<std::endl;
    return f;
  }
  ~Robot() {}
}; 
