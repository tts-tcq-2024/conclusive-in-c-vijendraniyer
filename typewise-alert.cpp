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

CoolingLimits getCoolingLimits(CoolingType coolingType) {
    switch (coolingType) {
        case PASSIVE_COOLING:
            return getPassiveCoolingLimits();
        case HI_ACTIVE_COOLING:
            return getHiActiveCoolingLimits();
        case MED_ACTIVE_COOLING:
            return getMedActiveCoolingLimits();
        default:
            throw std::invalid_argument("Invalid cooling type");
    }
}
