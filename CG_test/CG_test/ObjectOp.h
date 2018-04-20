#pragma once

#include "Ball.h"
#include "Cube.h"


void ballCollideFloor(Ball& ball, float CubeNumber, float friction);
//consumeRate<=1.0
void ballCollideBall(Ball& ball_1, Ball& ball_2, float friction);
void ballCollideBall_rotate(Ball& b1, Ball& b2);