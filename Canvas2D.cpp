//
// Created by ryousuke kaga on 2023/11/15.
//

#include "Canvas2D.h"

Canvas2D::Canvas2D(int width, int height): mWidth(width), mHeight(height), mIsRunning(true) {
    mWindow = SDL_CreateWindow(
            "Canvas",
            100,
            100,
            mWidth,
            mHeight,
            0
    );

    if (!mWindow) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return;
    }

    mRender = SDL_CreateRenderer(
            mWindow,
            -1,
            SDL_RENDERER_ACCELERATED
    );
}

void Canvas2D::shutdown() {
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRender);
    SDL_Quit();
}

void Canvas2D::write_pixel(int x, int y, const Eigen::Vector3d &color) {
    int r = (int)(color(0) * 255.0);
    int g = (int)(color(1) * 255.0);
    int b = (int)(color(2) * 255.0);
    SDL_SetRenderDrawColor(mRender, r, g, b, 255);
    SDL_RenderDrawPoint(mRender, x, y);
}

void Canvas2D::wait() {
    SDL_RenderPresent(mRender);

    SDL_Event event;

    while(mIsRunning) {
        while (SDL_PollEvent(&event)) {
            switch (event.type)
            {
                case SDL_QUIT:
                    mIsRunning = false;
                    break;
            }
        }

    }
}
