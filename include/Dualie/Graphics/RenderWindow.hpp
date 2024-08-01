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
#include <Dualie/Audio/Music.hpp>
#include <vector>

namespace dl {

    enum SCREEN {
        TOP_SCREEN = 0,
        BOTTOM_SCREEN = 2
    };



    /**
     * @brief A interface for rendering. Includes both top and bottoms screens as targets.
     */
    class RenderWindow {

    public:
        RenderWindow();
        ~RenderWindow();

        /**
         * @brief Initializes a screen to use for printing. Note that if a screen is initialized for printing and then
         * rendered to, it will render garbage.
         * @param screen    Screen to initizalize printing for
         */
        void InitPrintScreen(SCREEN screen);

        /**
         * @brief Prints text to the screen. A screen must be initialized using RenderWindow::InitPrintScreen for this
         * to work
         * @param str   The string to print
         * @param x     X position of text
         * @param y     Y position of text
         */
        void print(std::string str, int x, int y);

        /**
         * @brief Clears a screen and prepares it for rendering. Note that RenderWindow::draw and RenderWindow::display
         * will target the screen last cleared
         *
         * @param screen    The screen to clear
         * @param color     The clear color
         */
        void clear(SCREEN screen, Color color = dl::Color(0,0,0));

        /**
         * @brief Draws a drawable to the screen
         * @param drawable      The drawable object to draw to the screen
         */
        void draw(dl::Drawable& drawable);

        /**
         * @brief Displays rendered objects to the screen. Note that this will only display the objects drawn on the
         * last cleared screen. Screens must be cleared, drawn to, and displayed separately.
         */
        void display();

        /**
         * @brief   A function that should be used as a main loop. It also handles the updating of input.
         * @return  Whether the program is open or not.
         */
        bool isOpen();


        /**
         * @brief Sets a view to the screen
         * @param view  The view to set
         */
        void setView(const dl::View& view);

        /**
         * @brief Determines whether the stereoscopic 3d effect should be active or not
         * @param active    Whether the effect is active
         */
        void set3dActive(bool active);

        /**
         * @brief Gets the current render offset in pixels that the current view causes
         * @return  The render offset in pixels that the current view causes
         */
        dl::Vector2f getCurrentViewOffset();



    private:
        C3D_RenderTarget* m_screens[3];
        SCREEN m_currentScreen;
        dl::View m_view;
        bool m_3dActive;
        std::vector<dl::Drawable*> m_drawQueue;


    };

}


#endif //DUALIE_RENDERWINDOW_HPP
