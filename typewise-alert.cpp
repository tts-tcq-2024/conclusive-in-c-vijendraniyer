#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
    if(value < lowerLimit) {
        return TOO_LOW;
    }
    if(value > upperLimit) {
        return TOO_HIGH;
    }
    return NORMAL;
}

int getCoolingLimits(CoolingType coolingType, bool isLowerLimit) {
    switch(coolingType) {
        case PASSIVE_COOLING:
            return isLowerLimit ? 0 : 35;
        case HI_ACTIVE_COOLING:
            return isLowerLimit ? 0 : 45;
        case MED_ACTIVE_COOLING:
            return isLowerLimit ? 0 : 40;
        default:
            return 0; // or some sensible default
    }
}

int getLowerLimit(CoolingType coolingType) {
    return getCoolingLimits(coolingType, true);
}

int getUpperLimit(CoolingType coolingType) {
    return getCoolingLimits(coolingType, false);
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
    int lowerLimit = getLowerLimit(coolingType);
    int upperLimit = getUpperLimit(coolingType);
    return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void printEmailMessage(BreachType breachType) {
    const char* recipient = "a.b@c.com";
    switch(breachType) {
        case TOO_LOW:
            printf("To: %s\nHi, the temperature is too low\n", recipient);
            break;
        case TOO_HIGH:
            printf("To: %s\nHi, the temperature is too high\n", recipient);
            break;
        case NORMAL:
            break;
    }
}

void sendToEmail(BreachType breachType) {
    printEmailMessage(breachType);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
    switch(alertTarget) {
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
