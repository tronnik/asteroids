#include "projectile.h"
#include "utils.h"

Projectile projectiles[maxProjectiles];
int projectileCount = 0;

void shoot(Player& p)
{
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) && projectileCount < maxProjectiles)
    {
        projectiles[projectileCount].position = p.position;
        projectiles[projectileCount].direction = p.directionNormalized;
        projectiles[projectileCount].speed = p.ammoSpeed;
        projectiles[projectileCount].active = true;

        projectileCount++;
    }
}

void updateProjectiles()
{
    for (int i = 0; i < projectileCount; i++)
    {
        if (projectiles[i].active)
        {
            projectiles[i].position.x += projectiles[i].direction.x * projectiles[i].speed * GetFrameTime();
            projectiles[i].position.y += projectiles[i].direction.y * projectiles[i].speed * GetFrameTime();

            if (projectiles[i].position.x < 0 || projectiles[i].position.x > screenWidth ||
                projectiles[i].position.y < 0 || projectiles[i].position.y > screenHeight)
            {
                projectiles[i].active = false;
            }
        }
    }
}


void drawProjectiles()
{
    for (int i = 0; i < projectileCount; i++)
    {
        if (projectiles[i].active)
        {
            DrawCircle(static_cast<int>(projectiles[i].position.x), static_cast<int>(projectiles[i].position.y), 5.0f, RED);
        }
    }
}
