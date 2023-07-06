#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "Player.h"
#include "Enemy.h";
#include "Bullet.h";
#include "BulletPool.h"
#include "EnemyPool.h"
#include "UserInterface.h"

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart(){
	srand(time(0));
	bullet_pool.generateBullet();
	enemy_pool.setup();
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	player.update(delta_time);
	player.draw();

	enemy_pool.update(delta_time);
	enemy_pool.draw();
	
	bullet_pool.update(delta_time);
	bullet_pool.draw();

	user_interface.draw();
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}
