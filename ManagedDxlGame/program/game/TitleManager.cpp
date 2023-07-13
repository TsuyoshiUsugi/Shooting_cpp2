#include "TitleManager.h"

TitleManager title_manager;

void TitleManager::update(float delta_time) {
	
}

void TitleManager::draw() {
	SetFontSize(100);
	DrawStringEx(title_pos_.x, title_pos_.y, -1, "%s", TITLE_NAME.c_str());
	SetFontSize(50);
	DrawStringEx(subtext_pos_.x, subtext_pos_.y, -1, "%s", SUBTEXT.c_str());
}