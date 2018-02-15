#include "DHT.h"
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11 

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  delay(1000);
  Serial.println("DHTxx test!");
 
  dht.begin();
  delay(1000);
}

void printSensorData() {
  if(isnan( dht.readTemperature()) || isnan(dht.readHumidity()) )
	Serial.print("Failed to read from DHT sensor!");
  else {
    char message[80];
    //Serial.println(sprintf(message,"Temperature: %d" , dht.readTemperature() , "%\t" , "Humidity: %d" , dht.readHumidity() , "*C."));
    //Serial.println(sprintf(message,"Temperature: %d.%02d", (int)dht.readTemperature(), (int)(dht.readTemperature()*100)%100));
    strcpy(message, "Temperature: ");
    dtostrf(dht.readTemperature(), 2, 1, &message[strlen(message)]); 
    strcat(message, "*C,\tHumidity: ");
    dtostrf(dht.readHumidity(), 2, 0, &message[strlen(message)]);
    strcat(message, "%");
    Serial.println(message);
  }
}
void loop() {
  printSensorData();
  delay(5000);
}
