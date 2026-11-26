#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{

	m_effectmanager.Draw();
	m_map.Draw(0, Math::Vector2(0, 0));
}

void Scene::Update()
{
	m_effectmanager.Update();
	m_map.Update();
}

void Scene::Init()
{
	// 画像の読み込み処理
	charaTex.Load("player.png");

	m_effectmanager.Init();
	m_map.Init();
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
