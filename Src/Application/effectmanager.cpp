#include "main.h"
#include "EffectManager.h"

void EffectManager::Init()
{
    m_slashEffect.Init("Texture/斬撃.png", 0.3f, 128.0f);
    m_dashWind.Init("Texture/ダッシュ.png", 0.3f, 128.0f);
    m_dashEnergy.Init("Texture/ダッシュ2.png", 0.3f, 128.0f);
    m_dashDust.Init("Texture/ダッシュ3.png", 0.3f, 128.0f);
}

void EffectManager::Release()
{
    m_slashEffect.Release();
    m_dashWind.Release();
    m_dashEnergy.Release();
    m_dashDust.Release();
}

void EffectManager::Update()
{
    m_slashEffect.Update();
    m_dashWind.Update();
    m_dashEnergy.Update();
    m_dashDust.Update();
}

void EffectManager::Draw()
{
    m_slashEffect.Draw();
    m_dashWind.Draw();
    m_dashEnergy.Draw();
    m_dashDust.Draw();
}

void EffectManager::PlaySlash(float x, float y)
{
    m_slashEffect.Play(x, y);
}

void EffectManager::PlayDashStart(float x, float y)
{
    m_dashWind.Play(x, y);
}

void EffectManager::PlayDashEnd(float x, float y)
{
    m_dashEnergy.Play(x, y);
    m_dashDust.Play(x, y);
}
