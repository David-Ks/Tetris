#ifndef MENU_EVENT_H
#define MENU_EVENT_H

#include "Event.hpp"

namespace Listen
{
    class MenuEvent : public Event
    {
    public:
        MenuEvent(Draw::Window *win) : Event(win) {}
        ~MenuEvent() {}

    public:
        void handler(unsigned &choice, Map::Board *map);
    };
} // namespace Listen

#endif