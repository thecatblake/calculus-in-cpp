//
// Created by ryousuke kaga on 2023/11/15.
//

#ifndef CALCULUS_IN_CPP_CANVAS2D_H
#define CALCULUS_IN_CPP_CANVAS2D_H

#include <SDL.h>
#include <Eigen/Eigen>

class Canvas2D {
public:
    Canvas2D(int width, int height);
    void write_pixel(int  x, int y, const Eigen::Vector3d& color);
    void shutdown();
    void wait();
private:
    SDL_Window* mWindow;
    SDL_Renderer* mRender;
    bool mIsRunning;
    int mWidth;
    int mHeight;
};


#endif //CALCULUS_IN_CPP_CANVAS2D_H
