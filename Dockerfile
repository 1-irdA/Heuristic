FROM gcc:latest

ADD . /app/

WORKDIR /app/

RUN g++ -Wall -std=c++17 src/main.cpp src/models/*.cpp -o main 

CMD ["./main"]