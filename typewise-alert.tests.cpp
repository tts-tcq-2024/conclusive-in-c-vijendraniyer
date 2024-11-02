#include "gtest/gtest.h"
#include "typewise-alert.h"

/**
 * @brief Test suite for verifying the cooling limits functionality.
 */

// Test for retrieving passive cooling limits
TEST(CoolingLimitsTest, GetPassiveCoolingLimits) {
    CoolingLimits limits = getPassiveCoolingLimits(); // Retrieve passive cooling limits
    EXPECT_EQ(limits.lower, 0); // Check that the lower limit is correct
    EXPECT_EQ(limits.upper, 35); // Check that the upper limit is correct
}

// Test for retrieving high active cooling limits
TEST(CoolingLimitsTest, GetHiActiveCoolingLimits) {
    CoolingLimits limits = getHiActiveCoolingLimits(); // Retrieve high active cooling limits
    EXPECT_EQ(limits.lower, 0); // Check that the lower limit is correct
    EXPECT_EQ(limits.upper, 45); // Check that the upper limit is correct
}

// Test for retrieving medium active cooling limits
TEST(CoolingLimitsTest, GetMedActiveCoolingLimits) {
    CoolingLimits limits = getMedActiveCoolingLimits(); // Retrieve medium active cooling limits
    EXPECT_EQ(limits.lower, 0); // Check that the lower limit is correct
    EXPECT_EQ(limits.upper, 40); // Check that the upper limit is correct
}

// Test for retrieving cooling limits for passive cooling type
TEST(CoolingLimitsTest, GetCoolingLimits_Passive) {
    EXPECT_NO_THROW(getCoolingLimits_Passive(PASSIVE_COOLING)); // Ensure that no exception is thrown for valid input
}

// Test for retrieving cooling limits for high active cooling type
TEST(CoolingLimitsTest, GetCoolingLimits_HiActive) {
    EXPECT_NO_THROW(getCoolingLimits_HiActive(HI_ACTIVE_COOLING)); // Ensure that no exception is thrown for valid input
}

// Test for retrieving cooling limits for medium active cooling type
TEST(CoolingLimitsTest, GetCoolingLimits_MedActive) {
    EXPECT_NO_THROW(getCoolingLimits_MedActive(MED_ACTIVE_COOLING)); // Ensure that no exception is thrown for valid input
}

// Test for handling invalid cooling type by throwing an exception
TEST(CoolingLimitsTest, GetCoolingLimits_Invalid) {
    EXPECT_THROW(getCoolingLimits_Invalid(static_cast<CoolingType>(999)), std::invalid_argument); // Ensure an invalid argument exception is thrown
}
