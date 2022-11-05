#ifndef LOOP_HPP
#define LOOP_HPP


namespace GameLoop
{
    class Loop
    {
    private:
        bool exit;
    public:
        Loop() : exit(false) {}

    public:
        void menu();
        void game();
    
    public:
        void quite();
    };

    Loop &loop();
} // namespace GameLoop

#endif