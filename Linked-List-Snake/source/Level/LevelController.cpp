#include "Level/LevelController.h"
#include<Level/LevelModel.h>
#include<Level/LevelVeiw.h>

namespace Level
{
  LevelController::LevelController()
	{
	  level_model = new LevelModel();
	  level_view = new LevelView();
	}


  LevelController::~LevelController()
  {
	  delete level_model;
	  delete level_view;
  }

  void LevelController::intitilize()
  {
	  level_view->initialize();
	  level_model->initialize(level_view->getGridWidth(), level_view->getGridHeight());
  }

  void LevelController::update()
  {
	  level_view->update();
  }

  void LevelController::render()
  {
	  level_view->update();
  }

  float LevelController::getCellWidth()
  {
	  return level_model->getCellWidth();
  }

  float LevelController::getCellHeight()
  {
	  return level_model->getCellHeight();
  }



}