#pragma once
#include<vector>

//?}?b?v?I?u?W?F?N?g
struct MapObject
{
	KdTexture* tex = nullptr;
	Math::Vector2 pos;
	int width = 0;
	int height = 0;
};

//?}?b?v?????f?[?^
struct MapData
{
	//??
	std::vector<MapObject> walls;
	//??
	std::vector<MapObject> floors;
	//?V??
	std::vector<MapObject> ceilings;
	//?z???E???
	std::vector<MapObject> facilities;
	//?j???E???I
	std::vector<MapObject> debris;
	//????
	std::vector<MapObject> decorations;
};

//?}?b?v???
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

	//???????
	void Init();

	//???t???[???X?V
	void Update();

	//?}?b?v?`??
	void Draw(int mapID, const Math::Vector2& cameraPos);

	//?}?b?v?f?[?^??J??
	void Release();

	//?}?b?v????????èÔ
	const std::vector<MapConnection>& GetConnections()const
	{
		return m_mapConnections;
	}

private:
	
	KdTexture m_trash_bag_1;           //?S?~??P
	KdTexture m_trash_bag_2;           //?S?~??Q
	KdTexture m_trash_bag_3;           //?S?~??R
	KdTexture m_trash_bag_4;           //?S?~??S
	KdTexture m_trash_bag_5;           //?S?~??T
	KdTexture m_trash_bag_6;           //?S?~??U
	KdTexture m_cardboard_box_1;       //?_???{?[???P
	KdTexture m_cardboard_box_2;       //?_???{?[???Q
	KdTexture m_cardboard_box_3;       //?_???{?[???R
	KdTexture m_cardboard_box_4;       //?_???{?[???S
	KdTexture m_cardboard_box_5;       //?_???{?[???T
	KdTexture m_cardboard_box_6;       //?_???{?[???U
	KdTexture m_wooden_pallet;         //??????P
	KdTexture m_tire;                  //?^?C??



	KdTexture m_tent;                  //?e???g
	KdTexture m_firewood;              //?L?????v?t?@?C???[??d
	KdTexture m_sleeping_bag;          //?Q??
	KdTexture m_lantern;               //?????^??
	KdTexture m_backpack;              //???
	KdTexture m_cooking_pot;           //??
	KdTexture m_campfire_lit;          //????
	KdTexture m_campfire_unlit;        //????@??????



	KdTexture m_rock_1;                //??P
	KdTexture m_rock_2;                //??Q
	KdTexture m_rock_3;                //??R
	KdTexture m_rock_4;                //??S
	KdTexture m_rock_5;                //??T
	KdTexture m_rock_6;                //??U
	KdTexture m_rock_7;                //??V



	KdTexture m_traffic_cone;          //?J???[?R?[??
	KdTexture m_bucket_1;              //?o?P?c?P
	KdTexture m_bucket_2;              //?o?P?c?Q
	KdTexture m_empty_bottle_1;        //???r???P
	KdTexture m_empty_bottle_2;        //???r???Q
	KdTexture m_plastic_bottle;        //???y?b?g?{?g??
	KdTexture m_empty_can;             //????
	KdTexture m_wooden_crate;          //??

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

	KdTexture m_roadTex;

	//?e?N?X?`?????
	std::vector<KdTexture> m_textures;

	//?}?b?v?f?[?^
	std::vector<MapData> m_maps;

	//=====================================================================
	//?}?b?v??????@?@?@?@?@?@???????
	//=====================================================================

	//?}?b?v?f?[?^
	std::vector<std::vector<MapObject>> m_mapObjects;
	std::vector<MapConnection> m_mapConnections;

	//?I?u?W?F?N?g?z?u??????
	void InitObjects();

	//?I?u?W?F?N?g?`??
	void DrawObjects(int MapID, const Math::Vector2& cameraPos);

	//????`??
	void DrawRoads(int mapID, const Math::Vector2& cameraPos);

	//?}?b?v??????????
	void InitConnections();


};