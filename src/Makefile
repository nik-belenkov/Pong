CPP=g++
CPPFLAGS=-c -Wall -Werror -Wextra

pong : pong.o
	$(CPP) pong.o -o pong

pong.o : pong.cpp
	$(CPP) $(CPPFLAGS) pong.cpp

clean :
	rm -rf *.o
	rm pong