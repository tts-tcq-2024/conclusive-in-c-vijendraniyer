#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H

/**
 * @brief Enum representing different cooling types.
 */
enum CoolingType {
    PASSIVE_COOLING,  ///< Passive cooling type
    HI_ACTIVE_COOLING, ///< High active cooling type
    MED_ACTIVE_COOLING ///< Medium active cooling type
};

/**
 * @brief Structure to hold cooling limits.
 */
struct CoolingLimits {
    double lower; ///< Lower limit of cooling
    double upper; ///< Upper limit of cooling
};

// Function declarations for retrieving cooling limits
CoolingLimits getCoolingLimits_Passive(CoolingType coolingType_Passive);
CoolingLimits getCoolingLimits_HiActive(CoolingType coolingType_HiActive);
CoolingLimits getCoolingLimits_MedActive(CoolingType coolingType_MedActive);
CoolingLimits getCoolingLimits_Invalid(CoolingType coolingType_Invalid);

// New helper function declarations for specific cooling limits
CoolingLimits getPassiveCoolingLimits();
CoolingLimits getHiActiveCoolingLimits();
CoolingLimits getMedActiveCoolingLimits();

#endif // TYPEWISE_ALERT_H
