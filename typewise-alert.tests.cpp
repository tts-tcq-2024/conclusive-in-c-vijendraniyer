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

TEST(CoolingLimitsTest, GetCoolingLimits) {
    EXPECT_NO_THROW(getCoolingLimits(PASSIVE_COOLING));
    EXPECT_NO_THROW(getCoolingLimits(HI_ACTIVE_COOLING));
    EXPECT_NO_THROW(getCoolingLimits(MED_ACTIVE_COOLING));
    EXPECT_THROW(getCoolingLimits(static_cast<CoolingType>(999)), std::invalid_argument);
}
