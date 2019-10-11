#include <Wire.h>

void mux_Tx(int adr, int reg, byte data) {
  /* This function will send data to a MCP23017 chip */
  Wire.beginTransmission(adr);     /* address the chip */
  Wire.write(reg);                 /* point to the register of choice */
  Wire.write(data);                /* send the data */
  Wire.endTransmission();          /* end the transmission */
}

void mux_Rx(int adr, int reg, int numbytes, byte *data) {
  /* This function will request n bytes of data from a MCP23017 chip */
  Wire.beginTransmission(adr);     /* address the chip */
  Wire.write(reg);                 /* point to the register of choice */
  Wire.endTransmission();          /* end the transmission */
  Wire.requestFrom(adr, numbytes); /* request the data */
  *data = Wire.read();
}

void printBin(int var) {
  for (unsigned int test = 0x80; test; test >>= 1) {
    Serial.print(var  & test ? '1' : '0');
  }
}


void setup() {
  Serial.begin(9600); // Initialize the serial port
  Serial.print("I'm awake!\n");
  /* wake up the I2C_bus */
  int n_mux_chips_detected = 0;           /* number of MUX chips detected in the IBIT */
  const int c_num_mux_chips = 2;
  const int c_first_mux_address = 0x22;     /* the first I2C address in the MUX range [-]*/
  const int c_last_mux_address = 0x23;      /* the last I2C address in the MUX range [-]*/
  
  Wire.begin();
  Serial.print("Started Wire\n");
  /* check we have all the MCP23017 chips */
  for (byte a = c_first_mux_address; a <= c_last_mux_address; a++)   /* chip addresses start at 0x20, max of 8 chips */
  {
    Serial.print("Testing ");
    Serial.print(a);
    Wire.beginTransmission (a);
    int testval = Wire.endTransmission ();
    Serial.print(" returned ");
    Serial.print(testval);
    Serial.print("\n");
    if (testval == 0) {
      n_mux_chips_detected++;
    }
  }
  
  Serial.print("Done testing, detected: ");
  Serial.print(n_mux_chips_detected);
  Serial.print("\n");
  if (n_mux_chips_detected != c_num_mux_chips) {
    Serial.print("mux miss");
  }

}

void loop() {
  byte buffb=0;
  mux_Rx(0x22, // i2c 0
         0x13, // GPIOB
         1, // Start at register 1
         &buffb); //write to buff
  byte buffa=0;
  mux_Rx(0x22, // i2c 0
         0x12, // GPIOA
         1, // Start at register 1
         &buffa); //write to buff
  byte buffd=0;
  mux_Rx(0x23, // i2c 0
         0x13, // GPIOB
         1, // Start at register 1
         &buffd); //write to buff
  byte buffc=0;
  mux_Rx(0x23, // i2c 0
         0x12, // GPIOB
         1, // Start at register 1
         &buffc); //write to buff
  Serial.print("0x20A: ");
  printBin(buffa);
  Serial.print(" 0x20B: ");
  printBin(buffb);
  Serial.print(" 0x21A: ");
  printBin(buffc);
  Serial.print(" 0x21B: ");
  printBin(buffd);
  Serial.print("\n");
//  Serial.println(buffb,BIN);
  delay(100);

}
