#include "gtest/gtest.h"
#include "typewise-alert.h"

// Test cases for cooling limits
TEST(CoolingLimitsTests, PassiveCoolingLimits) {
    CoolingLimits limits = getCoolingLimits(PASSIVE_COOLING);
    EXPECT_EQ(limits.lowerLimit, 0);
    EXPECT_EQ(limits.upperLimit, 35);
}

TEST(CoolingLimitsTests, HiActiveCoolingLimits) {
    CoolingLimits limits = getCoolingLimits(HI_ACTIVE_COOLING);
    EXPECT_EQ(limits.lowerLimit, 0);
    EXPECT_EQ(limits.upperLimit, 45);
}

TEST(CoolingLimitsTests, MedActiveCoolingLimits) {
    CoolingLimits limits = getCoolingLimits(MED_ACTIVE_COOLING);
    EXPECT_EQ(limits.lowerLimit, 0);
    EXPECT_EQ(limits.upperLimit, 40);
}

// Example tests for classifyTemperatureBreach
TEST(ClassifyTemperatureBreachTests, PassiveCooling) {
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, -1), 1); // Too low
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 20), 0); // Normal
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 36), 2); // Too high
}

TEST(ClassifyTemperatureBreachTests, HiActiveCooling) {
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, -1), 1); // Too low
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 30), 0); // Normal
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50), 2); // Too high
}

TEST(ClassifyTemperatureBreachTests, MedActiveCooling) {
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1), 1); // Too low
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 35), 0); // Normal
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 45), 2); // Too high
}

// Tests for sending alerts
TEST(SendAlertsTests, SendToController) {
    testing::internal::CaptureStdout();
    sendToController(TOO_LOW);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sending alert: Temperature too low!\n");

    testing::internal::CaptureStdout();
    sendToController(TOO_HIGH);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sending alert: Temperature too high!\n");
}

TEST(SendAlertsTests, SendToEmail) {
    testing::internal::CaptureStdout();
    sendToEmail(TOO_LOW);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Email alert: Temperature too low!\n");

    testing::internal::CaptureStdout();
    sendToEmail(TOO_HIGH);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Email alert: Temperature too high!\n");
}

// Other existing tests...

