#ifndef MENU_HPP
#define MENU_HPP

#include "../../Settings.hpp"
#include "../Window/Output/NcursesWindow.hpp"
#include "../EventSystem/EventSystem.hpp"
#include "../Player/Player.hpp"
#include "../Board/PlayerBoard.hpp"
#include "../Board/BotBoard.hpp"
#include "../../utils/FileManager.hpp"

#include <string>
#include <vector>

class Menu
{
private:
    using Section = std::string;
    using Sections = std::vector<Section>;

private:
    Settings::GameState &currentState;
    EventSystem &eventSystem;
    const Window *window;

    int selected = 0;
    bool isBigSize = false;

    Player player;
    Player bot;

    Board *playerBoard;
    Board *botBoard;

    const Sections menu{"Play",
                         "PlayerVsCPU",
                         "Options",
                         "Records",
                         "Exit"};

    const Sections records{"Back"};

    Sections options{"Size 1x (+)",
                      "Size 2x",
                      "Back"};

public:
    Menu(Settings::GameState &state, EventSystem &eventSystem, const Window *win);

public:
    void draw() const;

private:
    void select();
    void moveDownSelector();
    void moveUpSelector();
};

#endif // MENU_HPP