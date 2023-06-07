#include "TextureManager.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

TextureManager *TextureManager::s_pInstance = nullptr;

using std::cout;

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
  clean();
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

void TextureManager::draw(SDL_Renderer *pRenderer, std::string id, int x, int y,
    int width, int height, SDL_RendererFlip flipFlags)
{
  SDL_Rect srcRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = width;
  srcRect.h = height;

  SDL_Rect dstRect;

  dstRect.x = x;
  dstRect.y = y;
  dstRect.w = width;
  dstRect.h = height;

  SDL_RenderCopyEx(pRenderer, m_textures[id], &srcRect, &dstRect, 0, 0, flipFlags);
}

void TextureManager::drawFrame(SDL_Renderer *pRenderer, std::string id, int x, int y, int width,
    int height, int frame, int row, SDL_RendererFlip flipFlags)
{
  SDL_Rect srcRect;

  srcRect.x = frame * width;
  srcRect.y = row;
  srcRect.w = width;
  srcRect.h = height;

  SDL_Rect dstRect;

  dstRect.x = x;
  dstRect.y = y;
  dstRect.w = width;
  dstRect.h = height;

  SDL_RenderCopyEx(pRenderer, m_textures[id], &srcRect, &dstRect, 0, 0, flipFlags);
}

void TextureManager::clean()
{
  // Free textures

  for (auto &pair: m_textures)
  {
    SDL_DestroyTexture(pair.second);
  }

  delete s_pInstance;
}
