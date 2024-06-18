main: src/main.cpp
	clang++ src/utils.cpp src/bullet.cpp src/player.cpp src/main.cpp -o build/rouge -I include/ -L lib/ -l raylib
