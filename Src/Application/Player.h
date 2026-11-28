
#pragma once

#include <unordered_set>
#include <vector>

#include "CharacterState.h"
#include "Animation.h"
#include "HitBox.h"

class Player
{
public:

	// 初期化
	void Init();

	// 更新
	void Update();
	void Update(float deltaTime);

	// 描画
	void Draw(const Math::Vector2& cameraPos);

	// -------------------------
	// 座標管理
	// -------------------------

	Math::Vector2 GetPos() const
	{
		return m_pos;
	}

	void SetPos(const Math::Vector2& pos);

	Math::Rectangle GetHitBox() const;

	void SetPosition(float x, float y);

	float GetX() const;
	float GetY() const;

	// -------------------------
	// 基本情報
	// -------------------------

	void SetSize(float width, float height);

	void SetMoveSpeed(float speed);

	float GetWidth() const;
	float GetHeight() const;
	float GetMoveSpeed() const;

	// -------------------------
	// HP管理
	// -------------------------

	void SetHP(int hp);
	void SetMaxHP(int hp);

	int GetHP() const;
	int GetMaxHP() const;

	// ダメージ処理
	void TakeDamage(int damage);

	// -------------------------
	// 向き・状態
	// -------------------------

	void SetFacingRight(bool right);

	bool IsFacingRight() const;

	bool IsInvincible() const;

	void SetState(CharacterState state);

	CharacterState GetState() const;

	// -------------------------
	// 攻撃・回避
	// -------------------------

	void StartAttack();

	void StartDodge();

	bool CanHitTarget(int targetID) const;

	void RegisterHitTarget(int targetID);

	// -------------------------
	// アニメーション
	// -------------------------

	int GetAnimationFrame() const;

	bool IsAnimationFinished() const;

	// -------------------------
	// 当たり判定
	// -------------------------

	const HitBox& GetBodyHitBox() const;

	const HitBox& GetAttackHitBox() const;


protected:

	void SetMovement(float x, float y);

	void UpdateCommon(float deltaTime);

private:

	// -------------------------
	// プレイヤーの向き
	// -------------------------

	enum class Direction
	{
		Up,
		Down,
		Left,
		Right
	};

	Direction m_direction = Direction::Down;

	bool m_FacingRight = true;

	// -------------------------
	// 画像
	// -------------------------

	KdTexture m_texture;

	// -------------------------
	// 座標・サイズ
	// -------------------------

	Math::Vector2 m_pos = { 0,0 };

	float m_Width = 32.0f;
	float m_Height = 48.0f;

	// 足元の当たり判定
	float m_hitWidth = 40.0f;
	float m_hitHeight = 20.0f;

	// -------------------------
	// 移動
	// -------------------------

	float m_MoveX = 0.0f;
	float m_MoveY = 0.0f;

	float m_MoveSpeed = 300.0f;

	bool m_isMoving = false;

	// -------------------------
	// HP
	// -------------------------

	int m_HP = 100;
	int m_MaxHP = 100;

	// -------------------------
	// 状態
	// -------------------------

	CharacterState m_State = CharacterState::Idle;

	bool m_Invincible = false;

	// -------------------------
	// 移動アニメーション
	// -------------------------

	int m_animFrame = 0;

	float m_animTime = 0.0f;

	float m_animInterval = 0.15f;

	// -------------------------
	// 戦闘アニメーション
	// -------------------------

	Animation m_Animation;

	// -------------------------
	// 当たり判定
	// -------------------------

	HitBox m_BodyHitBox;

	HitBox m_AttackHitBox;

	// 攻撃が命中した対象
	std::unordered_set<int> m_HitTargets;

	// -------------------------
	// 内部処理
	// -------------------------

	void SetAnimation(
		int totalFrame,
		float interval,
		bool loop);

	void AddAnimationEvent(
		int frame,
		AnimationEventType type);

	void ProcessAnimationEvents(
		const std::vector<AnimationEvent>& events);

	void UpdateHitBox();

};
