#include "typewise-alert.h"
#include <iostream>
#include <stdexcept>

// Define limits for different cooling types

/**
 * @brief Retrieve the passive cooling limits.
 * 
 * @return CoolingLimits The cooling limits for passive cooling.
 */
CoolingLimits getPassiveCoolingLimits() {
    return {0, 35}; // Passive cooling limits
}

/**
 * @brief Retrieve the high active cooling limits.
 * 
 * @return CoolingLimits The cooling limits for high active cooling.
 */
CoolingLimits getHiActiveCoolingLimits() {
    return {0, 45}; // High active cooling limits
}

/**
 * @brief Retrieve the medium active cooling limits.
 * 
 * @return CoolingLimits The cooling limits for medium active cooling.
 */
CoolingLimits getMedActiveCoolingLimits() {
    return {0, 40}; // Medium active cooling limits
}

/**
 * @brief Retrieve the cooling limits for passive cooling type.
 * 
 * @param coolingType_Passive The cooling type (expected to be PASSIVE_COOLING).
 * @return CoolingLimits The cooling limits for passive cooling.
 */
CoolingLimits getCoolingLimits_Passive(CoolingType coolingType_Passive) {
    return getPassiveCoolingLimits();
}

/**
 * @brief Retrieve the cooling limits for high active cooling type.
 * 
 * @param coolingType_HiActive The cooling type (expected to be HI_ACTIVE_COOLING).
 * @return CoolingLimits The cooling limits for high active cooling.
 */
CoolingLimits getCoolingLimits_HiActive(CoolingType coolingType_HiActive) {
    return getHiActiveCoolingLimits();
}

/**
 * @brief Retrieve the cooling limits for medium active cooling type.
 * 
 * @param coolingType_MedActive The cooling type (expected to be MED_ACTIVE_COOLING).
 * @return CoolingLimits The cooling limits for medium active cooling.
 */
CoolingLimits getCoolingLimits_MedActive(CoolingType coolingType_MedActive) {
    return getMedActiveCoolingLimits();
}

/**
 * @brief Retrieve cooling limits for an invalid cooling type.
 * 
 * @param coolingType_Invalid The cooling type (expected to be an invalid value).
 * @throws std::invalid_argument if the cooling type is invalid.
 */
CoolingLimits getCoolingLimits_Invalid(CoolingType coolingType_Invalid) {
    throw std::invalid_argument("Invalid cooling type");
}
