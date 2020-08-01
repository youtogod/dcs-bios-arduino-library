#ifndef __DCSBIOS_SHIFT_REGISTER_SWITCHES_H
#define __DCSBIOS_SHIFT_REGISTER_SWITCHES_H

#include "Arduino.h"
#include "ShiftRegisterReader.h"

namespace DcsBios {

    class Switch2Pos : PollingInput {
    private:
        const char *msg_;
        int digit_;
        int lastState_;
        bool reverse_;

        void init_(const char *msg, int digit, bool reverse) {
            msg_ = msg;
            digit_ = digit;
            lastState_ = ShiftRegisterReader::readBit(digit_);
            reverse_ = reverse;
        }

        void pollInput() {
            int state = ShiftRegisterReader::readBit(digit_);
            if (reverse_) state = !state;
            if (state != lastState_) {
                if (tryToSendDcsBiosMessage(msg_, state == 1 ? "0" : "1")) {
                    lastState_ = state;
                }
            }
        }

    public:
        Switch2Pos(const char *msg, int digit, bool reverse) { init_(msg, digit, reverse); }

        Switch2Pos(const char *msg, int digit) { init_(msg, digit, false); }
    };

}

#endif