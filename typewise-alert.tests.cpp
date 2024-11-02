#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite, InfersBreachAccordingToLimits) {
    EXPECT_EQ(inferBreach(25.0, 20.0, 30.0), NORMAL);
    EXPECT_EQ(inferBreach(15.0, 20.0, 30.0), TOO_LOW);
    EXPECT_EQ(inferBreach(35.0, 20.0, 30.0), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreach) {
    BatteryCharacter passiveBattery = {PASSIVE_COOLING, "PassiveBrand"};
    EXPECT_EQ(classifyTemperatureBreach(passiveBattery.coolingType, 30.0), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(passiveBattery.coolingType, 40.0), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(passiveBattery.coolingType, -1.0), TOO_LOW);

    BatteryCharacter hiActiveBattery = {HI_ACTIVE_COOLING, "HiActiveBrand"};
    EXPECT_EQ(classifyTemperatureBreach(hiActiveBattery.coolingType, 44.0), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(hiActiveBattery.coolingType, 46.0), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(hiActiveBattery.coolingType, -1.0), TOO_LOW);

    BatteryCharacter medActiveBattery = {MED_ACTIVE_COOLING, "MedActiveBrand"};
    EXPECT_EQ(classifyTemperatureBreach(medActiveBattery.coolingType, 39.0), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(medActiveBattery.coolingType, 41.0), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(medActiveBattery.coolingType, -1.0), TOO_LOW);
}

TEST(TypeWiseAlertTestSuite, CheckAndAlert) {
    BatteryCharacter batteryChar = {PASSIVE_COOLING, "BrandX"};
    testing::internal::CaptureStdout(); // Capture output to check in tests

    checkAndAlert(TO_CONTROLLER, batteryChar, 50.0); // TOO_HIGH alert
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("feed") != std::string::npos); // Check for controller alert format

    testing::internal::CaptureStdout();
    checkAndAlert(TO_EMAIL, batteryChar, -5.0); // TOO_LOW alert
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("too low") != std::string::npos); // Check for email alert

    testing::internal::CaptureStdout();
    checkAndAlert(TO_EMAIL, batteryChar, 25.0); // NORMAL, no alert expected
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty()); // No output expected
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
