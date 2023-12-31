#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "Bullet.h"

/// <summary>
/// 弾の管理を行うクラス
/// </summary>
class BulletPool {
public:
	std::vector<Bullet> current_field_bullet_list = {};
	static constexpr int MAX_BULLET_NUM = 10;

	void update(float delta_time);
	void draw();
	void shotRequest();
	void generateBullet();
};

extern BulletPool bullet_pool;