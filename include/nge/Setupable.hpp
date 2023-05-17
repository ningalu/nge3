#ifndef NGE_SETUPABLE_H
#define NGE_SETUPABLE_H

namespace nge {

template <class T, typename... Args>
concept Setupable = requires(T t, Args... args) { t.Setup(args...); };
}

#endif