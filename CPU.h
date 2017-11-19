#ifndef CPU_H
#define CPU_H

#include <iostream>
using namespace std;

#include "Memory.h"

class CPU {
public:
   CPU() {}
   ~CPU() {}

   void terminateTheCurrentProcess();

   // Functions for command 'S'
   void showProcessInCPU();
   void showProcessInReadyQueue();

private:
   Memory Memory_;
   // This function will retrieve the PID number of the process in CPU
   int getProcessIdentifier();
};

#endif
