#include <SDL2/SDL.h>

#include <map>
#include <string>

class TextureManager
{
public:

  /**
   * @brief Default constructor
   */
  TextureManager();

  /**
   * @brief Default destructor
   */
  ~TextureManager();

  /**
   * @brief
   *
   * @param     pRenderer Rendering context for game window.
   * @param[in] filename  Input image file name.
   * @param[in] id        Texture string ID.
   *
   * @return `true` on success, `false` on failure.
   */
  bool loadTexture(SDL_Renderer *pRenderer, std::string filename, std::string id);

  // TODO: Implement
  /**
   * @brief
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
  //bool draw(SDL_Renderer *pRenderer, std::string id, int x, int y, int width, int height,
  //    SDL_RendererFlip flipFlag = SDL_FLIP_NONE);

  // TODO: Implement
  /**
   * @brief
   *
   * @param pRenderer Rendering context for game window.
   *
   * @return `true` on success, `false` on failure.
   */
  //bool drawFrame(SDL_Renderer *pRenderer);

private:

  std::map<std::string, SDL_Texture *> m_textures;
};
