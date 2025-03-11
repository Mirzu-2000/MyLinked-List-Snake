#include "Player/BodyPart.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelView.h"
#include "Level/LevelModel.h"
#include "Global/Config.h"


namespace Player
{
	using namespace Global;
	using namespace Level;
	using namespace UI::UIElement;

	BodyPart::BodyPart()
	{
		grid_position = sf::Vector2i(0, 0);
		createBodyPartImage();
	}
	
	BodyPart::~BodyPart()
	{
		destroy();
	}
	
	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		grid_position = pos;
		direction = dir;

		initializeBodyPartImage();

	}
	void BodyPart::updatePosition()
	{
		bodypart_image->setPosition(getBodyPartScreenPosition());
		bodypart_image->setRotation(getRotationAngle());
		bodypart_image->update();
	}

	void BodyPart::render()
	{
		bodypart_image->render();
    }

	void BodyPart::setDirection(Direction direction)
	{
		this->direction = direction;
	}

	Direction BodyPart::getDirection()
	{
		return direction;
	}

	sf::Vector2i BodyPart::getNextPosition()
	{
		switch (direction)
		{
		case Player::Direction::UP:
			return getNextPositionUp();
		case Player::Direction::DOWN:
			return getNextPositionDown();
		case Player::Direction::LEFT:
			return getNextPositionLeft();
		case Player::Direction::RIGHT:
			return getNextPositionRight();
		default:
			return grid_position;
		}
	}

	sf::Vector2i BodyPart::getPosition()
	{
		return grid_position;
	}

	void BodyPart::setPosition(sf::Vector2i position)
	{
		grid_position = position;
	}

	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new ImageView();
	}

	void BodyPart::initializeBodyPartImage()
	{
		bodypart_image->initialize(Config::snake_body_texture_path, bodypart_width, bodypart_height, getBodyPartScreenPosition());
		bodypart_image->setOriginAtCentre();
	}

	void BodyPart::setPosition(sf::Vector2i position)
	{
		grid_position = position;
	}

	sf::Vector2f BodyPart::getBodyPartScreenPosition()
	{
		float x_screen_position = LevelView::border_offset_left + (grid_position.x * bodypart_width) + (bodypart_width / 2);
		float y_screen_position = LevelView::border_offset_top + (grid_position.y * bodypart_height) + (bodypart_height / 2);

		return sf::Vector2f(x_screen_position, y_screen_position);
	}

	float BodyPart::getRotationAngle()
	{
		switch (direction)
		{
		case Player::Direction::UP:
			return 270.f;
		case Player::Direction::DOWN:
			return 90.f;
		case Player::Direction::LEFT:
			return 180.f;
		case Player::Direction::RIGHT:
			return 0.f;
		}
	}

	sf::Vector2i BodyPart::getNextPositionUp()
	{
		return sf::Vector2i(grid_position.x, grid_position.y - 1);
	}

	sf::Vector2i BodyPart::getNextPositionDown()
	{
		return sf::Vector2i(grid_position.x, grid_position.y + 1);
	}

	sf::Vector2i BodyPart::getNextPositionLeft()
	{
		return sf::Vector2i(grid_position.x - 1, grid_position.y);
	}

	sf::Vector2i BodyPart::getNextPositionRight()
	{
		return sf::Vector2i(grid_position.x + 1, grid_position.y);
	}


	void BodyPart::destroy() { delete bodypart_image; }
	}