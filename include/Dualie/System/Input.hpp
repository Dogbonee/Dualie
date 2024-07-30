//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_INPUT_HPP
#define DUALIE_INPUT_HPP


#include <citro2d.h>
#include <array>
#include <Dualie/System/Vector2.hpp>


namespace dl::Input {

    enum InputType{
        PRESSED = 0,
        HELD,
        RELEASED
    };

    enum Key{
        A       = BIT(0),       ///< A
        B       = BIT(1),       ///< B
        SELECT  = BIT(2),       ///< Select
        START   = BIT(3),       ///< Start
        DRIGHT  = BIT(4),       ///< D-Pad Right
        DLEFT   = BIT(5),       ///< D-Pad Left
        DUP     = BIT(6),       ///< D-Pad Up
        DDOWN   = BIT(7),       ///< D-Pad Down
        R       = BIT(8),       ///< R
        L       = BIT(9),       ///< L
        X       = BIT(10),      ///< X
        Y       = BIT(11),      ///< Y
        ZL      = BIT(14),      ///< ZL (New 3DS only)
        ZR      = BIT(15),      ///< ZR (New 3DS only)
        TOUCH   = BIT(20),      ///< Touch (Not actually provided by HID)
        CSTICK_RIGHT = BIT(24), ///< C-Stick Right (New 3DS only)
        CSTICK_LEFT  = BIT(25), ///< C-Stick Left (New 3DS only)
        CSTICK_UP    = BIT(26), ///< C-Stick Up (New 3DS only)
        CSTICK_DOWN  = BIT(27), ///< C-Stick Down (New 3DS only)
        CPAD_RIGHT = BIT(28),   ///< Circle Pad Right
        CPAD_LEFT  = BIT(29),   ///< Circle Pad Left
        CPAD_UP    = BIT(30),   ///< Circle Pad Up
        CPAD_DOWN  = BIT(31),   ///< Circle Pad Down

        // Generic catch-all directions
        UP    = DUP    | CPAD_UP,    ///< D-Pad Up or Circle Pad Up
        DOWN  = DDOWN  | CPAD_DOWN,  ///< D-Pad Down or Circle Pad Down
        LEFT  = DLEFT  | CPAD_LEFT,  ///< D-Pad Left or Circle Pad Left
        RIGHT = DRIGHT | CPAD_RIGHT, ///< D-Pad Right or Circle Pad Right
    };

     extern u32 KeyPressedMask;
     extern u32 KeyHeldMask;
     extern u32 KeyReleasedMask;


     /**
      * @brief The touch position of the screen. If the screen is not touched, This will be (0,0). See LastTouchPosition
      */
     extern dl::Vector2f TouchPosition;

    /**
     * @brief The touch position of the screen. If the screen is not touched, This will be the last valid touch of the screen. See TouchPosition
     */
     extern dl::Vector2f LastTouchPosition;

     /**
      * @brief Returns whether a certain key was pressed that frame. Note that this does not capture held buttons
      * @param key  The button to check
      * @return     Whether the button is pressed
      */
     bool isKeyPressed(Key key);

     /**
      * @brief Returns whether a certain key was held that frame.
      * @param key  The button to check
      * @return Whether the button is held
      */
     bool isKeyHeld(Key key);

     /**
      * @brief Returns whether a certain key was released that frame.
      * @param key  The button to check
      * @return Whether the button is released
      */
     bool isKeyReleased(Key key);


     void updateInput();

}


#endif //DUALIE_INPUT_HPP
