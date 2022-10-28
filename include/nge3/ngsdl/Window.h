#ifndef NGE3_NGSDL_WINDOW_H
#define NGE3_NGSDL_WINDOW_H

#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <tuple>

#include "SDL2/SDL.h"

#include "Events/MouseButton.h"
#include "Point.h"
#include "WindowFlags.h"

namespace nge {
namespace sdl {
class Renderer;
class Window {
public:
  friend class Renderer;
  Window();
  Window(std::string title, int x, int y, int w, int h, WindowFlags flags);

  // SDL_GetWindowBordersSize

  // SDL_GetWindowBrightness

  // SDL_GetWindowData

  // SDL_GetWindowDisplayIndex

  // SDL_GetWindowDisplayMode

  // SDL_GetWindowFlags

  // SDL_GetWindowFromID

  // SDL_GetWindowGammaRamp

  // SDL_GetWindowGrab

  // SDL_GetWindowID
  const Uint32 GetID() const;

  // SDL_GetWindowMaximumSize
  std::tuple<int, int> GetMaxSize() const;
  int GetMaxW() const;
  int GetMaxH() const;
  void SetMaxSize(int w, int h);

  // SDL_GetWindowMinimumSize
  std::tuple<int, int> GetMinSize() const;
  int GetMinW() const;
  int GetMinH() const;
  void SetMinSize(int w, int h);

  // SDL_GetWindowOpacity
  float GetOpacity() const;
  void SetOpacity(float opacity);

  // SDL_GetWindowPixelFormat

  // SDL_GetWindowPosition
  Point GetPosition() const;
  void SetPosition(Point point);

  // SDL_GetWindowSize
  std::tuple<int, int> GetSize() const;
  int GetW() const;
  int GetH() const;
  void SetSize(int w, int h);

  // SDL_GetWindowSurface

  // SDL_GetWindowTitle
  std::string_view GetTitle() const;
  void SetTitle(const std::string &title);

  // SDL_GetMouseState
  std::tuple<MouseButton, Point> GetMouseState() const;
  MouseButton GetMouseButtons() const;
  Point GetMousePos() const;
  int GetMouseX() const;
  int GetMouseY() const;

  // SDL_GetKeyboardState
  const std::span<const Uint8> GetKeyboardState() const;

protected:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;

private:
};
} // namespace sdl
} // namespace nge

#endif