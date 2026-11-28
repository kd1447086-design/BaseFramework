#pragma once

#include <vector>
// アニメーションイベント
enum class AnimationEventType
{
    AttackOn,
    AttackOff,

    InvincibleOn,
    InvincibleOff,

    AnimationEnd
};

// イベント情報
struct AnimationEvent
{
    int frame;
    AnimationEventType type;
};

class Animation
{
private:

    int m_CurrentFrame;
    int m_TotalFrame;

    float m_Timer;
    float m_Interval;

    bool m_Loop;
    bool m_Finished;

    std::vector<AnimationEvent> m_Events;

public:

    Animation();

    // アニメーション設定
    void SetAnimation(
        int totalFrame,
        float interval,
        bool loop);

    // イベント登録
    void AddEvent(
        int frame,
        AnimationEventType type);

    // 再生
    void Play();

    // 更新
    std::vector<AnimationEvent> Update(
        float deltaTime);

    int GetCurrentFrame() const;

    bool IsFinished() const;
};