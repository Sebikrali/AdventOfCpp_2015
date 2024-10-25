CFLAGS = -std=c++17 -O2
LDFLAGS = 

all: run

run: merry
	out/christmas

merry: main.cpp
	g++ $(CFLAGS) -o out/christmas $^ $(LDFLAGS)

clean: 
	rm -rf out/christmas
