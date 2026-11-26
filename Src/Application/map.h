#pragma once
#include<vector>

//マップオブジェクト
struct MapObject
{
	KdTexture* tex = nullptr;
	Math::Vector2 pos;
	int width = 0;
	int height = 0;
};

//マップごとのデータ
struct MapData
{
	//壁
	std::vector<MapObject> walls;
	//床
	std::vector<MapObject> floors;
	//天井
	std::vector<MapObject> ceilings;
	//配線・設備
	std::vector<MapObject> facilities;
	//破損・瓦礫
	std::vector<MapObject> debris;
	//装飾
	std::vector<MapObject> decorations;
};

//マップ情報
struct MapConnection
{
	int fromMapID;
	int toMapID;

	float minX;
	float maxX;
	float minY;
	float maxY;

	Math::Vector2 spawnPos;
};

class Map
{
public:

	//初期設定
	void Init();

	//毎フレーム更新
	void Update();

	//マップ描画
	void Draw(int mapID, const Math::Vector2& cameraPos);

	//マップデータの解放
	void Release();

	//マップ接続情報を取得
	const std::vector<MapConnection>& GetConnections()const
	{
		return m_mapConnections;
	}

private:
	//===================================================
	//マップ内の画像　　　　　　ここから
	//===================================================

	//休眠カプセル画像

	KdTexture sleep_pod1;
	KdTexture sleep_pod2;
	KdTexture sleep_pod3;
	KdTexture sleep_pod4;
	KdTexture sleep_pod5;
	KdTexture sleep_pod6;
	KdTexture sleep_pod7;
	KdTexture sleep_pod8;
	KdTexture sleep_pod9;
	KdTexture sleep_pod10;
	KdTexture sleep_pod11;
	KdTexture sleep_pod12;
	KdTexture sleep_pod13;
	KdTexture sleep_pod14;
	KdTexture sleep_pod15;
	KdTexture sleep_pod16;
	KdTexture sleep_pod17;
	KdTexture sleep_pod18;

	//ゴミ・廃材系

	KdTexture m_trash_bag_1;           //ゴミ袋１
	KdTexture m_trash_bag_2;           //ゴミ袋２
	KdTexture m_trash_bag_3;           //ゴミ袋３
	KdTexture m_trash_bag_4;           //ゴミ袋４
	KdTexture m_trash_bag_5;           //ゴミ袋５
	KdTexture m_trash_bag_6;           //ゴミ袋６
	KdTexture m_trash_pile;            //ゴミの山
	KdTexture m_cardboard_box_1;       //ダンボール１
	KdTexture m_cardboard_box_2;       //ダンボール２
	KdTexture m_cardboard_box_3;       //ダンボール３
	KdTexture m_cardboard_box_4;       //ダンボール４
	KdTexture m_cardboard_box_5;       //ダンボール５
	KdTexture m_cardboard_box_6;       //ダンボール６
	KdTexture m_wooden_pallet;         //スノコ
	KdTexture m_tire;                  //タイヤ

	//キャンプ系

	KdTexture m_tent;                  //テント
	KdTexture m_firewood;              //キャンプファイヤー
	KdTexture m_sleeping_bag;          //寝袋
	KdTexture m_lantern;               //ランタン
	KdTexture m_backpack;              //荷物
	KdTexture m_cooking_pot;           //鍋
	KdTexture m_campfire_lit;          //焚火
	KdTexture m_campfire_unlit;        //焚火　消火済み

	//岩・自然物系

	KdTexture m_rock_1;                //岩１
	KdTexture m_rock_2;                //岩２
	KdTexture m_rock_3;                //岩３
	KdTexture m_rock_4;                //岩４
	KdTexture m_rock_5;                //岩５
	KdTexture m_rock_6;                //岩６
	KdTexture m_rock_7;                //岩７

	//空き容器

	KdTexture m_traffic_cone;          //カラーコーン
	KdTexture m_bucket_1;              //バケツ１
	KdTexture m_bucket_2;              //バケツ２
	KdTexture m_empty_bottle_1;        //空きビン１
	KdTexture m_empty_bottle_2;        //空きビン２
	KdTexture m_plastic_bottle;        //ペットボトル
	KdTexture m_empty_can;             //空きビン
	KdTexture m_wooden_crate;          //箱

	//壁用タイル

	KdTexture m_tile_1;
	KdTexture m_tile_2;
	KdTexture m_tile_3;
	KdTexture m_tile_4;
	KdTexture m_tile_5;
	KdTexture m_tile_6;
	KdTexture m_tile_7;
	KdTexture m_tile_8;
	KdTexture m_tile_9;
	KdTexture m_tile_10;
	KdTexture m_tile_11;
	KdTexture m_tile_12;
	KdTexture m_tile_13;
	KdTexture m_tile_14;
	KdTexture m_tile_15;
	KdTexture m_tile_16;

	//床用タイル

	KdTexture m_floortile_1;
	KdTexture m_floortile_2;
	KdTexture m_floortile_3;
	KdTexture m_floortile_4;
	KdTexture m_floortile_5;
	KdTexture m_floortile_6;
	KdTexture m_floortile_7;
	KdTexture m_floortile_8;
	KdTexture m_floortile_9;
	KdTexture m_floortile_10;
	KdTexture m_floortile_11;
	KdTexture m_floortile_12;
	KdTexture m_floortile_13;
	KdTexture m_floortile_14;
	KdTexture m_floortile_15;
	KdTexture m_floortile_16;

	KdTexture m_roadTex;

	//テクスチャ管理
	std::vector<KdTexture> m_textures;

	//マップデータ
	std::vector<MapData> m_maps;

	//接続位置に表示させる扉
	KdTexture m_doorTex;

	//=====================================================================
	//マップ内の画像　　　　　　ここまで
	//=====================================================================

	//マップデータ
	std::vector<std::vector<MapObject>> m_mapObjects;
	std::vector<MapConnection> m_mapConnections;

	//オブジェクト配置初期化
	void InitObjects();

	//オブジェクト描画
	void DrawObjects(int MapID, const Math::Vector2& cameraPos);

	//道の描画
	void DrawRoads(int mapID, const Math::Vector2& cameraPos);
	void DrawFloors(int mapID, const Math::Vector2& cameraPos);
	void DrawCeilings(int mapID, const Math::Vector2& cameraPos);
	void DrawFacilities(int mapID, const Math::Vector2& cameraPos);
	void DrawDebris(int mapID, const Math::Vector2& cameraPos);
	void DrawDecorations(int mapID, const Math::Vector2& cameraPos);

	//マップ接続情報初期化
	void InitConnections();

	std::vector<std::vector<MapObject>>m_floorObjects;
	std::vector<std::vector<MapObject>>m_ceilingObjects;
	std::vector<std::vector<MapObject>>m_facilityObjects;
	std::vector<std::vector<MapObject>>m_debrisObjects;
	std::vector<std::vector<MapObject>>m_decorationObjects;

	//=======================================
	//マップ配置データ　　重要！！
	//=======================================
	int m_mapData[12][18] = {};


};