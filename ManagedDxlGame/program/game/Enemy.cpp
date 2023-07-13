#include "Enemy.h"
#include "../dxlib_ext/dxlib_ext.h"

void Enemy::update(float delta_time) {

	pos_.y += Enemy::MOVE_SPEED;
}

void Enemy::draw() {

	DrawBoxEx(pos_, Enemy::SIZE_WIDTH, Enemy::SIZE_HEIGHT, false);
};