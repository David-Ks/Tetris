#ifndef EVENT_SYSTEM_HPP
#define EVENT_SYSTEM_HPP

#include "../../Settings.hpp"
#include "../Window/Input/NcursesInput.hpp"

#include <functional>
#include <map>
#include <memory> // unique_ptr

class EventSystem
{
public:
    enum Event
    {
        // Keyboard events
        KeyUp = 259,
        KeyDown = 258,
        KeyLeft = 260,
        KeyRight = 261,
        Enter = 10,
        Esc = 27,

        // Game events
        EndOfWhile = 777
    };
    
private:
    using Handler = std::function<void()>;
    using HandlerWithState = std::pair<Settings::GameState, Handler>;
    using Listener = std::multimap<Event, HandlerWithState>;

private:
    Settings::GameState &currentState;
    Listener eventListeners;

public:
    EventSystem(Settings::GameState &);

public:
    void runEventLoop();
    void addListener(Event, Handler, Settings::GameState);

private:
    void dispatch(Event) const;
};

#endif // EVENT_SYSTEM_HPP