#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite, InfersBreachAccordingToLimits) {
    // Add tests for inferBreach based on given limits
    EXPECT_EQ(inferBreach(30, 0, 35), NORMAL);
    EXPECT_EQ(inferBreach(-1, 0, 35), TOO_LOW);
    EXPECT_EQ(inferBreach(40, 0, 35), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite, GetLowerLimit) {
    EXPECT_EQ(getLowerLimit(PASSIVE_COOLING), 0);
    EXPECT_EQ(getLowerLimit(HI_ACTIVE_COOLING), 0);
    EXPECT_EQ(getLowerLimit(MED_ACTIVE_COOLING), 0);
}

TEST(TypeWiseAlertTestSuite, GetUpperLimit) {
    EXPECT_EQ(getUpperLimit(PASSIVE_COOLING), 35);
    EXPECT_EQ(getUpperLimit(HI_ACTIVE_COOLING), 45);
    EXPECT_EQ(getUpperLimit(MED_ACTIVE_COOLING), 40);
}

TEST(TypeWiseAlertTestSuite, ClassifyTemperatureBreach) {
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 30), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 40), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, -5), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 35), NORMAL);
}
