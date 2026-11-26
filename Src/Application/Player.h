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

private:

	//プレイヤー画像
	KdTexture m_texture;

	//プレイヤー座標
	Math::Vector2 m_pos = { 0,0 };

	//移動速度
	float m_speed = 5.0f;

	
};