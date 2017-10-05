//
// Created by Artem on 10/3/2017.
//

#ifndef POKERTD_CONST_H
#define POKERTD_CONST_H

namespace gameConstant{
    const int WINDOW_HEIGHT = 1000;
    const int WINDOW_WIDTH = 1000;
    const int NUM_SQUARES_HIGH = 8;
    const int NUM_SQUARES_WIDE = 8;
    const int SQUARE_HEIGHT = WINDOW_HEIGHT / NUM_SQUARES_HIGH;
    const int SQUARE_WIDTH = WINDOW_WIDTH / NUM_SQUARES_WIDE;

    const unsigned int SQUARE_HEIGHT_UNSIGNED = WINDOW_HEIGHT / NUM_SQUARES_HIGH;
    const unsigned int SQUARE_WIDTH_UNSIGNED = WINDOW_WIDTH / NUM_SQUARES_WIDE;

    const int FRAMES_PER_SECOND = 60;
}


#endif //POKERTD_CONST_H
