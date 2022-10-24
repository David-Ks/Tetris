#ifndef EVENT_HPP
#define EVENT_HPP

#include <map>

#include "../Controls/Command.hpp"
#include "../Graphics/Window.hpp"
#include "../Map/Board.hpp"

namespace EventSystem
{
    enum KEY
    {
        DOWN  = 2,
        UP    = 3,
        LEFT  = 4,
        RIGHT = 5,
        ENTER = 10,
    };

    class Event
    {
    protected:
        std::map<KEY, Action::Command *> listeners;

    public:
        Event() {}
        virtual ~Event() {}

    public:
        virtual void addListener(KEY key, Action::Command *command) = 0;
        virtual void delListener(KEY key) = 0;
        virtual void delAllListeners() = 0;
        virtual bool invoke(KEY key) = 0;
    };
} // namespace Action

#endif