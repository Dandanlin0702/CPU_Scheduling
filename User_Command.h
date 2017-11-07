#ifndef USER_COMMAND_H
#define USER_COMMAND_H

#include <string>
#include <iostream>

using namespace std;

class UserCommand {
public:
   // Function to create a new process
   void createNewProcess(string userCommand_);
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
   void commandSR ();
   void commandSI ();
   void commandSM ();
};

#endif
