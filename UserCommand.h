#ifndef USER_COMMAND_H
#define USER_COMMAND_H

#include <string>
#include <iostream>

#include "CPU.h"
#include "Memory.h"
#include "Devices.h"

using namespace std;

class UserCommand {
public:
   UserCommand() {}
   ~UserCommand() {}

   void commandIsA(string userCommand_);
   // Funtion to release disk when user input command D
   void releaseDisk(string userCommand_);
   // Function to request disk access
   void requestDiskAccess(string userCommand_);
   // Function to terminated current process running in CPU
   void terminateTheCurrentProcess();
   // Function to request access to a memory
   void requestMemoryAccess(string userCommand_);
   // Function to show details of certain device
   void showDetails(string userCommand_);

private:
   CPU CPU_;
   Memory Memory_;
   Devices Devices_;

   void commandSR ();
   void commandSI ();
   void commandSM ();
   // Function to create a new process
   void createNewProcess(string userCommand_, int& priorityLevel_);
};

#endif
