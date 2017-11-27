#ifndef STARTAPP_H
#define STARTAPP_H

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "SystemManager.h"

using namespace std;

class StartApp {
public:
   StartApp() {}
   ~StartApp() {}

   // Function to start the app
   void runApp();

private:
   SystemManager systemManager_;

   void setMemoryInfo(unsigned int ramMemory, int pageSize, int numOfFrames);
   void setHardDiskInfo(int numberOfHardDisks);

   // Function for command A
   void commandIsA(string userCommand);
   // Funtion for command D - releaseDisk
   void commandIsD(string userCommand);
   // Function for d command - request disk access
   void commandIsd(string userCommand);
   // Function to request access to a memory
   void commandIsM(string userCommand);
   // Function to show details of certain device
   void commandIsS(string userCommand);

   // Helper functions for user to check avaiable commands
   void helpMenu();
};

#endif
