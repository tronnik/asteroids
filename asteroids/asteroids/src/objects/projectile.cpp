#include "projectile.h"
#include "utils.h"

Projectile projectiles[maxProjectiles];
int projectileCount = 0;
Texture2D ammoShoot;


void fire(Player& p)
{
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) && projectileCount < maxProjectiles)
    {
        projectiles[projectileCount].position = p.position;
        projectiles[projectileCount].direction = p.directionNormalized;
        projectiles[projectileCount].speed = p.ammoSpeed;
        //projectiles[projectileCount].radius = 5.0f;
        projectiles[projectileCount].isActive = true;

        projectileCount++;

        ammoShoot = LoadTexture("res/shoot.png");
    }
}

void updateProjectiles()
{
    for (int i = 0; i < projectileCount; i++)
    {
        if (projectiles[i].isActive)
        {
            projectiles[i].position.x += projectiles[i].direction.x * projectiles[i].speed * GetFrameTime();
            projectiles[i].position.y += projectiles[i].direction.y * projectiles[i].speed * GetFrameTime();

            if (projectiles[i].position.x < 0 || projectiles[i].position.x > screenWidth ||
                projectiles[i].position.y < 0 || projectiles[i].position.y > screenHeight)
            {
                projectiles[i].isActive = false;
            }
        }
    }
}


void drawProjectiles()
{
    for (int i = 0; i < projectileCount; i++)
    {
        if (projectiles[i].isActive)
        {
            float scale = 2.0f;

            //DrawCircle(static_cast<int>(projectiles[i].position.x), static_cast<int>(projectiles[i].position.y), 5.0f, RED);
           // DrawTextureEx(ammoShoot, { projectiles[i].position.x , projectiles[i].position.y  }, 0.0f, scale, WHITE);

            DrawTextureEx(ammoShoot, { projectiles[i].position.x - (projectiles[i].radius * scale) / 2, projectiles[i].position.y - (projectiles[i].radius * scale) / 2 }, 0.0f, scale, WHITE);
        }
    }
}

