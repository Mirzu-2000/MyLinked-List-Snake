#include "Level/LevelService.h"
#include "Level/LevelController.h"

namespace Level 
{
	
   LevelService::LevelService()
   {
	   level_controller = nullptr;
	   createLevelController();
   }

   LevelService::~LevelService()
   {
	   destroy();
   }

   void LevelService::createLevelController()
   {
	   level_controller = new LevelController();
   }

   void LevelService::initilize()
   {
	   level_controller->intitilize();
   }

   void LevelService::render()
   {
	   level_controller->render();
   }

   void LevelService::createLevel(LevelNumber level_to_load)
   {
	   current_level = level_to_load;
   }

   void LevelService::destroy()
   {
	   delete level_controller;
   }

}