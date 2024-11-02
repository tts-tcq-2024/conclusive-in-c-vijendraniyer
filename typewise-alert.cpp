#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if (value < lowerLimit) {
    return TOO_LOW;
  }
  if (value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

// Helper function to get the lower limit based on cooling type
int getLowerLimit(CoolingType coolingType) {
  switch (coolingType) {
    case PASSIVE_COOLING: return 0;
    case HI_ACTIVE_COOLING: return 0;
    case MED_ACTIVE_COOLING: return 0;
    default: return 0; // Default case to avoid warnings
  }
}

// Helper function to get the upper limit based on cooling type
int getUpperLimit(CoolingType coolingType) {
  switch (coolingType) {
    case PASSIVE_COOLING: return 35;
    case HI_ACTIVE_COOLING: return 45;
    case MED_ACTIVE_COOLING: return 40;
    default: return 0; // Default case to avoid warnings
  }
}

// Helper function to print email message based on breach type
void printEmailMessage(BreachType breachType) {
  const char* recipient = "a.b@c.com";
  printf("To: %s\n", recipient);
  if (breachType == TOO_LOW) {
    printf("Hi, the temperature is too low\n");
  } else if (breachType == TOO_HIGH) {
    printf("Hi, the temperature is too high\n");
  }
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int lowerLimit = getLowerLimit(coolingType);
  int upperLimit = getUpperLimit(coolingType);
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  switch (alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  printEmailMessage(breachType);
}
