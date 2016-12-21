/***************************************************
 DFRobot Gravity: HCHO Sensor
 <https://www.dfrobot.com/wiki/index.php/Gravity:_HCHO_Sensor_SKU:_SEN0231>
 
 ***************************************************
 This example reads the concentration of HCHO in air by DAC mode.
 
 Created 2016-12-15
 By Jason <jason.ling@dfrobot.com@dfrobot.com>
 
 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/
 
 /***********Notice and Trouble shooting***************
 1. This code is tested on Arduino Uno with Arduino IDE 1.0.5 r2.
 2. In order to protect the sensor, do not touch the white sensor film on the sensor module, 
 and high concentration of Hydrogen sulfide, hydrogen, methanol, ethanol, carbon monoxide should be avoided. 
 3. Please do not use the modules in systems which related to human being’s safety.
 ****************************************************/
 
#define SensorAnalogPin A2	//this pin read the analog voltage from the HCHO sensor
#define VREF	5.0		//voltage on AREF pin

void setup()
{
    Serial.begin(9600);
}

void loop()
{  
    Serial.print(analogReadPPM());
    Serial.println("ppm");
    delay(1000);
}

float analogReadPPM()
{
   float analogVoltage = analogRead(SensorAnalogPin) / 1024.0 * VREF;
   float ppm = 3.125 * analogVoltage - 1.25;	//linear relationship(0.4V for 0 ppm and 2V for 5ppm)
   if(ppm<0)  ppm=0;
   else if(ppm>5)  ppm = 5;
   return ppm;
}
