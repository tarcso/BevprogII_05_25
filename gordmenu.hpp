#ifndef GORDMENU_HPP_INCLUDED
#define GORDMENU_HPP_INCLUDED

#include "widgets.hpp"

class MenuElem;

class GordMenu : public Widget
{
protected:
    std::string m_szov;
    std::vector<MenuElem*> m_elemek;
    bool m_gorg;
    int m_gorgsz, m_nyomott, m_hatardb;
    double m_gordmax;


public:
    GordMenu(Window* window,int x, int y, int sx, int sy, std::string szov, std::vector<std::string>, int darab);
    void draw() const;
    void handle(const genv::event& ev);
    void hozzaadElem(std::string s);
    void torolElem(std::string s);
    bool is_selected(int mx, int my) const;
    std::string allapot() const;
    void reset();
};

#endif // GORDMENU_HPP_INCLUDED