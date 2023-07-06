#pragma once
#include "Enemy.h"

class EnemyPool {
public:
	float time_ = 0;
	std::vector<Enemy> enemy_list = {};
	void update(float delta_time);
	void draw();
	void setup();
};

extern EnemyPool enemy_pool;