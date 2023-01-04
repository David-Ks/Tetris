#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../../Board/Board.hpp"
#include "../../../Settings.hpp"
#include "../../../utils/FileManager.hpp"

#include <string>
#include <vector>

class Window
{
protected:
    using Sections = std::vector<std::string>;
    using Matrix = std::vector<std::vector<char>>;
    using Additionl = std::vector<std::string>;

    int width;
    int height;

    // Options
    bool isBigSize = false;

    Settings::GameState &currentState;

public:
    Window(Settings::GameState &state) : currentState(state) {}
    virtual ~Window() {}

public:
    virtual void drawPlay(const Board *, const bool bigSize) const = 0;
    virtual void drawPlayerVsBot(const Board *, const Board *, const bool bigSize) const = 0;
    virtual void drawMenu(const Sections &, int selected, const Additionl &lines = {}) const = 0;
};

#endif // WINDOW_HPP