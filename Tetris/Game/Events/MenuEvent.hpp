#ifndef MENU_EVENT_H
#define MENU_EVENT_H

#include "Event.hpp"

namespace Listen
{
    class MenuEvent : public Event
    {
    public:
        MenuEvent() {}
        ~MenuEvent() {}

    public:
        void handler(unsigned &choice);
    };
} // namespace Listen

#endif