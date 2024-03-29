#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include <inttypes.h>


typedef int32_t			TICKS;
typedef int32_t			TICKS_100; // centième de ticks
typedef int				MM;
typedef double			RAD;
typedef int				DEG;

#define DUREE_CYCLE		2

#define PIN_EN_LEFT 3 		// enable moteur 1 (pwm)
#define PIN_DIR_LEFT 12 	// direction moteur 1
#define PIN_EN_RIGHT 11 	// enable moteur 2 (pwm)
#define PIN_DIR_RIGHT 13 	// direction moteur 2
#define PIN_LEFT_A 18 		// A encodeur 1 (gauche) (vert-marron)
#define PIN_LEFT_B 19 		// B encodeur 1 (gauche) (vert-blanc)
#define PIN_RIGHT_A 21 		// A encodeur 2 (droite) (noir-blanc)
#define PIN_RIGHT_B 20 		// B encodeur 2 (droite) (noir-marron)
#define VALUE_PIN_LEFT_A 		bitRead(PIND,3)
#define VALUE_PIN_LEFT_B 		bitRead(PIND,2)
#define VALUE_PIN_RIGHT_B 		bitRead(PIND,1)
#define VALUE_PIN_RIGHT_A 		bitRead(PIND,0)
#define INTERRUPT_LEFT_A 5 
#define INTERRUPT_LEFT_B 4 
#define INTERRUPT_RIGHT_A 2 
#define INTERRUPT_RIGHT_B 3


/* Parametres mecanique du robot */
#define DIST_MOTOR_AXIS_TO_BACK_MM 122.0 // Distance entre le l'axe des moteurs et l'arriere du robot

//#define ENC_CENTER_DIST_MM 250.0 //261.0 // {mm} Distance entre chaque roue codeuse
extern double ENC_CENTER_DIST_MM;
#define ENC_CENTER_DIST_TICKS (ENC_CENTER_DIST_MM*ENC_MM_TO_TICKS) // {tick} Distance entre chaque roue codeuse du robot en ticks
//#define ENC_RESOLUTION 512 		// Nombre de points par tour d'encodeur
#define ENC_RESOLUTION 500 		// Nombre de points par tour d'encodeur
//#define ENC_RADIUS 30.0 		// {mm} Rayon de la roue codeuse
#define ENC_RADIUS 34.0 		// {mm} Rayon de la roue codeuse

#define ENC_TICKS_TO_MM (2*M_PI*ENC_RADIUS)/(ENC_RESOLUTION*4) //0.10681415022205297 //(2*M_PI*ENC_RADIUS)/(ENC_RESOLUTION*4) // {mm.tick^-1} (opti: a calculer apres) 
#define ENC_MM_TO_TICKS (ENC_RESOLUTION*4)/(2*M_PI*ENC_RADIUS) //9.362055475993843 //(ENC_RESOLUTION*4)/(2*M_PI*ENC_RADIUS) // {tick.mm^-1}

#endif


