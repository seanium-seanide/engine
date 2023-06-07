#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <SDL2/SDL.h>

#include <map>
#include <string>

class TextureManager
{
public:

  /**
   * @brief Default destructor
   */
  ~TextureManager();

  /**
   * @brief     Load a texture from an image file.
   *
   * @param     pRenderer Rendering context for game window.
   * @param[in] filename  Input image file name.
   * @param[in] id        Texture string ID.
   *
   * @return `true` on success, `false` on failure.
   */
  bool loadTexture(SDL_Renderer *pRenderer, std::string filename, std::string id);

  /**
   * @brief     Draw a loaded texture.
   *
   * @param     pRenderer Rendering context for game window.
   * @param[in] id        Texture string ID.
   * @param[in] x         Destination x-coordinate of image top-left corner.
   * @param[in] y         Destination y-coordinate of image top-left corner.
   * @param[in] width     Image source width.
   * @param[in] height    Image source height.
   * @param[in] flipFlag  Flag to specify flipping (if any).
   *
   * @return `true` on success, `false` on failure.
   */
  void draw(SDL_Renderer *pRenderer, std::string id, int x, int y, int width, int height,
      SDL_RendererFlip flipFlags = SDL_FLIP_NONE);

  /**
   * @brief Draw a frame from a loaded texture.
   *
   * @param pRenderer Rendering context for game window.
   * @param id
   * @param x
   * @param y
   * @param width
   * @param height
   * @param frame
   * @param row
   * @param flipFlags
   *
   * @return `true` on success, `false` on failure.
   */
  void drawFrame(SDL_Renderer *pRenderer, std::string id, int x, int y, int width, int height,
      int frame, int row, SDL_RendererFlip flipFlags = SDL_FLIP_NONE);

  /**
   * @brief Free textures.
   */
  void clean();

  /**
   * @brief Lazy allocator and accessor for the solitary class instance.
   */
  static TextureManager *Instance()
  {
    if (s_pInstance == nullptr)
    {
      s_pInstance = new TextureManager;
    }

    return s_pInstance;
  }

private:

  /**
   * @brief Private default constructor
   */
  TextureManager();

  std::map<std::string, SDL_Texture *> m_textures;

  static TextureManager *s_pInstance;
};

typedef TextureManager TheTextureManager;

#endif
