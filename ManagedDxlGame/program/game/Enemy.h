#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Enemy {
public:
	int hp_ = 1;
	tnl::Vector3 pos_ = { 10, 10, 0 };

	static constexpr int SIZE_WIDTH = 50;
	static constexpr int SIZE_HEIGHT = 50;
	static constexpr int MOVE_SPEED = 5;

	void update(float delta_time);
	void draw();
};

extern Enemy enemy;