#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <HTTPClient.h>

#define API_KEY "YOUR_THINGSPEAK_API_KEY"
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASS "YOUR_WIFI_PASSWORD"
#define VOLTAGE_PIN A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();

    WiFi.begin(WIFI_SSID, WIFI_PASS);
    lcd.setCursor(0, 0);
    lcd.print("Connecting...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WiFi Connected");
    delay(2000);
}

void loop() {
    float batteryVoltage = readBatteryVoltage();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Battery: ");
    lcd.print(batteryVoltage);
    lcd.print("V");

    sendToThingSpeak(batteryVoltage);
    delay(15000);  // Update every 15 seconds
}

float readBatteryVoltage() {
    int rawValue = analogRead(VOLTAGE_PIN);
    float voltage = (rawValue / 1024.0) * 3.3 * (5.7 / 2.7);  // Adjust based on voltage divider
    return voltage;
}

void sendToThingSpeak(float voltage) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        String url = "http://api.thingspeak.com/update?api_key=" + String(API_KEY) + "&field1=" + String(voltage);
        http.begin(url);
        int httpCode = http.GET();
        http.end();
        Serial.println(httpCode == 200 ? "Sent to ThingSpeak" : "Failed to send");
    } else {
        Serial.println("WiFi not connected");
    }
}
