#include "UserCommand.h"

void UserCommand::setMemoryInfo(unsigned int ramMemory, int pageSize) {
   commandManager_.setMemoryInfo(ramMemory, pageSize);
}
void UserCommand::setHardDiskInfo(int numberOfHardDisks) {
   commandManager_.setHardDiskInfo(numberOfHardDisks);
}

void UserCommand::commandIsA(string userCommand) {
   stringstream ss;
   ss << userCommand;

   char commandType;
   int priorityLevel = 0;
   int PID = commandManager_.assignPID();

   ss >> commandType >> priorityLevel;
   if (priorityLevel < 1) {
      cout << "ERROR \n Please enter a valid priority level. \n";
   }

   // Allocate Memory for it's first page
   commandManager_.allocateMemoryForProcess(PID, priorityLevel);
   // Decide action: put the ready queue or use CPU
   commandManager_.decideAction(PID, priorityLevel);
}

void UserCommand::commandIsD(string userCommand) {
   stringstream ss;
   int diskNumber_;
   char commandType_;

   ss << userCommand;
   ss >> commandType_ >> diskNumber_;

   commandManager_.releaseDisk(diskNumber_);
}

void UserCommand::commandIsd(string userCommand) {
   stringstream ss;
   int diskNumber_;
   char commandType_;
   string fileName_;

   ss << userCommand;
   ss >> commandType_ >> diskNumber_ >> fileName_;

   commandManager_.requestDiskAccess(diskNumber_, fileName_);
}

void UserCommand::commandIsT() {
   commandManager_.terminateTheCurrentProcess();
}

void UserCommand::commandIsM(string userCommand) {
   stringstream ss;
   char commandType_;
   int memoryAddress_;

   ss << userCommand;
   ss >> commandType_ >> memoryAddress_;

   int PID_ = commandManager_.getCurrPID();

   commandManager_.setMemoryAddress(memoryAddress_);
   commandManager_.requestMemoryOperation(PID_);
}

void UserCommand::commandIsS(string userCommand) {
   stringstream ss;
   char commandType_, commandDetail_;

   ss << userCommand;
   ss >> commandType_ >> commandDetail_;

   // Check is the command is S r
   if (commandDetail_ == 'r') {
      // When command is S r call commandSR() function
      commandIsSR();
   } else if (commandDetail_ == 'i') {
      // When command is S i
      commandIsSI();
   } else if (commandDetail_ == 'm') {
      // When command is S m
      commandIsSM();
   } else {
      cout << "Sorry you entered an unknown command or your command is not correctly formatted\n Please enter again\n";
   }

   return;
}

/**************** Private Member Function for Command S ***********/
// Function to show
   // 1. what process is currently using the cpu
   // 2. What processed are waiting in the ready-queue
void UserCommand::commandIsSR () {
   commandManager_.showProcessInCPU();
   commandManager_.showProcessInReadyQueue();
}

// Function to show
   // 1. What processes are currently using the hard disks
   // 2. What processes are waiting to use the hard disk
   // For each busy hard disk show the process that uses it and show its I/O-queue. Make sure to display the filenames for each process.
void UserCommand::commandIsSI () {
   commandManager_.showProcessInHardDisk();
}

/***************** Memory Related Actions *************************/
void UserCommand::commandIsSM () {
   commandManager_.snapshotSystem();
}
