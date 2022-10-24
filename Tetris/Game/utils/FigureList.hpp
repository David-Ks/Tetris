#ifndef FIGURE_LIST_HPP
#define FIGURE_LIST_HPP

#include "../Figures/Figure.hpp"

#include <vector>

namespace Utils
{
    class FigureList
    {
    public:
        using FiugreVector = std::vector<Object::Figure *>;

    private:
        FiugreVector _list;

    public:
        FigureList() {}
        std::vector<Object::Figure *>::iterator begin();
        std::vector<Object::Figure *>::iterator end();
    
    public:
        void add(Object::Figure*);
        void del(Object::Figure*);
        FiugreVector items() const;

    };
} // namespace Utils

#endif