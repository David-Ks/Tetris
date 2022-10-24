#include "FigureList.hpp"

void Utils::FigureList::add(Object::Figure *figure)
{
    _list.push_back(figure);
}

void Utils::FigureList::del(Object::Figure *delFigure)
{
    for (auto &figure : _list)
    {
        if (figure == delFigure)
        {
            delete figure;
            figure = 0;
            break;
        }
    }
}

Utils::FigureList::FiugreVector Utils::FigureList::items() const
{
    return _list;
}

std::vector<Object::Figure *>::iterator Utils::FigureList::begin()
{
    return _list.begin();
}

std::vector<Object::Figure *>::iterator Utils::FigureList::end()
{
    return _list.end();
}