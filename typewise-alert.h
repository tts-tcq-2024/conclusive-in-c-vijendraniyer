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
CoolingLimits getCoolingLimits_Passive(CoolingType coolingType_Passive);
CoolingLimits getCoolingLimits_HiActive(CoolingType coolingType_HiActive);
CoolingLimits getCoolingLimits_MedActive(CoolingType coolingType_MedActive);
CoolingLimits getCoolingLimits_Invalid(CoolingType coolingType_Invalid);

// New helper function declarations
CoolingLimits getPassiveCoolingLimits();
CoolingLimits getHiActiveCoolingLimits();
CoolingLimits getMedActiveCoolingLimits();

#endif // TYPEWISE_ALERT_H
