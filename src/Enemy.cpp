#include "Enemy.hpp"

Enemy::Enemy()
: Entity()
{
}

Enemy::~Enemy()
{
}

void Enemy::load(int x, int y, int width, int height, std::string textureID)
{
  Entity::load(x, y, width, height, textureID);
}

void Enemy::clean()
{
}

void Enemy::update()
{
  m_currentFrame = static_cast<int>(SDL_GetTicks() / 100 % 6);
  m_x += 1;
  m_y += 1;
}

void Enemy::render(SDL_Renderer *pRenderer)
{
  Entity::render(pRenderer);
}
