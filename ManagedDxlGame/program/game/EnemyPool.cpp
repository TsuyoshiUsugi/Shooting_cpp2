#include "EnemyPool.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "BulletPool.h"
#include "UserInterface.h"
#include "Player.h"

EnemyPool enemy_pool;
int enemy_num = 10;

void EnemyPool::update(float delta_time) {
	enemy_pool.time_ += delta_time;


	for (int i = 0; i < enemy_list.size(); i++)		//弾が一定のポジション以下になったら場所を上に戻す
	{
		if (enemy_pool.enemy_list[i].pos_.y > 600) {
			auto max = DXE_WINDOW_WIDTH;
			float x = GetRand(DXE_WINDOW_WIDTH);
			enemy_pool.enemy_list[i].pos_ = { x, 0, 0 };
		}
	}

	for (int i = 0; i < enemy_list.size(); i++)		//弾と敵の当たり判定を行う
	{
		if (player.get_is_death()) return;
		for (size_t j = 0; j < bullet_pool.current_field_bullet_list.size(); j++)
		{
			if (bullet_pool.current_field_bullet_list[j].state_ == BulletState::STAYING) continue;

			int n = tnl::IsIntersectRectToCorrectPosition(enemy_pool.enemy_list[i].pos_, enemy_pool.enemy_list[i].pos_, enemy_pool.enemy_list[i].SIZE_WIDTH, enemy_pool.enemy_list[i].SIZE_WIDTH,
				bullet_pool.current_field_bullet_list[j].get_pos_(), bullet_pool.current_field_bullet_list[j].SIZE_WIDTH, bullet_pool.current_field_bullet_list[j].SIZE_HEIGHT);

			if (n != 0)
			{
				float x = GetRand(DXE_WINDOW_WIDTH);
				user_interface.addScore(1);
				bullet_pool.current_field_bullet_list[j].reset();
				enemy_pool.enemy_list[i].pos_ = { x, 0, 0 };
			}
		}
		enemy_pool.enemy_list[i].update(delta_time);
	}
}

void EnemyPool::setup() {
	for (int i = 0; i < enemy_num; i++)
	{
		Enemy enemy;
		enemy_pool.enemy_list.push_back(enemy);
	}
}

void EnemyPool::draw() {
	for (size_t i = 0; i < enemy_list.size(); i++)
	{
		enemy_list[i].draw();
	}
}

void EnemyPool::reset() {
	for (size_t i = 0; i < enemy_list.size(); i++)
	{
		enemy_list[i].pos_ = {-100, -1000, 0};
	}
}