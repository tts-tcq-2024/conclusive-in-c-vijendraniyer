#include "gtest/gtest.h"
#include "typewise-alert.h"

TEST(CoolingLimitsTest, GetPassiveCoolingLimits) {
    CoolingLimits limits = getPassiveCoolingLimits();
    EXPECT_EQ(limits.lower, 0);
    EXPECT_EQ(limits.upper, 35);
}

TEST(CoolingLimitsTest, GetHiActiveCoolingLimits) {
    CoolingLimits limits = getHiActiveCoolingLimits();
    EXPECT_EQ(limits.lower, 0);
    EXPECT_EQ(limits.upper, 45);
}

TEST(CoolingLimitsTest, GetMedActiveCoolingLimits) {
    CoolingLimits limits = getMedActiveCoolingLimits();
    EXPECT_EQ(limits.lower, 0);
    EXPECT_EQ(limits.upper, 40);
}

TEST(CoolingLimitsTest, GetCoolingLimits_Passive) {
    EXPECT_NO_THROW(getCoolingLimits_Passive(PASSIVE_COOLING));
}

TEST(CoolingLimitsTest, GetCoolingLimits_HiActive) {
    EXPECT_NO_THROW(getCoolingLimits_HiActive(HI_ACTIVE_COOLING));
}

TEST(CoolingLimitsTest, GetCoolingLimits_MedActive) {
    EXPECT_NO_THROW(getCoolingLimits_MedActive(MED_ACTIVE_COOLING));
}

TEST(CoolingLimitsTest, GetCoolingLimits_Invalid) {
    EXPECT_THROW(getCoolingLimits_Invalid(static_cast<CoolingType>(999)), std::invalid_argument);
}