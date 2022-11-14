#ifndef KEYBOARD_EVENT_HPP
#define KEYBOARD_EVENT_HPP

#include "Event.hpp"

namespace EventSystem
{
    class KeyBoardEvent : public Event
    {
    public:
        KeyBoardEvent() {}
    
    public:
        void addListener(const KEY key, Action::Command* command);
        void deleteListenerIfExists(const KEY key);
        void delAllListeners();
        bool invoke(const KEY key);
    };
} // namespace EventSystem

#endif