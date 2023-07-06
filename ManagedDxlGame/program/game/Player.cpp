#include "Player.h"
#include "BulletPool.h"
#include "EnemyPool.h"

Player player;

void Player::update(float delta_time) {
	if (player.is_death_) return;
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) pos_.x -= Player::MOVE_SPEED;
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) pos_.x += Player::MOVE_SPEED;

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE)) Shot();

	for (size_t i = 0; i < enemy_pool.enemy_list.size(); i++)
	{
		int n = tnl::IsIntersectRectToCorrectPosition(enemy_pool.enemy_list[i].pos_, enemy_pool.enemy_list[i].pos_, enemy_pool.enemy_list[i].SIZE_WIDTH, enemy_pool.enemy_list[i].SIZE_WIDTH,
			player.pos_,player.SIZE_WIDTH, player.SIZE_HEIGHT);

		if (n != 0)
		{
			player.is_death_ = true;
		}
	}
}

void Player::draw() {
	if (player.is_death_) return;
	DrawBoxEx(pos_, Player::SIZE_WIDTH, Player::SIZE_HEIGHT, false);
}

void Player::Shot() {
	bullet_pool.shotRequest();
}