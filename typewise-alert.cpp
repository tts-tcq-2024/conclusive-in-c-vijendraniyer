#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
    if (value < lowerLimit) {
        return TOO_LOW;
    }
    if (value > upperLimit) {
        return TOO_HIGH;
    }
    return NORMAL;
}

// Helper function to define lower limit based on cooling type
int getPassiveCoolingLowerLimit() {
    return 0;
}

int getHiActiveCoolingLowerLimit() {
    return 0;
}

int getMedActiveCoolingLowerLimit() {
    return 0;
}

int getLowerLimit(CoolingType coolingType) {
    switch (coolingType) {
        case PASSIVE_COOLING: return getPassiveCoolingLowerLimit();
        case HI_ACTIVE_COOLING: return getHiActiveCoolingLowerLimit();
        case MED_ACTIVE_COOLING: return getMedActiveCoolingLowerLimit();
        default: return -1; // Error case, should not occur
    }
}

// Helper function to define upper limit based on cooling type
int getPassiveCoolingUpperLimit() {
    return 35;
}

int getHiActiveCoolingUpperLimit() {
    return 45;
}

int getMedActiveCoolingUpperLimit() {
    return 40;
}

int getUpperLimit(CoolingType coolingType) {
    switch (coolingType) {
        case PASSIVE_COOLING: return getPassiveCoolingUpperLimit();
        case HI_ACTIVE_COOLING: return getHiActiveCoolingUpperLimit();
        case MED_ACTIVE_COOLING: return getMedActiveCoolingUpperLimit();
        default: return -1; // Error case, should not occur
    }
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
    int lowerLimit = getLowerLimit(coolingType);
    int upperLimit = getUpperLimit(coolingType);
    return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
    switch (alertTarget) {
        case TO_CONTROLLER:
            sendToController(breachType);
            break;
        case TO_EMAIL:
            sendToEmail(breachType);
            break;
    }
}

void sendToController(BreachType breachType) {
    const unsigned short header = 0xfeed;
    printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
    const char* recipient = "a.b@c.com";
    if (breachType == TOO_LOW) {
        printf("To: %s\n", recipient);
        printf("Hi, the temperature is too low\n");
    } else if (breachType == TOO_HIGH) {
        printf("To: %s\n", recipient);
        printf("Hi, the temperature is too high\n");
    }
}
