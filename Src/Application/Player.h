#pragma once

class Player
{
public:
	//初期化
	void Init();

	//更新
	void Update();

	//描画
	void Draw();

	//プレイヤーの座標取得
	Math::Vector2 GetPos() const
	{
		return m_pos;
	}

	void SetPos(const Math::Vector2& pos)
	{
		m_pos = pos;
	}

	Math::Rectangle GetHitBox()const;

private:

	//プレイヤーの向き
	enum class Direction
	{
		Up,
		Down,
		Left,
		Right
	};

	//現在の向き
	Direction m_direction = Direction::Down;

	//プレイヤー画像
	KdTexture m_texture;

	//プレイヤー座標
	Math::Vector2 m_pos = { 0,0 };

	//プレイヤーの当たり判定
	float m_hitWidth = 40.0f;
	float m_hitHeight = 20.0f;

	//プレイヤーが移動中か
	bool m_isMoving = false;

	//アニメーションのコマ番号
	int m_animFrame = 0;

	//アニメーション切り替え時間
	float m_animTime = 0.0f;

	//アニメーション切り替え間隔
	float m_animInterval = 0.15f;

	//移動速度
	float m_speed = 5.0f;

	
};