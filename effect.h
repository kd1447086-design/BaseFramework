Effect.h

#pragma once

class Effect
{
private:
    KdTexture m_texture;
    Math::Vector2 m_pos = { 0.0f, 0.0f };

    float m_age = 0.0f;
    float m_lifetime = 0.3f;
    float m_size = 128.0f;

    bool m_active = false;

public:
    void Init(const char* fileName, float lifetime, float size);
    void Release();
    void Update();
    void Draw();
    void Play(float x, float y);

    bool IsActive() const { return m_active; }
};
