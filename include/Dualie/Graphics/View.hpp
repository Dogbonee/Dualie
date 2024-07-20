//
// Created by caleb on 6/18/24.
//

#ifndef DUALIE_VIEW_H
#define DUALIE_VIEW_H


#include <Dualie/System/Rect.hpp>
#include <Dualie/System/Vector2.hpp>

namespace dl{

class View {

private:
    dl::FloatRect m_viewRect;


public:


    View();
    View(const dl::FloatRect& viewRect);

    void reset(const dl::FloatRect& viewRect);
    void setCenter(dl::Vector2f center);
    void move(dl::Vector2f offset);

    dl::Vector2f getOffset();


};

}


#endif //DUALIE_VIEW_H
