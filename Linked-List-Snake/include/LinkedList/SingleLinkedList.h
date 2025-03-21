#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"

namespace LinkedList
{

	class SingleLinkedList
	{
	

	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Direction default_direction;

		Node* createNode();
		sf::Vector2i getNewNodePosition(Node* reference_node);


	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		
		void insertNodeAtTail();
		void updateNodePosition();
		void updateNodeDirection(Direction direction_to_set);
		bool processNodeCollision();
		Node* getHeadNode();
		void removeNodeAtHead();
		void removeAllNodes();
		
		std::vector<sf::Vector2i> getNodesPositionList();

		void render();



	};
}