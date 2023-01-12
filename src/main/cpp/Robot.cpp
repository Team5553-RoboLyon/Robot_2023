// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  frc::SmartDashboard::PutNumber("SpeedIntake1", 0);
  frc::SmartDashboard::PutNumber("SpeedIntake2", 0);
  frc::SmartDashboard::PutNumber("SpeedConvoyeur1", 0);
  frc::SmartDashboard::PutNumber("SpeedConvoyeur2", 0);
  frc::SmartDashboard::PutNumber("SpeedIntakeFollower", 0);
  frc::SmartDashboard::PutNumber("SpeedConvoyeurFollower", 0);
  frc::SmartDashboard::PutBoolean("IntakeFollower", false);
  frc::SmartDashboard::PutBoolean("ConvoyeurFollower", false);
  frc::SmartDashboard::PutBoolean("Invert_Intake_Motor1", false);
  frc::SmartDashboard::PutBoolean("Invert_Intake_Motor2", false);
  frc::SmartDashboard::PutBoolean("Invert_Convoyeur_Motor1", false);
  frc::SmartDashboard::PutBoolean("Invert_Convoyeur_Motor2", false);

  m_MotorIntake1.SetInverted(frc::SmartDashboard::GetBoolean("Invert_Intake_Motor1", false));
  m_MotorIntake2.SetInverted(frc::SmartDashboard::GetBoolean("Invert_Intake_Motor2", false));
  m_MotorConvoyeur1.SetInverted(frc::SmartDashboard::GetBoolean("Invert_Convoyeur_Motor1", false));
  m_MotorConvoyeur2.SetInverted(frc::SmartDashboard::GetBoolean("Invert_Convoyeur_Motor2", false));


}
void Robot::TeleopPeriodic() {
  //get speed from dashboard
  double SpeedIntake1 = frc::SmartDashboard::GetNumber("SpeedIntake1", 0);
  double SpeedIntake2 = frc::SmartDashboard::GetNumber("SpeedIntake2", 0);
  double SpeedConvoyeur1 = frc::SmartDashboard::GetNumber("SpeedConvoyeur1", 0);
  double SpeedConvoyeur2 = frc::SmartDashboard::GetNumber("SpeedConvoyeur2", 0);
  double SpeedIntakeFollower = frc::SmartDashboard::GetNumber("SpeedIntakeFollower", 0);
  double SpeedConvoyeurFollower = frc::SmartDashboard::GetNumber("SpeedConvoyeurFollower", 0);
  bool IntakeFollower = frc::SmartDashboard::GetBoolean("IntakeFollower", false);
  bool ConvoyeurFollower = frc::SmartDashboard::GetBoolean("ConvoyeurFollower", false);
  bool Invert_Intake_Motor1 = frc::SmartDashboard::GetBoolean("Invert_Intake_Motor1", false);
  bool Invert_Intake_Motor2 = frc::SmartDashboard::GetBoolean("Invert_Intake_Motor2", false);
  bool Invert_Convoyeur_Motor1 = frc::SmartDashboard::GetBoolean("Invert_Convoyeur_Motor1", false);
  bool Invert_Convoyeur_Motor2 = frc::SmartDashboard::GetBoolean("Invert_Convoyeur_Motor2", false);
  
  //set speed to motor
  if (IntakeFollower) {
    m_MotorIntake1.Set(SpeedIntakeFollower);
    m_MotorIntake2.Set(SpeedIntakeFollower);
  } else {
    m_MotorIntake1.Set(SpeedIntake1);
    m_MotorIntake2.Set(SpeedIntake2);
  }

  if (ConvoyeurFollower) {
    m_MotorConvoyeur1.Set(SpeedConvoyeurFollower);
    m_MotorConvoyeur2.Set(SpeedConvoyeurFollower);
  } else {
    m_MotorConvoyeur1.Set(SpeedConvoyeur1);
    m_MotorConvoyeur2.Set(SpeedConvoyeur2);
  }

  //set invert motor
  if (Invert_Intake_Motor1 != m_MotorIntake1.GetInverted()) {
    m_MotorIntake1.SetInverted(Invert_Intake_Motor1);
  }
  if (Invert_Intake_Motor2 != m_MotorIntake2.GetInverted()) {
    m_MotorIntake2.SetInverted(Invert_Intake_Motor2);
  }

  if (Invert_Convoyeur_Motor1 != m_MotorConvoyeur1.GetInverted()) {
    m_MotorConvoyeur1.SetInverted(Invert_Convoyeur_Motor1);
  }
  if (Invert_Convoyeur_Motor2 != m_MotorConvoyeur2.GetInverted()) {
    m_MotorConvoyeur2.SetInverted(Invert_Convoyeur_Motor2);
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
