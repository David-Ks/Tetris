#ifndef INPUT_HPP
#define INPUT_HPP

#include "../../../Settings.hpp"

class Input
{
public:
    Input() {}
    virtual ~Input() {}

public:
    virtual int getKey() const = 0;
};

#endif // INPUT_HPP