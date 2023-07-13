#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class TitleManager {
	 const std::string TITLE_NAME = "SIMPLE SHOOTING";
	 const std::string SUBTEXT = "Press Enter";
	 tnl::Vector3 title_pos_ = {DXE_WINDOW_WIDTH / 2 - 350, DXE_WINDOW_HEIGHT / 2, 0};
	 tnl::Vector3 subtext_pos_ = {DXE_WINDOW_WIDTH / 2 - 150, DXE_WINDOW_HEIGHT / 2 + 150, 0};
	 bool is_title = false;

public:
	bool get_is_title() {
		return is_title;
	}
	void draw();
	void update(float delta_time);
};

extern TitleManager title_manager;