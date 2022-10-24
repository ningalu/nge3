#ifndef NGE3_NGSDL_EVENTS_EVENTVISITOR_H
#define NGE3_NGSDL_EVENTS_EVENTVISITOR_H

namespace nge::sdl {

template <class... Ts>
struct EventVisitor : Ts... {
  using Ts::operator()...;
};

template <class... Ts>
EventVisitor(Ts...) -> EventVisitor<Ts...>;
} // namespace nge::sdl

#endif