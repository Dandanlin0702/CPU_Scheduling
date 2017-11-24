#include "Devices.h"

void Devices::requestDiskAccess(int PID, int diskNumber, string fileName) {
   cout << "Total disk num is :" << numberOfHardDisks_ << endl;

   if (diskNumber > numberOfHardDisks_) {
      cout << "Sorry you entered an invalid diskNumber, please try again \n";

      return;
   } else {
      HardDisk* tempHardDisk = new HardDisk;
      queue<HardDisk*> tempDiskQueue;

      cout << "Testing: curr process PID: " << PID << endl;
      tempHardDisk->PID_ = PID;
      tempHardDisk->fileName_ = fileName;
      tempHardDisk->isOccupied_ = true;

      tempDiskQueue.push(tempHardDisk);
      hardDisk_.push_back(tempDiskQueue);
   }
}

void Devices::releaseDisk(int diskNumber) {
   hardDisk_[diskNumber-1].pop();
}

/***************************** Command S *****************************/
void Devices::showProcessInHardDisk() {
   if (hardDisk_.size() == 0) {
      cout << "No process is using the Hard Disk ATM. \n";
   } else {
      for (int i = 0; i < hardDisk_.size(); ++i) {

         if (hardDisk_[i].empty()) {
            cout << "No process in using Hard Disk #" << i+1 << endl;
         } else {
            cout << "In Hard Disk #" << i+1
                 << ": \n\tProcess: " << hardDisk_[i].front()->PID_
                 << ": \n\tFile: " << hardDisk_[i].front()->fileName_
                 << endl;

            hardDisk_[i].pop();

            if (hardDisk_[i].empty()) {
               cout << "No process is waiting for the Hard Disk # " << i+1 << ". \n";
            } else if (hardDisk_[i].front()->isOccupied_ == true) {
               cout << "Hard Disk " << i+1 << ": process " << hardDisk_[i].front()->PID_ << endl;
            }
         }

         showProcessInWaitingQueue(i);
      }
   }
}

void Devices::showProcessInWaitingQueue(int hardDiskNumber) {
   queue<HardDisk*> tempDiskQueue;

   tempDiskQueue = hardDisk_[hardDiskNumber];
   while (!tempDiskQueue.empty()) {
      cout << "\tWaiting Queue "
           << hardDiskNumber+1 << ": \n"
           << "\t\tProcess: " << tempDiskQueue.front()->PID_
           << "\n \t\tFile Name: " << tempDiskQueue.front()->fileName_
           << endl;

      tempDiskQueue.pop();
   }
}
