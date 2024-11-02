#include "typewise-alert.h"
#include <iostream>
#include <stdexcept>

// Define limits for different cooling types
double getPassiveCoolingLowerLimit() {
    return 0; // Passive cooling lower limit
}

double getPassiveCoolingUpperLimit() {
    return 35; // Passive cooling upper limit
}

double getHiActiveCoolingLowerLimit() {
    return 0; // High active cooling lower limit
}

double getHiActiveCoolingUpperLimit() {
    return 45; // High active cooling upper limit
}

double getMedActiveCoolingLowerLimit() {
    return 0; // Medium active cooling lower limit
}

double getMedActiveCoolingUpperLimit() {
    return 40; // Medium active cooling upper limit
}

CoolingLimits getCoolingLimits(CoolingType coolingType) {
    CoolingLimits limits;

    switch (coolingType) {
        case PASSIVE_COOLING:
            limits.lowerLimit = getPassiveCoolingLowerLimit();
            limits.upperLimit = getPassiveCoolingUpperLimit();
            break;
        case HI_ACTIVE_COOLING:
            limits.lowerLimit = getHiActiveCoolingLowerLimit();
            limits.upperLimit = getHiActiveCoolingUpperLimit();
            break;
        case MED_ACTIVE_COOLING:
            limits.lowerLimit = getMedActiveCoolingLowerLimit();
            limits.upperLimit = getMedActiveCoolingUpperLimit();
            break;
        default:
            throw std::invalid_argument("Invalid cooling type");
    }

    return limits;
}

// Update this function to return BreachType
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperature) {
    CoolingLimits limits = getCoolingLimits(coolingType);
    if (temperature < limits.lowerLimit) {
        return TOO_LOW; // Too low
    } else if (temperature > limits.upperLimit) {
        return TOO_HIGH; // Too high
    }
    return NORMAL; // Normal
}

void sendToController(BreachType breachType) {
    // Implement the logic for sending alerts to the controller
    if (breachType == TOO_LOW) {
        std::cout << "Sending alert: Temperature too low!" << std::endl;
    } else if (breachType == TOO_HIGH) {
        std::cout << "Sending alert: Temperature too high!" << std::endl;
    }
}

void sendToEmail(BreachType breachType) {
    // Implement the logic for sending alerts via email
    if (breachType == TOO_LOW) {
        std::cout << "Email alert: Temperature too low!" << std::endl;
    } else if (breachType == TOO_HIGH) {
        std::cout << "Email alert: Temperature too high!" << std::endl;
    }
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryCharacter, double temperature) {
    BreachType breachType = classifyTemperatureBreach(batteryCharacter.coolingType, temperature);
    if (alertTarget == TO_CONTROLLER) {
        sendToController(breachType);
    } else if (alertTarget == TO_EMAIL) {
        sendToEmail(breachType);
    }
}
