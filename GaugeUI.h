#pragma once

#include "Effect.h"

class EffectManager
{
private:
    Effect m_slashEffect;
    Effect m_dashWind;
    Effect m_dashEnergy;
    Effect m_dashDust;

public:
    void Init();
    void Release();
    void Update();
    void Draw();

    void PlaySlash(float x, float y);
    void PlayDashStart(float x, float y);
    void PlayDashEnd(float x, float y);
};
