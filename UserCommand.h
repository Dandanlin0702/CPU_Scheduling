#ifndef USER_COMMAND_H
#define USER_COMMAND_H

#include <string>
#include <sstream>
#include <iostream>

#include "SystemManager.h"

using namespace std;

class UserCommand {
public:
   UserCommand() {}
   ~UserCommand() {}
   //
   // void getMemoryInfo() { systemManager_.getMemoryInfo(); }
   // void getDeviceInfo() { systemManager_.getDeviceInfo(); }
   void setMemoryInfo(unsigned int ramMemory, int pageSize, int numOfFrames);
   void setHardDiskInfo(int numberOfHardDisks);

   // Function for command A
   void commandIsA(string userCommand);
   // Funtion for command D - releaseDisk
   void commandIsD(string userCommand);
   // Function for d command - request disk access
   void commandIsd(string userCommand);
   // Function to terminated current process running in CPU
   void commandIsT();
   // Function to request access to a memory
   void commandIsM(string userCommand);
   // Function to show details of certain device
   void commandIsS(string userCommand);

private:
   SystemManager systemManager_;

   int currPID_ = 0, currPriorityLevel_ = 0;

   void commandIsSR ();
   void commandIsSI ();
   void commandIsSM ();
};

#endif
