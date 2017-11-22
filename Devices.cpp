#include "Devices.h"

void Devices::getDeviceInfo() {
   cout << "How many hard disks the simulated computer has? \n> ";
   cin >> numberOfHardDisks_;

   while (numberOfHardDisks_ < 0) {
      cout << "Youe input is invalid, please enter again\n> ";
      cin >> numberOfHardDisks_;
   }
}

void Devices::requestDiskAccess(int diskNumber, string fileName) {
   cout << "Curr disk num is :" << numberOfHardDisks_ << endl;

   if (diskNumber > numberOfHardDisks_) {
      cout << "Sorry you entered an invalid diskNumber, please try again \n";

      return;
   } else {
      HardDisk* tempHardDisk = new HardDisk;

      tempHardDisk->PID_ = CPU_.getCurrPID();
      tempHardDisk->fileName_ = fileName;
      tempHardDisk->isOccupied_ = true;

      hardDisk_[diskNumber-1] = tempHardDisk;
   }

   CPU_.removeFromCPU();
}

void Devices::releaseDisk(int diskNumber) {

}

/****************Command S****************************************/
void Devices::showProcessInHardDisk() {
   if (hardDisk_.size() == 0) {
      cout << "No process is using the Hard Disk ATM. \n";
   } else {
      for (int i = 0; i < hardDisk_.size(); ++i) {
         if (hardDisk_[i]->isOccupied_ == true) {
            cout << "Hard Disk " << i << ": process " << hardDisk_[i]->PID_ << endl;

            showProcessInWaitingQueue(i);
         }
      }
   }
}

void Devices::showProcessInWaitingQueue(int hardDiskNumber) {

}

//For each busy hard disk show the process that uses it and show its I/O-queue. Make sure to display the filenames for each process.
void Devices::showIOQueue(int hardDiskNumber) {

}
// Get filename for process with PID number PID_
void Devices::getFileName(int PID) {

}
