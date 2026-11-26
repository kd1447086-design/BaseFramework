#include"main.h"
#include"Player.h"

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
	//上下左右移動
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_pos.y += m_speed;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_pos.y -= m_speed;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_pos.x -= m_speed;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_pos.x += m_speed;
	}
	//移動範囲制限
	if (m_pos.x < -650)m_pos.x = -650;
	if (m_pos.x > 850)m_pos.x = 850;
	if (m_pos.y < -50)m_pos.y = -50;
	if (m_pos.y > 50)m_pos.y = 50;

}
//描画
void Player::Draw()
{
	SHADER.m_spriteShader.DrawTex(&m_texture, 0, 0, 100, 100);
}