#ifndef OBJECT_TOOL_CPP
#define OBJECT_TOOL_CPP

#include "../../src/Figures/Figure.hpp"
#include <vector>

namespace Utils
{
    namespace Objects
    {
        void push(std::vector<Object::Figure *> &_list, Object::Figure *obj, const Position pos);
        void del(Object::Figure *&obj);
        void clear(std::vector<Object::Figure *> &_list);
        Object::Figure *getPenultItem(const std::vector<Object::Figure *> &_list);
        Object::Figure *getLastItem(const std::vector<Object::Figure *> &_list);
    } // namespace Objects
} // namespace Utils

#endif