#ifndef EVENT_H
#define EVENT_H

namespace Listen
{
    class Event
    {
    public:
        Event() {}
        virtual ~Event() {}

    public:
        int getKey()
        {
            return Draw::window()->input();
        }

        virtual void handler(unsigned &choice) = 0;
    };
} // namespace Listen

#endif