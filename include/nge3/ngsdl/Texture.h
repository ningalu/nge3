#ifndef NGE3_NGSDL_TEXTURE_H
#define NGE3_NGSDL_TEXTURE_H

#include <memory>
#include <string>
#include <tuple>

#include "SDL2/SDL.h"

#include "BlendMode.h"
#include "Rectangle.h"

namespace nge::sdl {
class Renderer;
class TextureLoader;
class Texture {
  friend class Renderer;
  friend class TextureLoader;

public:
  // SDL_CreateTexture
  Texture(const Renderer &renderer, Uint32 format, int access, int w, int h);

  // IMG_LoadTexture
  Texture(const Renderer &renderer, std::string filename);

  // SDL_GetTextureAlphaMod
  // SDL_SetTextureAlphaMod
  Uint8 GetAlphaMod() const;
  void SetAlphaMod(Uint8 mod);

  // SDL_GetTextureBlendMode
  // SDL_SetTextureBlendMode
  BlendMode GetBlendMode() const;
  void SetBlendMode(BlendMode mode);

  // SDL_GetTextureColorMod
  // SDL_SetTextureColorMod
  std::tuple<Uint8, Uint8, Uint8> GetColorMod() const;
  void SetColorMod(Uint8 r, Uint8 g, Uint8 b);
  std::tuple<Uint8, Uint8, Uint8> GetColourMod() const;
  void SetColourMod(Uint8 r, Uint8 g, Uint8 b);

  // SDL_LockTexture
  // SDL_UnlockTexture

  // SDL_QueryTexture
  std::tuple<Uint32, int, int, int> Query() const;
  Uint32 GetFormat() const;
  int GetAccess() const;
  int GetW() const;
  int GetH() const;
  std::tuple<int, int> GetSize() const;

  // SDL_UpdateTexture

protected:
  std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture_;

private:
};
} // namespace nge::sdl

#endif