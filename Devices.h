#ifndef DEVICES_H
#define DEVICES_H

#include <iostream>
using namespace std;

class Devices {
public:
   Devices() {}
   ~Devices() {}










   void setUpReadyQueue();
   void setUpIOQueue();

   void releaseDisk(int diskNumber);
   // Add current process to ready queue
   void putInReadyQueue(int priorityLevel, int PID);

   void requestDiskAccess(int diskNumber, string fileName);

/******************** User Input Command S ****************************/
   // Show Process
   void showProcessInReadyQueue();
   // Shows processes are currently using the hard disks
      // For each busy hard disk show the process that uses it and show its I/O-queue. Make sure to display the filenames for each process.
   void showProcessInHardDisk();
   // Show processes are waiting to use the hard disk
   void showProcessInWaitingQueue();

private:


   void showIOQueue(int hardDiskNumber);
   void getFileName(int PID);
};

#endif
