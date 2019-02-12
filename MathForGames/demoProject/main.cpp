#include "raylib.h"
#include "tank.h"
#include "turret.h"

int main()
{
	InitWindow(800, 450, "Demo Project");
	tank player;
	turret gun(&(player.transform));

	while (!WindowShouldClose())
	{
		player.update(GetFrameTime());
		gun.update(GetFrameTime());
		BeginDrawing();

		ClearBackground(RAYWHITE);
		player.draw();
		gun.draw();
		EndDrawing();
	}

	CloseWindow();
}