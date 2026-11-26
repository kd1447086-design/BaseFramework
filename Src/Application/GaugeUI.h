#pragma once

class GaugeUI
{
private:

    // HP
    int m_maxHP = 100;
    int m_currentHP = 100;

    // ダメージ演出用HP
    float m_damageHP = 100.0f;

    // ゲージの減少速度
    float m_damageSpeed = 40.0f;

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

    // 現在HPを設定
    void SetHP(int hp);

    // 現在HPを取得
    int GetHP() const { return m_currentHP; }

    // 最大HPを設定
    void SetMaxHP(int hp);

    // 最大HPを取得
    int GetMaxHP() const { return m_maxHP; }

    // ゲージの位置を設定
    void SetPosition(float x, float y);

    // ゲージの大きさを設定
    void SetSize(float width, float height);
};
