/*
    The MIT License (MIT)
    Author: Hongtai Liu (lht856@foxmail.com)
    Copyright (C) 2020  Seeed Technology Co.,Ltd.
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/


#ifdef __IMXRT1062__
#ifndef __RS_RTC_TEENSY41_H__
#define __RS_RTC_TEENSY41_H__
#include "DateTime.h"


typedef void (*rtcCallBack)(uint32_t flag); 

// Default date & time after reset
#define DEFAULT_YEAR 2000 // 2000..2063
#define DEFAULT_MONTH 1   // 1..12
#define DEFAULT_DAY 1     // 1..31
#define DEFAULT_HOUR 0    // 1..23
#define DEFAULT_MINUTE 0  // 0..59
#define DEFAULT_SECOND 0  // 0..59

class Rs_RTC_Teensy41
{
public:
    

    boolean begin();
    void adjust(const DateTime &dt);
    DateTime now();
    
private:
    
};
#endif
#endif