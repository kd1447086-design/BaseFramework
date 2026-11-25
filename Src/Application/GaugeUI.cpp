#include "../../プログラム/スケルトンプログラム/Src/Application/main.h"
#include "GaugeUI.h"
void GaugeUI::Init()
{
    // HPを初期化
    m_maxHP = 100;
    m_currentHP = 100;
}
void GaugeUI::Update()
{

}
void GaugeUI::Draw()
{
    // ゲージの背景
    SHADER.m_spriteShader.DrawBox(
        (int)m_posX,
        (int)m_posY,
        (int)m_width / 2,
        (int)m_height / 2,
        Math::Color(0.1f, 0.1f, 0.1f, 1.0f)
    );
    // HPゲージの割合
    float hpRate = (float)m_currentHP / m_maxHP;
    // HPゲージの幅
    float hpWidth = m_width * hpRate;
    // HPゲージの表示位置
    float hpPosX = m_posX - (m_width - hpWidth) / 2;
    // HPゲージ
    SHADER.m_spriteShader.DrawBox(
        (int)hpPosX,
        (int)m_posY,
        (int)hpWidth / 2,
        (int)m_height / 2,
        Math::Color(0.8f, 0.1f, 0.1f, 1.0f)
    );
}
void GaugeUI::Release()
{

}