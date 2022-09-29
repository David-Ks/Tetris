#ifndef WINDOW_H
#define WINDOW_H

#include "../Settings.cpp"
#include <vector>


namespace Draw
{
    enum Section
    {
        PLAY = 0,
        RECORDS,
        EXIT
    };

    class Window
    {
    protected:
        Section section;
    
    public:
        static const std::vector<std::string>menuItems;

    public:
        Window() : section(Section::PLAY) {}
        virtual ~Window() {}

    public:
        virtual void drawMenu() = 0;
        virtual void drawGame() = 0;
        virtual void clean() = 0;
        virtual int input() = 0;
    
    public:
        void setSection(Section section) { this->section = section; }
        Section getSection() { return section; }
    };

    const std::vector<std::string> Window::menuItems = {
        "Play",
        "Records",
        "Exit"
    };

    Window *window();
} // namespace Draw

#endif