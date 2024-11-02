#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H

typedef enum {
    PASSIVE_COOLING,
    HI_ACTIVE_COOLING,
    MED_ACTIVE_COOLING
} CoolingType;

typedef struct {
    double lowerLimit;
    double upperLimit;
} CoolingLimits;

typedef enum {
    TOO_LOW,
    NORMAL,
    TOO_HIGH
} BreachType;

typedef enum {
    TO_CONTROLLER,
    TO_EMAIL
} AlertTarget;

typedef struct {
    CoolingType coolingType;
    // Other battery characteristics can be added here
} BatteryCharacter;

CoolingLimits getCoolingLimits(CoolingType coolingType);
double getPassiveCoolingLowerLimit();
double getPassiveCoolingUpperLimit();
double getHiActiveCoolingLowerLimit();
double getHiActiveCoolingUpperLimit();
double getMedActiveCoolingLowerLimit();
double getMedActiveCoolingUpperLimit();
double classifyTemperatureBreach(CoolingType coolingType, double temperature);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryCharacter, double temperature);

#endif // TYPEWISE_ALERT_H
