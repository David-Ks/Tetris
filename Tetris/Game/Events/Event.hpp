#ifndef EVENT_H
#define EVENT_H

#include <map>
#include "../Controls/Command.hpp" // temporarily
#include "../Map/Board.hpp"        // temporarily
#include "../Graphics/Window.hpp"  // temporarily

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
        virtual void delListener(KEY code) = 0;
        virtual void delAllListeners() = 0;
        virtual bool invoke(KEY code) = 0;
    };
} // namespace Action

#endif