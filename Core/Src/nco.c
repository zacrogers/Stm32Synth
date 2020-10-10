/*
 * nco.c
 *
 *  Created on: Aug 3, 2020
 *      Author: Zac
 */
#include "nco.h"

void NCO_init(NCO *nco, int clock_freq)
{
	nco->phase_accum = 0;
	nco->delta_phase = 0;
	nco->clock_freq = clock_freq;

	for(int i = 0; i < LUT_LENGTH; ++i)
	{
		nco->lut[i] = ((sin(i*2*M_PI/LUT_LENGTH) + 1)*(4096/2));
	}

//	for(int n = 0; n < LUT_LENGTH; ++n)
//	{
//		if(n < (LUT_LENGTH / 2))
//		{
//			nco->lut[n] = 4096;
//		}
//		else
//		{
//			nco->lut[n] = 0;
//		}
//	}
}


//void NCO_init(NCO *nco, int clock_freq, Waveform wf)
//{
//	nco->phase_accum = 0;
//	nco->delta_phase = 0;
//	nco->clock_freq = clock_freq;
//
//	switch(wf)
//	{
//		case WF_SINE:
//			for(int i = 0; i < LUT_LENGTH; ++i)
//			{
//				nco->lut[i] = ((sin(i*2*M_PI/LUT_LENGTH) + 1)*(4096/2));
//			}
//			break;
//
//		case WF_SQUARE:
//			for(int n = 0; n < LUT_LENGTH; ++n)
//			{
//				if(n < (LUT_LENGTH / 2))
//				{
//					nco->lut[n] = 255;
//				}
//				else
//				{
//					nco->lut[n] = 0;
//				}
//			}
//			break;
//
//		case WF_TRIANGLE:
//			for(int n = 0; n < LUT_LENGTH/2; ++n)
//			{
//				nco->lut[n] = n * 2;
//			}
//			for(int n = LUT_LENGTH/2; n > 0; --n)
//			{
//				nco->lut[n] = n * 2;
//			}
//			break;
//
//		case WF_SAW:
//			for(int n = 0; n < LUT_LENGTH; ++n)
//			{
//				nco->lut[n] = n;
//			}
//			break;
//
//		case WF_REV_SAW:
//			for(int n = LUT_LENGTH; n > 0; --n)
//			{
//				nco->lut[n] = n;
//			}
//			break;
//	}
//}

int NCO_next_signal(NCO *nco)
{
	nco->phase_accum += nco->delta_phase;
	return nco->lut[(uint16_t)(nco->phase_accum>>6)];
}

void NCO_set_freq(NCO *nco, float freq)
{
	float phase_word = freq * ((float)65536/(float)nco->clock_freq);
//	float phase_word = (float)freq / (float)65536/(float)nco->clock_freq;
//	nco->delta_phase = 1;//(freq / (LUT_LENGTH / pow(2, PHASE_ACC_WIDTH)));
	nco->delta_phase = phase_word;//(uint16_t)phase_word;
}

//
//void NCO_init(NCO *nco, Wave wave, int clk_freq)
//{
//	nco->phase = 0.0;
//	nco->delta_phase = 0.0;
//	nco->clk_freq = clk_freq;
//
//	NCO_set_waveform(nco, wave);
//}
//
//
//void NCO_set_waveform(NCO *nco, Wave wave)
//{
//    switch(wave)
//    {
//        case WF_SINE:
//            for(int n = 0; n < LUT_LENGTH; ++n)
//            {
//            	nco->lut[n] = (4096/2) * (sin(2 * M_PI * n / LUT_LENGTH) + 1);
//            }
//            break;
//
//        case WF_SQUARE:
//            for(int n = 0; n < LUT_LENGTH; ++n)
//            {
//                if(n < (LUT_LENGTH / 2))
//                {
//                	nco->lut[n] = 255;
//                }
//                else
//                {
//                	nco->lut[n] = 0;
//                }
//            }
//            break;
//
//        case WF_TRIANGLE:
//            for(int n = 0; n < LUT_LENGTH/2; ++n)
//            {
//            	nco->lut[n] = n * 2;
//            }
//            for(int n = LUT_LENGTH/2; n > 0; --n)
//            {
//            	nco->lut[n] = n * 2;
//            }
//            break;
//
//        case WF_SAW:
//            for(int n = 0; n < LUT_LENGTH; ++n)
//            {
//            	nco->lut[n] = n;
//            }
//            break;
//
//        case WF_REV_SAW:
//            for(int n = LUT_LENGTH; n > 0; --n)
//            {
//            	nco->lut[n] = n;
//            }
//            break;
//    }
//}
//
//int8_t NCO_next_signal(NCO *nco)
//{
////    nco->phase += nco->delta_phase;
////	if(nco->delta_phase < LUT_LENGTH-1)
////	{
////		nco->phase ++;
////	}
////	else
////    	{
////    		nco->delta_phase = 0;
////    	}
//
////    while(nco->phase >= LUT_LENGTH)
////    {
////    	nco->phase -= LUT_LENGTH;
////    }
//    return nco->lut[nco->phase];
////    return nco->lut[(int) nco->phase];
//
//}
//
//void NCO_set_frequency(NCO *nco, float freq)
//{
//	nco->delta_phase = 1;
////	if(nco->delta_phase >= LUT_LENGTH)
////	{
////		nco->delta_phase = 0;
////	}
////	nco->delta_phase = (AUDIO_CLOCK / LUT_LENGTH) / freq;
////	nco->delta_phase = (freq / AUDIO_CLOCK) * 4294967295;
//}
