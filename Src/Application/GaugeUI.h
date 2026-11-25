#pragma once
class GaugeUI
{
private:
    // HP
    int m_maxHP = 100;
    int m_currentHP = 100;
    // ゲージの位置
    float m_posX = 150.0f;
    float m_posY = 300.0f;
    // ゲージの大きさ
    float m_width = 200.0f;
    float m_height = 16.0f;
public:
    // 初期化
    void Init();
    // 更新
    void Update();
    // 描画
    void Draw();
    // 解放
    void Release();
};