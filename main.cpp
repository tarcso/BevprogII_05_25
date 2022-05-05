#include "gordmenu.hpp"
#include "menuelem.hpp"
#include "szambeall.hpp"
#include "pushbutton.hpp"
#include "Window.hpp"
#include "textbox.hpp"
#include <vector>
#include <iostream>
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

    public:
        Calculator()
        {
            muvelet = false;
            current = 0;
            previous = 0;
            std::cout << allapot << std::endl;
            ered = 0;
            std::vector<PushButton*> v;
            m_elemek.push_back(new PushButton(this, XX/5.0, 400, 30, 30, "1", [this](){
                if(current == ered) current = 0;
                current = current * 10 + 1;
                txt->setText(std::to_string(current));
            }));
            m_elemek.push_back(new PushButton(this, XX/5.0+30, 400, 30, 30, "2", [this](){
                if(current == ered) current = 0;
                current = current * 10 + 2;
                txt->setText(std::to_string(current));
            }));
            m_elemek.push_back(new PushButton(this, XX/5.0+60, 400, 30, 30, "3", [this](){
                if(current == ered) current = 0;
                current = current * 10 + 3;
                txt->setText(std::to_string(current));
            }));
            m_elemek.push_back(new PushButton(this, XX/5.0, 430, 30, 30, "4", [this](){
                if(current == ered) current = 0;
                current = current * 10 + 4;
                txt->setText(std::to_string(current));
            }));
            m_elemek.push_back(new PushButton(this, XX/5.0+30, 430, 30, 30, "5", [this](){
                if(current == ered) current = 0;
                current = current * 10 + 5;
                txt->setText(std::to_string(current));
            }));
            m_elemek.push_back(new PushButton(this, XX/5.0+60, 430, 30, 30, "6", [this](){
                if(current == ered) current = 0;
                current = current * 10 + 6;
                txt->setText(std::to_string(current));
            }));
            m_elemek.push_back(new PushButton(this, XX/5.0, 460, 30, 30, "7", [this](){
                if(current == ered) current = 0;
                current = current * 10 + 7;
                txt->setText(std::to_string(current));
            }));
            m_elemek.push_back(new PushButton(this, XX/5.0+30, 460, 30, 30, "8", [this](){
                if(current == ered) current = 0;
                current = current * 10 + 8;
                txt->setText(std::to_string(current));
            }));
            m_elemek.push_back(new PushButton(this, XX/5.0+60, 460, 30, 30, "9", [this](){
                if(current == ered) current = 0;
                current = current * 10 + 9;
                txt->setText(std::to_string(current));
            }));
            m_elemek.push_back(new PushButton(this, XX/5.0+30, 490, 30, 30, "0", [this](){
                if(current == ered) current = 0;
                current = current * 10;
                txt->setText(std::to_string(current));
            }));
            txt = new textBox(this, XX/5.0, 370, 150, 30, "");
            add = new PushButton(this, XX/5.0+90, 400, 30, 30, "+", [this](){allapot = ADD; muvelet = true; previous = current; current = 0; txt->setText("");});
            sub = new PushButton(this, XX/5.0 + 120, 400, 30, 30, "-", [this](){allapot = SUBSTRACT; muvelet = true; previous = current; current = 0; txt->setText("");});
            multi = new PushButton(this, XX/5.0 + 90, 430, 30, 30, "*", [this](){allapot = MULTIPLY; muvelet = true; previous = current; current = 0; txt->setText("");});
            div = new PushButton(this, XX/5.0 + 120, 430, 30, 30, "/", [this](){allapot = DIVISION; muvelet = true; previous = current; current = 0; txt->setText("");});
            equal = new PushButton(this, XX/5.0 + 90, 460, 60, 60, "=", [this](){if(allapot < 4)muvVegez(allapot);});
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