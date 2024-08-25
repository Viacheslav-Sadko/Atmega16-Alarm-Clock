void I2C_init();
void I2C_Start();
void I2C_Stop();
void I2C_Send_byte(uint8_t c);
uint8_t I2C_Read_byte();
uint8_t I2C_Read_Last_Byte();
#define I2C_DELAY 100
