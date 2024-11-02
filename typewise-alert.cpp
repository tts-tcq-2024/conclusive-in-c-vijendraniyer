#include "typewise-alert.h"
#include <stdio.h>

// Lower and Upper limits based on cooling type
const double PASSIVE_LOWER = 0.0;
const double PASSIVE_UPPER = 35.0;
const double HI_ACTIVE_LOWER = 0.0;
const double HI_ACTIVE_UPPER = 45.0;
const double MED_ACTIVE_LOWER = 0.0;
const double MED_ACTIVE_UPPER = 40.0;

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
    if (value < lowerLimit) {
        return TOO_LOW;
    }
    if (value > upperLimit) {
        return TOO_HIGH;
    }
    return NORMAL;
}

double getLowerLimit(CoolingType coolingType) {
    switch (coolingType) {
        case PASSIVE_COOLING: return PASSIVE_LOWER;
        case HI_ACTIVE_COOLING: return HI_ACTIVE_LOWER;
        case MED_ACTIVE_COOLING: return MED_ACTIVE_LOWER;
    }
    return 0.0; // Default case, should never hit if coolingType is valid
}

double getUpperLimit(CoolingType coolingType) {
    switch (coolingType) {
        case PASSIVE_COOLING: return PASSIVE_UPPER;
        case HI_ACTIVE_COOLING: return HI_ACTIVE_UPPER;
        case MED_ACTIVE_COOLING: return MED_ACTIVE_UPPER;
    }
    return 0.0; // Default case, should never hit if coolingType is valid
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
    double lowerLimit = getLowerLimit(coolingType);
    double upperLimit = getUpperLimit(coolingType);
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
