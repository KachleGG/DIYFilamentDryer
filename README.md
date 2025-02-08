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
 - **OUT**: `A0`

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