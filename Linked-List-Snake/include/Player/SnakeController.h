#pragma once
#include "SFML/System/Vector2.hpp"
#include "Direction.h"
#include "LinkedList/Node.h"
#include "LinkedList/SingleLinkedList.h"

namespace Player
{
    using namespace LinkedList;

    enum class SnakeState
    {
        ALIVE,
        DEAD,
    };

    enum class InoutState
    {
        WAITING,
        PROCESSING
    };

    class SnakeController
    {
    private:
        const int initial_snake_length = 10;
        const float movement_frame_duration = 0.1f;
        const float restart_duration = 3.f;

        const sf::Vector2i default_position = sf::Vector2i(25, 13);
        const LinkedList::Direction default_direction = LinkedList::Direction::RIGHT;

        SnakeState current_snake_state;
        LinkedList::Direction current_snake_direction;
        LinkedList::SingleLinkedList* single_linked_list;
        InoutState current_input_state;

        float elapsed_duration;
        float restart_counter;

        void createLinkedList();

        void processPlayerInput();
        void updateSnakeDirection();
        void moveSnake();
        void delayedUpdate();
        void processSnakeCollision();
        void handleRestart();


        void reset();
        void destroy();

    public:
        SnakeController();
        ~SnakeController();

        void initialize();
        void update();
        void render();

        void spawnSnake();
        void respawnSnake();
        SnakeState getSnakeState();
        void setSnakeState(SnakeState state);
  
    };
}