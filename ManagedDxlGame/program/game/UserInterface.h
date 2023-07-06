#pragma once
#include "../dxlib_ext/dxlib_ext.h"

using namespace std;

class UserInterface {
	int score_ = 0;
	std::string help_ = "←→キーで左右に移動。スペースキーで弾発射";
	std::string gameover_ = "GAME OVER";
	tnl::Vector3 help_show_pos_ = {100, 600, 0};
	tnl::Vector3 score_show_pos_ = {100, 650, 0};
	tnl::Vector3 gameover_show_pos_ = {DXE_WINDOW_WIDTH / 2 - 250, DXE_WINDOW_HEIGHT / 2, 0};
	int fontsize_ = 50;

public:
	void addScore(int point);
	void draw();
};

extern UserInterface user_interface;