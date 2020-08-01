#ifndef __DCSBIOS_SHIFT_REGISTER_READER_H
#define __DCSBIOS_SHIFT_REGISTER_READER_H

#include "Arduino.h"


namespace DcsBios {

    class ShiftRegisterReader {
    private {
            static unsigned long SHIFT_REGISTER_VALUE = 0ul;
        }
    public {
            void static readShiftRegister(int latchPin, int clockPin, int PatchPin, int count);
            int static readBit(int digit);
        }
    };

    void ShiftRegisterReader::readShiftRegister(int latchPin, int clockPin, int PatchPin, int count) {
        ShiftRegisterReader = 0;
    }

    int ShiftRegisterReader::readBit(int digit) { //0 ~ (8 * n) - 1
        return bitRead(SHIFT_REGISTER_VALUE, digit);
    }
}


#endif