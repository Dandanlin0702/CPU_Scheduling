#CPU Simulator

This term project is implemented by Dandan Lin for CSCI 340 (Operating System).

#Getting Started

##Compilation

''' $ make '''

##Running the tests

''' $./cpu '''

##Testing

Following are the commands you may use: '''

```
  1\. Q or q
     Exit
  Interrupts:
  2\. A <priority_level>
     Create a new process with priority of priorityLevel
     Ex: A 5 - Create a new process with priorityLevel of 5
  3\. D <hard_disk_number>
     Release a certain hard disk
     Ex: D 2 - Release hard disk 2
  4\. S r
     Show process is currently using CPU and processes are waiting for ready-queue
  5\. S i
     Show process is currently using Hard Disk and processes are waiting to use Hard Disk
  6\. S m
     Show memory state

  System Calls:
  7\. t
     Terminate process that currently uses the CPU
  8\. d <hard_disk_number> <file_name>
     Request a hard disk & read/write file
     Ex: d 2 testing - Current executing process is requesting access to hard disk 2 and wants to read/write testing file
  9\. m <memory_address>
     Request a memory operation
     Ex: m 16 - Current executing process requesting access to memoryaddress 16
```

'''

#!Important

Note: All the commands are strictly formatted

#Project including following:

##Header File:

CPU.h PCB.h Memory.h Devices.h StartApp.h SystemManager.h

##CPP File:

main.cpp CPU.cpp PCB.cpp Memory.cpp<br>
Devices.cpp StartApp.cpp SystemManager.cpp

##Compilation File:

makefile

##Documentations:

README.md

#Language

C++

#Authors

Dandan Lin @November 2017
