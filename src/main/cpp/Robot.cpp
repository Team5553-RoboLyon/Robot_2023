// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {

  double y = m_accelerometer.GetY()*9.806; // -1/1
  double z = m_accelerometer.GetZ()*9.806; // -1/1

  double angle = atan2(y, z) * 180 / M_PI;

  double output = m_pidController.Calculate(angle, 0);

  m_MotorRight.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, output);
  m_MotorRightFollower.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, output);
  m_MotorRightFollower2.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, output);
  m_MotorLeft.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -output);

}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
