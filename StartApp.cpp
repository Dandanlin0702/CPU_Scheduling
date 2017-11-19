#ifndef STARTAPP_CPP
#define STARTAPP_CPP

#include "StartApp.h"

void StartApp::runApp() {
   // Variable to store user commands
   string userCommand;

   long int ramMemory = 0;
   int pageSize = 0, numberOfHardDisks = 0;

   cout << "How much RAM memory(in bytes) is there on the simulated computer? (Range from 1-4000000000) \n> ";
   cin >> ramMemory;

   while (ramMemory > 4000000000 || ramMemory <= 0) {
      cout << "Youe input is invalid, please enter again\n> ";
      cin >> ramMemory;
   }

   cout << "What is the size of a page/frame? \n> ";
   cin >> pageSize;

   while (pageSize < 0 || pageSize >= ramMemory) {
      cout << "Youe pagesize is invalid, please enter again\n> ";
      cin >> pageSize;
   }

   cout << "How many hard disks the simulated computer has? \n> ";
   cin >> numberOfHardDisks;

   while (numberOfHardDisks < 0) {
      cout << "Youe input is invalid, please enter again\n> ";
      cin >> numberOfHardDisks;
   }

   Memory memorySystem_ = Memory(ramMemory, pageSize, numberOfHardDisks);

   cout << "Enter 'H' or 'h' for HELP \n"
        << "Enter 'Q' or 'q' to QUIT \n"
        << "Else, please enter command: \n";

   getline (cin, userCommand);
   // While loop keeps reading user's input
   do {
      cout << ">> ";
      getline (cin, userCommand);

      if (userCommand.size() == 0) {
         cout << "No valid command received, please re-enter \n>>";
         getline (cin, userCommand);
      }

      if (userCommand.at(0) == 'Q' || userCommand.at(0) == 'q') {
         cout << "Program terminatting";
         exit(0);
      } else if (userCommand.at(0) == 'H' || userCommand.at(0) == 'h') {
         string menu = helpMenu();
         cout << menu << endl;
      } else if (userCommand.at(0) == 'A' && userCommand.at(1) == ' ') {
         userCommand_.commandIsA(userCommand);
      } else if (userCommand.at(0) == 'D' && userCommand.at(1) == ' ') {
         userCommand_.releaseDisk(userCommand);
      } else if (userCommand.at(0) == 'd' && userCommand.at(1) == ' ') {
         userCommand_.requestDiskAccess(userCommand);
      } else if (userCommand.at(0) == 't') {
         userCommand_.terminateTheCurrentProcess();
      } else if (userCommand.at(0) == 'm' && userCommand.at(1) == ' ') {
         userCommand_.requestMemoryAccess(userCommand);
      } else if (userCommand.at(0) == 'S' && userCommand.at(1) == ' ') {
         userCommand_.showDetails(userCommand);
      } else {
         cout << "Unknown user command (" << userCommand << ") invoked. \n"
              << "All commands should be restrictly formatted. Enter \'H\' or \'h\' for help. \n" ;
      }
      cout << "\n";
   } while (true);
}

string StartApp::helpMenu () {
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

   return ss.str();
}

#endif
