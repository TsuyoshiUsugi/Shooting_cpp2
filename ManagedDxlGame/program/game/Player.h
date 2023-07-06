#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Player {
	bool is_death_ = false;
public:
	static constexpr int SIZE_WIDTH = 100;
	static constexpr int SIZE_HEIGHT = 30;
	static constexpr int MOVE_SPEED = 5;
	tnl::Vector3 pos_ = { DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT * 0.8f, 0 };

	bool get_is_death() { return is_death_; }
	
	void update(float delta_time);
	void draw();
	void Shot();
};

extern Player player;
