#include "Arduino.h"
#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle nh;
Servo servo;

void servo_cb(const std_msgs::UInt16& cmd_msg)
{
  servo.write(cmd_msg.data);
}

ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);

void setup()
{
  pinMode(8, OUTPUT);
  
  nh.initNode();
  nh.subscribe(sub);
  
  servo.attach(8);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
