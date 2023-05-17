#ifndef NGE_COMPONENT_COMPOSITE_H
#define NGE_COMPONENT_COMPOSITE_H

namespace nge {
template <typename... Ts>
class Composite : public Ts... {
public:
  Composite(Ts... ts) : Ts(ts)... {}

  template <typename T>
  void set(T t) {
    static_cast<T &>(*this) = t;
  }
};
} // namespace nge

#endif