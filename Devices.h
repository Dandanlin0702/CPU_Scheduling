#ifndef DEVICES_H
#define DEVICES_H

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct HardDisk {
   int PID_;
   int priorityLevel_;

   string fileName_;
   bool isOccupied_ = false;
};

class Devices {
public:
   Devices() {}
   ~Devices() {}

   // Set up hard disk info
   void setHardDiskInfo(int numberOfHardDisks) { numberOfHardDisks_ = numberOfHardDisks; }

   // Functions:
   //    1. Request disk access
   //    2. Release a hard disk
   void requestDiskAccess(int PID, int priorityLevel, int diskNumber, string fileName);
   void releaseDisk(int diskNumber, int& PID, int& priorityLevel);

   // Show Process in Hard Disk
   void showProcessInHardDisk();

private:
   int numberOfHardDisks_;

   unordered_map<int, queue<HardDisk*>>hardDiskQueue_;
   unordered_map<int, queue<HardDisk*>>::iterator it;
};

#endif
