#ifndef DEVICES_H
#define DEVICES_H

#include <iostream>
using namespace std;

class Devices {
public:
   Devices() {}
   ~Devices() {}

   void setUpReadyQueue(const int numberOfHardDisks_);
   void setUpIOQueue();
   // Add current process to ready queue
   void putInReadyQueue();


   //********************User Input Command S****************************//
   // show processes Currently using CPU
   void showProcessInCPU();
   // Show Process
   void showProcessInReadyQueue();
   // Shows processes are currently using the hard disks
   void showProcessInHardDisk();
   // Show processes are waiting to use the hard disk
   void showProcessInWaitingQueue();

private:
   void showIOQueue(int hardDiskNumber_);
   void getFileName(int PID_);

};

#endif
