#include <SFML/Graphics.hpp>

#include <random>
#include <memory>
#include <iostream>

#include "screen/GameScreen.h"
#include "screen/GameOverScreen.h"
#include "Game.h"

using namespace sfSnake;

GameScreen::GameScreen() : snake_()
{
}

void GameScreen::handleInput(sf::RenderWindow &window)
{
    snake_.handleInput();
}

void GameScreen::update(sf::Time delta)
{
    if (fruit_.size() == 0)
        generateFruit();

    snake_.update(delta);
    snake_.checkFruitCollisions(fruit_);

    if (snake_.hitSelf())
    {
        Game::Screen_ = std::make_shared<GameOverScreen>(snake_.getScore());
    }
}

void GameScreen::render(sf::RenderWindow &window)
{
    grid_.render(window);
    snake_.render(window);
    for (auto fruit : fruit_)
        fruit.render(window);
}

void GameScreen::generateFruit()
{
    static std::default_random_engine engine(time(NULL));

    static std::uniform_int_distribution<int> xDistribution(10, Game::VideoMode_.width - 10);
    static std::uniform_int_distribution<int> yDistribution(10, Game::VideoMode_.height - 10);

    fruit_.push_back(Fruit(sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}