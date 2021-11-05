/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Ben Petterborg                                            */
/*    Created:      2021/11/05                                                */
/*    Description:  Speedbot Exponential Drivetrain                           */
/*                                                                            */
/*    Name: Ben Petterborg                                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor            motor         1               
// RightMotor           motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "math.h"

using namespace vex;

// left exponential drive function
int getLeftDriveSpeed (vex::directionType type, int percentage) 
{
  if (percentage>=0)
  {
    // when stationary, or going forwards, put the percentage in the exponential func
    return percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage; 
  }
  else
  {
    // when reversing, take the positive percentage, and put it in exponential func
    percentage = -percentage;
    percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage; 
    // when the new percentage val is calculated, make negative for backwards movement
    return percentage = -percentage;
  }
}

// right exponential drive function
int getRightDriveSpeed (vex::directionType type, int percentage) 
{
  if (percentage>=0)
  {
    // when stationary, or going forwards, put the percentage in the exponenential func
    return percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage; 
  }
  else
  {
    // when reversing, take the positive percentage, and put it in exponential func
    percentage = -percentage;
    percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage; 
    // when the new percentage val is calculated, make negative for backwards movement
    return percentage = -percentage;
  }
}


// main stuff
int main() 
{
  // don't delete, bad things happen
  vexcodeInit();

  // deadband stops motors from spinning if joysticks are close to zero
  int deadband = 5;

  while (true) 
  {
    // not quite sure what to do with this right now

    int leftMotorSpeed = getLeftDriveSpeed (vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value()));
    int rightMotorSpeed = getRightDriveSpeed (vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value()));


    // set left motor group speed
    if (abs(leftMotorSpeed) < deadband) 
    {
      // if less than deadband, set to zero
      LeftFrontMotor.setVelocity(0, percent);
      LeftRearMotor.setVelocity(0, percent);
    } 
    else 
    {
      LeftFrontMotor.setVelocity(leftMotorSpeed, percent);
      LeftRearMotor.setVelocity(leftMotorSpeed, percent);
    }

    // set right motor group speed
    if (abs(rightMotorSpeed) < deadband) 
    {
      RightFrontMotor.setVelocity(0, percent);
      RightRearMotor.setVelocity(0, percent);
    } 
    else
    {
      // set to rightMotorSpeed
      RightFrontMotor.setVelocity(rightMotorSpeed, percent);
      RightFrontMotor.setVelocity(rightMotorSpeed, percent);
    }

    // spin both motor groups forward
    LeftFrontMotor.spin(forward);
    LeftRearMotor.spin(forward);
    
    RightFrontMotor.spin(forward);
    RightRearMotor.spin(forward);

    wait(25, msec);

  }
}
