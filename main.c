 #include<lpc214x.h>
 #include"TMP117.h"
 #include"I2C.h"
 #include"TYPE.h"
 
 float64 tmp;
 int main()
 {
  TMP117_init();
  tmp=TMP117_read();
 }
