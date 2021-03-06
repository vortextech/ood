/*
 *  X10Led.h
 */

#include <stdio.h>
#include "X10Led.h"

typedef struct X10Led X10Led;
struct X10Led
{
	LedDriver base;
    X10_HouseCode house;
    int unit;    
};

static X10Led x10LedObj;
LedDriver *x10Led = (LedDriver *)&x10LedObj;

static const char *houseCode[] =
{
    "X10_A", "X10_B", "X10_C", "X10_D", "X10_E", "X10_F",
    "X10_G", "X10_H", "X10_I", "X10_J", "X10_K", "X10_L",
    "X10_M", "X10_N", "X10_O", "X10_P"
};

static void
sendMessage(X10Led *me, const char *oper)
{
    LedDriver *base = (LedDriver *)me;
    printf("%s - driver=%s, type=%d, house=%s, unit=%d\r\n", oper, 
                                                     base->type, 
                                                     base->id,
                                                     houseCode[me->house],
                                                     me->unit);
}

static void 
turnOn(LedDriver *const me)
{
    X10Led *realMe = (X10Led *)me;

    sendMessage(realMe, "TurnOn");
}

static void 
turnOff(LedDriver *const me)
{
    X10Led *realMe = (X10Led *)me;

    sendMessage(realMe, "TurnOff");
}

void 
X10Led_init(X10_HouseCode house, int unit)
{
    static const LedDriverVtbl vtbl = {turnOn, turnOff};
    LedDriver *base = &x10LedObj.base;

    base->id = 0;
    base->type = "X10";
    base->offset = offsetof(X10Led, base);
    base->vptr = &vtbl;
    x10LedObj.house = house;
    x10LedObj.unit = unit;
}
