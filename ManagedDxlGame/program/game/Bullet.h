#pragma once
#include "../dxlib_ext/dxlib_ext.h"

/// <summary>
/// �e�̏�Ԃ̃X�e�[�g
/// </summary>
enum class BulletState {
	FLYING,
	STAYING,
	MAX_STATE_NUM,
};

class Bullet {
	/// <summary> �e�̃_���[�W </summary>
	int damage_ = 1;
	/// <summary> �e�̈ʒu </summary>
	tnl::Vector3 pos_ = { 100, 30, 0 };
public:
	/// <summary> �e�̉��� </summary>
	static constexpr int SIZE_WIDTH = 30;
	/// <summary> �e�̏c�� </summary>
	static constexpr int SIZE_HEIGHT = 30;
	/// <summary> �e�̈ړ����x </summary>
	static constexpr int MOVE_SPEED = 5;
	/// <summary> �e�̏�� </summary>
	BulletState state_ = BulletState::STAYING;

	tnl::Vector3 get_pos_() { return pos_; }
	void set_pos_(tnl::Vector3 pos) { pos_ = pos; }

	void update(float delta_time);
	void reset();
	void draw();
};