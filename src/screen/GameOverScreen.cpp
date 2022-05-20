#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "Game.h"
#include "screen/GameScreen.h"
#include "screen/GameOverScreen.h"

using namespace sfSnake;

GameOverScreen::GameOverScreen(std::size_t score) : score_(score)
{
    font_.loadFromFile("assets/fonts/SourceHanSansSC-Bold.otf");
    text_.setFont(font_);
    text_.setString("Your score: " + std::to_string(score) + "!" + "\n\nPress [SPACE] to retry" + "\n\nPress [ESC] to quit");
    text_.setFillColor(sf::Color::Red);
    text_.setCharacterSize(Game::VideoMode_.width / 30);

    sf::FloatRect textBounds = text_.getLocalBounds();
    text_.setOrigin(textBounds.left + textBounds.width / 2,
                    textBounds.top + textBounds.height / 2);
    text_.setPosition(Game::VideoMode_.width / 2, Game::VideoMode_.height / 2);
}

void GameOverScreen::handleInput(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        Game::Screen_ = std::make_shared<GameScreen>();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
}

void GameOverScreen::update(sf::Time delta)
{
}

void GameOverScreen::render(sf::RenderWindow &window)
{
    window.draw(text_);
}