#include "Menu.hpp"

Menu::Menu(Settings::GameState &state, EventSystem &eventSystem, const Window *win)
    : currentState(state),
      eventSystem(eventSystem),
      window(win),
      playerBoard(new PlayerBoard(eventSystem, state, player)),
      botBoard(new BotBoard(eventSystem, state, bot))
{
    const auto inAnyMenuState = Settings::GameState::inAnyMenu;
    eventSystem.addListener(EventSystem::Event::EndOfWhile, std::bind(&Menu::draw, this), Settings::GameState::Any);
    eventSystem.addListener(EventSystem::Event::KeyDown, std::bind(&Menu::moveDownSelector, this), inAnyMenuState);
    eventSystem.addListener(EventSystem::Event::KeyUp, std::bind(&Menu::moveUpSelector, this), inAnyMenuState);
    eventSystem.addListener(EventSystem::Event::Enter, std::bind(&Menu::select, this), inAnyMenuState);
}

void Menu::select()
{
    if (currentState == Settings::GameState::Records)
    {
        if (records[selected] == "Back")
            currentState = Settings::GameState::Menu;
    }
    else if (currentState == Settings::GameState::Menu)
    {
        if (menu[selected] == "Play")
        {
            playerBoard->theEnd();
            currentState = Settings::GameState::Play;
        }
        else if (menu[selected] == "PlayerVsCPU")
        {
            playerBoard->theEnd();
            botBoard->theEnd();
            currentState = Settings::GameState::PlayerVsCPU;
        }
        else if (menu[selected] == "Menu")
            currentState = Settings::GameState::Menu;
        else if (menu[selected] == "Options")
            currentState = Settings::GameState::Options;
        else if (menu[selected] == "Records")
            currentState = Settings::GameState::Records;
        else if (menu[selected] == "Exit")
            currentState = Settings::GameState::Exit;
    }
    else if (currentState == Settings::GameState::Options)
    {
        if (options[selected] == "Size 1x")
        {
            isBigSize = false;
            options[selected] = "Size 1x (+)";
            options[selected + 1] = "Size 2x";
        }
        else if (options[selected] == "Size 2x")
        {
            isBigSize = true;
            options[selected] = "Size 2x (+)";
            options[selected - 1] = "Size 1x";
        }
        else if (options[selected] == "Back")
            currentState = Settings::GameState::Menu;
        return;
    }
    selected = 0;
}

void Menu::moveDownSelector()
{
    if ((currentState == Settings::GameState::Menu && (int)menu.size() - 1 > selected) ||
        (currentState == Settings::GameState::Records && (int)records.size() - 1 > selected) ||
        (currentState == Settings::GameState::Options && (int)options.size() - 1 > selected))
    {
        selected += 1;
    }
}

void Menu::moveUpSelector()
{
    if (selected > 0)
    {
        selected -= 1;
    }
}

void Menu::draw() const
{
    if (currentState == Settings::GameState::Menu)
    {
        window->drawMenu(menu, selected);
    }
    else if (currentState == Settings::GameState::Options)
    {
        window->drawMenu(options, selected);
    }
    else if (currentState == Settings::GameState::Records)
    {
        const auto recordsList = Utils::FileManager::read("records.txt");
        window->drawMenu(records, selected, recordsList);
    }
    else if (currentState == Settings::GameState::Play)
    {
        window->drawPlay(playerBoard, isBigSize);
    }
    else if (currentState == Settings::GameState::PlayerVsCPU)
    {
        window->drawPlayerVsBot(playerBoard, botBoard, isBigSize);
    }
}
