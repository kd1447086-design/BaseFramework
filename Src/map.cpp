#include"Src/Application/main.h"
#include"map.h"
#include<cstdlib>

void Map::Init()
{
	m_trash_bag_1.Load("texture/?P??/?S?~??P.png");
	m_trash_bag_2.Load("texture/?P??/?S?~??Q.png");
	m_trash_bag_3.Load("texture/?P??/?S?~??R.png");
	m_trash_bag_4.Load("texture/?P??/?S?~??S.png");
	m_trash_bag_5.Load("texture/?P??/?S?~??T.png");
	m_trash_bag_6.Load("texture/?P??/?S?~??U.png");
	m_cardboard_box_1.Load("texture/?P??/?_???{?[???P.png");
	m_cardboard_box_2.Load("texture/?P??/?_???{?[???Q.png");
	m_cardboard_box_3.Load("texture/?P??/?_???{?[???R.png");
	m_cardboard_box_4.Load("texture/?P??/?_???{?[???S.png");
	m_cardboard_box_5.Load("texture/?P??/?_???{?[???T.png");
	m_cardboard_box_6.Load("texture/?P??/?_???{?[???U.png");
	m_wooden_pallet.Load("texture/?P??/?X?m?R.png");
	m_tire.Load("texture/?P??/?^?C??.png");

	m_tent.Load("texture/?P??/?e???g.png");
	m_firewood.Load("texture/?P??/?L?????v?t?@?C???[??d.png");
	m_sleeping_bag.Load("texture/?P??/?Q??.png");
	m_lantern.Load("texture/?P??/?????^??.png");
	m_backpack.Load("texture/?P??/???.png");
	m_cooking_pot.Load("texture/?P??/??.png");
	m_campfire_lit.Load("texture/?P??/????.png");
	m_campfire_unlit.Load("texture/?P??/????@??????.png");

	m_rock_1.Load("texture/?P??/??P.png");
	m_rock_2.Load("texture/?P??/??Q.png");
	m_rock_3.Load("texture/?P??/??R.png");
	m_rock_4.Load("texture/?P??/??S.png");
	m_rock_5.Load("texture/?P??/??T.png");
	m_rock_6.Load("texture/?P??/??U.png");
	m_rock_7.Load("texture/?P??/??V.png");

	m_traffic_cone.Load("texture/?P??/?J???[?R?[??.png");
	m_bucket_1.Load("texture/?P??/?o?P?c?P.png");
	m_bucket_2.Load("texture/?P??/?o?P?c?Q.png");
	m_empty_bottle_1.Load("texture/?P??/???r???P.png");
	m_empty_bottle_2.Load("texture/?P??/???r???Q.png");
	m_plastic_bottle.Load("texture/?P??/???y?b?g?{?g??.png");
	m_empty_can.Load("texture/?P??/????.png");
	m_wooden_crate.Load("texture/?P??/??.png");
	//?^?C??
	


	m_roadTex.Load("texture/?S?~??R.png");

	//?}?b?v?????
	InitConnections();

	//?}?b?v?I?u?W?F?N?g?z?u
	InitObjects();
}

//???t???[???X?V
void Map::Update()
{

}

//===================================================================
//????`??
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
//?}?b?v?`??
//===================================================================
void Map::Draw(int mapID, const Math::Vector2& cameraPos)
{
	//?n??`????}?b?v
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

	//?}?b?vID?O?`?X?X?X??z?u???X?g??p??
	m_mapObjects.resize(1000);

	//?e?}?b?v??I?u?W?F?N?g??p??
	
	//============================================
	//?P??
	//============================================
	
	//?}?b?v?O
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
	//?Q??
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
//?}?b?v?I?u?W?F?N?g?`??
//=======================================================
void Map::DrawObjects(int MapID, const Math::Vector2& cameraPos)
{
	//?}?b?vID?????O???`?œ®???
	if (MapID < 0 || MapID >= (int)m_mapObjects.size())
	{
		return;
	}
	//?????}?b?v??o?^????????I?u?W?F?N?g??`??
	for (const auto& obj : m_mapObjects[MapID])
	{
		if (obj.tex == nullptr)continue;
		SHADER.m_spriteShader.DrawTex(obj.tex, (int)(obj.pos.x - cameraPos.x), (int)(obj.pos.y - cameraPos.y), obj.width, obj.height);
	}
}

//===================================================
//?}?b?v???
//===================================================
void Map::InitConnections()
{
	m_mapConnections =
	{
		//?c???????????????????????????????????????????????
		//?O???P
		{ 0,1,300,400,-550,-450,Math::Vector2(0,500) },

		//?????s?????P???O??????
		
		//?????????????????????????????????????????????????
		//?P???Q
		{ 1,2,850,900,-50,50,Math::Vector2(0,500) },
		//?Q???P
		{ 2,1,-900,-850,-50,50,Math::Vector2(500,-450) },
		//?Q???R
		{ 2,3,850,900,-50,50,Math::Vector2(0,500) },
		//?R???Q
		{ 3,2,-900,-850,-50,50,Math::Vector2(500,-450) },
		//?R???S
		{ 3,4,850,900,-50,50,Math::Vector2(0,500) },
		//?S???R
		{ 4,3,-900,-850,-50,50,Math::Vector2(500,-450) },
		//?S???T
		{ 4,5,850,900,-50,50,Math::Vector2(0,500) },
		//?T???S
		{ 5,4,-900,-850,-50,50,Math::Vector2(500,-450) },
		//?T???U
		{ 5,6,850,900,-50,50,Math::Vector2(0,500) },
		//?U???T
		{ 6,5,-900,-850,-50,50,Math::Vector2(500,-450) },
		//?U???V
		{ 6,7,850,900,-50,50,Math::Vector2(0,500) },
		//?V???U
		{ 7,6,-900,-850,-50,50,Math::Vector2(500,-450) },
		//?V???W
		{ 7,8,850,900,-50,50,Math::Vector2(0,500) },
		//?W???V
		{ 8,7,-900,-850,-50,50,Math::Vector2(500,-450) },

		//?c???????????????????????????????????????????????
		//?W???X
		{ 8,9,300,400,-550,-450,Math::Vector2(0,500) },
		//?X???W
		{ 9,8,450,550,500,600,Math::Vector2(500,-450) },

		//?????????????????????????????????????????????????
		//?X???P?O
		{ 9,10,850,900,-50,50,Math::Vector2(0,500) },
		//?P?O???X
		{ 10,9,-900,-850,-50,50,Math::Vector2(500,-450) },
		//?P?O???P?P
		{ 10,11,850,900,-50,50,Math::Vector2(0,500) },
		//?P?P???P?O
		{ 11,10,-900,-850,-50,50,Math::Vector2(500,-450) },
		//?P?P???P?Q
		{ 11,12,850,900,-50,50,Math::Vector2(0,500) },
		//?P?Q???P?P
		{ 12,11,-900,-850,-50,50,Math::Vector2(500,-450) },

	};
}

void Map::Release()
{

}