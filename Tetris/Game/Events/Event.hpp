#ifndef EVENT_H
#define EVENT_H

#include "../Settings.hpp"

namespace Listen
{
    class Event
    {
    private:
        Draw::Window *win;

    public:
        Event(Draw::Window *win)
        {
            this->win = win;
        }

        virtual ~Event() {}

    public:
        int get()
        {
            return win->input();
        }

        virtual void handler(unsigned &choice, Map::Board *map = 0) = 0;
    };
} // namespace Listen

#endif