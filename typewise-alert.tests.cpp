#include <gtest/gtest.h>
#include "typewise-alert.h"

// Test cases for inferBreach
TEST(TypeWiseAlertTestSuite, InfersBreachAccordingToLimits) {
    EXPECT_EQ(inferBreach(30, 0, 35), NORMAL);
    EXPECT_EQ(inferBreach(36, 0, 35), TOO_HIGH);
    EXPECT_EQ(inferBreach(-1, 0, 35), TOO_LOW);
}

// Test cases for getLowerLimit
TEST(TypeWiseAlertTestSuite, GetLowerLimit) {
    EXPECT_EQ(getLowerLimit(PASSIVE_COOLING), 0);
    EXPECT_EQ(getLowerLimit(HI_ACTIVE_COOLING), 0);
    EXPECT_EQ(getLowerLimit(MED_ACTIVE_COOLING), 0);
}

// Test cases for getUpperLimit
TEST(TypeWiseAlertTestSuite, GetUpperLimit) {
    EXPECT_EQ(getUpperLimit(PASSIVE_COOLING), 35);
    EXPECT_EQ(getUpperLimit(HI_ACTIVE_COOLING), 45);
    EXPECT_EQ(getUpperLimit(MED_ACTIVE_COOLING), 40);
}

// Test cases for classifyTemperatureBreach
TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreachCorrectly) {
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 30), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 36), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, -1), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 41), TOO_HIGH);
}

// Test cases for sendToEmail
// Note: Since sendToEmail prints to stdout, we might want to test its output
TEST(TypeWiseAlertTestSuite, SendToEmailOutputsCorrectMessage) {
    testing::internal::CaptureStdout(); // Capture the output
    sendToEmail(TOO_LOW);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Hi, the temperature is too low"), std::string::npos);

    testing::internal::CaptureStdout();
    sendToEmail(TOO_HIGH);
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Hi, the temperature is too high"), std::string::npos);
}

// Test cases for sendToController
TEST(TypeWiseAlertTestSuite, SendToControllerOutputsCorrectMessage) {
    testing::internal::CaptureStdout(); // Capture the output
    sendToController(TOO_LOW); // Just an example, you can test with any breach type
    std::string output = testing::internal::GetCapturedStdout();
    // Verify the output format; replace with the expected header and breachType format
    EXPECT_NE(output.find("feed"), std::string::npos);
}

