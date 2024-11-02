#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite, InfersBreachAccordingToLimits) {
    EXPECT_EQ(inferBreach(0, 1, 10), TOO_LOW);
    EXPECT_EQ(inferBreach(5, 1, 10), NORMAL);
    EXPECT_EQ(inferBreach(11, 1, 10), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreach) {
    BatteryCharacter batteryChar;

    batteryChar.coolingType = PASSIVE_COOLING;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar.coolingType, -1), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar.coolingType, 20), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar.coolingType, 36), TOO_HIGH);

    batteryChar.coolingType = HI_ACTIVE_COOLING;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar.coolingType, 46), TOO_HIGH);

    batteryChar.coolingType = MED_ACTIVE_COOLING;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar.coolingType, 41), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite, CheckAndAlertFunction) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;

    // Test sending to controller
    checkAndAlert(TO_CONTROLLER, batteryChar, 36); // Sends to controller

    // Test sending to email
    checkAndAlert(TO_EMAIL, batteryChar, -1); // Sends email alert for too low
    checkAndAlert(TO_EMAIL, batteryChar, 36); // Sends email alert for too high
}
