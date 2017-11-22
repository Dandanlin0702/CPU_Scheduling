#ifndef DEVICES_H
#define DEVICES_H

#include <vector>
#include <iostream>
using namespace std;

#include "CPU.h"

struct HardDisk {
   int PID_;
   string fileName_;
   bool isOccupied_ = false;
};

class Devices {
public:
   Devices() {}
   Devices(int numberOfHardDisks):numberOfHardDisks_(numberOfHardDisks), hardDisk_(numberOfHardDisks_, nullptr) {}
   ~Devices() {}

   void requestDiskAccess(int diskNumber, string fileName);
   void releaseDisk(int diskNumber);


/******************** User Input Command S ****************************/
   // Show Process
   void showProcessInHardDisk();
   // Show processes are waiting to use the hard disk
   void showProcessInWaitingQueue(int hardDiskNumber);

private:
   CPU CPU_;

   int numberOfHardDisks_;
   vector<HardDisk*>hardDisk_;

   void showIOQueue(int hardDiskNumber);
   void getFileName(int PID);
};

#endif
