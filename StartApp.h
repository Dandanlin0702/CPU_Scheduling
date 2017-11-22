#ifndef STARTAPP_H
#define STARTAPP_H

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "UserCommand.h"

using namespace std;

class StartApp {
public:
   StartApp() {}
   ~StartApp() {}

   // Function to start the app
   void runApp();

private:
   UserCommand userCommand_;
   // Helper functions for user to check avaiable commands
   void helpMenu();
};

#endif
