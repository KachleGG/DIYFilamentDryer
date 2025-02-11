# Homemade filament dryer

## Stuff needed 
 - Enclosure
 - Arduino nano
 - 12V power adapter
 - Heating element 2x
 - Relay module
 - Temparature sensor
 - Rotary encoder with pushbutton
 - 16x2 LCD display

## Costs
 | Part                 | Amount |  Cost  |
 |----------------------|--------|--------|
 | 3D printing          |        |        |
 | Enclosure            |   1    |  130 Kč|
 | Arduino nano         |   1    |  86 Kč |
 | 12V Power Supply     |   1    |  70 Kč |
 | 16x2 LCD display     |   1    |  80 Kč |
 | Heating Element      |   2    |  77 Kč |
 | Temparature Sensor   |   1    |  10 Kč |
 | Rotary Encoder with Push Button | 1| 62Kč |
 | Relay module         |   1    |  30 Kč  |
 | | |
 | Overall| | 545 Kč |

 # Power Consumption Estimate
  ## 12V system Power costs
  Here's the power consumption breakdown for your components, with the current remaining the same:
  - **Arduino Nano**: 40 mA
  - **LCD**: 20 mA
  - **Temperature Sensor**: 1.5 mA
  - **Rotary Encoder**: 10 mA
  - **Relay Module**: 50 mA

  **Total Current**: 121.5 mA

  Using the formula:
  \[ \text{Power (W)} = \text{Voltage (V)} \times \text{Current (A)} \]

  \[ \text{Power} = 12V \times 0.1215A = 1.458W \]

  If you run this setup for an hour, it will consume:
  \[ \text{Energy (Wh)} = \text{Power (W)} \times \text{Time (h)} \]

  \[ \text{Energy} = 1.458W \times 1h = 1.458Wh \]

  For a whole day (24 hours):
  \[ \text{Energy} = 1.458W \times 24h = 34.992Wh \]

  Over a month (30 days):
  \[ \text{Energy} = 34.992Wh \times 30 = 1,049.76Wh \]

  \[ \text{Energy} = 1.04976kWh \]

  If your electricity cost is €0.15 per kWh:
  \[ \text{Cost} = 1.04976kWh \times €0.15 = €0.157 \]

  So, running your setup continuously for a month would cost you approximately €0.16 if your cost is €0.15 per kWh.


## Wiring
 ### Power Supply
 - **Positive Terminal**: `VIN`
 - **Negative Terminal**: `GND`

 ### Relay Module
 - **VCC**: `5V`
 - **GND**: `GND`
 - **IN**: `D2`

 ### Temperature Sensor
 - **VCC**: `5V`
 - **GND**: `GND`
 - **OUT**: `D6`

 ### Heating Elements
 - **One Terminal**: `COM (on Relay module)`
 - **Second Terminal**: `NO (on Relay module)`

 ### Rotary Encoder with Pushbutton
 - **VCC**: `5V`
 - **GND**: `GND`
 - **CLK**: `D3`
 - **DT**: `D4`
 - **SW**: `D5`

 ### 16x2 LCD Display
 - **VCC**: `5V`
 - **GND**: `GND`
 - **RS**: `D7`
 - **E**: `D8`
 - **D4**: `D9`
 - **D5**: `D10`
 - **D6**: `D11`
 - **D7**: `D12`
 - **A**: `5V`
 - **K**: `GND`


#### Disclaimer
The information provided herein is intended for educational and informational purposes 
only, and should not be considered as professional advice. By accessing this content, you agree that you 
are responsible for your actions and decisions, including those related to assembling a homemade device 
project or using the code and components suggested herein. We cannot be held liable for any damages, 
injuries, or losses resulting from the use or misuse of this information, nor for any damage caused by 
the assembly process, the device's operation, or any malfunction thereof. It is your responsibility to 
ensure that all local laws and regulations are complied with when assembling, using, or modifying this project.