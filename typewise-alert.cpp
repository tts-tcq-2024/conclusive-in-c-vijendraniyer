#include "typewise-alert.h"
#include <iostream>
#include <stdexcept>

// Define limits for different cooling types
CoolingLimits getPassiveCoolingLimits() {
    return {0, 35}; // Passive cooling limits
}

CoolingLimits getHiActiveCoolingLimits() {
    return {0, 45}; // High active cooling limits
}

CoolingLimits getMedActiveCoolingLimits() {
    return {0, 40}; // Medium active cooling limits
}

CoolingLimits getCoolingLimits_Passive(CoolingType coolingType_Passive) {
    return getPassiveCoolingLimits();
}

CoolingLimits getCoolingLimits_HiActive(CoolingType coolingType_HiActive) {
    return getHiActiveCoolingLimits();
}

CoolingLimits getCoolingLimits_MedActive(CoolingType coolingType_MedActive) {
    return getMedActiveCoolingLimits();
}

CoolingLimits getCoolingLimits_Invalid(CoolingType coolingType_Invalid) {
    throw std::invalid_argument("Invalid cooling type");
}
