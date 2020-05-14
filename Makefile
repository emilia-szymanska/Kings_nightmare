kings_nightmare: obj obj/main.o obj/Board.o
	g++ -g -o kings_nightmare obj/main.o obj/Board.o 

obj/main.o: src/main.cpp inc/Board.hh
	g++ -g -c -o obj/main.o src/main.cpp

#obj/GameManagement.o: src/GameManagement.cpp inc/GameManagement.hh inc/MinMax.hh
#	g++ -g -c -o obj/GameManagement.o src/GameManagement.cpp 

#obj/MinMax.o: src/MinMax.cpp inc/MinMax.hh inc/WinCondition.hh
#	g++ -g -c -o obj/MinMax.o src/MinMax.cpp 

#obj/WinCondition.o: src/WinCondition.cpp inc/WinCondition.hh inc/Board.hh
#	g++ -g -c -o obj/WinCondition.o src/WinCondition.cpp 

obj/Board.o: src/Board.cpp inc/Board.hh inc/Matrix.hh
	g++ -g -c -o obj/Board.o src/Board.cpp 
