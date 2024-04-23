#include <stdint.h>
#include <assert.h>

#include "raylib.h"
#include "Parameters.hh"
#include "Game_Frame.hh"
#include "Game_Logic.hh"

int main() {
	SetTargetFPS(FPS);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGTH, WINDOW_TITLE);

	Game_Frame *gf = new Game_Frame();
	gf->Scale(1.5);

	Game_Logic gl = Game_Logic();
	gl.Print_Board();

	//return 0;

	while (!WindowShouldClose()) {
		/// User
		if (IsKeyDown(KEY_MINUS)) {
			gf->Scale(1.0 - GAME_FRAME_SCALE);
		}
		if (IsKeyDown(KEY_EQUAL)) {
			gf->Scale(1.0 + GAME_FRAME_SCALE);
		}

		/// Render
		BeginDrawing();
		ClearBackground((Color){0, 0, 0, 255});
		DrawRectangle(gf->position.x + (float)GAME_FRAME_OFFSET_X, gf->position.y + (float)GAME_FRAME_OFFSET_Y, gf->width, gf->height, (Color){18, 18, 18, 255});
		EndDrawing();
		WaitTime(1.0/FPS);
	}
	CloseWindow();
	return 0;
}
