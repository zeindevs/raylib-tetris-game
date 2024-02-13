#pragma once

#include <raylib.h>

#include <map>
#include <vector>

#include "position.hpp"

class Block {
 private:
  int cellSize;
  int rotationState;
  int columnOffset;
  int rowOffset;
  std::vector<Color> colors;

 public:
  int id;
  std::map<int, std::vector<Position>> cells;

  Block();

  void Draw(int offsetX, int offsetY);
  void Move(int rows, int columns);
  void Rotate();
  void UndoRotation();
  std::vector<Position> GetCellPositions();
};
