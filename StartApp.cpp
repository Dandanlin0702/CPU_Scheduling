#include "StartApp.h"

void StartApp::runApp() {
   string userCommand;

   unsigned int ramMemory = 0;
   int pageSize = 0, numberOfHardDisks = 0;

   cout << "How much RAM memory(in bytes) is there on the simulated computer? (Range from 1-4000000000) \n> ";
   cin >> ramMemory;

   while (ramMemory > 4000000000 || ramMemory <= 0) {
      cout << "Youe input is invalid, please enter again\n> ";
      cin >> ramMemory;
   }

   cout << "What is the size of your page/frame? \n> ";
   cin >> pageSize;

   while (pageSize < 0 || pageSize > ramMemory) {
      cout << "Youe pagesize is invalid, please enter again\n> ";
      cin >> pageSize;
   }

   cout << "How many hard disks the simulated computer has? \n> ";
   cin >> numberOfHardDisks;

   while (numberOfHardDisks < 0) {
      cout << "Youe input is invalid, please enter again\n> ";
      cin >> numberOfHardDisks;
   }

   int numOfFrames = ramMemory / pageSize;

   systemManager_.setMemoryInfo(ramMemory, pageSize, numOfFrames);
   systemManager_.setHardDiskInfo(numberOfHardDisks);

   cout << " Enter 'H' or 'h' for HELP \n"
        << " Enter 'Q' or 'q' to QUIT \n"
        << " Else, please enter command: \n";

   getline (cin, userCommand);
   do {
      cout << "> ";
      getline (cin, userCommand);

      if (userCommand.size() == 0) {
         cout << "No valid command received, please re-enter \n>";
         getline (cin, userCommand);
      }

      switch (userCommand.at(0)) {
         case 'Q':
         case 'q':
            cout << "Program terminatting .\n";
            exit(0);
            break;
         case 'H':
         case 'h':
            helpMenu();
            break;
         case 'A':
            commandIsA(userCommand);
            break;
         case 'D':
            commandIsD(userCommand);
            break;
         case 'd':
            commandIsd(userCommand);
            break;
         case 't':
            systemManager_.terminateTheCurrentProcess();
            break;
         case 'm':
            commandIsM(userCommand);
            break;
         case 'S':
            commandIsS(userCommand);
            break;
         default:
            cout << "Unknown user command (" << userCommand << ") invoked. \n"
                 << "All commands should be restrictly formatted. Enter \'H\' or \'h\' for help. \n" ;
            break;
      }

      cout << "\n";
   } while (true);
}

void StartApp::commandIsA(string userCommand) {
   stringstream ss;
   ss << userCommand;

   char commandType;
   int currPriorityLevel;

   int currPID = systemManager_.assignPID();

   ss >> commandType >> currPriorityLevel;
   if (currPriorityLevel < 1) {
      cout << "ERROR \n Please enter a valid priority level. \n";
   }

   systemManager_.setCurrPID(currPID, currPriorityLevel);
   // Allocate Memory for it's first page
   systemManager_.allocateMemoryForProcess(currPID, currPriorityLevel);
   // Decide action: put the ready queue or use CPU
   systemManager_.decideAction(currPID, currPriorityLevel);
}

void StartApp::commandIsD(string userCommand) {
   stringstream ss;
   int diskNumber_;
   char commandType_;

   ss << userCommand;
   ss >> commandType_ >> diskNumber_;

   systemManager_.releaseDisk(diskNumber_);
}

void StartApp::commandIsd(string userCommand) {
   stringstream ss;

   char commandType_;
   int diskNumber_;
   string fileName_;

   ss << userCommand;
   ss >> commandType_ >> diskNumber_ >> fileName_;

   if (fileName_ == "") {
      cout << "Error, please specify the file name. \n";
   }

   systemManager_.requestDiskAccess(diskNumber_, fileName_);
}

void StartApp::commandIsM(string userCommand) {
   stringstream ss;
   char commandType_;
   int memoryAddress_;

   ss << userCommand;
   ss >> commandType_ >> memoryAddress_;

   systemManager_.requestMemoryOperation(memoryAddress_);
}

void StartApp::commandIsS(string userCommand) {
   stringstream ss;
   char commandType_, commandDetail_;

   ss << userCommand;
   ss >> commandType_ >> commandDetail_;

   // Check is the command is S r
   if (commandDetail_ == 'r') {
      // When command is S r call commandSR() function
      systemManager_.showProcessInCPU();
      // systemManager_.showProcessInReadyQueue();
   } else if (commandDetail_ == 'i') {
      // When command is S i
      systemManager_.showProcessInHardDisk();
   } else if (commandDetail_ == 'm') {
      // When command is S m
      systemManager_.snapshotSystem();
   } else {
      cout << "Sorry you entered an unknown command or your command is not correctly formatted\n Please enter again.\n";
   }
}


void StartApp::helpMenu () {
   stringstream ss;
   ss << "Following are the commands you can use: \n"
      << "1. Exit:\n"
         << "\t\"Q\" or \"q\"\n"

      // Interrupts:
      << "2. Create a new process:\n"
         << "\t\"A <priority level>\"\n"
      << "3. Release hard disk:\n"
         << "\t\"D <hard disk number>\"\n"
      << "4. Show process is currently using CPU and processes are waiting for ready-queue:\n"
         << "\t\"S r\"\n"
      << "5. Show process is currently using Hard Disk and processes are waiting to use Hard Disk:\n"
         << "\t\"S i\"\n"
      << "6. Show memory state:\n"
         << "\t\"S m\"\n"

      // System Calls: Lower Case
      << "7. Terminate process that currently uses the CPU:\n"
         << "\t\"t\"\n"
      << "8. Request a hard disk & read/write file:\n"
         << "\t\"d <hard disk number> <file_name>\"\n"
      << "9. Request a memory operation:\n"
         << "\t\"m <memory address>\"\n";

   cout << ss.str();
}
