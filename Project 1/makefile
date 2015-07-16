main:	main.o Screen.o Map.o Snake.o
	g++ -o main main.o Screen.o Map.o Snake.o -lncurses
main.o:	main.cpp SM.h Screen.h header.h
	g++ -c main.cpp

Screen.o:	Screen.cpp Screen.h header.h
	g++ -c Screen.cpp

Snake.o:	Snake.cpp SM.h header.h
	g++ -c Snake.cpp

Map.o:	Map.cpp SM.h header.h
	g++ -c Map.cpp

clean: 
	rm *.o -rf


#sc:
#	vi Screen.cpp
#s:	
#	vi Snake.cpp
#m:	
#	vi Map.cpp
#sch:
#	vi Screen.h
#sm:
#	vi SM.h
#h:
#	vi header.h
#game:
#	vi main.cpp
#help:
#	@echo sc   開啟 Screen.cpp
#	@echo s    開啟 Snake.cpp
#	@echo m    開啟 Map.cpp
#	@echo sch  開啟 Screen.h
#	@echo sm   開啟 SM.h
#	@echo h    開啟 header.h
#	@echo game 開啟 main.cpp
