#include "Player.hpp"

Player::Player()
: Entity()
{
}

Player::~Player()
{
}

void Player::load(int x, int y, int width, int height, std::string textureID)
{
  Entity::load(x, y, width, height, textureID);
}

void Player::clean()
{
}

void Player::update()
{
  m_currentFrame = static_cast<int>(SDL_GetTicks() / 100 % 6);
  m_x -= 1;
}

void Player::render(SDL_Renderer *pRenderer)
{
  Entity::render(pRenderer);
}
