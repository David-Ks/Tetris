#ifndef OBJECT_TOOL_CPP
#define OBJECT_TOOL_CPP

#include "../../src/Figures/Figure.hpp"
#include <vector>

namespace Utils
{
    namespace Objects
    {
        void push(std::vector<Object::Figure *> &_list, Object::Figure *obj, Position pos)
        {
            obj->setPos(pos);
            _list.push_back(obj);
        }

        void del(Object::Figure *&obj)
        {
            for (auto &block : obj->blocks)
            {
                if (!block)
                    continue;

                delete block;
                block = 0;
            }

            delete obj;
            obj = 0;
        }

        void clear(std::vector<Object::Figure *> &_list)
        {
            for (auto &obj : _list)
            {
                if (!obj)
                    continue;

                del(obj);
            }

            _list.clear();
        }

        Object::Figure *getPenultItem(const std::vector<Object::Figure *> &_list)
        {
            const int size = _list.size();
            if (size > 1)
                return _list[size - 2];

            return 0;
        }

        Object::Figure *getlastItem(const std::vector<Object::Figure *> &_list)
        {
            const int size = _list.size();
            if (size > 0)
                return _list[size - 1];

            return 0;
        }
    } // namespace ObjectList
} // namespace Object

#endif