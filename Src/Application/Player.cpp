#include"main.h"
#include"Player.h"

//プレイヤーの足元の当たり判定を取得
Math::Rectangle Player::GetHitBox()const
{
	return{
		(long)(m_pos.x - m_hitWidth / 2),
		(long)(m_pos.y - m_hitHeight / 2),
		(long)(m_pos.x - m_hitWidth / 2),
		(long)(m_pos.y - m_hitHeight / 2)
	};
}

//初期化
void Player::Init()
{

	//プレイヤー画像
	m_texture.Load("texture/プレイヤー画像.png");

	//初期位置
	m_pos = { 0.0 };

	//移動速度
	m_speed = 5.0f;
}

//更新
void Player::Update()
{
	m_isMoving = false;

	//上下左右移動
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_pos.y += m_speed;
		m_direction = Direction::Up;
		m_isMoving = true;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_pos.y -= m_speed;
		m_direction = Direction::Down;
		m_isMoving = true;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_pos.x -= m_speed;
		m_direction = Direction::Left;
		m_isMoving = true;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_pos.x += m_speed;
		m_direction = Direction::Right;
		m_isMoving = true;
	}
	//移動範囲制限
	if (m_pos.x < -650)m_pos.x = -650;
	if (m_pos.x > 850)m_pos.x = 850;
	if (m_pos.y < -50)m_pos.y = -50;
	if (m_pos.y > 50)m_pos.y = 50;
	//停止中はアニメーションを初期状態に戻す
	if (!m_isMoving)
	{
		m_animFrame = 0;
		m_animTime = 0.0f;
	}
	//移動中はアニメーション時間を加算
	if (m_isMoving)
	{
		m_animTime += 1.0f / 60.0f;

		//一定時間ごとにアニメーションを切り替える
		if (m_animTime >= m_animInterval)
		{
			m_animFrame++;

			if (m_animFrame > 2)
			{
				m_animFrame = 1;
			}

			m_animFrame = 0.0f;

		}
	}

}
//描画
void Player::Draw()
{
	SHADER.m_spriteShader.DrawTex(&m_texture, 0, 0, 100, 100);
}