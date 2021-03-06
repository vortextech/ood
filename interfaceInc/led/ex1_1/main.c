/*
 * 	main.c
 */

#include <stdio.h>
#include "X10Led.h"
#include "AcmeWirelessLed.h"

static X10Led x10Led;
static AcmeWirelessLed acmeWirelessLed;

void
main(void)
{
    LedDriver *ledA, *ledB;

    X10Led_init(&x10Led, X10_A, 8);
    AcmeWirelessLed_init(&acmeWirelessLed, "Home", "123abc", 4);

    ledA = &x10Led.base;
    ledB = &acmeWirelessLed.base;

	LedDriver_turnOn(ledA);
	LedDriver_turnOff(ledA);

	LedDriver_turnOn(ledB);
	LedDriver_turnOff(ledB);

    ledA = &acmeWirelessLed.base;
	LedDriver_turnOn(ledA);
	LedDriver_turnOff(ledA);

    getchar();
}
