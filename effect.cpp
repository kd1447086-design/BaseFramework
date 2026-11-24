Effect.cpp

#include "main.h"
#include "Effect.h"

void Effect::Init(const char* fileName, float lifetime, float size)
{
    m_lifetime = lifetime;
    m_size = size;
    m_age = 0.0f;
    m_active = false;

    m_texture.Load(fileName);
}

void Effect::Release()
{
    m_texture.Release();
}

void Effect::Play(float x, float y)
{
    m_pos.x = x;
    m_pos.y = y;

    m_age = 0.0f;
    m_active = true;
}

void Effect::Update()
{
    if (!m_active) return;

    m_age += 1.0f / 60.0f;

    if (m_age >= m_lifetime)
    {
        m_active = false;
    }
}

void Effect::Draw()
{
    if (!m_active) return;

    float alpha = 1.0f - (m_age / m_lifetime);

    if (alpha < 0.0f) alpha = 0.0f;
    if (alpha > 1.0f) alpha = 1.0f;

    Math::Color color(1.0f, 1.0f, 1.0f, alpha);

    SHADER.m_spriteShader.DrawTex(
        &m_texture,
        (int)m_pos.x,
        (int)m_pos.y,
        (int)m_size,
        (int)m_size,
        nullptr,
        &color
    );
}
