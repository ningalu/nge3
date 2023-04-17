#ifndef NGE3_NGSDL_EVENTS_EVENTVISITOR_H
#define NGE3_NGSDL_EVENTS_EVENTVISITOR_H

namespace nge::sdl {

// EventVisitor.hpp(13,1): warning C4623:
// 'nge::sdl::EventVisitor<nge::App::Run::<lambda_1>,nge::App::Run::<lambda_2>>':
// default constructor was implicitly defined as deleted
// no idea how to fix this
#pragma warning(push)
#pragma warning(disable : 4623)

template <class... Ts>
struct EventVisitor : public Ts... {
  EventVisitor<Ts...> operator=(const EventVisitor<Ts...> &) = delete;
  using Ts::operator()...;
};
#pragma warning(pop)

template <class... Ts>
EventVisitor(Ts...) -> EventVisitor<Ts...>;
} // namespace nge::sdl

#endif