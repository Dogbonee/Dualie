//
// Created by caleb on 6/16/24.
//

#include <Dualie/Graphics/RenderWindow.hpp>


dl::RenderWindow::RenderWindow() {

    romfsInit();
    cfguInit();
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();

    m_screens[TOP_SCREEN] = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    m_screens[BOTTOM_SCREEN] = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

}

dl::RenderWindow::~RenderWindow() {
    C2D_Fini();
    C3D_Fini();
    romfsExit();
    cfguExit();
    gfxExit();
}


void dl::RenderWindow::InitPrintScreen(dl::SCREEN screen) {
    consoleInit((gfxScreen_t)screen, NULL);
}

void dl::RenderWindow::print(std::string str, int x, int y) {
    printf("\x1b[%s;%sH%s", std::to_string(y).c_str(), std::to_string(x).c_str(), str.c_str());
}



bool dl::RenderWindow::isOpen() {

    hidScanInput();
    dl::Input::updateInput();
    return aptMainLoop();
}

void dl::RenderWindow::clear(SCREEN screen, Color color) {

    C3D_FrameBegin(0);
    C2D_TargetClear(m_screens[screen] ,color.getColorValue());
    C2D_SceneBegin(m_screens[screen]);
}

void dl::RenderWindow::draw(const dl::Drawable &drawable) {
    drawable.draw(m_view.getOffset());
}

void dl::RenderWindow::display() {
    C3D_FrameEnd(0);
}

void dl::RenderWindow::setView(const dl::View &view) {
    m_view = view;
}

dl::Vector2f dl::RenderWindow::getCurrentViewOffset() {
    return m_view.getOffset();
}





