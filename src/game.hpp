#pragma once

#include <raylib.h>

#include <vector>

#include "block.hpp"
#include "grid.hpp"

class Game {
 private:
  Grid grid;
  std::vector<Block> blocks;
  std::vector<Block> GetAllBlocks();
  Block currentBlock;
  Block nextBlock;
  Block GetRandomBlock();

  void MoveBlockLeft();
  void MoveBlockRight();
  bool IsBlockOutside();
  void RotateBlock();
  void LockBlock();
  bool BlockFits();
  void Reset();
  void UpdateScore(int linesCleared, int moveDownPoints);
  Sound rotateSound;
  Sound clearSound;

 public:
  int score;
  bool gameOver;

  Game();
  ~Game();

  void Draw();
  void HandleInput();
  void MoveBlockDown();
  Music music;
};
