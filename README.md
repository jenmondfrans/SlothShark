SlothShark
==========

SlothShark with an interactive fin and evil eyes

What are my inputs? Flex sensor and analog input.
What are my outputs? Four servos and Two LEDs and One speaker

Set pin_mode directions.
Set up interrupts (when a signal goes low to high or high to low or changes state)

Void (loop)
main_loop_begin_time = micros() (set the start time of the loop)
call a routine (sub routine) that does all the stuff that measures the flex sensor
If my fin has been flicked then I'm going to call my routine of my flicked fin
If it hasn't been flicked, then I'm going to go and wait in my main loop control timer

My flicked fin routine: 
If it's within a band, then nothing happens
If it's outside of the range, then something happens

Something happens:
Turn on glowing LED eyeballs, the intensity is modulation by the degree of fin tweakage
Start the music
Start swimming
Control motors

*shrug*


