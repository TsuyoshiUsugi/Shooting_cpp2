#include "../dxlib_ext/dxlib_ext.h"
#include "Bullet.h"

void Bullet::update(float delta_time) {
	pos_.y -= Bullet::MOVE_SPEED;
}

/// <summary>
/// ’e‚ÌˆÊ’u‚Æó‘Ô‚ğ‰Šú‰»‚·‚é
/// </summary>
void Bullet::reset() {
	pos_ = { -1000, 0, 0 };
	state_ = BulletState::STAYING;
}

void Bullet::draw() {
	DrawBoxEx(pos_, Bullet::SIZE_WIDTH, Bullet::SIZE_HEIGHT, false);
};