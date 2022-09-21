#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include "Event.hpp"

namespace Listen
{
    class GameEvent : public Event
    {
    public:
        GameEvent(Draw::Window *win) : Event(win) {}
        ~GameEvent() {}

    public:
        void handler(unsigned &choice, Map::Board *map);
    };
} // namespace Listen

#endif