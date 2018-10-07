# Device-Theft-and-Malfunction-Detection

## Inspiration 
We couldn't figure out what we wanted to do as a project, and then we decided to implement a data safety solution.We saw the importance of discarded objects which can be utilized to make profit.

## What it does?

Implemented IoT  devices which prevents damage or theft of sensitive information. We integrated the temperature and the light sensor with IoT device. This will help prevent theft by checking light exposure if it's within the original limits it means the objects are at their own place. The system also prevents damage of the object by sensing the temperature and determining whether the object has caught fire or exposed to heat this is done by emission of temperature sensor on the device.

## How we built it 

Arduino101 was used as a IoT.Then the express server was used to collect and process the data.

## Challenges we ran into 
Arduinos only return 10-bit values from analog inputs, from 0 to 1023, so I had to first convert them to voltage and then find equations online to figure out how to turn the output voltage into units of dB, temperature, and lux, which were fairly difficult to find and implement.

## Accomplishments that I'm proud of 
Coming up with he logarithmic equations which relate the absolute value of the difference between the average and current values to values of red and green for the backlight. I had to find the maximum logarithm of the absolute difference (keeping in mind that log(0) is undefined so if the absolute difference was 0 bad things would happen). I am also proud of implementing the equations for finding the actual ambient sound, temperature, and lux from the analog values I received.
