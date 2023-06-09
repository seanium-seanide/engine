#include "Player.hpp"

Player::Player(const LoaderParams *pParams)
: Entity(pParams)
{
}

Player::~Player()
{
}

void Player::clean()
{
}

void Player::update()
{
  m_currentFrame = static_cast<int>(SDL_GetTicks() / 100 % 6);
  m_x += 1;
}

void Player::render()
{
  Entity::render();
}
