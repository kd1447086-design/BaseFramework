#include "Animation.h"

#include <stdexcept>
#include <cmath>

Animation::Animation()
    : m_CurrentFrame(0),
    m_TotalFrame(1),
    m_Timer(0.0f),
    m_Interval(1.0f / 60.0f),
    m_Loop(false),
    m_Finished(false)
{
}

void Animation::SetAnimation(
    int totalFrame,
    float interval,
    bool loop)
{
    if (totalFrame <= 0 ||
        !std::isfinite(interval) ||
        interval <= 0.0f)
    {
        throw std::invalid_argument(
            "Animation: Invalid settings");
    }

    m_TotalFrame = totalFrame;
    m_Interval = interval;
    m_Loop = loop;

    // 前のアニメーションのイベントを削除
    m_Events.clear();

    Play();
}

void Animation::AddEvent(
    int frame,
    AnimationEventType type)
{
    if (frame < 0 || frame >= m_TotalFrame)
    {
        throw std::invalid_argument(
            "Animation: Invalid event frame");
    }

    m_Events.push_back({ frame, type });
}

void Animation::Play()
{
    m_CurrentFrame = 0;
    m_Timer = 0.0f;
    m_Finished = false;
}

std::vector<AnimationEvent> Animation::Update(
    float deltaTime)
{
    std::vector<AnimationEvent> result;

    if (m_Finished)
        return result;

    if (!std::isfinite(deltaTime) || deltaTime < 0.0f)
    {
        throw std::invalid_argument(
            "Animation: Invalid deltaTime");
    }

    m_Timer += deltaTime;

    while (m_Timer >= m_Interval && !m_Finished)
    {
        m_Timer -= m_Interval;

        int previousFrame = m_CurrentFrame;

        m_CurrentFrame++;

        if (m_CurrentFrame >= m_TotalFrame)
        {
            if (m_Loop)
            {
                m_CurrentFrame = 0;
            }
            else
            {
                m_CurrentFrame = m_TotalFrame - 1;
                m_Finished = true;
            }
        }

        // 現在のフレームで発生するイベントを取得
        for (const auto& event : m_Events)
        {
            if (event.frame > previousFrame &&
                event.frame <= m_CurrentFrame)
            {
                result.push_back(event);
            }
        }

        if (m_Finished)
        {
            result.push_back({
                m_CurrentFrame,
                AnimationEventType::AnimationEnd
                });
        }
    }

    return result;
}

int Animation::GetCurrentFrame() const
{
    return m_CurrentFrame;
}

bool Animation::IsFinished() const
{
    return m_Finished;
}