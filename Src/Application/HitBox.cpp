#include "HitBox.h"

#include <stdexcept>
#include <cmath>

HitBox::HitBox()
	: m_X(0.0f),
	m_Y(0.0f),
	m_Width(0.0f),
	m_Height(0.0f),
	m_Active(false)
{
}
void HitBox::Set(
	float x,
	float y,
	float width,
	float height)
{
	//不正な値を検出
	if (!std::isfinite(x) ||
		!std::isfinite(y) ||
		!std::isfinite(width) ||
		!std::isfinite(height))
	{
		throw std::invalid_argument(
			"HitBox: Invalid numeric value");
	}

	//サイズの成り立たないものを検出
	if (width <= 0.0f || height <= 0.0f)
	{
		throw std::invalid_argument(
			"HitBox: Size must be positive");
	}

	m_X = x;
	m_Y = y;

	m_Width = width;
	m_Height = height;
}

void HitBox::SetActive(bool active)
{
	m_Active = active;
}

bool HitBox::IsActive() const
{
	return m_Active;
}

float HitBox::GetX() const
{
	return m_X;
}

float HitBox::GetY() const
{
	return m_Y;
}

float HitBox::GetWidth() const
{
	return m_Width;
}

float HitBox::GetHeight() const
{
	return m_Height;
}