#include "percepteur.h"

Percepteur *g_percepteur_droit;
Percepteur *g_percepteur_gauche;

Percepteur::Percepteur(char i, char pin_haut_, char pin_bas_, char cote) {
  this->id = i;
  this->cote = cote;
  this->pwm = 0;
  this->sens = FORWARD;
  this->moteur = new AF_DCMotor(i+1, MOTOR12_64KHZ);
  this->moteur->setSpeed(0);
  this->moteur->run(FORWARD);
  this->id_ordre = 0;
  this->etat_switchs = 4;
  
  pinMode(pin_haut_, INPUT);
  pinMode(pin_bas_, INPUT);
  digitalWrite(pin_haut_, HIGH);
  digitalWrite(pin_bas_, HIGH);

  this->pin_haut = pin_haut_;
  this->pin_bas = pin_bas_;
}

int Percepteur::set_pwm(int _ordre, int _pwm) {
  this->id_ordre = _ordre;

  if (_pwm == 0) this->etat_moteur = 0;

  this->pwm = abs(min(255,_pwm));
  if (_pwm < 0) {
    this->sens = BACKWARD;
    if (this->etat_switchs != 0) {
      this->etat_moteur = 2;
      sendMessage(_ordre, "B", this->etat_moteur);
    }
    else
      return 0;
  }
  else if (_pwm > 0) {
    this->sens = FORWARD;
    if (this->etat_switchs != 2) {
      this->etat_moteur = 1;
      sendMessage(_ordre, "F", this->etat_moteur);
    }
    else
      return 0;
  }

  this->moteur->setSpeed(this->pwm);
  this->moteur->run(this->sens);

  return 1;
}

void Percepteur::change_haut(char etat) {
  char envoi[4] = {this->cote, 'e', 'e','\0'};
  if (etat) { //switch on
    if (this->etat_switchs != 2) {
      this->etat_switchs = 2;
      envoi[1] = 'H';
      envoi[2] = 'H';
      sendMessage(this->id_ordre, envoi, this->etat_moteur);

      if (this->etat_moteur == 1)
        this->set_pwm(this->id_ordre, 0);
    }
  } else {
    envoi[1] = 'R';
    envoi[2] = 'H';
    sendMessage(this->id_ordre, envoi);
    this->etat_switchs = 4;
  }
}

void Percepteur::change_bas(char etat) {
  char envoi[4] = {this->cote, 'e', 'e','\0'};
  if (etat) { // switch on
    if (this->etat_switchs != 0) {
      this->etat_switchs = 0;
      envoi[1] = 'H';
      envoi[2] = 'B';
      sendMessage(this->id_ordre, envoi, this->etat_moteur);
      if (this->etat_moteur == 2)
        this->set_pwm(this->id_ordre, 0);
    }
  } else {
    envoi[1] = 'R';
    envoi[2] = 'B';
    sendMessage(this->id_ordre, envoi);
    this->etat_switchs = 4;
  }
}

void fdcDroitHaut() {
  g_percepteur_droit->change_haut(!digitalRead(DROIT_HAUT));
}

void fdcDroitBas() {
  g_percepteur_droit->change_bas(!digitalRead(DROIT_BAS));
}

void fdcGaucheHaut() {
  g_percepteur_gauche->change_haut(!digitalRead(GAUCHE_HAUT));
}

void fdcGaucheBas() {
  g_percepteur_gauche->change_bas(!digitalRead(GAUCHE_BAS));
}


/*
  Significations des lettres
  H : le moteur vient d'enclencher l'interrupteur (Hit)
  R : le moteur est parti de l'interrupteur (Release)

  H : Haut
  B : Bas
*/
