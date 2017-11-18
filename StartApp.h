#ifndef STARTAPP_H
#define STARTAPP_H

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "Memory.h"
#include "UserCommand.h"

using namespace std;

class StartApp {
public:
   StartApp() {}
   ~StartApp() {}

   // Function to get uer commands
   void runApp();

private:
   UserCommand userCommand_;

   // Functions for user to check commands
   string helpMenu();
};

#endif
