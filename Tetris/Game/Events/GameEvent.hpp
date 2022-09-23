#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include "Event.hpp"

namespace Listen
{
    class GameEvent : public Event
    {
    public:
        GameEvent() {}
        ~GameEvent() {}

    public:
        void handler(unsigned &choice);
    };
} // namespace Listen

#endif