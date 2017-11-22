#ifndef USER_COMMAND_H
#define USER_COMMAND_H

#include <string>
#include <sstream>
#include <iostream>

#include "Devices.h"

using namespace std;

class UserCommand {
public:
   UserCommand() {}
   ~UserCommand() {}

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
   CPU CPU_;
   PCB PCB_;
   Memory Memory_;
   Devices Devices_;

   void commandIsSR ();
   void commandIsSI ();
   void commandIsSM ();
};

#endif
