
#include "main.h"
#include "Player.h"

#include <stdexcept>
#include <cmath>

// -------------------------
// 初期化
// -------------------------

void Player::Init()
{
	// プレイヤー画像
	m_texture.Load("texture/プレイヤー画像.png");

	// 初期位置
	m_pos = { 0.0f, 0.0f };

	// サイズ
	m_Width = 32.0f;
	m_Height = 48.0f;

	// 移動速度
	m_MoveSpeed = 300.0f;

	// HP
	m_HP = 100;
	m_MaxHP = 100;

	// 向き
	m_direction = Direction::Down;
	m_FacingRight = true;

	// 状態
	m_State = CharacterState::Idle;
	m_Invincible = false;

	// 移動
	m_MoveX = 0.0f;
	m_MoveY = 0.0f;
	m_isMoving = false;

	// 移動アニメーション
	m_animFrame = 0;
	m_animTime = 0.0f;

	// 戦闘アニメーション
	m_Animation.SetAnimation(
		1, 1.0f / 60.0f, true);

	// 攻撃対象
	m_HitTargets.clear();

	// 当たり判定
	m_BodyHitBox.SetActive(true);
	m_AttackHitBox.SetActive(false);

	UpdateHitBox();
}

void Player::SetPos(const Math::Vector2& pos)
{
	SetPosition(pos.x, pos.y);
}

// -------------------------
// 座標管理
// -------------------------

void Player::SetPosition(float x, float y)
{
	if (!std::isfinite(x) || !std::isfinite(y))
	{
		throw std::invalid_argument(
			"Player: Invalid position");
	}

	m_pos.x = x;
	m_pos.y = y;

	UpdateHitBox();
}

float Player::GetX() const
{
	return m_pos.x;
}

float Player::GetY() const
{
	return m_pos.y;
}

// 足元の当たり判定
Math::Rectangle Player::GetHitBox() const
{
	return
	{
		(long)(m_pos.x - m_hitWidth / 2),
		(long)(m_pos.y - m_hitHeight / 2),
		(long)m_hitWidth,
		(long)m_hitHeight
	};
}

// -------------------------
// 基本情報
// -------------------------

void Player::SetSize(float width, float height)
{
	if (!std::isfinite(width) ||
		!std::isfinite(height) ||
		width <= 0.0f ||
		height <= 0.0f)
	{
		throw std::invalid_argument(
			"Player: Invalid size");
	}

	m_Width = width;
	m_Height = height;

	UpdateHitBox();
}

void Player::SetMoveSpeed(float speed)
{
	if (!std::isfinite(speed) || speed < 0.0f)
	{
		throw std::invalid_argument(
			"Player: Invalid move speed");
	}

	m_MoveSpeed = speed;
}

float Player::GetWidth() const
{
	return m_Width;
}

float Player::GetHeight() const
{
	return m_Height;
}

float Player::GetMoveSpeed() const
{
	return m_MoveSpeed;
}

// -------------------------
// HP管理
// -------------------------

void Player::SetHP(int hp)
{
	if (hp < 0 || hp > m_MaxHP)
	{
		throw std::invalid_argument(
			"Player: HP is out of range");
	}

	m_HP = hp;

	if (m_HP == 0)
	{
		m_State = CharacterState::Dead;
		m_AttackHitBox.SetActive(false);
	}
}

void Player::SetMaxHP(int hp)
{
	if (hp <= 0 || m_HP > hp)
	{
		throw std::invalid_argument(
			"Player: Invalid MaxHP");
	}

	m_MaxHP = hp;
}

int Player::GetHP() const
{
	return m_HP;
}

int Player::GetMaxHP() const
{
	return m_MaxHP;
}

// -------------------------
// ダメージ処理
// -------------------------

void Player::TakeDamage(int damage)
{
	if (damage < 0)
	{
		throw std::invalid_argument(
			"Player: Invalid damage");
	}

	if (m_Invincible ||
		m_State == CharacterState::Dead)
	{
		return;
	}

	m_HP -= damage;

	if (m_HP < 0)
	{
		m_HP = 0;
	}

	if (m_HP == 0)
	{
		m_State = CharacterState::Dead;

		m_AttackHitBox.SetActive(false);

		m_Invincible = false;

		return;
	}

	// 被弾状態
	m_State = CharacterState::Damage;

	m_AttackHitBox.SetActive(false);

	m_Invincible = true;

	SetAnimation(30, 1.0f / 60.0f, false);

	AddAnimationEvent(
		20, AnimationEventType::InvincibleOff);
}

// -------------------------
// 向き・状態
// -------------------------

void Player::SetFacingRight(bool right)
{
	m_FacingRight = right;

	m_direction = right
		? Direction::Right
		: Direction::Left;
}

bool Player::IsFacingRight() const
{
	return m_FacingRight;
}

bool Player::IsInvincible() const
{
	return m_Invincible;
}

void Player::SetState(CharacterState state)
{
	m_State = state;
}

CharacterState Player::GetState() const
{
	return m_State;
}

// -------------------------
// 攻撃
// -------------------------

void Player::StartAttack()
{
	if (m_State == CharacterState::Dead ||
		m_State == CharacterState::Damage ||
		m_State == CharacterState::Dodge ||
		m_State == CharacterState::Attack)
	{
		return;
	}

	m_State = CharacterState::Attack;

	m_AttackHitBox.SetActive(false);

	m_HitTargets.clear();

	SetAnimation(60, 1.0f / 60.0f, false);

	AddAnimationEvent(
		15, AnimationEventType::AttackOn);

	AddAnimationEvent(
		30, AnimationEventType::AttackOff);
}

// -------------------------
// 回避
// -------------------------

void Player::StartDodge()
{
	if (m_State == CharacterState::Dead ||
		m_State == CharacterState::Damage ||
		m_State == CharacterState::Dodge ||
		m_State == CharacterState::Attack)
	{
		return;
	}

	m_State = CharacterState::Dodge;

	m_AttackHitBox.SetActive(false);

	SetAnimation(30, 1.0f / 60.0f, false);

	AddAnimationEvent(
		5, AnimationEventType::InvincibleOn);

	AddAnimationEvent(
		20, AnimationEventType::InvincibleOff);
}

// -------------------------
// 攻撃対象管理
// -------------------------

bool Player::CanHitTarget(int targetID) const
{
	return m_HitTargets.find(targetID)
		== m_HitTargets.end();
}

void Player::RegisterHitTarget(int targetID)
{
	m_HitTargets.insert(targetID);
}

// -------------------------
// アニメーション
// -------------------------

void Player::SetAnimation(
	int totalFrame,
	float interval,
	bool loop)
{
	m_Animation.SetAnimation(
		totalFrame, interval, loop);
}

void Player::AddAnimationEvent(
	int frame,
	AnimationEventType type)
{
	m_Animation.AddEvent(frame, type);
}

int Player::GetAnimationFrame() const
{
	return m_Animation.GetCurrentFrame();
}

bool Player::IsAnimationFinished() const
{
	return m_Animation.IsFinished();
}

// -------------------------
// アニメーションイベント
// -------------------------

void Player::ProcessAnimationEvents(
	const std::vector<AnimationEvent>& events)
{
	for (const auto& event : events)
	{
		switch (event.type)
		{
		case AnimationEventType::AttackOn:

			m_AttackHitBox.SetActive(true);

			break;

		case AnimationEventType::AttackOff:

			m_AttackHitBox.SetActive(false);

			break;

		case AnimationEventType::InvincibleOn:

			m_Invincible = true;

			break;

		case AnimationEventType::InvincibleOff:

			m_Invincible = false;

			break;

		case AnimationEventType::AnimationEnd:

			m_AttackHitBox.SetActive(false);

			m_Invincible = false;

			if (m_State != CharacterState::Dead)
			{
				m_State = CharacterState::Idle;
			}

			break;
		}
	}
}

// -------------------------
// 移動量設定
// -------------------------

void Player::SetMovement(float x, float y)
{
	if (!std::isfinite(x) || !std::isfinite(y))
	{
		throw std::invalid_argument(
			"Player: Invalid movement");
	}

	m_MoveX = x;
	m_MoveY = y;
}

// -------------------------
// 当たり判定更新
// -------------------------

void Player::UpdateHitBox()
{
	// 本体判定
	m_BodyHitBox.Set(
		m_pos.x - m_Width / 2.0f,
		m_pos.y - m_Height / 2.0f,
		m_Width,
		m_Height);

	// 攻撃判定
	const float attackWidth = 40.0f;
	const float attackHeight = 20.0f;

	float attackX;

	if (m_FacingRight)
	{
		attackX = m_pos.x + m_Width / 2.0f;
	}
	else
	{
		attackX = m_pos.x
			- m_Width / 2.0f
			- attackWidth;
	}

	float attackY =
		m_pos.y - attackHeight / 2.0f;

	m_AttackHitBox.Set(
		attackX,
		attackY,
		attackWidth,
		attackHeight);
}

// -------------------------
// 共通更新
// -------------------------

void Player::UpdateCommon(float deltaTime)
{
	if (!std::isfinite(deltaTime) ||
		deltaTime < 0.0f)
	{
		throw std::invalid_argument(
			"Player: Invalid deltaTime");
	}

	if (m_State == CharacterState::Dead)
	{
		return;
	}

	// アニメーション更新
	auto events = m_Animation.Update(deltaTime);

	// イベント処理
	ProcessAnimationEvents(events);

	// 移動
	if (m_State != CharacterState::Damage &&
		m_State != CharacterState::Dead)
	{
		m_pos.x += m_MoveX * m_MoveSpeed * deltaTime;
		m_pos.y += m_MoveY * m_MoveSpeed * deltaTime;
	}

	// マップ移動範囲制限
	if (m_pos.x < -650) m_pos.x = -650;
	if (m_pos.x > 850) m_pos.x = 850;
	if (m_pos.y < -50) m_pos.y = -50;
	if (m_pos.y > 50) m_pos.y = 50;

	// 当たり判定更新
	UpdateHitBox();
}

// -------------------------
// 更新
// -------------------------

void Player::Update()
{
	Update(1.0f / 60.0f);
}

void Player::Update(float deltaTime)
{
	m_isMoving = false;

	float moveX = 0.0f;
	float moveY = 0.0f;

	// 死亡・被弾中は移動入力を受け付けない
	if (m_State != CharacterState::Dead &&
		m_State != CharacterState::Damage)
	{
		// 上
		if (GetAsyncKeyState('W') & 0x8000)
		{
			moveY += 1.0f;
			m_direction = Direction::Up;
			m_isMoving = true;
		}

		// 下
		if (GetAsyncKeyState('S') & 0x8000)
		{
			moveY -= 1.0f;
			m_direction = Direction::Down;
			m_isMoving = true;
		}

		// 左
		if (GetAsyncKeyState('A') & 0x8000)
		{
			moveX -= 1.0f;
			m_direction = Direction::Left;
			m_FacingRight = false;
			m_isMoving = true;
		}

		// 右
		if (GetAsyncKeyState('D') & 0x8000)
		{
			moveX += 1.0f;
			m_direction = Direction::Right;
			m_FacingRight = true;
			m_isMoving = true;
		}
	}

	SetMovement(moveX, moveY);

	// 移動状態
	if (m_State == CharacterState::Idle ||
		m_State == CharacterState::Walk)
	{
		m_State = m_isMoving
			? CharacterState::Walk
			: CharacterState::Idle;
	}

	// 移動アニメーション
	if (!m_isMoving)
	{
		m_animFrame = 0;
		m_animTime = 0.0f;
	}
	else
	{
		m_animTime += deltaTime;

		if (m_animTime >= m_animInterval)
		{
			m_animTime -= m_animInterval;

			m_animFrame++;

			if (m_animFrame > 2)
			{
				m_animFrame = 1;
			}
		}
	}

	// 共通更新
	UpdateCommon(deltaTime);
}

// -------------------------
// 描画
// -------------------------

void Player::Draw(const Math::Vector2& cameraPos)
{
	SHADER.m_spriteShader.DrawTex(
		&m_texture,
		(int)(m_pos.x - cameraPos.x),
		(int)(m_pos.y - cameraPos.y),
		100,
		100);
}

// -------------------------
// 当たり判定取得
// -------------------------

const HitBox& Player::GetBodyHitBox() const
{
	return m_BodyHitBox;
}

const HitBox& Player::GetAttackHitBox() const
{
	return m_AttackHitBox;
}
