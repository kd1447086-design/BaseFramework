#include "main.h"
#include "GaugeUI.h"

// 初期化
void GaugeUI::Init()
{
    // HPを初期化
    m_maxHP = 100;
    m_currentHP = 100;

    // ダメージ演出用HPを初期化
    m_damageHP = (float)m_currentHP;
}

// 更新
void GaugeUI::Update()
{
    // ダメージゲージを遅れて減少させる
    if (m_damageHP > m_currentHP)
    {
        m_damageHP -= m_damageSpeed / 60.0f;

        // 現在HPより小さくならないようにする
        if (m_damageHP < m_currentHP)
        {
            m_damageHP = (float)m_currentHP;
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

    // ダメージゲージの割合
    float damageRate = m_damageHP / m_maxHP;

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

    // HPゲージの割合
    float hpRate = (float)m_currentHP / m_maxHP;

    // HPゲージの幅
    float hpWidth = m_width * hpRate;

    // HPゲージの位置
    float hpPosX = m_posX - (m_width - hpWidth) / 2;

    // HPゲージの色
    Math::Color hpColor(0.0f, 1.0f, 0.0f, 1.0f);

    // HPの割合に応じて色を変更
    if (hpRate <= 0.2f)
    {
        // HPが20%以下なら赤
        hpColor = Math::Color(1.0f, 0.0f, 0.0f, 1.0f);
    }
    else if (hpRate <= 0.5f)
    {
        // HPが50%以下なら黄色
        hpColor = Math::Color(1.0f, 1.0f, 0.0f, 1.0f);
    }

    // HPゲージを描画
    SHADER.m_spriteShader.DrawBox(
        (int)hpPosX,
        (int)m_posY,
        (int)hpWidth / 2,
        (int)m_height / 2,
        &hpColor
    );
}

// 解放
void GaugeUI::Release()
{
}

// 現在HPを設定
void GaugeUI::SetHP(int hp)
{
    // HPを設定
    m_currentHP = hp;

    // HPが最大値を超えないようにする
    if (m_currentHP > m_maxHP)
    {
        m_currentHP = m_maxHP;
    }

    // HPがマイナスにならないようにする
    if (m_currentHP < 0)
    {
        m_currentHP = 0;
    }

    // 回復した場合はダメージゲージも合わせる
    if (m_damageHP < m_currentHP)
    {
        m_damageHP = (float)m_currentHP;
    }
}

// 最大HPを設定
void GaugeUI::SetMaxHP(int hp)
{
    // 最大HPが0以下にならないようにする
    if (hp < 1)
    {
        hp = 1;
    }

    m_maxHP = hp;

    // 現在HPが最大HPを超えたら調整
    if (m_currentHP > m_maxHP)
    {
        m_currentHP = m_maxHP;
    }

    // ダメージゲージも最大HPに合わせる
    if (m_damageHP > m_maxHP)
    {
        m_damageHP = (float)m_maxHP;
    }
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

