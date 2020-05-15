kings_nightmare: obj obj/main.o obj/Board.o obj/DFS.o obj/MakePath.o
	g++ -g -o kings_nightmare obj/main.o obj/Board.o obj/DFS.o obj/MakePath.o

obj/main.o: src/main.cpp inc/Board.hh inc/DFS.hh inc/MakePath.hh
	g++ -g -c -o obj/main.o src/main.cpp

obj/DFS.o: src/DFS.cpp inc/DFS.hh inc/GraphList.hh
	g++ -g -c -o obj/DFS.o src/DFS.cpp 

obj/Board.o: src/Board.cpp inc/Board.hh inc/Matrix.hh
	g++ -g -c -o obj/Board.o src/Board.cpp 

obj/MakePath.o: src/MakePath.cpp inc/MakePath.hh
	g++ -g -c -o obj/MakePath.o src/MakePath.cpp 

#obj/MinMax.o: src/MinMax.cpp inc/MinMax.hh inc/WinCondition.hh
#	g++ -g -c -o obj/MinMax.o src/MinMax.cpp 

