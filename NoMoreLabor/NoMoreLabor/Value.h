#ifndef VALUE_H
#define VALUE_H
#include"DxLib.h"

//定数をまとめておくヘッダー

const int RED = GetColor(255, 0, 0);		//赤の色コード
const int GREEN = GetColor(0, 255, 0);		//緑の色コード
const int BLUE = GetColor(0, 0, 255);		//青の色コード
const int WHITE = GetColor(255, 255, 255);	//白の色コード

const int DISP_WIDTH = 1280;	//ディスプレイの画素（横）
const int DISP_HEIGHT = 800;	//ディスプレイの画素（縦）

const double PI = 3.14159265358979;		//円周率
const double rootTwo = 1.4142135624;	//ルート2
const double rootThree = 1.7320508;		//ルート3

const double F_ABS_MAX = DISP_WIDTH;	//力の最大値（モーターの感度）

const int P_HEIGHT = 544 * 0.05;			//プレイヤーの描画の大きさ
const int P_WIDTH = 928 * 0.05;				//
const double ACCELE = 1.0/2.0;				//1フレーム当たりの加速度の大きさ
const double BRAKE = -0.5;					//1フレーム当たりのブレーキの強さ
const double LIMIT = 20.0/2;				//制限速度
const double ADDED_ANGLE = PI / 24.0/2.0;	//1フレーム当たりの回転角度
const double DECAY_STRAIGHT = 0.999;		//縦方向の抵抗率
const double DECAY_SIDE = 0.8;				//横方向の低効率
const double JUMPING_TIME = 30.0;			//ジャンプに要するフレーム数

const int M_X = DISP_WIDTH - 100;			//コーススタート時のマウスの初期位置（横）
const int M_Y = DISP_HEIGHT - 100;			//コーススタート時のマウスの初期位置（縦）
const int M_RANGE = 80;						//描画用、円の半径

const int WAVE_INTERVAL = 20 * 60;	//波の生まれる間隔（フレーム）
const int WAVE_SPEED = 2;			//1フレーム当たりの波の進む速度
const int WAVE_BAND = 50;			//波の太さ

const int SPL_NUM = 100;				//同時に描画する波の個数（ライフタイムにも依存している）
const int SPL_INTERVAL = 0.05 * 60;		//何フレームごとに飛沫が発生するか
const double SPL_LIFETIME = 3.0 * 60.0;	//何フレームで飛沫の描画が終わるか

#endif // !VALUE_H
