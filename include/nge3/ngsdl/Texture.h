#ifndef NGE3_NGSDL_TEXTURE_H
#define NGE3_NGSDL_TEXTURE_H

#include <cstdint>
#include <memory>
#include <string>
#include <tuple>

#pragma warning(push, 0)
#include "SDL2/SDL.h"
#pragma warning(pop)

#include "BlendMode.h"
#include "Color.h"
#include "FontRenderType.h"
#include "Rectangle.h"

namespace nge::sdl {
class Renderer;
class Font;
class Texture {
  friend class Renderer;
  friend class Font;

public:
  // SDL_CreateTexture
  Texture(const Renderer &renderer, Uint32 format, int access, int w, int h);

  // Internal SDL_Texture* could get deleted if you can copy from a Texture;
  // Textures must exclusively own their SDL_Texture*
  Texture(const Texture &) = delete;
  Texture &operator=(const Texture &) = delete;

  // IMG_LoadTexture
  Texture(const Renderer &renderer, std::string filename);

  // TTF_RenderText_Blended
  // TTF_RenderText_LCD
  // TTF_RenderText_Shaded
  // TTF_RenderText_Solid
  Texture(
    const Renderer &renderer,
    const Font &font,
    const std::string &text,
    FontRenderType type,
    Color color,
    Color bg = {0, 0, 0, 0}
  );

  // TTF_RenderText_Blended_Wrapped
  // TTF_RenderText_LCD_Wrapped
  // TTF_RenderText_Shaded_Wrapped
  // TTF_RenderText_Solid_Wrapped
  Texture(
    const Renderer &renderer,
    const Font &font,
    const std::string &text,
    FontRenderType type,
    Color color,
    uint32_t wrap_length,
    Color bg = {0, 0, 0, 0}
  );

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
  Texture(SDL_Texture *texture);
  std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture_;

private:
};
} // namespace nge::sdl

#endif