## CPU Simulator
   This term project is implemented by Dandan Lin for CSCI 340 (Operating System).

   This program uses preemptive priority scheduling.
   All I/O queues are FCFS.

## Getting Started
## Compilation
```
   $ make
```
## Running the tests
```
   $./cpu
```
## Testing
   Following are the commands you may use to test this program:

```
  1. H or h
     Show Help Menu

  2. Q or q
     Exit

  3. A <priority_level>
     Create a new process with priority of priorityLevel
     Example: A 5 - Create a new process with priorityLevel of 5

  4. D <hard_disk_number>
     Release a certain hard disk
     Example: D 2 - Release hard disk 2

  5. S r
     Show process is currently using CPU and processes are waiting for ready-queue

  6. S i
     Show process is currently using Hard Disk and processes are waiting to use Hard Disk

  7. S m
     Show memory state

  8. t
     Terminate process that currently uses the CPU

  9. d <hard_disk_number> <file_name>
     Request a hard disk & read/write file
     Example: d 2 testing - Current executing process is requesting access to hard disk 2 and wants to read/write testing file

  10. m <memory_address>
     Request a memory operation
     Example: m 16 - Current executing process requesting access to memoryaddress 16
```

## !Important
   Note: All the commands are strictly formatted

## Project including following:
   **Header File:**<br />
   CPU.h PCB.h Memory.h Devices.h StartApp.h SystemManager.h

   **CPP File:**<br />
   main.cpp CPU.cpp PCB.cpp Memory.cpp<br>
   Devices.cpp StartApp.cpp SystemManager.cpp

   **Compilation File:**<br />
   makefile

   **Documentations:**<br />
   README.md

## Language Used
   C++

## Data Structure Used
   Vector <br />
   Linked List <br />
   Unordered Map <br />
   Priority Queue <br />

## Authors
   Dandan Lin @December 4th, 2017
