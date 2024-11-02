// typewise-alert.h

#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H

enum CoolingType { PASSIVE_COOLING, HI_ACTIVE_COOLING, MED_ACTIVE_COOLING };
enum BreachType { NORMAL, TOO_LOW, TOO_HIGH };
enum AlertTarget { TO_CONTROLLER, TO_EMAIL };

struct CoolingLimits {
    double lowerLimit;
    double upperLimit;
};

struct BatteryCharacter {
    CoolingType coolingType;
};

CoolingLimits getCoolingLimits(CoolingType coolingType);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperature); // Change return type to BreachType
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryCharacter, double temperature);

#endif // TYPEWISE_ALERT_H
