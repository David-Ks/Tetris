#ifndef EVENT_H
#define EVENT_H

#include "../Settings.hpp"

namespace Listen
{
    class Event
    {
    private:
        Draw::Window *window;

    public:
        Event(Draw::Window *window)
        {
            this->window = window;
        }

        virtual ~Event() {}

    public:
        int getKey()
        {
            return window->input();
        }

        virtual void handler(unsigned &choice, Map::Board *map = 0) = 0;
    };
} // namespace Listen

#endif