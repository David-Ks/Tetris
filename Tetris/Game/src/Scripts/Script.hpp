#ifndef SCRIPT_HPP
#define SCRIPT_HPP

namespace Scenario
{
    class Script
    {
    public:
        Script() {}
        virtual ~Script() {}

    public:
        virtual void start() = 0;
        virtual void update() = 0;
    };
} // namespace Scenario

#endif