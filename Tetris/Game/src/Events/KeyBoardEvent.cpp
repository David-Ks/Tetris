#include "KeyBoardEvent.hpp"

void EventSystem::KeyBoardEvent::addListener(const EventSystem::KEY key, Action::Command *command)
{
    deleteListenerIfExists(key);
    listeners.insert({key, command});
}

void EventSystem::KeyBoardEvent::deleteListenerIfExists(const EventSystem::KEY key)
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

bool EventSystem::KeyBoardEvent::invoke(const EventSystem::KEY key)
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