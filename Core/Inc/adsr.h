/*
 * adsr.h
 *
 *  Created on: Oct 10, 2020
 *      Author: Zac
 */

#ifndef INC_ADSR_H_
#define INC_ADSR_H_

#include <stdint.h>
#include <stdbool.h>

#define SAMPLE_FREQ 40000

typedef enum
{
	ENV_INIT = 0,
	ENV_ATTACK,
	ENV_DECAY,
	ENV_SUSTAIN,
	ENV_RELEASE
}ADSR_STATE;

typedef struct
{
	uint16_t   attack;
	uint16_t   decay;
	float      sustain;
	uint16_t   release;
	uint32_t   tick;
	float      amplitude;
	bool       note_on;
	ADSR_STATE state;
}ADSR;

void  ADSR_init        (ADSR *adsr, uint16_t a, uint16_t d, float s, uint16_t r);
void  ADSR_set_vals    (ADSR *adsr, uint16_t a, uint16_t d, float s, uint16_t r);
void  ADSR_set_attack  (ADSR *adsr, uint16_t a);
void  ADSR_set_decay   (ADSR *adsr, uint16_t d);
void  ADSR_set_sustain (ADSR *adsr, float s);
void  ADSR_set_release (ADSR *adsr, uint16_t r);
void  ADSR_note_on     (ADSR *adsr);
void  ADSR_note_off    (ADSR *adsr);
float ADSR_get_next    (ADSR *adsr);

#endif /* INC_ADSR_H_ */
