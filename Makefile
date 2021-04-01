main:
	g++ -Wall -std=c++17 src/main.cpp src/models/*.cpp -o main

run:
	./main

clean:
	rm main