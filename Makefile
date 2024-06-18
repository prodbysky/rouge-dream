main: src/main.cpp
	clang++ src/player.cpp src/main.cpp -o build/rouge -I include/ -L lib/ -l raylib
