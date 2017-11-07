#ifndef START_APP_H
#define START_APP_H

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

class StartApp {
public:
   StartApp();
   ~StartApp();

   // Function to get uer commands
   void runApp();
   // Functions for user to check commands
   string helpMenu();

private:
   // Function to set up system
   void setUpSystem(int pageSize_, int numberOfHardDisks_);
};

#endif
