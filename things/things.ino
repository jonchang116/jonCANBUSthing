#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <map>



// Replace with the actual I2C address of your LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight(); // Enable the backlight

  // Initialize the display with a welcome message
  lcd.setCursor(0, 0);
  lcd.print("CAN Data Display");
  delay(2000);
  lcd.clear();
}

public int candecode()
{
  return (2);
}

void loop() {
  // Replace with the actual CAN messages received from your CAN module
  String canData[] = {
        "002#0013700386000000",
        "376#AD",
        "280#0001100000000000",
        "156#0100000000000028",
        "140#0009FD4300000D00",
        "141#06265527FD832700",
        "3D1#96100000FD000000",
        "371#000000A001EA0000",
        "002#0013700588000000",
        "0D0#0F00000000000000",
        "0D1#00000080",
        "0D2#0000FFFF10000000",
        "0D3#8006C00F000000",
        "0D4#0000000000000000",
        "152#E17C000000000880",
        "37A#0000000000040000",
        "370#0000000003080000",
        "140#000AFD4300000D00",
        "141#06265527FD832700",
        "144#C000637E5024A000",
        "360#3801545C0D400100",
        "361#002124D142000000",
        "362#989E89AE9087DE04",
        "002#001370078A000000",
        "280#0002100000000000",
        "156#0100000000000028",
        "140#000BFD4300000D00",
    // ... add more CAN messages as needed
  };

  for (int i = 0; i < sizeof(canData) / sizeof(canData[0]); i++) {
    lcd.clear();

    // Display the CAN message
    lcd.setCursor(0, 0);
    lcd.print("CAN Message:");
    lcd.setCursor(0, 1);
    lcd.print(canData[i]);

    //delay(100);

    // Parse and display relevant information
   parseAndDisplay(canData[i]);

    // Wait before displaying the next message
    delay(1000);
  }
}

void parseAndDisplay(String canMessage) {
  
  String id = canMessage.substring(0, 3);
  String bytes12 = canMessage.substring(9, 13);
  if (id == "600")
    {
      String tempC = new String(bytes12.substring(3,6);
      int tempCint = stod(tempC);
      double temp = tempCint*1.8 + 32
      
    }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Oil Temp: " + temp);
  

 
}
