#include "gordmenu.hpp"
#include "menuelem.hpp"
#include "szambeall.hpp"
#include "pushbutton.hpp"
#include "Window.hpp"
#include "textbox.hpp"
#include <vector>
#include <fstream>
#include <functional>

using namespace genv;

const int XX = 400;
const int YY = 600;

enum muveletek {ADD, DIVISION, SUBSTRACT, MULTIPLY};

class Calculator : public Window
{
    private:
        std::vector<PushButton*> m_elemek;
        PushButton* add;
        PushButton* div;
        PushButton* sub;
        PushButton* multi;
        PushButton* equal;
        textBox* txt;
        int current;
        int previous;
        int ered;
        bool muvelet;
        muveletek allapot;
        int meret;
        int kozpontx;
        int kozponty;

    public:
        Calculator()
        {
            meret = 80;
            kozpontx = 0;
            kozponty = 2*meret;
            muvelet = false;
            current = 0;
            previous = 0;
            ered = 0;
            std::vector<PushButton*> v;
            for (int i = 0; i < 9; i++)
            {
                m_elemek.push_back(new PushButton(this, kozpontx + i%3 * meret, kozponty + i/3 * meret, meret, meret, std::to_string(i+1), [=](){
                    if(current == ered) current = 0;
                    current = current * 10 + i + 1;
                    txt->setText(std::to_string(current));
                }));
            }
            
            m_elemek.push_back(new PushButton(this, kozpontx+meret, kozponty + 3*meret, meret, meret, "0", [this](){
                if(current == ered) current = 0;
                current = current * 10;
                txt->setText(std::to_string(current));
            }));
            txt = new textBox(this, kozpontx, kozponty - meret, 5*meret, meret, "");
            add = new PushButton(this, kozpontx+3*meret, kozponty, meret, meret, "+", [this](){allapot = ADD; muvelet = true; previous = current; current = 0; txt->setText("");});
            sub = new PushButton(this, kozpontx + 3*meret, kozponty + meret, meret, meret, "-", [this](){allapot = SUBSTRACT; muvelet = true; previous = current; current = 0; txt->setText("");});
            multi = new PushButton(this, kozpontx + 4*meret, kozponty, meret, meret, "*", [this](){allapot = MULTIPLY; muvelet = true; previous = current; current = 0; txt->setText("");});
            div = new PushButton(this, kozpontx + 4*meret, kozponty + meret, meret, meret, "/", [this](){allapot = DIVISION; muvelet = true; previous = current; current = 0; txt->setText("");});
            equal = new PushButton(this, kozpontx + 3*meret, kozponty + 2*meret, 2 * meret, 2*meret, "=", [this](){if(allapot < 4)muvVegez(allapot);});
        }

        void muvVegez(muveletek muv)
        {
            if(muv == ADD)
            {
                ered  = current + previous;
            }

            if(muv == SUBSTRACT)
            {
                ered  = previous - current;
            }

            if(muv == DIVISION)
            {
                ered = previous / current;
            }

            if(muv == MULTIPLY)
            {
                ered = previous * current;
            }

            current = ered;
            previous = 0;
            muvelet = false;
            txt->setText(std::to_string(ered));
        }

        void esemeny(const std::string& ki_mondta)
        {}
};

int main()
{
    gout.open(XX, YY);
    gout.load_font("LiberationSans-Regular.ttf");
    Calculator* c = new Calculator;
    c->event_loop();
    return 0;
}