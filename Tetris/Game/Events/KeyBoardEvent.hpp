#ifndef KEYBOARD_EVENT_H
#define KEYBOARD_EVENT_H

#include "Event.hpp"

namespace EventSystem
{
    class KeyBoardEvent : public Event
    {
    public:
        KeyBoardEvent() {}
        ~KeyBoardEvent() {}
    
    public:
        void addListener(KEY key, Action::Command* command);
        void delListener(KEY key);
        void delAllListeners();
        bool invoke(KEY key);
    };
} // namespace EventSystem

#endif