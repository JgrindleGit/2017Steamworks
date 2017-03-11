#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/Drivebase.h"
//#include "Subsystems/Intake.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Shooooooter.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<Drivebase> CommandBase::driveBase =
		std::make_unique<Drivebase>();

std::unique_ptr<Climber> CommandBase::climber =
		std::make_unique<Climber>();

std::unique_ptr<Shooooooter> CommandBase::shooter =
		std::make_unique<Shooooooter>();
/*std::unique_ptr<Intake> CommandBase::intake =
		std::make_unique<Intake>();*/

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
