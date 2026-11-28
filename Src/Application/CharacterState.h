#pragma once

//キャラクターの状態
enum class CharacterState
{
	Idle,	//待機
	Walk,	//移動
	Attack,	//攻撃
	Dodge,	//回避
	Damage,	//被弾
	Dead	//死亡
};