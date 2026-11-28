#pragma once

class HitBox
{
public:

	HitBox();

	//”»’è‚Ìİ’è
	void Set(
		float x,
		float y,
		float width,
		float Height);

	//—LŒøó‘Ô
	void SetActive(bool active);

	bool IsActive() const;

	// ˆÊ’u‚Æ‘å‚«‚³‚ğæ“¾
	float GetX() const;
	float GetY() const;

	float GetWidth() const;
	float GetHeight() const;

private:
	float m_X;
	float m_Y;

	float m_Width;
	float m_Height;

	bool m_Active;
};