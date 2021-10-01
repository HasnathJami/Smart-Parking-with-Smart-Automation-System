# Objective:

The objective of our project is to design a system which reduces the time
spent by the driver searching for an open parking space. By monitoring the
status (occupied or vacant) of each and every spot in the lot, we can collect
the necessary data to alert the driver to vacant parking spaces faster.


# Social Values:

The smart parking system is considered beneficial for the car park operators, car park patrons as well as in environment conservation. For the
car park operators, the information gathered via the implementation of
the Smart Parking System can be exploited to predict future parking patterns. In terms of environment conservation, the level of pollution can
be reduced by decreasing vehicle emission (air pollutant) in the air. This
can be attributed to the fact that vehicle travel is reduced. As fuel consumption is directly related to vehicle miles travelled, it will be reduces as
well. Moreover, it saves the driver from being confused and from wasting
valuable time.

# Required Components:

 These following parts and tools are required for building this project
• Arduino Mega
• Ultrasonic sensor
• LCD Screen
• LED
• Bread Board
• Power Supply
• Connecting Wires
• Motor
• Servo Motor
• Vibration Sensor
• Fire Sensor
• Gas Sensor
• Buzzer
• Motor Driver IC
• Potentiometer
• LDR sensor


# Working Procedure:

Our Smart parking with smart automation system has the following

# Features:

• Automated gate functioning
• Slot Allocation
• Fire Detection
• Gas Detection
• Earthquake Detection
• Emergency Evacuation

## Automated gate functioning:

Then entrance and the exit gates will open close automatically according
to the distance of the cars from the gate. It will also remain closed depending on the number of cars.If the parking slots are full then the entrance
gate will remain closed.This function is working by using servo motors and
ultrasonic sensors.Also since we are using a single sensor per gate a servo
motor is used to rotate the sensor so that it can measure the distance in
both directions.The opening of the gates will be indicated by the led.’Red’
means closed ’Green’ means open.

## Slot Allocation:
The slots will be visible in the LCD according to allocations of cars. If
’0’then there is no car indication and if ’X’ there is a car. This function is
working by using ultrasonic sensors in the respective parking slots.


## Fire Detection:
If any kind of fire/flame occurs then a fire alarm will be activated.This
system is executed by using flame sensor and buzzer

## Fire sprinkler System:
When Fire is detected the sprinkler system will be activated by using dc
motor consisting of a water supply system providing adequate pressure
and flow rate to a water distribution.

## Gas Detection:
If any kind of gas leakage occurs then a fire alarm will be activated.This
system is executed by using gas sensor and buzzer.

## Earthquake Detection:
During earthquake an alarm will be activated. This system is executed by
using vibration sensor and buzzer.

## Emergency Evacuation:
During any type of hazards like fire,earthquake,gas leakage etc both the
entrance and exit gates will automatically open.During this type the LCD
will also show an emergency message.

## Automated lighting system:
The lighting system of the parking lot will be automatically activated when
there is not enough sunlight.This will ensure proper lighting during night
time gloomy weather.Moreover there is an emergency light attached which
will work when there is any emergency situation like fire or earthquake
and the other lights will automatically turned off. This functionality is
implemented by using an LDR sensor.


# Difficulties:
Making all the sensors intercommunicate. Specially opening and closing
the entrance and exit gates while measuring the distance with the ultrasonic sensors. Setting the control variable values properly and changing
between iterations was a challenging part. Making the emergency situations run properly. Restarting the system after any emergency situation
comes to an end. Figuring out the best way to use the boolean variable
denoting whether the situation is normal or not was a bit difficult. Making
the sensor flipping servo motors work timely was also a challenging part.


# Future Work:
We will try to add more functionalities in this project such as we are
working with only 4 cars right now but in future we will increase the count
of the cars.Along with this we are thinking about implementing automated
ticketing system which may ensure the security of the parking lot.


# Conclusion:
After doing study on Parking lot Monitoring system project it is found
that this system can be introduced in our country and it will be beneficiary in the context of our country. There is less maintenance cost for
this system. It provides security to the parking ground. This system reduces the hassle in parking grounds and traffic jam.So in a way it is also





