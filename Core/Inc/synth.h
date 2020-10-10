/*
* Numerically controlled oscillator
*
*/
#ifndef SYNTH_H_
#define SYNTH_H_

#include <math.h>

void note_on(float freq);
float midi_to_freq(int note)
{
	return (440.0 / 32.0) * pow(2, ((note - 9.0) / 12.0));
}


#endif
