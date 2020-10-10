/*
 * adsr.c
 *
 *  Created on: Oct 10, 2020
 *      Author: Zac
 */

#include "adsr.h"

void ADSR_init(ADSR *adsr, uint16_t a, uint16_t d, float s, uint16_t r)
{
	ADSR_set_vals(adsr, a, d, s, r);

	adsr->tick = 0;
	adsr->state = ENV_INIT;
}

void ADSR_set_vals(ADSR *adsr, uint16_t a, uint16_t d, float s, uint16_t r)
{
	adsr->attack = a;
	adsr->decay = d;
	adsr->sustain = s;
	adsr->release = r;
}

void  ADSR_set_attack(ADSR *adsr, uint16_t a){adsr->attack = a;}
void  ADSR_set_decay(ADSR *adsr, uint16_t d){adsr->decay = d;}
void  ADSR_set_sustain(ADSR *adsr, float s){adsr->sustain = s;}
void  ADSR_set_release(ADSR *adsr, uint16_t r){adsr->release = r;}

void  ADSR_note_on(ADSR *adsr)
{
	adsr->tick = 0;
	adsr->state = ENV_ATTACK;
}
void  ADSR_note_off(ADSR *adsr)
{
	adsr->tick = 0;
	adsr->state = ENV_RELEASE;
}

float ADSR_get_next(ADSR *adsr)
{
	adsr->amplitude = (adsr->tick/adsr->attack);

	if(adsr->tick < adsr->attack-1)
	{
//				adsr->amplitude += (adsr->tick/adsr->attack);
		adsr->tick++;
	}
	else
	{
//		adsr->amplitude = 1.0;
////				adsr->state = ENV_DECAY;
//		adsr->state = ENV_SUSTAIN;
		adsr->tick = 0;
	}
//	switch(adsr->state)
//	{
//		case ENV_INIT:
//		{
//			adsr->amplitude = 0.0;
//			break;
//		}
//
//		case ENV_ATTACK:
//		{
//			adsr->amplitude = (adsr->tick/adsr->attack);
//
//			if(adsr->tick < adsr->attack)
//			{
////				adsr->amplitude += (adsr->tick/adsr->attack);
//				adsr->tick++;
//			}
//			else
//			{
//				adsr->amplitude = 1.0;
////				adsr->state = ENV_DECAY;
//				adsr->state = ENV_SUSTAIN;
//				adsr->tick = 0;
//			}
////			adsr->tick++;
//
//			break;
//		}
//
//		case ENV_DECAY:
//		{
//			break;
//		}
//
//		case ENV_SUSTAIN:
//		{
//			adsr->amplitude = 1.0;
//			break;
//		}
//
//		case ENV_RELEASE:
//		{
//			break;
//		}
//	}

	return adsr->amplitude;
}
