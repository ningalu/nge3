template <class T, typename... Args>
concept Setupable = requires(T t, Args... args) { t.Setup(args...); };