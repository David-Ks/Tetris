#include "EventSystem.hpp"

EventSystem::EventSystem(Settings::GameState &state) : currentState(state) {}

void EventSystem::addListener(Event event, Handler handler, Settings::GameState state)
{
    std::pair<Settings::GameState, Handler> handlerWithState {state, handler};
    eventListeners.insert({event, handlerWithState});
}

void EventSystem::dispatch(Event event) const
{
    auto listenersRange = eventListeners.equal_range(event);
    for (auto listener = listenersRange.first; listener != listenersRange.second; ++listener)
    {
        const HandlerWithState handler = listener->second;
        const Settings::GameState state = handler.first;

        if ((state == currentState || state == Settings::GameState::Any) ||
            (currentState == Settings::GameState::PlayerVsCPU && state == Settings::GameState::Play) ||
            (state == Settings::GameState::inAnyMenu && Settings::isAnyMenu(currentState)))
        {
            const Handler exec = handler.second;
            exec();
        }
    }
}

void EventSystem::runEventLoop()
{
    std::unique_ptr<Input> input(new NcursesInput);

    while (true)
    {
        if (currentState == Settings::GameState::Exit)
            break;

        Event keyboardEvent = static_cast<Event>(input->getKey());
        dispatch(keyboardEvent);
        dispatch(Event::EndOfWhile);
    }
}