#include <ESP32Servo.h>
#include <ros.h>
#include <std_msgs/Int16MultiArray.h>


static const int servoPinPitch= 19;
static const int servoPinYaw= 18;

Servo servoP ,servoY;
unsigned long currentMillis;
long previousMillis = 0;    // set up timers
long interval = 20;        // time constant for timer(ms)
float desired_pitch,prev_pitch = 90 ,smoothed_pitch = 90,prev_desired_pitch=90;
float desired_yaw,prev_yaw = 90 ,smoothed_yaw = 90,prev_desired_yaw=90;

int pitch=90,yaw=90;

ros::NodeHandle  nh;


void servo_callback( const std_msgs::Int16MultiArray& cmd_msg){
  pitch = cmd_msg.data[1]; //y-axis
  yaw = cmd_msg.data[0]; //x-axis
  
  if (abs(prev_desired_pitch-pitch)>15)  //15 degree
    desired_pitch = pitch;
  if (abs(prev_desired_yaw-yaw)>15)  //15 degree
    desired_yaw = yaw;
  
  // servoP.write(smoothed_pitch);  // set servo angle
  // servoY.write(smoothed_yaw);  // set servo angle
}

ros::Subscriber<std_msgs::Int16MultiArray> sub("servo", servo_callback );

void setup()
{
  servoP.attach(servoPinPitch);
  servoY.attach(servoPinYaw);
  
  nh.initNode();
  nh.subscribe(sub);

}

void loop()
{
  // update this value every 20ms
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    smoothed_pitch = (0.04*desired_pitch + 0.96*prev_pitch);
    smoothed_yaw = (0.04*desired_yaw + 0.96*prev_yaw);

    prev_pitch = smoothed_pitch;
    prev_yaw = smoothed_yaw;

    previousMillis = currentMillis;
    if(abs(smoothed_pitch-pitch)<=2)
      prev_desired_pitch=pitch;
    if(abs(smoothed_yaw-yaw)<=2)
      prev_desired_yaw=yaw;

    servoP.write(smoothed_pitch);  // set servo angle
    servoY.write(smoothed_yaw);  // set servo angle    
  }
  
  nh.spinOnce();
  
}
