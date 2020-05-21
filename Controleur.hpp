/*
* This file is part of Turtle.
*
* Copyright (C) 2018 SUN Hao, WU Mengxin, LIU Bohua Université Polythec Nice Sophia 
*
* Définition d'une class Controleur qui assure la connexion entre 
* la partie Modele et la partie Vue et enregistre les gestionnaires 
* d’événements qui traitent les événements émis par l’utilisateur.
*
*/

#pragma once
#include "Vue.hpp"
#include "Modele.hpp"

class Controleur {
private:
  Vue *v = new Vue;
  Modele * m = new Modele;

public:
  // constructeur
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
  
/* 
 * Rôle: Gérer l'événement de quitter le programme
 */
  void on_button_exit() {
    v->on_button_close();
    delete m;
    delete v;
  }
/* 
 * Rôle: Gérer l'événement d'exécuter une commande
 */
  void on_button_command() {
    m->set_command(v->getCommand());
  }
/* 
 * Rôle: Gérer l'événement d'annuler l'opération
 */
  void on_menu_undo(){
    m->set_command("undo");
  }
/* 
 * Rôle: Gérer l'événement de nettoyer d'interface graphique
 */
  void on_menu_clear(){
    m->set_command("clear");
  }
/* 
 * Rôle: Gérer l'événement de lire un fichier
 */
  void on_read_file() {
    m->readFile(v->getDialogCommand());
  }
/* 
 * Rôle: Gérer l'événement de lire file1
 */
  void on_read_file1() {
    m->readFile("Exemple1.txt");
  }
/* 
 * Rôle: Gérer l'événement de lire file2
 */ 
  void on_read_file2() {
    m->readFile("Exemple2.txt");
  }
/* 
 * Rôle: Gérer l'événement de lire file3
 */
  void on_read_file3() {
    m->readFile("Exemple3.txt");
  }
/* 
 * Rôle: Gérer l'événement d'exécuter un fichier
 */
   void on_run_file() {
    m->runFile(v->getDialogText());
  }  
};
