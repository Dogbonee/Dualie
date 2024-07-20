//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_RENDERWINDOW_HPP
#define DUALIE_RENDERWINDOW_HPP
#include <citro2d.h>
#include <Dualie/Graphics/Color.hpp>
#include <Dualie/Graphics/Drawable.hpp>
#include <Dualie/System/Input.hpp>
#include <Dualie/Graphics/View.hpp>

namespace dl {

    enum SCREEN {
        TOP_SCREEN = 0,
        BOTTOM_SCREEN = 1
    };


    class RenderWindow {

    public:
        RenderWindow();
        ~RenderWindow();

        void InitPrintScreen(SCREEN screen);
        void print(std::string str, int x, int y);

        void clear(SCREEN screen, Color color = dl::Color(255, 255, 255));
        void draw(const dl::Drawable& drawable);
        void display();
        bool isOpen();

        void setView(const dl::View& view);
        dl::Vector2f getCurrentViewOffset();



    private:
        C3D_RenderTarget* m_screens[2];
        dl::View m_view;


    };

}


#endif //DUALIE_RENDERWINDOW_HPP
