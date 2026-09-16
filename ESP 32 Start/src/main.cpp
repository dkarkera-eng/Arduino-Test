#include <Arduino.h>
#include <Wire.h>

const int MPU_ADDR = 0x68;

int16_t accelerometer_x, accelerometer_y, accelerometer_z; // variables for accelerometer raw data
int16_t gyro_x, gyro_y, gyro_z; // variables for gyro raw data
int16_t temperature; // variables for temperature data
// Use long integers for accumulators to prevent overflow
long axBias = 0;
long ayBias = 0;
long azBias = 0;

void calibration() {
  Serial.println("Calibrating IMU... Keep sensor flat and completely still!");
  
  for(int i = 0; i < 300; i++) {
    // 1. Point to the starting register
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x3B); 
    Wire.endTransmission(false);
    
    // 2. Request the 6 bytes for X, Y, and Z accelerometer data
    Wire.requestFrom((uint8_t)MPU_ADDR, (size_t)6, true); 
    
    // 3. Read and accumulate the data
    axBias += (Wire.read() << 8 | Wire.read());
    ayBias += (Wire.read() << 8 | Wire.read());
    azBias += (Wire.read() << 8 | Wire.read());
    
    // 4. Give the sensor a tiny break to update its internal registers
    delay(2); 
  }
  
  // Calculate the average
  axBias /= 300;
  ayBias /= 300;
  azBias /= 300;

  // Account for 1g of gravity on the Z-axis!
  // At the default +/- 2g sensitivity, 1g = 16384
  azBias -= 16384; 
  
  Serial.println("Calibration complete!");
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // --- WAKE UP SEQUENCE ---
  Wire.beginTransmission(MPU_ADDR); 
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0);    // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true); // Data is sent here! The sensor is now awake.
  
  delay(100); // Give it a brief moment to stabilize
  
  // --- CALIBRATE ---
  calibration();
}
char tmp_str[7]; // temporary variable used in convert function

char* convert_int16_to_str(int16_t i) { // converts int16 to string. Moreover, resulting strings will have the same length in the debug monitor.
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}

void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
  Wire.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
  Wire.requestFrom((uint8_t)MPU_ADDR, (size_t)14, true); // request a total of 7*2=14 registers
  
  // "Wire.read()<<8 | Wire.read();" means two registers are read and stored in the same variable
  accelerometer_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  accelerometer_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  accelerometer_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
  temperature = Wire.read()<<8 | Wire.read(); // reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)
  gyro_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
  gyro_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
  gyro_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)
  

  // print out data
  
  Serial.print("aX = "); Serial.print(convert_int16_to_str(accelerometer_x - axBias));
  Serial.print(" | aY = "); Serial.print(convert_int16_to_str(accelerometer_y - ayBias));
  Serial.print(" | aZ = "); Serial.print(convert_int16_to_str(accelerometer_z - azBias));
  
  //Serial.print("aX = "); Serial.print(axBias);
  //Serial.print(" | aY = "); Serial.print(ayBias);
  //Serial.print(" | aZ = "); Serial.print(azBias);

  // the following equation was taken from the documentation [MPU-6000/MPU-6050 Register Map and Description, p.30]
  Serial.print(" | tmp = "); Serial.print(temperature/340.00+36.53);
  Serial.print(" | gX = "); Serial.print(convert_int16_to_str(gyro_x));
  Serial.print(" | gY = "); Serial.print(convert_int16_to_str(gyro_y));
  Serial.print(" | gZ = "); Serial.print(convert_int16_to_str(gyro_z));
  Serial.println();
  
  // delay
  delay(300);

}
