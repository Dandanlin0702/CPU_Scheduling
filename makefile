CC = g++
LFLAGS = -std=c++11
CFLAGS = -c -Wall

EXECUTABLE_NAME = cpuScheduling
SOURCES = main.cpp CPU.cpp IO_Devices.cpp Memory.cpp Start_App.cpp User_Command.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJECTS)
	$(CC) -o $(EXECUTABLE_NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE_NAME)
