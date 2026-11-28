#pragma once

class GaugeUI
{
private:

    // ゲージの最大値
    int m_maxValue = 100;
    // ゲージの現在値
    int m_currentValue = 100;

    // ダメージ演出用の値
    float m_damageValue = 100.0f;

    // ダメージ演出を使用するか
    bool m_useDamageEffect = true;

    // ゲージの減少速度
    float m_damageSpeed = 40.0f;

    // ゲージの位置
    float m_posX = 150.0f;
    float m_posY = 300.0f;

    // ゲージの大きさ
    float m_width = 200.0f;
    float m_height = 16.0f;

    // ゲージの色
    Math::Color m_gaugeColor =
        Math::Color(0.0f, 1.0f, 0.0f, 1.0f);

public:
    // 初期化
    void Init();

    // 更新
    void Update();

    // 描画
    void Draw();

    // 解放
    void Release();

    // ゲージの現在値
    void SetValue(int value);
    int GetValue() const { return m_currentValue; }

    // ゲージの最大値
    void SetMaxValue(int value);
    int GetMaxValue() const { return m_maxValue; }

    // ゲージの消費
    void UseValue(int value);

    // 指定した数値を消費できるか確認
    bool CanUseValue(int value) const;

    // ゲージの回復
    void RecoverValue(int value);

    // ゲージの位置を設定
    void SetPosition(float x, float y);

    // ゲージの大きさを設定
    void SetSize(float width, float height);

    // ゲージの色を設定
    void SetColor(Math::Color color);

    // ダメージ演出のON・OFF
    void SetDamageEffect(bool enable);

};
