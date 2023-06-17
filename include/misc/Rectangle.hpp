#ifndef MISC_RECTANGLE_HPP
#define MISC_RECTANGLE_HPP

#include <algorithm>
#include <ostream>
#include <tuple>
#include <type_traits>

#include "fmt/format.h"

#include "misc/Arithmetic.hpp"

namespace ngl {
// Rectangle Forward Declaration
template <Arithmetic T>
class Rectangle;
} // namespace ngl

namespace ngl {
// Point Forward Declaration
template <Arithmetic T>
struct Point;
} // namespace ngl

// Point Declaration
namespace ngl {
template <Arithmetic T>
struct Point {
public:
  Point();
  Point(T x, T y);
  Point(std::tuple<T, T> pos);

  template <Arithmetic C = T>
  [[nodiscard]] inline C X() const noexcept;
  template <Arithmetic C = T>
  [[nodiscard]] inline C Y() const noexcept;

  inline void SetX(T x) noexcept;
  inline void SetY(T y) noexcept;
  template <Arithmetic C>
  inline void SetX(std::type_identity_t<C> x) noexcept;
  template <Arithmetic C>
  inline void SetY(std::type_identity_t<C> y) noexcept;

  template <Arithmetic C>
  [[nodiscard]] inline bool Within(const Rectangle<C> &r) const noexcept;

  [[nodiscard]] inline double Distance(Point<T> p) const noexcept;

  Point<T> &operator+=(const Point<T> &rhs);
  Point<T> &operator-=(const Point<T> &rhs);
  Point<T> &operator*=(const Point<T> &rhs);
  Point<T> &operator/=(const Point<T> &rhs);

  T x, y;
};
} // namespace ngl

// Rectangle Declaration
namespace ngl {
template <Arithmetic T>
class Rectangle {
public:
  Rectangle();
  Rectangle(T x, T y, T w, T h);
  Rectangle(std::tuple<T, T> pos, T w, T h);
  Rectangle(T x, T y, std::tuple<T, T> dim);
  Rectangle(std::tuple<T, T> pos, std::tuple<T, T> dim);
  Rectangle(const Point<T> &pos, T w, T h);
  Rectangle(const Point<T> &pos, std::tuple<T, T> dim);
  template <Arithmetic U>
  Rectangle(Rectangle<U> r);

  template <typename C>
    requires Arithmetic<C>
  [[nodiscard]] inline Rectangle<C> As() const noexcept;

  // direct accessors

  template <Arithmetic C = T>
  [[nodiscard]] inline C X() const noexcept;
  template <Arithmetic C = T>
  [[nodiscard]] inline C Y() const noexcept;
  template <Arithmetic C = T>
  [[nodiscard]] inline C W() const noexcept;
  template <Arithmetic C = T>
  [[nodiscard]] inline C H() const noexcept;

  // direct mutators

  inline void SetX(T x) noexcept;
  inline void SetY(T y) noexcept;
  inline void SetW(T w) noexcept;
  inline void SetH(T h) noexcept;

  template <Arithmetic C>
  inline void SetX(std::type_identity_t<C> x) noexcept;
  template <Arithmetic C>
  inline void SetY(std::type_identity_t<C> y) noexcept;
  template <Arithmetic C>
  inline void SetW(std::type_identity_t<C> w) noexcept;
  template <Arithmetic C>
  inline void SetH(std::type_identity_t<C> h) noexcept;

  void MoveX(T dx) noexcept;
  void MoveY(T dy) noexcept;

  // relative accesors

  template <Arithmetic C = T>
  [[nodiscard]] inline T Left() const noexcept;
  template <Arithmetic C = T>
  [[nodiscard]] inline T Right() const noexcept;
  template <Arithmetic C = T>
  [[nodiscard]] inline T Top() const noexcept;
  template <Arithmetic C = T>
  [[nodiscard]] inline T Bottom() const noexcept;
  template <Arithmetic C = T>
  [[nodiscard]] inline T CenterX() const noexcept;
  template <Arithmetic C = T>
  [[nodiscard]] inline T CenterY() const noexcept;
  template <Arithmetic C = T>
  [[nodiscard]] inline Point<C> Center() const noexcept;

  // relative mutators

  inline void SetLeft(T l) noexcept;
  inline void SetRight(T r) noexcept;
  inline void SetTop(T t) noexcept;
  inline void SetBottom(T b) noexcept;
  inline void SetCenterX(T b) noexcept;
  inline void SetCenterY(T b) noexcept;
  inline void SetCenter(Point<T> b) noexcept;

  template <Arithmetic C>
  inline void SetLeft(std::type_identity_t<C> l) noexcept;
  template <Arithmetic C>
  inline void SetRight(std::type_identity_t<C> r) noexcept;
  template <Arithmetic C>
  inline void SetTop(std::type_identity_t<C> t) noexcept;
  template <Arithmetic C>
  inline void SetBottom(std::type_identity_t<C> b) noexcept;

  template <Arithmetic U>
  [[nodiscard]] inline bool Intersects(const Rectangle<U> &r) const;

  template <Arithmetic U>
  [[nodiscard]] inline bool Encloses(U x, U y) const;

  template <typename C = T>
    requires Arithmetic<C>
  [[nodiscard]] inline bool Encloses(const Point<C> &p) const;

protected:
  T x_, y_;
  T w_, h_;
};
} // namespace ngl

// Point Implementation
namespace ngl {
template <Arithmetic T>
Point<T>::Point() : x(0), y(0) {}

template <Arithmetic T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <Arithmetic T>
Point<T>::Point(std::tuple<T, T> pos)
    : x(std::get<0>(pos)), y(std::get<1>(pos)) {}

template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline C Point<T>::X() const noexcept {
  return static_cast<C>(x);
}
template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline C Point<T>::Y() const noexcept {
  return static_cast<C>(y);
}

template <Arithmetic T>
inline void Point<T>::SetX(T new_x) noexcept {
  x = new_x;
}
template <Arithmetic T>
inline void Point<T>::SetY(T new_y) noexcept {
  y = new_y;
}

template <Arithmetic T>
template <Arithmetic C>
inline void Point<T>::SetX(std::type_identity_t<C> new_x) noexcept {
  this->x = static_cast<T>(new_x);
}
template <Arithmetic T>
template <Arithmetic C>
inline void Point<T>::SetY(std::type_identity_t<C> new_y) noexcept {
  this->y = static_cast<T>(new_y);
}

template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline bool Point<T>::Within(const Rectangle<C> &r
) const noexcept {
  return r.Encloses(x, y);
}
template <Arithmetic T>
[[nodiscard]] inline double Point<T>::Distance(Point<T> p) const noexcept {
  return std::sqrt(std::pow(x - p.X(), 2) + std::pow(y - p.Y(), 2));
}

template <Arithmetic T>
Point<T> operator+(const Point<T> &lhs, const Point<T> &rhs) {
  return Point{lhs.x + rhs.x, lhs.y + rhs.y};
}
template <Arithmetic T>
Point<T> &Point<T>::operator+=(const Point<T> &rhs) {
  x += rhs.x;
  y += rhs.y;
  return *this;
}
template <Arithmetic T>
Point<T> operator-(const Point<T> &lhs, const Point<T> &rhs) {
  return Point{lhs.x - rhs.x, lhs.y - rhs.y};
}
template <Arithmetic T>
Point<T> &Point<T>::operator-=(const Point<T> &rhs) {
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}
template <Arithmetic T>
Point<T> operator*(const Point<T> &lhs, const Point<T> &rhs) {
  return Point{lhs.x * rhs.x, lhs.y * rhs.y};
}
template <Arithmetic T>
Point<T> &Point<T>::operator*=(const Point<T> &rhs) {
  x *= rhs.x;
  y *= rhs.y;
  return *this;
}
template <Arithmetic T>
Point<T> operator/(const Point<T> &lhs, const Point<T> &rhs) {
  return Point{lhs.x / rhs.x, lhs.y / rhs.y};
}
template <Arithmetic T>
Point<T> &Point<T>::operator/=(const Point<T> &rhs) {
  x /= rhs.x;
  y /= rhs.y;
  return *this;
}

} // namespace ngl

// Rectangle Implementation
namespace ngl {
template <Arithmetic T>
Rectangle<T>::Rectangle() : x_(0), y_(0), w_(0), h_(0) {}
template <Arithmetic T>
Rectangle<T>::Rectangle(T x, T y, T w, T h) : x_(x), y_(y), w_(w), h_(h) {}

template <Arithmetic T>
Rectangle<T>::Rectangle(std::tuple<T, T> pos, T w, T h)
    : x_(std::get<0>(pos)), y_(std::get<1>(pos)), w_(w), h_(h) {}

template <Arithmetic T>
Rectangle<T>::Rectangle(T x, T y, std::tuple<T, T> dim)
    : x_(x), y_(y), w_(std::get<0>(dim)), h_(std::get<1>(dim)) {}

template <Arithmetic T>
Rectangle<T>::Rectangle(std::tuple<T, T> pos, std::tuple<T, T> dim)
    : x_(std::get<0>(pos)), y_(std::get<1>(pos)), w_(std::get<0>(dim)),
      h_(std::get<1>(dim)) {}

template <Arithmetic T>
Rectangle<T>::Rectangle(const Point<T> &pos, T w, T h)
    : x_(pos.X()), y_(pos.Y()), w_(w), h_(h) {}

template <Arithmetic T>
Rectangle<T>::Rectangle(const Point<T> &pos, std::tuple<T, T> dim)
    : x_(pos.X()), y_(pos.Y()), w_(std::get<0>(dim)), h_(std::get<1>(dim)) {}

template <Arithmetic T>
template <Arithmetic U>
Rectangle<T>::Rectangle(Rectangle<U> r)
    : x_(static_cast<T>(r.X())), y_(static_cast<T>(r.Y())),
      w_(static_cast<T>(r.W())), h_(static_cast<T>(r.H())) {}

template <Arithmetic T>
template <typename C>
  requires Arithmetic<C>
[[nodiscard]] inline Rectangle<C> Rectangle<T>::As() const noexcept {
  return Rectangle<C>(*this);
}

template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline C Rectangle<T>::X() const noexcept {
  return static_cast<C>(x_);
}
template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline C Rectangle<T>::Y() const noexcept {
  return static_cast<C>(y_);
}
template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline C Rectangle<T>::W() const noexcept {
  return static_cast<C>(w_);
}
template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline C Rectangle<T>::H() const noexcept {
  return static_cast<C>(h_);
}

template <Arithmetic T>
inline void Rectangle<T>::SetX(T x) noexcept {
  x_ = x;
}
template <Arithmetic T>
inline void Rectangle<T>::SetY(T y) noexcept {
  y_ = y;
}
template <Arithmetic T>
inline void Rectangle<T>::SetW(T w) noexcept {
  w_ = w;
}
template <Arithmetic T>
inline void Rectangle<T>::SetH(T h) noexcept {
  h_ = h;
}
template <Arithmetic T>
template <Arithmetic C>
inline void Rectangle<T>::SetX(std::type_identity_t<C> x) noexcept {
  x_ = static_cast<T>(x);
}
template <Arithmetic T>
template <Arithmetic C>
inline void Rectangle<T>::SetY(std::type_identity_t<C> y) noexcept {
  y_ = static_cast<T>(y);
}
template <Arithmetic T>
template <Arithmetic C>
inline void Rectangle<T>::SetW(std::type_identity_t<C> w) noexcept {
  w_ = static_cast<T>(w);
}
template <Arithmetic T>
template <Arithmetic C>
inline void Rectangle<T>::SetH(std::type_identity_t<C> h) noexcept {
  h_ = static_cast<T>(h);
}

template <Arithmetic T>
void Rectangle<T>::MoveX(T dx) noexcept {
  x_ += dx;
}
template <Arithmetic T>
void Rectangle<T>::MoveY(T dy) noexcept {
  y_ += dy;
}

template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline T Rectangle<T>::Left() const noexcept {
  return static_cast<C>(x_);
}
template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline T Rectangle<T>::Right() const noexcept {
  return static_cast<C>(x_ + w_);
}
template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline T Rectangle<T>::Top() const noexcept {
  return static_cast<C>(y_);
}
template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline T Rectangle<T>::Bottom() const noexcept {
  return static_cast<C>(y_ + h_);
}

template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline T Rectangle<T>::CenterX() const noexcept {
  return static_cast<C>(x_ + (w_ / 2));
}
template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline T Rectangle<T>::CenterY() const noexcept {
  return static_cast<C>(y_ + (h_ / 2));
}
template <Arithmetic T>
template <Arithmetic C>
[[nodiscard]] inline Point<C> Rectangle<T>::Center() const noexcept {
  return Point<C>{CenterX<C>, CenterY<C>};
}

template <Arithmetic T>
inline void Rectangle<T>::SetLeft(T l) noexcept {
  x_ = l;
}
template <Arithmetic T>
inline void Rectangle<T>::SetRight(T r) noexcept {
  x_ = r - w_;
}
template <Arithmetic T>
inline void Rectangle<T>::SetTop(T t) noexcept {
  y_ = t;
}
template <Arithmetic T>
inline void Rectangle<T>::SetBottom(T b) noexcept {
  y_ = b - h_;
}

template <Arithmetic T>
template <Arithmetic C>
inline void Rectangle<T>::SetLeft(std::type_identity_t<C> l) noexcept {
  x_ = static_cast<T>(l);
}
template <Arithmetic T>
template <Arithmetic C>
inline void Rectangle<T>::SetRight(std::type_identity_t<C> r) noexcept {
  x_ = static_cast<T>(r - static_cast<C>(w_));
}
template <Arithmetic T>
template <Arithmetic C>
inline void Rectangle<T>::SetTop(std::type_identity_t<C> t) noexcept {
  y_ = static_cast<T>(t);
}
template <Arithmetic T>
template <Arithmetic C>
inline void Rectangle<T>::SetBottom(std::type_identity_t<C> b) noexcept {
  y_ = static_cast<T>(b - static_cast<C>(h_));
}

template <Arithmetic T>
inline void Rectangle<T>::SetCenterX(T b) noexcept {
  x_ = b - (w_ / 2);
}
template <Arithmetic T>
inline void Rectangle<T>::SetCenterY(T b) noexcept {
  y_ = b - (h_ / 2);
}
template <Arithmetic T>
inline void Rectangle<T>::SetCenter(Point<T> b) noexcept {
  SetCenterX(b.x);
  SetCenterY(b.y);
}

template <Arithmetic T>
template <Arithmetic U>
[[nodiscard]] inline bool Rectangle<T>::Intersects(const Rectangle<U> &r
) const {
  return (Left() < r.Right()) && (Right() > r.Left()) && (Top() < r.Bottom())
         && (Bottom() > r.Top());
}

template <Arithmetic T>
template <Arithmetic U>
[[nodiscard]] inline bool Rectangle<T>::Encloses(U x, U y) const {
  return (Left() < x) && (Right() > x) && (Top() < y) && (Bottom() > y);
}

template <Arithmetic T>
template <typename C>
  requires Arithmetic<C>
[[nodiscard]] inline bool Rectangle<T>::Encloses(const Point<C> &p) const {
  return Encloses(p.X(), p.Y());
}

} // namespace ngl

namespace ngl {
template <Arithmetic T>
std::ostream &operator<<(std::ostream &os, const Rectangle<T> &rect) {
  os << fmt::format(
    "x: {0} y: {1} w: {2} h: {3}", rect.X(), rect.Y(), rect.W(), rect.H()
  );
  return os;
}

} // namespace ngl

#endif