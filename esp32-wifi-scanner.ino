/*
 * ESP32 WiFi Scanner (Passive Scan)
 * Author: Ethical Hacking Lab
 * Purpose: Educational WiFi scanning for ethical hacking practice
 */

#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); // Set WiFi mode to station (client)
  WiFi.disconnect();   // Disconnect from any AP if connected
  delay(100);

  Serial.println("ESP32 WiFi Scanner Starting...");
}

void loop() {
  Serial.println("Scanning WiFi networks...");

  int n = WiFi.scanNetworks();
  Serial.printf("Found %d networks\n", n);

  if (n == 0) {
    Serial.println("No networks found.");
  } else {
    // Print header
    Serial.println("------------------------------------------------------------------------");
    Serial.println("| No | SSID                      | RSSI | CH | MAC Address     | ENC |");
    Serial.println("------------------------------------------------------------------------");

    for (int i = 0; i < n; i++) {
      // Print network info
      Serial.printf("| %2d | %-25.25s | %4ddB | %2d | %8.8s | %3d |\n",
        i + 1,
        WiFi.SSID(i).c_str(),
        WiFi.RSSI(i),
        WiFi.channel(i),
        WiFi.BSSIDstr(i).c_str(),
        WiFi.encryptionType(i));
      delay(10);
    }
    Serial.println("------------------------------------------------------------------------");
  }

  Serial.println("\nScan complete.\n");
  delay(10000); // Wait 10 seconds before next scan
}
