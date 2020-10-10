/*
* Numerically controlled oscillator
*
*/
#ifndef NCO_H_
#define NCO_H_

#include <stdint.h>
#include <math.h>

#define PHASE_ACC_WIDTH 8
#define LUT_LENGTH 1024
#define BIT_DEPTH 16

typedef enum
{
	WF_SINE = 0,
	WF_SQUARE,
	WF_TRIANGLE,
	WF_SAW,
	WF_REV_SAW
}Waveform;

typedef struct
{
	int lut[LUT_LENGTH];
	uint16_t phase_accum;
	uint16_t delta_phase;
	int clock_freq;
}NCO;

void NCO_init(NCO *nco, int clock_freq);
//void NCO_init(NCO *nco, int clock_freq, Waveform wf);
int  NCO_next_signal(NCO *nco);
void NCO_set_freq(NCO *nco, float freq);

//#ifndef AUDIO_CLOCK
//#define AUDIO_CLOCK (uint16_t)40000
//#endif
//
//#define LUT_LENGTH 250
//
//typedef enum
//{
//	WF_SINE = 0,
//	WF_SQUARE,
//	WF_TRIANGLE,
//	WF_SAW,
//	WF_REV_SAW
//}Wave;
//
//typedef struct
//{
//	uint32_t lut[LUT_LENGTH];
//	int  phase;
//	int  delta_phase;
//	int    clk_freq;
//}NCO;
//
//void   NCO_init(NCO *nco, Wave wave, int clk_freq);
//void   NCO_set_waveform(NCO *nco, Wave wave);
//int8_t NCO_next_signal(NCO *nco);
//void   NCO_set_frequency(NCO *nco, float freq);

#endif /* NCO_H_ */

