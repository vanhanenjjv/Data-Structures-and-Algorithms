CXX = g++

PROGRAM = gol
OBJECTS = \
	main.cc \
	console/console.o \
	game-of-life/game.o \
	game-of-life/terminal.o

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $@ $^
