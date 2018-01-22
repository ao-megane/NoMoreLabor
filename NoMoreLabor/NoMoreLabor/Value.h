#ifndef VALUE_H
#define VALUE_H
#include"DxLib.h"

const int RED = GetColor(255, 0, 0);
const int GREEN = GetColor(0, 255, 0);
const int BLUE = GetColor(0, 0, 255);
const int WHITE = GetColor(255, 255, 255);

const int DISP_WIDTH = 1280;
const int DISP_HEIGHT = 800;
//1920*1080

const int KEY_NUM = 6;

const double PI = 3.14159265358979;
const double gra = 9.8;
const double rootTwo = 1.4142135624;
const double rootThree = 1.7320508;

const double F_ABS_MAX = DISP_WIDTH;

const int P_HEIGHT = 544 * 0.05;//プレイヤーの描画の大きさ
const int P_WIDTH = 928 * 0.05;
const double ACCELE = 1.0;
const double BRAKE = -0.5;
const double LIMIT = 20.0;
const double ADDED_ANGLE = PI / 24.0;
const double DECAY_STRAIGHT = 0.999;
const double DECAY_SIDE = 0.8;

const int M_X = DISP_WIDTH - 100;
const int M_Y = DISP_HEIGHT - 100;
const int M_RANGE = 80;

const int MAX_SPEED = 40;

const int WAVE_INTERVAL = 20 * 60;//フレーム
const int WAVE_SPEED = 2;//pixel / frame
const int WAVE_BAND = 50;

#endif // !VALUE_H
