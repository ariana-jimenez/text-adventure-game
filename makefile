# Final Project Makefile

PROJ = FinalProject_Jimenez_Ariana
CXX = g++ -std=c++0x
CXXFLAGS = -g

SRC  = main.cpp
SRC += Space.cpp Scene1.cpp Scene2.cpp Scene3.cpp Scene4.cpp Scene5.cpp Scene6.cpp
SRC += validate1.cpp validate2.cpp validate3.cpp validate4.cpp
SRC += Node.cpp Queue.cpp
SRC += menu.cpp Game.cpp displayImage.cpp

OBJ = $(SRC:.cpp=.o)

output: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

valgrind:
	@valgrind --leak-check=full --track-origins=yes ./output

zip:
	zip -D $(PROJ).zip *.cpp *.hpp *.txt makefile

clean:
	rm *.o output

