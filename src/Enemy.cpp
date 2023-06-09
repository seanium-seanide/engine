#include "Enemy.hpp"

Enemy::Enemy(const LoaderParams *pParams)
: Entity(pParams)
{
}

Enemy::~Enemy()
{
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

void Enemy::render()
{
  Entity::render();
}
