#ifndef CPU_H
#define CPU_H

#include <iostream>
using namespace std;

class CPU {
public:
   CPU() {}
   ~CPU() {}


   void terminateTheCurrentProcess();

   // Functions for command 'S'
   void showCurrentProcess();
   void showProcessInReadyQueue();

};

#endif
