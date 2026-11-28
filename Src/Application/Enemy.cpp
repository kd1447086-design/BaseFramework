#include "Enemy.h"

#include <cmath>
#include <stdexcept>

Enemy::Enemy()
    : m_AttackPower(10),
    m_SearchRange(250.0f),
    m_AttackRange(40.0f),
    m_TargetX(0.0f),
    m_TargetY(0.0f),
    m_HasTarget(false)
{
    SetSize(32.0f, 48.0f);

    SetHP(50);

    SetMoveSpeed(80.0f);

    SetAnimation(1, 1.0f / 60.0f, true);
}

void Enemy::SetTarget(float x, float y)
{
    if (!std::isfinite(x) ||
        !std::isfinite(y))
    {
        throw std::invalid_argument(
            "Enemy: Invalid target position");
    }

    m_TargetX = x;
    m_TargetY = y;

    m_HasTarget = true;
}

void Enemy::SetAttackPower(int power)
{
    if (power < 0)
    {
        throw std::invalid_argument(
            "Enemy: Invalid attack power");
    }

    m_AttackPower = power;
}

void Enemy::SetSearchRange(float range)
{
    if (!std::isfinite(range) || range < 0.0f)
    {
        throw std::invalid_argument(
            "Enemy: Invalid search range");
    }

    m_SearchRange = range;
}

void Enemy::SetAttackRange(float range)
{
    if (!std::isfinite(range) || range < 0.0f)
    {
        throw std::invalid_argument(
            "Enemy: Invalid attack range");
    }

    m_AttackRange = range;
}

float Enemy::CalculateDistance() const
{
    float dx = m_TargetX - GetX();
    float dy = m_TargetY - GetY();

    return std::sqrt(dx * dx + dy * dy);
}

void Enemy::Update(float deltaTime)
{
    if (GetState() == CharacterState::Dead)
        return;

    if (m_HasTarget)
    {
        float dx = m_TargetX - GetX();
        float dy = m_TargetY - GetY();

        float distance = CalculateDistance();

        // çıìGîÕàÕì‡
        if (distance <= m_SearchRange)
        {
            if (distance > m_AttackRange)
            {
                // É^Å[ÉQÉbÉgÇ…å¸Ç©Ç¡Çƒà⁄ìÆ
                float moveX = 0.0f;
                float moveY = 0.0f;

                if (distance > 0.0f)
                {
                    moveX = dx / distance;
                    moveY = dy / distance;
                }

                SetMovement(moveX, moveY);

                SetFacingRight(dx >= 0.0f);

                if (GetState() == CharacterState::Idle)
                {
                    SetState(CharacterState::Walk);
                }
            }
            else
            {
                SetMovement(0.0f, 0.0f);

                // çUåÇîÕàÕì‡
                if (GetState() == CharacterState::Idle ||
                    GetState() == CharacterState::Walk)
                {
                    StartAttack();
                }
            }
        }
        else
        {
            SetMovement(0.0f, 0.0f);
        }
    }

    UpdateCommon(deltaTime);
}

int Enemy::GetAttackPower() const
{
    return m_AttackPower;
}

float Enemy::GetSearchRange() const
{
    return m_SearchRange;
}