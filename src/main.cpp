#include <raylib.h>

#include <cstdio>

#include "colors.hpp"
#include "game.hpp"

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main() {
  InitWindow(500, 620, "Tetris Game!");
  SetTargetFPS(60);

  // Font font = LoadFontEx("font/Montserrat-Bold.ttf", 64, 0, 0);
  Font font  = GetFontDefault();

  Game game = Game();

  while (WindowShouldClose() == false) {
    UpdateMusicStream(game.music);

    game.HandleInput();
    if (EventTriggered(0.2)) {
      game.MoveBlockDown();
    }

    BeginDrawing();

    ClearBackground(darkBlue);
    DrawTextEx(font, "Score", {365, 15}, 28, 2, WHITE);
    DrawTextEx(font, "Next", {375, 175}, 28, 2, WHITE);
    if (game.gameOver) {
      DrawTextEx(font, "GAME OVER", {320, 450}, 30, 2, WHITE);
    }
    DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

    char scoreText[10];
    sprintf(scoreText, "%d", game.score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 30, 2);

    DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 70}, 30, 2, WHITE);
    DrawRectangleRounded({320, 215, 170, 120}, 0.3, 6, lightBlue);
    game.Draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
