main: src/main.cpp
	mkdir build
	clang++ src/main.cpp -o build/rouge -I include/ -L lib/ -l raylib
