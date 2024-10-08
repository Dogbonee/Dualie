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
    m_screens[TOP_SCREEN + 1] = C2D_CreateScreenTarget(GFX_TOP, GFX_RIGHT);
    m_screens[BOTTOM_SCREEN] = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);




    ndspInit();
    ndspChnReset(0);
    ndspSetOutputMode(NDSP_OUTPUT_STEREO);
    ndspChnSetInterp(0, NDSP_INTERP_POLYPHASE);
    ndspChnSetRate(0, Music::SAMPLE_RATE);
    ndspChnSetFormat(0, NDSP_FORMAT_STEREO_PCM16);

}

dl::RenderWindow::~RenderWindow() {
    C2D_Fini();
    C3D_Fini();
    romfsExit();
    cfguExit();
    gfxExit();
    ndspExit();
}


void dl::RenderWindow::InitPrintScreen(dl::SCREEN screen) {
    consoleInit(screen < 2 ? GFX_TOP : GFX_BOTTOM, NULL);
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

    m_currentScreen = screen;
    C3D_FrameBegin(0);

    C2D_TargetClear(m_screens[screen] ,color.getColorValue());
    if(m_currentScreen == TOP_SCREEN)
    {
        C2D_TargetClear(m_screens[screen + 1], color.getColorValue());
    }

}

void dl::RenderWindow::draw(dl::Drawable &drawable) {

    m_drawQueue.push_back(&drawable);

}

void dl::RenderWindow::display() {
    auto offset = m_view.getOffset();
    if(m_3dActive && m_currentScreen == TOP_SCREEN){
        //Draw for the left eye
        C2D_SceneBegin(m_screens[m_currentScreen]);
        for(auto& drawable : m_drawQueue){
            drawable->draw(dl::Vector2f(offset.x + drawable->getDepth() * dl::Input::SliderValue, offset.y));
        }
        //Draw for the right eye
        C2D_SceneBegin(m_screens[m_currentScreen + 1]);
        for(auto& drawable : m_drawQueue){
            drawable->draw(dl::Vector2f(offset.x - drawable->getDepth() * dl::Input::SliderValue, offset.y));
        }
    }else{
        C2D_SceneBegin(m_screens[m_currentScreen]);
        for(auto& drawable : m_drawQueue){
            drawable->draw(offset);
        }
    }
    m_drawQueue.clear();
    C3D_FrameEnd(0);
}

void dl::RenderWindow::setView(const dl::View &view) {
    m_view = view;
}

dl::Vector2f dl::RenderWindow::getCurrentViewOffset() {
    return m_view.getOffset();
}

void dl::RenderWindow::set3dActive(bool active)
{
    gfxSet3D(active);
    m_3dActive = active;
}





