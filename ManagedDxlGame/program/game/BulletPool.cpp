#include "BulletPool.h"
#include "Player.h"

BulletPool bullet_pool;

void BulletPool::update(float delta_time) {
	for (size_t i = 0; i < current_field_bullet_list.size(); i++)
	{
		if (current_field_bullet_list[i].state_ == BulletState::FLYING) {
			current_field_bullet_list[i].update(delta_time);
		}

		if (current_field_bullet_list[i].get_pos_().y < 100) {
			current_field_bullet_list[i].state_ = BulletState::STAYING;
			current_field_bullet_list[i].set_pos_(tnl::Vector3{ -1000, 0, 0 });
		}
	}
}

void BulletPool::draw() {
	for (size_t i = 0; i < current_field_bullet_list.size(); i++)
	{
		current_field_bullet_list[i].draw();
	}
};

void BulletPool::shotRequest() {
	for (size_t i = 0; i < current_field_bullet_list.size(); i++)
	{
		if (current_field_bullet_list[i].state_ == BulletState::STAYING) {
			current_field_bullet_list[i].set_pos_(player.pos_);
			current_field_bullet_list[i].state_ = BulletState::FLYING;
			return;
		}
	}
}

void BulletPool::generateBullet() {
	for (int i = 0; i < MAX_BULLET_NUM; i++)
	{
		Bullet bullet;

		bullet.set_pos_(tnl::Vector3{ -10000, 0, 0 });
		current_field_bullet_list.push_back(bullet);
	}
}