#ifndef DEVICES_H
#define DEVICES_H

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct HardDisk {
   int PID_;
   string fileName_;
   bool isOccupied_ = false;
};

class Devices {
public:
   Devices() {}
   ~Devices() {}

   void setHardDiskInfo(int numberOfHardDisks) { numberOfHardDisks_ = numberOfHardDisks; }

   void requestDiskAccess(int PID, int diskNumber, string fileName);
   void releaseDisk(int diskNumber);

/************************** User Input Command S **************************/
   // Show Process
   void showProcessInHardDisk();
   // Show processes are waiting to use the hard disk
   void showProcessInWaitingQueue(int hardDiskNumber);

private:
   int numberOfHardDisks_;
   vector<queue<HardDisk*>>hardDisk_;
};

#endif
