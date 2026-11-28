#include "main.h"
#include "Scene.h"
#include"GaugeUI.h"

void Scene::Draw2D()
{
	m_effectmanager.Draw();
	m_map.Draw(m_currentMapID, m_cameraPos);
	m_player.Draw(m_cameraPos);
	hpGauge.Draw();
	mpGauge.Draw();
}

void Scene::Update()
{
	m_effectmanager.Update();
	m_map.Update();
	m_player.Update();
	hpGauge.Update();
	mpGauge.Update();


	//マップ接続判定
	for (const auto& connection : m_map.GetConnections())
	{
		//現在のマップと接続元が一致するか確認
		if (connection.fromMapID != m_currentMapID)continue;

		Math::Vector2 playerPos = m_player.GetPos();

		//接続範囲に入ったか確認
		if (playerPos.x >= connection.minX && playerPos.x <= connection.maxX && playerPos.y >= connection.minY && playerPos.y <= connection.maxY)
		{
			//マップ切り替え
			m_currentMapID = connection.toMapID;

			//移動先の出現座標へ移動
			m_player.SetPos(connection.spawnPos);

			break;
		}
	}
	//カメラ　プレイヤー追従
	m_cameraPos = m_player.GetPos();
}

void Scene::Init()
{
	// 画像の読み込み処理
	charaTex.Load("player.png");

	m_effectmanager.Init();
	m_map.Init();
	m_player.Init();

	// HPゲージ
	hpGauge.Init();
	hpGauge.SetMaxValue(100);
	hpGauge.SetValue(100);
	hpGauge.SetPosition(-490.0f, 310.0f);
	hpGauge.SetSize(240.0f, 18.0f);
	hpGauge.SetColor(Math::Color(0.0f, 1.0f, 0.0f, 1.0f));
	hpGauge.SetDamageEffect(true);

	// MPゲージ
	mpGauge.Init();
	mpGauge.SetMaxValue(80);
	mpGauge.SetValue(80);
	mpGauge.SetPosition(-490.0f, 282.0f);
	mpGauge.SetSize(240.0f, 18.0f);
	mpGauge.SetColor(Math::Color(0.0f, 0.3f, 1.0f, 1.0f));
	mpGauge.SetDamageEffect(false);
}

void Scene::Release()
{
	// 画像の解放処理
	charaTex.Release();

	 m_effectmanager.Release();
	 m_map.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
