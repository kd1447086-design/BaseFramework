#include"Src/Application/main.h"
#include"map.h"
#include<cstdlib>

void Map::Init()
{
	//各マップのサイズ設定
	SetMapSize(0, 18, 12);
	SetMapSize(1, 30, 20);
	SetMapSize(2, 50, 35);
	SetMapSize(3, 30, 20);
	SetMapSize(4, 30, 20);
	SetMapSize(5, 30, 20);
	SetMapSize(6, 30, 20);
	SetMapSize(7, 30, 20);
	SetMapSize(8, 30, 20);
	SetMapSize(9, 30, 20);
	SetMapSize(10, 30, 20);
	SetMapSize(11, 30, 20);

	//１面==========================================================-

	//休眠カプセル
	sleep_pod1.Load("texture/研究所/休眠カプセル１.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル２.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル３.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル４.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル５.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル６.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル７.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル８.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル９.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル１０.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル１１.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル１２.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル１３.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル１４.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル１５.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル１６.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル１７.png");
	sleep_pod1.Load("texture/研究所/休眠カプセル１８.png");

	//ゴミ・廃材系
	m_trash_bag_1.Load("texture/１面/ゴミ袋１.png");
	m_trash_bag_2.Load("texture/１面/ゴミ袋２.png");
	m_trash_bag_3.Load("texture/１面/ゴミ袋３.png");
	m_trash_bag_4.Load("texture/１面/ゴミ袋４.png");
	m_trash_bag_5.Load("texture/１面/ゴミ袋５.png");
	m_trash_bag_6.Load("texture/１面/ゴミ袋６.png");
	m_trash_pile.Load("texture/ごみの山.png");
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
	m_traffic_cone.Load("texture/カラーコーン.png");
	m_bucket_1.Load("texture/１面/バケツ１.png");
	m_bucket_2.Load("texture/１面/バケツ２.png");
	m_empty_bottle_1.Load("texture/１面/空きビン１.png");
	m_empty_bottle_2.Load("texture/１面/空きビン２.png");
	m_plastic_bottle.Load("texture/１面/空きペットボトル.png");
	m_empty_can.Load("texture/１面/空き缶.png");
	m_wooden_crate.Load("texture/１面/箱.png");
	//壁用タイル
	m_tile_1.Load("texture/１面/タイル１.png");
	m_tile_2.Load("texture/１面/タイル２.png");
	m_tile_3.Load("texture/１面/タイル３.png");
	m_tile_4.Load("texture/１面/タイル４.png");
	m_tile_5.Load("texture/１面/タイル５.png");
	m_tile_6.Load("texture/１面/タイル６.png");
	m_tile_7.Load("texture/１面/タイル７.png");
	m_tile_8.Load("texture/１面/タイル８.png");
	m_tile_9.Load("texture/１面/タイル９.png");
	m_tile_10.Load("texture/１面/タイル１０.png");
	m_tile_11.Load("texture/１面/タイル１１.png");
	m_tile_12.Load("texture/１面/タイル１２.png");
	m_tile_13.Load("texture/１面/タイル１３.png");
	m_tile_14.Load("texture/１面/タイル１４.png");
	m_tile_15.Load("texture/１面/タイル１５.png");
	m_tile_16.Load("texture/１面/タイル１６.png");
	//床用タイル
	m_floortile_1.Load("texture/１面/床タイル１.png");
	m_floortile_2.Load("texture/１面/床タイル２.png");
	m_floortile_3.Load("texture/１面/床タイル３.png");
	m_floortile_4.Load("texture/１面/床タイル４.png");
	m_floortile_5.Load("texture/１面/床タイル５.png");
	m_floortile_6.Load("texture/１面/床タイル６.png");
	m_floortile_7.Load("texture/１面/床タイル７.png");
	m_floortile_8.Load("texture/１面/床タイル８.png");
	m_floortile_9.Load("texture/１面/床タイル９.png");
	m_floortile_10.Load("texture/１面/床タイル１０.png");
	m_floortile_11.Load("texture/１面/床タイル１１.png");
	m_floortile_12.Load("texture/１面/床タイル１２.png");
	m_floortile_13.Load("texture/１面/床タイル１３.png");
	m_floortile_14.Load("texture/１面/床タイル１４.png");
	m_floortile_15.Load("texture/１面/床タイル１５.png");
	m_floortile_16.Load("texture/１面/床タイル１６.png");


	m_roadTex.Load("texture/ごみの山.png");

	m_doorTex.Load("texture/扉.png");

	//マップ接続状況
	InitConnections();

	//マップオブジェクト配置
	InitObjects();

	//全マップ配置データ初期化
	for (int map = 0; map < 12; map++)
	{
		for (int y = 0; y < m_mapData[map].size(); y++)
		{
			for (int x = 0; x < m_mapData[map][y].size(); x++)
			{
				m_mapData[map][y][x] = 0;
			}
		}
	}
	//部屋の床を配置
	for (int y = 5; y < 7; y++)
	{
		for (int x = 2; x < 18; x++)
		{
			m_mapData[0][y][x] = 1;
		}
	}

	//マップ１の床を配置
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			m_mapData[1][y][x] = 1;
		}
	}
	for (int y = 0; y < 35; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			m_mapData[2][y][x] = 1;
		}
	}







}

//毎フレーム更新
void Map::Update()
{

}


//===================================================================
//マップ描画
//===================================================================
void Map::Draw(int mapID, const Math::Vector2& cameraPos)
{
	//床を描画
	DrawFloors(mapID, cameraPos);

	//天井を描画
	DrawCeilings(mapID, cameraPos);

	//設備
	DrawFacilities(mapID, cameraPos);

	//壁を描画
	DrawRoads(mapID, cameraPos);

	//瓦礫を描画
	DrawDebris(mapID, cameraPos);

	//装飾を描画
	DrawDecorations(mapID, cameraPos);

	//オブジェクトを描画
	DrawObjects(mapID, cameraPos);

	//接続扉の描画
	if (mapID == 0)
	{
		SHADER.m_spriteShader.DrawTex(&m_doorTex, 350 - (int)cameraPos.x, -500 - (int)cameraPos.y, 100, 100);
	}
	if (mapID == 1)
	{
		SHADER.m_spriteShader.DrawTex(&m_doorTex, 875 - (int)cameraPos.x, 0 - (int)cameraPos.y, 100, 100);
	}
	if (mapID == 2)
	{
		SHADER.m_spriteShader.DrawTex(&m_doorTex, -875 - (int)cameraPos.x, 0 - (int)cameraPos.y, 100, 100);
	}

}

void Map::DrawRoads(int mapID, const Math::Vector2& cameraPos)
{
	//壁タイル描画
	auto DrawTile = [&](KdTexture* tex, int x, int y)
	{
		SHADER.m_spriteShader.DrawTex(tex, x - (int)cameraPos.x, y - (int)cameraPos.y, 100, 100);
	};
	KdTexture* walltiles[16] =
	{
		&m_tile_1,&m_tile_2,&m_tile_3,&m_tile_4,&m_tile_5,&m_tile_6,&m_tile_7,&m_tile_8,&m_tile_9,&m_tile_10,
		&m_tile_11,&m_tile_12,&m_tile_13,&m_tile_14,&m_tile_15,&m_tile_16
	};

	//上側の壁
	for (int x = -650; x <= 850; x += 100)
	{
		int tileIndex = (x + 650) / 100 % 16;
		DrawTile(walltiles[tileIndex], x, 150);
	}
	//下側の壁
	for (int x = -650; x <= 850; x += 100)
	{
		int tileIndex = (x + 650) / 100 % 16;
		DrawTile(walltiles[tileIndex], x, -150);
	}


}

void Map::DrawFloors(int mapID, const Math::Vector2& cameraPos)
{
	//マップIDの確認
	if (mapID < 0 || mapID >= 12)return;
	
	//床タイル描画
	auto DrawFloor = [&](KdTexture* tex, int x, int y)
	{
		SHADER.m_spriteShader.DrawTex(tex, x - (int)cameraPos.x, y - (int)cameraPos.y, 100, 100);
	};

	//床タイル１６種類
	KdTexture* floortiles[16] =
	{
		&m_floortile_1,
		&m_floortile_2,
		&m_floortile_3,
		&m_floortile_4,
		&m_floortile_5,
		&m_floortile_6,
		&m_floortile_7,
		&m_floortile_8,
		&m_floortile_9,
		&m_floortile_10,
		&m_floortile_11,
		&m_floortile_12,
		&m_floortile_13,
		&m_floortile_14,
		&m_floortile_15,
		&m_floortile_16
	};

	//基本の床タイル
	KdTexture* basictiles[9] =
	{
		floortiles[1],  //2
		floortiles[3],  //4
		floortiles[5],  //6
		floortiles[6],  //7
		floortiles[9],  //10
		floortiles[11], //12
		floortiles[12], //13
		floortiles[14], //15
		floortiles[15], //16
	};
	//瓦礫タイルを敷き詰める
	KdTexture* damagetiles[2] =
	{
		floortiles[4],  //5
		floortiles[10], //11
	};
	//金属・通気口タイルを敷き詰める
	KdTexture* metaltiles[5] =
	{
		floortiles[0],  //1
		floortiles[2],  //3
		floortiles[7],  //8
		floortiles[8],  //9
		floortiles[13], //14
	};
	//床タイルを敷き詰める
	for (int y = 0; y < m_mapData[mapID].size(); y++)
	{
		for (int x = 0; x < m_mapData[mapID][y].size(); x++)
		{
			KdTexture* tile = basictiles[(x + y * 3) % 9];

			if (mapID == 0)
			{
				if ((x == 4 && y == 3) || (x == 12 && y == 8))
				{
					tile = damagetiles[(x + y) % 2];
				}
			}
			if (mapID == 1)
			{
				if (x % 6 == 0 && y % 4 == 1)
				{
					tile = damagetiles[(x + y) % 2];
				}
			}
			if (mapID == 2)
			{
				if (x % 5 == 2 && y % 4 == 2)
				{
					tile = metaltiles[(x + y) % 5];
				}
			}
			if (mapID == 3)
			{
				if ((x + y) % 11 == 0)
				{
					tile = damagetiles[(x + y) % 2];
				}
			}
			if (mapID == 4)
			{
				if ((x * 2 + y) % 13 == 0)
				{
					tile = damagetiles[(x + y) % 2];
				}
			}
			if (mapID == 5)
			{
				if ((x + y * 2) % 7 == 0)
				{
					tile = damagetiles[(x + y) % 2];
				}
			}
			if (mapID == 6)
			{
				if ((x * 3 + y * 2) % 17 == 0)
				{
					tile = damagetiles[(x + y) % 2];
				}
			}
			if (mapID == 7)
			{
				if ((x + y * 3) % 9 == 0)
				{
					tile = damagetiles[(x + y) % 2];
				}
			}
			if (mapID == 8)
			{
				if ((x + y) % 6 == 0)
				{
					tile = metaltiles[(x + y) % 5];
				}
			}
			if (mapID == 9)
			{
				if ((x * 2 + y) % 7 == 0)
				{
					tile = metaltiles[(x + y) % 5];
				}
			}
			if (mapID == 10)
			{
				if ((x + y * 2) % 15 == 0)
				{
					tile = metaltiles[(x + y) % 5];
				}
			}
			if (mapID == 11)
			{
				if ((x + y) % 3 == 0)
				{
					tile = metaltiles[(x + y) % 5];
				}
				else if ((x * 2 + y) % 11 == 0)
				{
					tile = damagetiles[(x + y) % 2];
				}
			}
			//床が配置されてるマスだけ描画
			if (m_mapData[mapID][y][x] == 1)
			{
				DrawFloor(tile, -850 + x * 100, -550 + y * 100);
			}
		}
	}
}

void Map::DrawCeilings(int mapID, const Math::Vector2& cameraPos)
{
	if (mapID < 0 || mapID >= m_ceilingObjects.size())
	{
		return;
	}
	for (const auto& obj : m_ceilingObjects[mapID])
	{
		if (obj.tex != nullptr)
		{
			SHADER.m_spriteShader.DrawTex(obj.tex, obj.pos.x - cameraPos.x, obj.pos.y - cameraPos.y, obj.width, obj.height);
		}
	}
}

void Map::DrawFacilities(int mapID, const Math::Vector2& cameraPos)
{
	if (mapID < 0 || mapID >= m_facilityObjects.size())
	{
		return;
	}
	for (const auto& obj : m_facilityObjects[mapID])
	{
		if (obj.tex != nullptr)
		{
			SHADER.m_spriteShader.DrawTex(obj.tex, obj.pos.x - cameraPos.x, obj.pos.y - cameraPos.y, obj.width, obj.height);
		}
	}
}
void Map::DrawDebris(int mapID, const Math::Vector2& cameraPos)
{
	if (mapID < 0 || mapID >= m_debrisObjects.size())
	{
		return;
	}
	for (const auto& obj : m_debrisObjects[mapID])
	{
		if (obj.tex != nullptr)
		{
			SHADER.m_spriteShader.DrawTex(obj.tex, obj.pos.x - cameraPos.x, obj.pos.y - cameraPos.y, obj.width, obj.height);
		}
	}
}
void Map::DrawDecorations(int mapID, const Math::Vector2& cameraPos)
{
	if (mapID < 0 || mapID >= m_decorationObjects.size())
	{
		return;
	}
	for (const auto& obj : m_decorationObjects[mapID])
	{
		if (obj.tex != nullptr)
		{
			SHADER.m_spriteShader.DrawTex(obj.tex, obj.pos.x - cameraPos.x, obj.pos.y - cameraPos.y, obj.width, obj.height);
		}
	}
}

void Map::InitObjects()
{
	m_mapObjects.clear();

	//マップID０～９９９の配置リストを用意
	m_mapObjects.resize(1000);

	m_floorObjects.clear();
	m_floorObjects.resize(12);
	for (int i = 0; i < 12; i++)
	{
		m_floorObjects[i] = {};
	}

	m_ceilingObjects.clear();
	m_ceilingObjects.resize(12);
	for (int i = 0; i < 12; i++)
	{
		m_ceilingObjects[i] = {};
	}

	m_facilityObjects.clear();
	m_facilityObjects.resize(12);
	for (int i = 0; i < 12; i++)
	{
		m_facilityObjects[i] = {};
	}

	m_debrisObjects.clear();
	m_debrisObjects.resize(12);
	for (int i = 0; i < 12; i++)
	{
		m_debrisObjects[i] = {};
	}

	m_decorationObjects.clear();
	m_decorationObjects.resize(12);
	for (int i = 0; i < 12; i++)
	{
		m_decorationObjects[i] = {};
	}

	//============================================
	//１面
	//============================================
	// m_mapObjects　　　　一般オブジェクト
	// m_floorobjects　　　床
	// m_ceilingobjects　　天井
	// m_facilityObjects　 配線・設備
	// m_debrisObjects　　 瓦礫
	// m_decorations　　　 装飾

	//マップ０
	m_mapObjects[0] =
	{
		//またあとで決める
	};
	m_floorObjects[0] =
	{

	};
	m_ceilingObjects[0] =
	{

	};
	m_facilityObjects[0] =
	{

	};
	m_debrisObjects[0] =
	{

	};
	m_decorationObjects[0] =
	{

	};

	m_mapObjects[1] =
	{
		//ゴミの山があるエリア

		//ゴミの山＆ゴミ
		{ &m_trash_pile,Math::Vector2(-500,140),1000,500 },
		{ &m_trash_bag_1,Math::Vector2(300,100),100,100 },
		{ &m_trash_bag_2,Math::Vector2(600,110),100,100 },
		{ &m_trash_bag_3,Math::Vector2(400,130),100,100 },
		{ &m_trash_bag_3,Math::Vector2(100,130),100,100 },
		{ &m_trash_bag_3,Math::Vector2(200,80),100,100 },
		{ &m_trash_bag_3,Math::Vector2(300,-55),100,100 },
		{ &m_trash_bag_4,Math::Vector2(600,-55),100,100 },
		{ &m_trash_bag_5,Math::Vector2(700,-50),100,100 },
		//カラーコーン
		{ &m_traffic_cone,Math::Vector2(500,100),100,100 },
		{ &m_traffic_cone,Math::Vector2(100,-50),100,100 },
		// バケツ
		{ &m_bucket_1,Math::Vector2(750,100),50,50 },
		{ &m_bucket_2,Math::Vector2(850,-75),50,50 },
		// 空きビン
		{ &m_empty_bottle_1,Math::Vector2(350,-80),30,50 },
		{ &m_empty_bottle_2,Math::Vector2(450,100),30,50 },
		// ペットボトル
		{ &m_plastic_bottle,Math::Vector2(650,-80),30,50 },
		// 空き缶
		{ &m_empty_can,Math::Vector2(60,-70),50,50 },
		// 木箱
		{ &m_wooden_crate,Math::Vector2(850,100),100,100 },
	};
	m_floorObjects[1] =
	{

	};
	m_ceilingObjects[1] =
	{

	};
	m_facilityObjects[1] =
	{

	};
	m_debrisObjects[1] =
	{

	};
	m_decorationObjects[1] =
	{

	};

	m_mapObjects[2] =
	{

	};
	m_floorObjects[2] =
	{

	};
	m_ceilingObjects[2] =
	{

	};
	m_facilityObjects[2] =
	{

	};
	m_debrisObjects[2] =
	{

	};
	m_decorationObjects[2] =
	{

	};

	m_mapObjects[3] =
	{

	};
	m_floorObjects[3] =
	{

	};
	m_ceilingObjects[3] =
	{

	};
	m_facilityObjects[3] =
	{

	};
	m_debrisObjects[3] =
	{

	};
	m_decorationObjects[3] =
	{

	};

	m_mapObjects[4] =
	{

	};
	m_floorObjects[4] =
	{

	};
	m_ceilingObjects[4] =
	{

	};
	m_facilityObjects[4] =
	{

	};
	m_debrisObjects[4] =
	{

	};
	m_decorationObjects[4] =
	{

	};

	m_mapObjects[5] =
	{

	};
	m_floorObjects[5] =
	{

	};
	m_ceilingObjects[5] =
	{

	};
	m_facilityObjects[5] =
	{

	};
	m_debrisObjects[5] =
	{

	};
	m_decorationObjects[5] =
	{

	};

	m_mapObjects[6] =
	{

	};
	m_floorObjects[6] =
	{

	};
	m_ceilingObjects[6] =
	{

	};
	m_facilityObjects[6] =
	{

	};
	m_debrisObjects[6] =
	{

	};
	m_decorationObjects[6] =
	{

	};

	m_mapObjects[7] =
	{

	};
	m_floorObjects[7] =
	{

	};
	m_ceilingObjects[7] =
	{

	};
	m_facilityObjects[7] =
	{

	};
	m_debrisObjects[7] =
	{

	};
	m_decorationObjects[7] =
	{

	};

	m_mapObjects[8] =
	{

	};
	m_floorObjects[8] =
	{

	};
	m_ceilingObjects[8] =
	{

	};
	m_facilityObjects[8] =
	{

	};
	m_debrisObjects[8] =
	{

	};
	m_decorationObjects[8] =
	{

	};

	m_mapObjects[9] =
	{

	};
	m_floorObjects[9] =
	{

	};
	m_ceilingObjects[9] =
	{

	};
	m_facilityObjects[9] =
	{

	};
	m_debrisObjects[9] =
	{

	};
	m_decorationObjects[9] =
	{

	};

	m_mapObjects[10] =
	{

	};
	m_floorObjects[10] =
	{

	};
	m_ceilingObjects[10] =
	{

	};
	m_facilityObjects[10] =
	{

	};
	m_debrisObjects[10] =
	{

	};
	m_decorationObjects[10] =
	{

	};

	m_mapObjects[11] =
	{

	};
	m_floorObjects[11] =
	{

	};
	m_ceilingObjects[11] =
	{

	};
	m_facilityObjects[11] =
	{

	};
	m_debrisObjects[11] =
	{

	};
	m_decorationObjects[11] =
	{

	};

	//================================================
	//２面
	//================================================
	/*
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
	*/

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
		{ 0,1,300,400,-50,-40,Math::Vector2(-500,500) },
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

//===================================
//サイズ設定処理
//===================================
void Map::SetMapSize(int mapID, int width, int height)
{
	if (mapID < 0 || mapID >= 12)return;
	if (width <= 0 || height <= 0)return;

	m_mapData[mapID].resize(height);

	for (int y = 0; y < height; y++)
	{
		m_mapData[mapID][y].resize(width, 0);
	}

}