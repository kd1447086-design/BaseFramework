#include "main.h"
#include "GaugeUI.h"

// 初期化
void GaugeUI::Init()
{
    // ゲージの初期値
    m_maxValue = 100;
    m_currentValue = 100;
    m_damageValue = (float)m_currentValue;

}

// 更新
void GaugeUI::Update()
{
    // 遅延演出を使わない場合
    if (m_useDamageEffect == false)
    {
        m_damageValue = (float)m_currentValue;
        return;
    }

    // ダメージゲージを遅れて減少させる
    if (m_damageValue > m_currentValue)
    {
        m_damageValue -= m_damageSpeed / 60.0f;

        // 現在値より小さくならないようにする
        if (m_damageValue < m_currentValue)
        {
            m_damageValue = (float)m_currentValue;
        }
    }
}

// 描画
void GaugeUI::Draw()
{
    // 背景色
    Math::Color bgColor(0.1f, 0.1f, 0.1f, 1.0f);

    // ゲージの背景を描画
    SHADER.m_spriteShader.DrawBox(
        (int)m_posX,
        (int)m_posY,
        (int)m_width / 2,
        (int)m_height / 2,
        &bgColor
    );


    // 遅延演出がONの場合だけ描画
    if (m_useDamageEffect == true)
    {
        // ダメージゲージの割合
        float damageRate = m_damageValue / m_maxValue;

        // ダメージゲージの幅
        float damageWidth = m_width * damageRate;

        // ダメージゲージの位置
        float damagePosX = m_posX - (m_width - damageWidth) / 2;

        // ダメージゲージの色
        Math::Color damageColor(1.0f, 0.7f, 0.0f, 1.0f);

        // ダメージゲージを描画
        SHADER.m_spriteShader.DrawBox(
            (int)damagePosX,
            (int)m_posY,
            (int)damageWidth / 2,
            (int)m_height / 2,
            &damageColor
        );
    }

    // 現在値の割合
    float valueRate = (float)m_currentValue / m_maxValue;

    // ゲージの幅
    float valueWidth = m_width * valueRate;

    // ゲージの位置
    float valuePosX = m_posX - (m_width - valueWidth) / 2;

    Math::Color valueColor = m_gaugeColor;


    //ゲージを描画
    SHADER.m_spriteShader.DrawBox(
        (int)valuePosX,
        (int)m_posY,
        (int)valueWidth / 2,
        (int)m_height / 2,
        &valueColor
    );
}

// 解放
void GaugeUI::Release()
{
}

//現在値を設定
void GaugeUI::SetValue(int value)
{
    // 現在値を設定
    m_currentValue = value;

    // 最大値を超えないようにする
    if (m_currentValue > m_maxValue)
    {
        m_currentValue = m_maxValue;
    }

    // 0未満にならないようにする
    if (m_currentValue < 0)
    {
        m_currentValue = 0;
    }

    // 回復した場合はダメージゲージも合わせる
    if (m_damageValue < m_currentValue)
    {
        m_damageValue = (float)m_currentValue;
    }

}

// 現在値を設定
void GaugeUI::SetMaxValue(int value)
{
    // 最大値が0以下にならないようにする
    if (value < 1)
    {
        value = 1;
    }

    m_maxValue = value;

    // 現在値が最大値を超えたら調整
    if (m_currentValue > m_maxValue)
    {
        m_currentValue = m_maxValue;
    }

    // ダメージゲージも最大値に合わせる
    if (m_damageValue > m_maxValue)
    {
        m_damageValue = (float)m_maxValue;
    }

}

// ゲージの消費
void GaugeUI::UseValue(int value)
{
    // マイナスの値は処理しない
    if (value <= 0)
    {
        return;
    }


    // 消費できるか確認
    if (CanUseValue(value) == false)
    {
        return;
    }

    m_currentValue -= value;

    // 0未満にならないようにする
    if (m_currentValue < 0)
    {
        m_currentValue = 0;
    }
}


// 指定した数値を消費できるか確認
bool GaugeUI::CanUseValue(int value) const
{
    // 0以下の値は消費できない
    if (value <= 0)
    {
        return false;
    }

    // 現在値が消費量以上なら使用できる
    if (m_currentValue >= value)
    {
        return true;
    }

    return false;

}


// ゲージの回復
void GaugeUI::RecoverValue(int value)
{
    // マイナスの値は処理しない
    if (value <= 0)
    {
        return;
    }


    m_currentValue += value;

    // 最大値を超えないようにする
    if (m_currentValue > m_maxValue)
    {
        m_currentValue = m_maxValue;
    }

    // 回復したらダメージゲージも合わせる
    m_damageValue = (float)m_currentValue;

}

// ゲージの位置を設定
void GaugeUI::SetPosition(float x, float y)
{
    m_posX = x;
    m_posY = y;
}

// ゲージの大きさを設定
void GaugeUI::SetSize(float width, float height)
{
    // 大きさが0以下にならないようにする
    if (width < 1.0f)
    {
        width = 1.0f;
    }

    if (height < 1.0f)
    {
        height = 1.0f;
    }

    m_width = width;
    m_height = height;
}

// ゲージの色を設定
void GaugeUI::SetColor(Math::Color color)
{
    m_gaugeColor = color;
}

// ダメージ演出のON・OFFを設定
void GaugeUI::SetDamageEffect(bool enable)
{
    m_useDamageEffect = enable;

    // 演出をOFFにした場合は現在値に合わせる
    if (m_useDamageEffect == false)
    {
        m_damageValue = (float)m_currentValue;
    }
}
