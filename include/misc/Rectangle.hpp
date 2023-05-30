#ifndef MISC_RECTANGLE_H
#define MISC_RECTANGLE_H

#include <type_traits>

#include "misc/Arithmetic.hpp"

namespace ngl {
template <typename T>
  requires Arithmetic<T>
class Rectangle {
public:
  Rectangle(T x, T y, T w, T h) : x_(x), y_(y), w_(w), h_(h) {}

  template <typename U>
    requires Arithmetic<U>
  Rectangle(Rectangle<U> r)
      : x_(static_cast<T>(r.X())), y_(static_cast<T>(r.Y())),
        w_(static_cast<T>(r.W())), h_(static_cast<T>(r.H())) {}

  template <typename C>
    requires Arithmetic<C>
  [[nodiscard]] inline Rectangle<C> As() const noexcept {
    return Rectangle<C>(*this);
  }

  // direct accessors

  template <typename C = T>
    requires Arithmetic<T>
  [[nodiscard]] inline C X() const noexcept {
    return static_cast<C>(x_);
  }
  template <typename C = T>
    requires Arithmetic<T>
  [[nodiscard]] inline C Y() const noexcept {
    return static_cast<C>(y_);
  }
  template <typename C = T>
    requires Arithmetic<T>
  [[nodiscard]] inline C W() const noexcept {
    return static_cast<C>(w_);
  }
  template <typename C = T>
    requires Arithmetic<T>
  [[nodiscard]] inline C H() const noexcept {
    return static_cast<C>(h_);
  }

  // direct mutators

  inline void SetX(T x) noexcept { x_ = x; }
  inline void SetY(T y) noexcept { y_ = y; }
  inline void SetW(T w) noexcept { w_ = w; }
  inline void SetH(T h) noexcept { h_ = h; }
  template <typename C>
    requires Arithmetic<C>
  inline void SetX(std::type_identity_t<C> x) noexcept {
    x_ = static_cast<T>(x);
  }
  template <typename C>
    requires Arithmetic<T>
  inline void SetY(std::type_identity_t<C> y) noexcept {
    y_ = static_cast<T>(y);
  }
  template <typename C>
    requires Arithmetic<T>
  inline void SetW(std::type_identity_t<C> w) noexcept {
    w_ = static_cast<T>(w);
  }
  template <typename C>
    requires Arithmetic<T>
  inline void SetH(std::type_identity_t<C> h) noexcept {
    h_ = static_cast<T>(h);
  }

  void MoveX(T dx) noexcept { x_ += dx; }
  void MoveY(T dy) noexcept { y_ += dy; }

  // relative accesors

  template <typename C = T>
    requires Arithmetic<T>
  [[nodiscard]] inline T Left() const noexcept {
    return static_cast<C>(x_);
  }
  template <typename C = T>
    requires Arithmetic<T>
  [[nodiscard]] inline T Right() const noexcept {
    return static_cast<C>(x_ + w_);
  }
  template <typename C = T>
    requires Arithmetic<T>
  [[nodiscard]] inline T Top() const noexcept {
    return static_cast<C>(y_);
  }
  template <typename C = T>
    requires Arithmetic<T>
  [[nodiscard]] inline T Bottom() const noexcept {
    return static_cast<C>(y_ + h_);
  }

  // relative mutators

  inline void SetLeft(T l) noexcept { x_ = l; }
  inline void SetRight(T r) noexcept { x_ = r - w_; }
  inline void SetTop(T t) noexcept { y_ = t; }
  inline void SetBottom(T b) noexcept { y_ = b - h_; }
  template <typename C>
    requires Arithmetic<C>
  inline void SetLeft(std::type_identity_t<C> l) noexcept {
    x_ = static_cast<T>(l);
  }
  template <typename C>
    requires Arithmetic<T>
  inline void SetRight(std::type_identity_t<C> r) noexcept {
    x_ = static_cast<T>(r - static_cast<C>(w_));
  }
  template <typename C>
    requires Arithmetic<T>
  inline void SetTop(std::type_identity_t<C> t) noexcept {
    y_ = static_cast<T>(t);
  }
  template <typename C>
    requires Arithmetic<T>
  inline void SetBottom(std::type_identity_t<C> b) noexcept {
    y_ = static_cast<T>(b - static_cast<C>(h_));
  }

  template <typename U>
    requires Arithmetic<U>
  [[nodiscard]] inline bool Intersects(const Rectangle<U> &r) {
    return (Left() < r.Right()) && (Right() > r.Left()) && (Top() < r.Bottom())
           && (Bottom() > r.Top());
  }

protected:
  T x_, y_;
  T w_, h_;
};
} // namespace ngl

#endif