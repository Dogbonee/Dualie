//
// Created by caleb on 6/16/24.
//

#include "Dualie/System/Input.hpp"


u32 dl::Input::KeyPressedMask = 0;
u32 dl::Input::KeyHeldMask = 0;
u32 dl::Input::KeyReleasedMask = 0;
dl::Vector2f dl::Input::TouchPosition = dl::Vector2f(0,0);
dl::Vector2f dl::Input::LastTouchPosition = dl::Vector2f(0,0);

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

    touchPosition touch;
    hidTouchRead(&touch);
    TouchPosition = dl::Vector2f(touch.px, touch.py);
    if(TouchPosition.x + TouchPosition.y != 0){
        LastTouchPosition = TouchPosition;
    }
}
