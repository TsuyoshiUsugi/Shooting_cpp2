#include "UserInterface.h"
#include "Player.h"

UserInterface user_interface;

void UserInterface::addScore(int point) {
	score_ += point;
}

void UserInterface::draw() {
	SetFontSize(fontsize_);
	DrawStringEx(help_show_pos_.x, help_show_pos_.y, -1, "%s", help_.c_str());
	DrawStringEx(score_show_pos_.x, score_show_pos_.y, -1, "ÉXÉRÉA%d", score_);

	if (player.get_is_death()) {
		SetFontSize(fontsize_ * 2);
		DrawStringEx(gameover_show_pos_.x, gameover_show_pos_.y, -1, "%s", gameover_.c_str());
		SetFontSize(fontsize_);
		DrawStringEx(gameover_help_show_pos_.x, gameover_help_show_pos_.y, -1, "%s", gameover_help_show_.c_str());
	}
}

void UserInterface::reset() {
	score_ = 0;
}