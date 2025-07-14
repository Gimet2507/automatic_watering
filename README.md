🌿 IoT-Based Automatic Plant Watering System (ESP8266 + Blynk)

This project is an automatic plant watering system using a NodeMCU ESP8266, soil moisture sensor, relay module, LCD I2C display, and the Blynk IoT platform for remote monitoring. The system automatically waters plants when the soil is detected as dry.

🔧 Components Used

NodeMCU ESP8266

Analog soil moisture sensor
1-channel relay module (for water pump/valve)
16x2 I2C LCD display
DC water pump or solenoid valve
WiFi connection
Blynk app (Android/iOS)

📲 Features

Automatic watering when soil is dry
Real-time soil status on LCD display
Remote monitoring via Blynk
Live display of soil status: DRY, WET, or NORMAL
Pump control via relay

🧠 System Logic

Sensor Value	Soil Condition	Pump	LCD Display
- 600	Dry	ON	SOIL DRY
- < 350	Wet	OFF	SOIL WET
- 350–600	Normal	ON	SOIL NORMAL

🔌 Pin Configuration
Component	NodeMCU Pin
Soil Moisture Sensor	A0
Relay Module	D3
I2C LCD Display	SDA → D2, SCL → D1

🧪 Required Arduino Libraries

Make sure the following libraries are installed:
ESP8266WiFi
Blynk
LiquidCrystal_I2C
Wire

📱 Blynk Virtual Pins

V0: Displays raw sensor value
V1: Displays sensor status text

Note: Make sure to use your valid Blynk Auth Token and ensure your WiFi network is stable.

📷 System Preview
(You can add wiring diagrams, photos of the setup, or Blynk screenshots here)

⚙️ Quick Setup

Enter your WiFi name and password in the code.
Insert your Blynk Auth Token.
Upload the code to your NodeMCU ESP8266.
Open the Serial Monitor (9600 baud) to monitor readings.
Connect your pump to the relay — the system will start automatically!

✅ Optional Feature Ideas

Manual pump control via Blynk button
Telegram notification when soil stays dry for too long
Scheduled watering using Blynk’s RTC/time feature

Feel free to open Issues or submit a Pull Request if you’d like to collaborate!
