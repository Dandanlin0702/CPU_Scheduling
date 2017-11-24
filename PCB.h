#ifndef PCB_H
#define PCB_H

#include <iostream>
using namespace std;

class PCB {
public:
   // Create PCB for process starts from 1
   int assignPID() { PID_+= 1; return PID_; }
   // Function to obtain the Process indentifier
   int getPID() { return PID_; }

private:
   int PID_ = 0;
};

#endif
