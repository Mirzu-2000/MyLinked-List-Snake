#pragma once
#include<vector>
#include "Level/LevelModel.h"

namespace Level
{
	class LevelView;

	class LevelController
	{
      
	private:
		LevelModel* level_model;
		LevelView* level_view;

	public:

		LevelController();
		~LevelController();

		void intitilize();
		void update();
		void render();
		
		float getCellWidth();
		float getCellHeight();



	};


}