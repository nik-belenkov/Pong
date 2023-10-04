CPP=g++
CPPFLAGS=-c -Wall -Werror -Wextra

pong : pong.o
	$(CPP) pong.o -o ../build/pong

pong.o : pong.cpp
	$(CPP) $(CPPFLAGS) pong.cpp

pong_interactive : pong_interactive.o
	$(CPP) pong_interactive.o -o ../build/pong_interactive -lncurses

pong_interactive.o : pong_interactive.cpp
	$(CPP) $(CPPFLAGS) pong_interactive.cpp

clean :
	rm -rf *.o
	rm ../build/*