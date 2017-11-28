#include "Devices.h"

void Devices::requestDiskAccess(int PID, int diskNumber, string fileName) {
   HardDisk* tempHardDisk = new HardDisk;
   tempHardDisk->PID_ = PID;
   tempHardDisk->fileName_ = fileName;
   tempHardDisk->isOccupied_ = true;

   it = hardDiskQueue_.find(diskNumber);
   if (it != hardDiskQueue_.end()) {
      it->second.push(tempHardDisk);
   } else {
      queue<HardDisk*> tempDiskQueue;
      tempDiskQueue.push(tempHardDisk);

      hardDiskQueue_.insert(pair<int, queue<HardDisk*>>(diskNumber, tempDiskQueue));
   }
}

void Devices::releaseDisk(int diskNumber) {
   it = hardDiskQueue_.find(diskNumber);

   if (it == hardDiskQueue_.end()) {
      cout << "Oops, there's no processes are using the hard disk " << diskNumber << ". \n";
   } else {
      it->second.pop();

      if (!it->second.empty()) {
         cout << "Released Hard Disk #" << diskNumber
              << ".\nCurrent process using hard disk " << diskNumber << " is: \n\tProcess "
              << it->second.front()->PID_ << endl;
      } else {
         cout << "There's no process waiting to use hard disk #" << diskNumber << endl;
      }
   }
}

/***************************** Command S *****************************/
void Devices::showProcessInHardDisk() {
   unordered_map<int, queue<HardDisk*>>hardDiskQueueCopy;
   hardDiskQueueCopy = hardDiskQueue_;

   if (hardDiskQueueCopy.size() == 0) {
      cout << "No process is using the Hard Disk ATM. \n";
   } else {
      for (it = hardDiskQueueCopy.begin(); it != hardDiskQueueCopy.end(); ++it) {
         if (it->second.empty()) {
            cout << "No process in using Hard Disk #" << it->first << endl;
         } else {
            cout << "In Hard Disk #" << it->first
                 << ": \n\tProcess: " << it->second.front()->PID_
                 << " \n\tFile: " << it->second.front()->fileName_
                 << endl;

            it->second.pop();

            if (it->second.empty()) {
               cout << "No process is waiting for the Hard Disk # " << it->first << ". \n";
            } else {
               while (!it->second.empty()) {
                  if (it->second.front()->isOccupied_ == true) {
                     cout << "Waiting for Hard Disk #" << it->first << ": \n\tProcess " << it->second.front()->PID_ << " \n\tFilename: " << it->second.front()->fileName_ << endl;
                  }

                  it->second.pop();
               }
            }
         }

         showProcessInWaitingQueue(it);
      }
   }
}

void Devices::showProcessInWaitingQueue(unordered_map<int, queue<HardDisk*>>::iterator it) {
   queue<HardDisk*> tempDiskQueue;

   tempDiskQueue = it->second;
   while (!tempDiskQueue.empty()) {
      cout << "\tWaiting Queue "
           << it->first << ": \n"
           << "\t\tProcess: " << tempDiskQueue.front()->PID_
           << "\n \t\tFile Name: " << tempDiskQueue.front()->fileName_
           << endl;

      tempDiskQueue.pop();
   }
}
