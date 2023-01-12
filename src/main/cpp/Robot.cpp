// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  frc::SmartDashboard::PutNumber("Motor Speed 1", 0.0);
  frc::SmartDashboard::PutNumber("Motor Speed 2", 0.0);
  frc::SmartDashboard::PutNumber("Motor Speed Follower", 0.0);
  frc::SmartDashboard::PutBoolean("Follower", false);
  //motor inversé
  frc::SmartDashboard::PutBoolean("Motor 1 inversé", false);
  frc::SmartDashboard::PutBoolean("Motor 2 inversé", false);
}
void Robot::TeleopPeriodic() {

  if (frc::SmartDashboard::GetBoolean("Motor 1 inversé", false)) {
    m_motor.SetInverted(true);
  } else {
    m_motor.SetInverted(false);
  }

  if (frc::SmartDashboard::GetBoolean("Motor 2 inversé", false)) {
    m_motor2.SetInverted(true);
  } else {
    m_motor2.SetInverted(false);
  }

  if (frc::SmartDashboard::GetBoolean("Follower", false)) {
    m_motor.Set(frc::SmartDashboard::GetNumber("Motor Speed Follower", 0.0));
    m_motor2.Set(frc::SmartDashboard::GetNumber("Motor Speed Follower", 0.0));
  } else {
    m_motor.Set(frc::SmartDashboard::GetNumber("Motor Speed 1", 0.0));
    m_motor2.Set(frc::SmartDashboard::GetNumber("Motor Speed 2", 0.0));
  }
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
