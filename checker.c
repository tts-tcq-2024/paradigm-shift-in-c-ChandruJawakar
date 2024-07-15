#include <stdio.h>
#include <assert.h>

// Function to check if a value is within a specified range
// Returns 1 if value is within [min, max], 0 otherwise
int isWithinRange(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        printf("%s\n", message);  // Print the message if value is out of range
        return 0;  // Return 0 indicating out of range
    }
    return 1;  // Return 1 indicating within range
}

// Function to check if battery parameters are within acceptable ranges
// Returns 1 if all parameters are within their respective ranges, 0 otherwise
int batteryIsOk(float temperature, float soc, float chargeRate) {
    // Check each parameter against its specified range using isWithinRange function
    return isWithinRange(temperature, 0, 45, "Temperature out of range!") &&
           isWithinRange(soc, 20, 80, "State of Charge out of range!") &&
           isWithinRange(chargeRate, 0, 0.8, "Charge Rate out of range!");
}

int main() {
    // Test cases using assert to validate the batteryIsOk function
    assert(batteryIsOk(25, 70, 0.7));    // Expected to pass
    assert(!batteryIsOk(50, 85, 0));     // Expected to fail
}

