#ifndef WINDOW_H
#define WINDOW_H

namespace Draw
{
    class Window
    {
    public:
        Window() {}
        virtual ~Window() {}

    public:
        virtual void drawMenu(unsigned &choice) = 0;
        virtual void drawGame() = 0;
        virtual void clean() = 0;
        virtual int input() = 0;
    };
} // namespace Draw

#endif