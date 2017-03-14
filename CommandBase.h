#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>
#include <WPILib.h>
#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/Drivebase.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Shooooooter.h"
#include "subsystems/Intake.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<Drivebase> driveBase;
	static std::unique_ptr<Climber> climber;
	static std::unique_ptr<Shooooooter> shooter;
	static std::unique_ptr<Intake> intake;
	static std::unique_ptr<OI> oi;
};

#endif  // COMMAND_BASE_H
