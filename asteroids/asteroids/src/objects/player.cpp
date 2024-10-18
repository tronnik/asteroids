#include "player.h"
#include <math.h>  
#include "utils.h"

const float DECELERATION_RATE = 400.0f; 
const float ACCELERATION_RATE = 1000.0f;
Player player;

void initPlayer(Player& p) 
{
    p.position = { static_cast<float>(screenWidth) / 2.0f, static_cast<float>(screenHeight) / 2.0f };
    p.speed = { 0.0f, 0.0f };
    p.acceleration = { 0.0f, 0.0f };
    p.maxSpeed = 600.0f;  
    p.width = 30.0f;
    p.height = 30.0f;
    p.angle = 0.0f;  
}

void updatePlayer(Player& p) 
{
    Vector2 mousePosition = GetMousePosition();
    Vector2 direction = { mousePosition.x - p.position.x, mousePosition.y - p.position.y }; 

    float magnitude = sqrtf(direction.x * direction.x + direction.y * direction.y);

    if (magnitude != 0.0f) 
    {
        p.angle = atan2f(direction.y, direction.x) * (180.0f / PI); 

        Vector2 directionNormalized = { direction.x / magnitude, direction.y / magnitude };

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) 
        {
            p.acceleration.x = directionNormalized.x * ACCELERATION_RATE; 
            p.acceleration.y = directionNormalized.y * ACCELERATION_RATE;
        }
        else 
        {
            p.acceleration.x = 0.5f;
            p.acceleration.y = 0.5f;
        }
    }
    

    p.speed.x += p.acceleration.x * GetFrameTime();
    p.speed.y += p.acceleration.y * GetFrameTime();

    float speedMagnitude = sqrtf(p.speed.x * p.speed.x + p.speed.y * p.speed.y);
    if (speedMagnitude > p.maxSpeed) 
    {
        Vector2 speedNormalized = { p.speed.x / speedMagnitude, p.speed.y / speedMagnitude };
        p.speed.x = speedNormalized.x * p.maxSpeed;
        p.speed.y = speedNormalized.y * p.maxSpeed;
    }

    if (p.position.x < static_cast<float>(screenWidthMin))
    {
        p.position.x = static_cast<float>(screenWidth);
    }

    if (p.position.x > static_cast<float>(screenWidth))
    {
        p.position.x = static_cast<float>(screenWidthMin);
    }

    if (p.position.y < static_cast<float>(screenHeightMin))
    {
        p.position.y = static_cast<float>(screenHeight);
    }

    if (p.position.y > static_cast<float>(screenHeight))
    {
        p.position.y = static_cast<float>(screenHeightMin);
    }

    p.position.x += p.speed.x * GetFrameTime();
    p.position.y += p.speed.y * GetFrameTime();
}

void drawPlayer(Player& p) 
{
    DrawRectanglePro(Rectangle{ p.position.x, p.position.y , p.width, p.height }, Vector2{ p.width / 2, p.height / 2 }, p.angle, RED);
}





