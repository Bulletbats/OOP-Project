CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp Game.cpp Level.cpp Player.cpp Enemy.cpp Item.cpp CombatSystem.cpp BossEnemy.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
