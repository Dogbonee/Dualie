//
// Created by caleb on 6/16/24.
//

#include "Dualie/System/Input.hpp"


u32 dl::Input::KeyPressedMask = 0;
u32 dl::Input::KeyHeldMask = 0;
u32 dl::Input::KeyReleasedMask = 0;
float dl::Input::SliderValue = 0;
dl::Vector2u dl::Input::TouchPosition = dl::Vector2u(0, 0);
dl::Vector2u dl::Input::LastTouchPosition = dl::Vector2u(0,0);
dl::Vector2i dl::Input::CirclePadPosition = dl::Vector2i(0,0);

bool dl::Input::isKeyPressed(dl::Input::Key key) {
    return KeyPressedMask & key;
}

bool dl::Input::isKeyHeld(dl::Input::Key key) {
    return KeyHeldMask & key;
}

bool dl::Input::isKeyReleased(dl::Input::Key key) {
    return KeyReleasedMask & key;
}

void dl::Input::updateInput() {
    KeyPressedMask = hidKeysDown();
    KeyHeldMask = hidKeysHeld();
    KeyReleasedMask = hidKeysUp();
    SliderValue = osGet3DSliderState();

    touchPosition touch;
    hidTouchRead(&touch);
    TouchPosition = dl::Vector2u(touch.px, touch.py);

    circlePosition pos;
    hidCircleRead(&pos);
    CirclePadPosition = dl::Vector2i(pos.dx, pos.dy);

    if(TouchPosition.x + TouchPosition.y != 0){
        LastTouchPosition = TouchPosition;
    }
}
