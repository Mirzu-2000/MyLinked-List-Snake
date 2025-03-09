#pragma once
#include "Level/LevelService.h"

namespace Level
{

	struct LevelData
	{
		LevelNumber level_index;

		LevelData(LevelNumber ind)
		{
			level_index = ind;
		}

	};


}