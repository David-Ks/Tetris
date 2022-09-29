#include "KeyBoardEvent.hpp"
#include <iostream>

void EventSystem::KeyBoardEvent::addListener(EventSystem::KEY key, Action::Command *command)
{
    if (listeners.count(key))
    {
        delListener(key);
    }
    listeners.insert({key, command});
}

void EventSystem::KeyBoardEvent::delListener(EventSystem::KEY key)
{
    if (listeners.count(key))
    {
        delete listeners.at(key);
    }
    listeners.erase(key);
}

void EventSystem::KeyBoardEvent::delAllListeners()
{
    for (auto &listener : listeners)
    {
        delete listener.second;
    }
    listeners.clear();
}

bool EventSystem::KeyBoardEvent::invoke(EventSystem::KEY key)
{
    if (listeners.count(key))
    {
        Action::Command *command = listeners.at(key);

        if (command->isAvailable())
        {
            command->execute();
            return true;
        }
    }
    return false;
}