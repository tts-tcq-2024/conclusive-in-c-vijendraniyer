#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H

enum CoolingType {
    PASSIVE_COOLING,
    HI_ACTIVE_COOLING,
    MED_ACTIVE_COOLING
};

struct CoolingLimits {
    double lower;
    double upper;
};

// Original function declaration
CoolingLimits getCoolingLimits(CoolingType coolingType);

// New helper function declarations
CoolingLimits getPassiveCoolingLimits();
CoolingLimits getHiActiveCoolingLimits();
CoolingLimits getMedActiveCoolingLimits();

#endif // TYPEWISE_ALERT_H
