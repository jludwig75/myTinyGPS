/*
 * Arduino.h
 *
 *  Created on: Nov 28, 2018
 *      Author: jludwig
 */

#ifndef ARDUINO_H_
#define ARDUINO_H_


#include <stdlib.h>
#include <math.h>


#define	TWO_PI	(2 * M_PI)


typedef unsigned char byte;


extern "C" {

unsigned long millis();


float radians(float degrees);

float degrees(float radians);

float sq(float value);

}



#endif /* ARDUINO_H_ */
