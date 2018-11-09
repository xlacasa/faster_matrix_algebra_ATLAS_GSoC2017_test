OPTIONS = -std=c++11

all: main.exe debug.exe
	
main.exe: main.cc
	g++ main.cc -o main.exe $(OPTIONS)

debug.exe: debug.cc
	g++ debug.cc -o debug.exe $(OPTIONS)

clean:
	rm *.exe
