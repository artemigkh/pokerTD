//
// Created by Artem on 10/6/2017.
//

#ifndef POKERTD_GRAPHICSCONSTANTS_H
#define POKERTD_GRAPHICSCONSTANTS_H

namespace grc{
    const int SPRITE_HEIGHT = 48;
    const int SPRITE_WIDTH = 48;
    const int SPRITE_SHEET_NUM_X = 3;
    const int SPRITE_SHEET_NUM_Y = 4;
    const int SPRITE_SHEET_GROUP_HEIGHT = SPRITE_HEIGHT * SPRITE_SHEET_NUM_Y;
    const int SPRITE_SHEET_GROUP_WIDTH = SPRITE_WIDTH * SPRITE_SHEET_NUM_X;

    const int NUM_TICKS_IN_SPRITE_FRAME = 10;

    const int TOWER_WINDOW_WIDTH = 300;
    const int TOWER_WINDOW_HEIGHT = 1100;

    const int MENU_TITLE_HEIGHT = 100;
    const float MENU_DISTANCE = 88.5;
    const int MENU_LEFT_MARGIN = 20;

    const int NAME_TEXT_SIZE = 20;
    const int DESC_TEXT_SIZE = 12;
    const int DESC_TOP_MARGIN = 6;
    const int DESC_SIDE_OFFSET = 75;

    const int HP_BAR_HEIGHT = 5;
    const int HP_BAR_WIDTH = 45;
    const int HP_BAR_OFFSET = SPRITE_HEIGHT;
}

#endif //POKERTD_GRAPHICSCONSTANTS_H
