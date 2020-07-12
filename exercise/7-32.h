#ifndef _07_32_H
#define _07_32_H

#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::cin; using std::string; using std::vector;

class Screen;

class Window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    vector<Screen> screens{Screen(24,80,' ')};
};

class Screen {
public:
    friend void Window_mgr::clear(ScreenIndex i);
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd);
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) {}

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos ht, pos wd, char c);
    inline Screen& display(std::ostream &os);
    inline const Screen& display(std::ostream &os) const;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    void do_display(std::ostream &os) const {
        os << contents;
    }
};


Screen::Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd, ' ') {}

char Screen::get(pos r, pos c) const {
    pos row = r*width;
    return contents[row+c];
}

Screen& Screen::move(pos r, pos c) {
    pos row = r*width;
    cursor = row+c;
    return *this;
}

Screen& Screen::display(std::ostream &os){
    do_display(os);
    return *this;
}

Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen& Screen::set(pos row, pos col, char ch) {
    contents[row*width+col] = ch;
    return *this;
}

const Screen& Screen::display(std::ostream &os) const {
    do_display(os);
    return *this;
}

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height*s.width, ' ');
}

#endif