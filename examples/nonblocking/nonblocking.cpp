#include <Adafruit_ADS1X15.h>
#include <iostream>
#include <unistd.h>

// Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */

void setup(void)
{
  std::cout << "Hello!" << std::endl;

  std::cout << "Getting differential reading from AIN0 (P) and AIN1 (N)" << std::endl;
  std::cout << "ADC Range: +/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)" << std::endl;

  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

  if (!ads.begin()) {
    std::cout << "Failed to initialize ADS." << std::endl;
    while (1);
  }

  // Start the first conversion.
  ads.startADCReading(ADS1X15_REG_CONFIG_MUX_DIFF_0_1, /*continuous=*/false);
}

void loop(void)
{
  // If we don't have new data, skip this iteration.
  if (!ads.conversionComplete()) {
    return;
  }

  int16_t results = ads.getLastConversionResults();

  std::cout << "Differential: " << results << "(" << ads.computeVolts(results) << "mV)" << std::endl;

  // Start another conversion.
  ads.startADCReading(ADS1X15_REG_CONFIG_MUX_DIFF_0_1, /*continuous=*/false);

  usleep(1000*1000);
}

int main()
{
  setup();
  for (int i = 0; i < 10; i++){ 
    loop(); 
  }
  return 0;
}
