kings_nightmare: obj obj/main.o obj/Board.o obj/DFS.o obj/MakePath.o obj/AStar.o
	g++ -fsanitize=address -g -o kings_nightmare obj/main.o obj/Board.o obj/DFS.o obj/MakePath.o obj/AStar.o

obj/main.o: src/main.cpp inc/Board.hh inc/DFS.hh inc/MakePath.hh inc/AStar.hh
	g++ -fsanitize=address -g -c -o obj/main.o src/main.cpp

obj/DFS.o: src/DFS.cpp inc/DFS.hh inc/GraphList.hh
	g++ -fsanitize=address -g -c -o obj/DFS.o src/DFS.cpp 

obj/Board.o: src/Board.cpp inc/Board.hh inc/Matrix.hh
	g++ -fsanitize=address -g -c -o obj/Board.o src/Board.cpp 

obj/MakePath.o: src/MakePath.cpp inc/MakePath.hh
	g++ -fsanitize=address -g -c -o obj/MakePath.o src/MakePath.cpp 

obj/AStar.o: src/AStar.cpp inc/AStar.hh inc/GraphList.hh
	g++ -fsanitize=address -g -c -o obj/AStar.o src/AStar.cpp

