# Compilers options
C++_FLAG = -Wall -Werror `urg-config --cflags` `sdl-config --cflags`  `urg-config --libs` `sdl-config --libs` -lc -lpthread 

O_FILE = comManager.o argManager.o urgDriver.o urgDriverHelp.o urgException.o urgDriverCompute.o mainAppException.o mainAppDriver.o

hokuyoApp : src/mainApp.cpp $(O_FILE)
	g++ -o hokuyoapp.exe src/mainApp.cpp $(O_FILE)  $(C++_FLAG)

urgException.o : src/urgException.cpp
	g++ -o urgException.o -c src/urgException.cpp $(C++_FLAG)
	
mainAppException.o : src/mainAppException.cpp
	g++ -o mainAppException.o -c src/mainAppException.cpp $(C++_FLAG)

urgDriverCompute.o : src/urgDriverCompute.cpp
	g++ -o urgDriverCompute.o -c src/urgDriverCompute.cpp $(C++_FLAG)

urgDriverHelp.o : src/urgDriverHelp.cpp
	g++ -o urgDriverHelp.o -c src/urgDriverHelp.cpp $(C++_FLAG)

urgDriver.o : src/urgDriver.cpp
	g++ -o urgDriver.o -c src/urgDriver.cpp $(C++_FLAG)

comManager.o : src/comManager.cpp
	g++ -o comManager.o -c src/comManager.cpp $(C++_FLAG)

argManager.o : src/argManager.cpp
	g++ -o argManager.o -c src/argManager.cpp $(C++_FLAG)
	
mainAppDriver.o : src/mainAppDriver.cpp
	g++ -o mainAppDriver.o -c src/mainAppDriver.cpp $(C++_FLAG)

clean : 
	rm -f *.o
