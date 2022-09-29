#ifndef MAP_EVENT_H
#define MAP_EVENT_H

#include "Event.hpp"

namespace EventSystem
{
    class MapEvent : public Event
    {
    public:
        MapEvent() {}
        ~MapEvent() {}
    
    public:
        void addListener(KEY key, Action::Command* command);
        void delListener(KEY key);
        void delAllListeners();
        bool invoke(KEY key);
    };
} // namespace EventSystem

#endif