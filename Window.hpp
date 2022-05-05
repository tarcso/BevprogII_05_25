#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>

class Window
{
protected:
    std::vector<Widget*> widgets;

public:
    Window();
    void event_loop();
    void registerwidget(Widget* widget) {widgets.push_back(widget);}
    virtual void esemeny(const std::string& ki_mondta) = 0;
};


#endif // OSABLAK_HPP_INCLUDED