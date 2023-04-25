#include "TextureManager.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

bool TextureManager::loadTexture(SDL_Renderer *pRenderer, std::string filename, std::string id)
{
  SDL_Surface *pTempSurface = IMG_Load(filename.c_str());
  if (pTempSurface == nullptr)
  {
    fprintf(stderr, "Failed to load BMP file %s: %s\n", filename.c_str(), SDL_GetError());
    return false;
  }

  SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);
  if (pTexture == nullptr)
  {
    fprintf(stderr, "Failed to convert texture to surface: %s\n", SDL_GetError());
    return false;
  }

  m_textures[id] = pTexture;

  return true;
}

// TODO: Implement
//bool TextureManager::draw(SDL_Renderer *pRenderer, std::string id, int x, int y,
//    int width, int height, SDL_RendererFlip flipFlag)
//{
//  return true;
//}

// TODO: Implement
//bool TextureManager::drawFrame(SDL_Renderer *pRenderer)
//{
//  return true;
//}
