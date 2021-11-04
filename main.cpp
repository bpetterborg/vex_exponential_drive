// it makes the thing go brr

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftFrontMotor       motor         1               
// RightFrontMotor      motor         10              
// LeftRearMotor        motor         11              
// RightRearMotor       motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void setLeftDriveExpo (vex::directionType type, int percentage) 
    {
      if (percentage>=0)
      {
        // when stationary, or going forwards, put the percentage in the exponenential func
        percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage; 
      }
      else
      {
        // when reversing, take the positive percentage, and put it in exponential func
        percentage = -percentage;
        percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage; 
        // when the new percentage val is calculated, make negative for backwards movement
        percentage = -percentage;
      }

    }

void setRightDriveExpo (vex::directionType type, int percentage) 
    {
      if (percentage>=0)
      {
        // when stationary, or going forwards, put the percentage in the exponenential func
        percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage; 
      }
      else
      {
        // when reversing, take the positive percentage, and put it in exponential func
        percentage = -percentage;
        percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage; 
        // when the new percentage val is calculated, make negative for backwards movement
        percentage = -percentage;
      }

    }


int main() 
{
  // don't delete, bad things happen
  vexcodeInit();

  // deadband stops motors from spinning if joysticks are close to zero
  //int deadband = 5;

  while (true) 
  {
    // not quite sure what to do with this right now
    setLeftDriveExpo (vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value()));
    
    setRightDriveExpo (vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value()));

    /*

    // probably delete these???
    // (Axis3 + Axis1)
    int leftMotorSpeed =
        Controller1.Axis3.position() - Controller1.Axis1.position();
    
    
    // (Axis3 - Axis1)
    int rightMotorSpeed =
        Controller1.Axis3.position() - Controller1.Axis1.position();


    
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
    */

  }
}
