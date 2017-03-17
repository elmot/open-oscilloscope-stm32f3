#include "oscilloscope.h"
//
// Created by elmot on 17.3.2017.
//

static const unsigned const short SINE_WAVE[] = {
        16384,
        17812,
        19229,
        20624,
        21988,
        23308,
        24576,
        25781,
        26915,
        27969,
        28935,
        29805,
        30573,
        31233,
        31780,
        32210,
        32519,
        32706,
        32768,
        32706,
        32519,
        32210,
        31780,
        31233,
        30573,
        29805,
        28935,
        27969,
        26915,
        25781,
        24576,
        23308,
        21988,
        20624,
        19229,
        17812,
        16384,
        14956,
        13539,
        12144,
        10780,
        9460,
        8192,
        6987,
        5853,
        4799,
        3833,
        2963,
        2195,
        1535,
        988,
        558,
        249,
        62,
        0,
        62,
        249,
        558,
        988,
        1535,
        2195,
        2963,
        3833,
        4799,
        5853,
        6987,
        8192,
        9460,
        10780,
        12144,
        13539,
        14956
};

void genSineWave(uint16_t ampl, uint16_t pInt[72]) {
  for (int i = 0; i < GEN_DMA_LENGTH; i++) {
    pInt[i] = (uint16_t) (ampl * SINE_WAVE[i] / 32768);
  }

}
