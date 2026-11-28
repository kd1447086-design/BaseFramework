#pragma once
#include"Player.h"

class Enemy : public Player
{
private:

    int m_AttackPower;

    float m_SearchRange;

    float m_AttackRange;

    // ターゲットの座標
    float m_TargetX;
    float m_TargetY;

    // ターゲットが存在するか
    bool m_HasTarget;

    float CalculateDistance() const;

public:

    Enemy();

    void Update(float deltaTime);

    // AIのターゲット設定
    void SetTarget(float x, float y);

    // 固有パラメータ設定
    void SetAttackPower(int power);
    void SetSearchRange(float range);
    void SetAttackRange(float range);

    // 情報取得
    int GetAttackPower() const;

    float GetSearchRange() const;
};