#include"Src/Application/main.h"
#include"map.h"
#include<cstdlib>

void Map::Init()
{
	//１面==========================================================-
	//ゴミ・廃材系
	m_trash_bag_1.Load("texture/１面/ゴミ袋１.png");
	m_trash_bag_2.Load("texture/１面/ゴミ袋２.png");
	m_trash_bag_3.Load("texture/１面/ゴミ袋３.png");
	m_trash_bag_4.Load("texture/１面/ゴミ袋４.png");
	m_trash_bag_5.Load("texture/１面/ゴミ袋５.png");
	m_trash_bag_6.Load("texture/１面/ゴミ袋６.png");
	m_cardboard_box_1.Load("texture/１面/ダンボール１.png");
	m_cardboard_box_2.Load("texture/１面/ダンボール２.png");
	m_cardboard_box_3.Load("texture/１面/ダンボール３.png");
	m_cardboard_box_4.Load("texture/１面/ダンボール４.png");
	m_cardboard_box_5.Load("texture/１面/ダンボール５.png");
	m_cardboard_box_6.Load("texture/１面/ダンボール６.png");
	m_wooden_pallet.Load("texture/１面/スノコ.png");
	m_tire.Load("texture/１面/タイヤ.png");
	//キャンプ系
	m_tent.Load("texture/１面/テント.png");
	m_firewood.Load("texture/１面/キャンプファイヤーの薪.png");
	m_sleeping_bag.Load("texture/１面/寝袋.png");
	m_lantern.Load("texture/１面/ランタン.png");
	m_backpack.Load("texture/１面/荷物.png");
	m_cooking_pot.Load("texture/１面/鍋.png");
	m_campfire_lit.Load("texture/１面/焚火.png");
	m_campfire_unlit.Load("texture/１面/焚火　消火済み.png");

	m_rock_1.Load("texture/１面/岩１.png");
	m_rock_2.Load("texture/１面/岩２.png");
	m_rock_3.Load("texture/１面/岩３.png");
	m_rock_4.Load("texture/１面/岩４.png");
	m_rock_5.Load("texture/１面/岩５.png");
	m_rock_6.Load("texture/１面/岩６.png");
	m_rock_7.Load("texture/１面/岩７.png");
	//空き容器
	m_traffic_cone.Load("texture/１面/カラーコーン.png");
	m_bucket_1.Load("texture/１面/バケツ１.png");
	m_bucket_2.Load("texture/１面/バケツ２.png");
	m_empty_bottle_1.Load("texture/１面/空きビン１.png");
	m_empty_bottle_2.Load("texture/１面/空きビン２.png");
	m_plastic_bottle.Load("texture/１面/空きペットボトル.png");
	m_empty_can.Load("texture/１面/空き缶.png");
	m_wooden_crate.Load("texture/１面/箱.png");
	//タイル
	

	m_roadTex.Load("texture/ゴミの山.png");

	//マップ接続状況
	InitConnections();

	//マップオブジェクト配置
	InitObjects();
}

//毎フレーム更新
void Map::Update()
{

}

//===================================================================
//道の描画
//===================================================================
void Map::DrawRoads(int mapID, const Math::Vector2& cameraPos)
{
	auto DrawRoad = [&](int x, int y)
	{
		SHADER.m_spriteShader.DrawTex(&m_roadTex, x - (int)cameraPos.x, y - (int)cameraPos.y, 100, 100);
	};
	switch (mapID)
	{
	default:
		break;
	}
}

//===================================================================
//マップ描画
//===================================================================
void Map::Draw(int mapID, const Math::Vector2& cameraPos)
{
	//地面描画するマップ
	switch (mapID)
	{
		DrawRoads(mapID, cameraPos);
		DrawObjects(mapID, cameraPos);
	default:
		break;
	}
}

void Map::InitObjects()
{
	m_mapObjects.clear();

	//マップID０～９９９の配置リストを用意
	m_mapObjects.resize(1000);

	//各マップのオブジェクトを用意
	
	//============================================
	//１面
	//============================================
	
	//マップ０
	m_mapObjects[0] =
	{

	};
	m_mapObjects[1] =
	{

	};
	m_mapObjects[2] =
	{

	};
	m_mapObjects[3] =
	{

	};
	m_mapObjects[4] =
	{

	};
	m_mapObjects[5] =
	{

	};
	m_mapObjects[6] =
	{

	};
	m_mapObjects[7] =
	{

	};
	m_mapObjects[8] =
	{

	};
	m_mapObjects[9] =
	{

	};
	m_mapObjects[10] =
	{

	};
	m_mapObjects[11] =
	{

	};

	//================================================
	//２面
	//================================================
	m_mapObjects[12] =
	{

	};
	m_mapObjects[13] =
	{

	};
	m_mapObjects[14] =
	{

	};
	m_mapObjects[15] =
	{

	};
	m_mapObjects[16] =
	{

	};
	m_mapObjects[17] =
	{

	};
	m_mapObjects[18] =
	{

	};
	m_mapObjects[19] =
	{

	};
	m_mapObjects[20] =
	{

	};
	m_mapObjects[21] =
	{

	};
	m_mapObjects[22] =
	{

	};
	m_mapObjects[23] =
	{

	};
	m_mapObjects[24] =
	{

	};
	m_mapObjects[25] =
	{

	};
	m_mapObjects[26] =
	{

	};
	m_mapObjects[27] =
	{

	};
	m_mapObjects[28] =
	{

	};
	m_mapObjects[29] =
	{

	};
	m_mapObjects[30] =
	{

	};
	m_mapObjects[31] =
	{

	};
	m_mapObjects[32] =
	{

	};
	m_mapObjects[33] =
	{

	};
	m_mapObjects[34] =
	{

	};
	m_mapObjects[35] =
	{

	};
	m_mapObjects[36] =
	{

	};
	m_mapObjects[37] =
	{

	};
	m_mapObjects[38] =
	{

	};
	m_mapObjects[39] =
	{

	};
	m_mapObjects[40] =
	{

	};
	m_mapObjects[41] =
	{

	};
	m_mapObjects[42] =
	{

	};
	m_mapObjects[43] =
	{

	};
	m_mapObjects[44] =
	{

	};
	m_mapObjects[45] =
	{

	};
	m_mapObjects[46] =
	{

	};
	m_mapObjects[47] =
	{

	};
	m_mapObjects[48] =
	{

	};
	m_mapObjects[49] =
	{

	};
	m_mapObjects[50] =
	{

	};
	m_mapObjects[51] =
	{

	};
	m_mapObjects[52] =
	{

	};
	m_mapObjects[53] =
	{

	};
	m_mapObjects[54] =
	{

	};
	m_mapObjects[55] =
	{

	};
	m_mapObjects[56] =
	{

	};
	m_mapObjects[57] =
	{

	};
	m_mapObjects[58] =
	{

	};
	m_mapObjects[59] =
	{

	};
	m_mapObjects[60] =
	{

	};
	m_mapObjects[61] =
	{

	};
	m_mapObjects[62] =
	{

	};
	m_mapObjects[63] =
	{

	};
	m_mapObjects[64] =
	{

	};
	m_mapObjects[65] =
	{

	};
	m_mapObjects[66] =
	{

	};
	m_mapObjects[67] =
	{

	};
	m_mapObjects[68] =
	{

	};
	m_mapObjects[69] =
	{

	};
	m_mapObjects[70] =
	{

	};
	m_mapObjects[71] =
	{

	};
	m_mapObjects[72] =
	{

	};
	m_mapObjects[73] =
	{

	};
	m_mapObjects[74] =
	{

	};
	m_mapObjects[75] =
	{

	};
	m_mapObjects[76] =
	{

	};
	m_mapObjects[77] =
	{

	};
	m_mapObjects[78] =
	{

	};
	m_mapObjects[79] =
	{

	};
	m_mapObjects[80] =
	{

	};
	m_mapObjects[81] =
	{

	};
	m_mapObjects[82] =
	{

	};
	m_mapObjects[83] =
	{

	};
	m_mapObjects[84] =
	{

	};
	m_mapObjects[85] =
	{

	};
	m_mapObjects[86] =
	{

	};
	m_mapObjects[87] =
	{

	};
	m_mapObjects[88] =
	{

	};
	m_mapObjects[89] =
	{

	};
	m_mapObjects[90] =
	{

	};
	m_mapObjects[91] =
	{

	};
	m_mapObjects[92] =
	{

	};
	m_mapObjects[93] =
	{

	};
	m_mapObjects[94] =
	{

	};
	m_mapObjects[95] =
	{

	};
	m_mapObjects[96] =
	{

	};
	m_mapObjects[97] =
	{

	};
	m_mapObjects[98] =
	{

	};
	m_mapObjects[99] =
	{

	};
	m_mapObjects[100] =
	{

	};

}

//=======================================================
//マップオブジェクト描画
//=======================================================
void Map::DrawObjects(int MapID, const Math::Vector2& cameraPos)
{
	//マップIDは範囲外なら描画しない
	if (MapID < 0 || MapID >= (int)m_mapObjects.size())
	{
		return;
	}
	//現在のマップに登録されているオブジェクトを描画
	for (const auto& obj : m_mapObjects[MapID])
	{
		if (obj.tex == nullptr)continue;
		SHADER.m_spriteShader.DrawTex(obj.tex, (int)(obj.pos.x - cameraPos.x), (int)(obj.pos.y - cameraPos.y), obj.width, obj.height);
	}
}

//===================================================
//マップ移動
//===================================================
void Map::InitConnections()
{
	m_mapConnections =
	{
		//縦移動===========================================
		{ 0,1,300,400,-550,-450,Math::Vector2(0,500) },
		{ 1,2,850,900,-50,50,Math::Vector2(0,500) },
		{ 2,1,-900,-850,-50,50,Math::Vector2(500,-450) },
		{ 2,3,850,900,-50,50,Math::Vector2(0,500) },
		{ 3,2,-900,-850,-50,50,Math::Vector2(500,-450) },
		{ 3,4,850,900,-50,50,Math::Vector2(0,500) },
		{ 4,3,-900,-850,-50,50,Math::Vector2(500,-450) },
		{ 4,5,850,900,-50,50,Math::Vector2(0,500) },
		{ 5,4,-900,-850,-50,50,Math::Vector2(500,-450) },
		{ 5,6,850,900,-50,50,Math::Vector2(0,500) },
		{ 6,5,-900,-850,-50,50,Math::Vector2(500,-450) },
		{ 6,7,850,900,-50,50,Math::Vector2(0,500) },
		{ 7,6,-900,-850,-50,50,Math::Vector2(500,-450) },
		{ 7,8,850,900,-50,50,Math::Vector2(0,500) },
		{ 8,7,-900,-850,-50,50,Math::Vector2(500,-450) },

		{ 8,9,300,400,-550,-450,Math::Vector2(0,500) },
		{ 9,8,450,550,500,600,Math::Vector2(500,-450) },

		{ 9,10,850,900,-50,50,Math::Vector2(0,500) },
		{ 10,9,-900,-850,-50,50,Math::Vector2(500,-450) },
		{ 10,11,850,900,-50,50,Math::Vector2(0,500) },
		{ 11,10,-900,-850,-50,50,Math::Vector2(500,-450) },
		{ 11,12,850,900,-50,50,Math::Vector2(0,500) },
		{ 12,11,-900,-850,-50,50,Math::Vector2(500,-450) },

	};
}

void Map::Release()
{

}