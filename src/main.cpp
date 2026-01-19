#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "C++ 2D Game");
    window.setFramerateLimit(60);

    sf::RectangleShape player(sf::Vector2f(40.f, 40.f));
    player.setFillColor(sf::Color::Green);
    sf::Vector2f startPos(380.f, 280.f);
    player.setPosition(startPos);

    sf::RectangleShape enemy(sf::Vector2f(60.f, 60.f));
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(100.f, 200.f);

    float playerSpeed = 200.f;
    float enemySpeed = 150.f;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            movement.y -= playerSpeed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            movement.y += playerSpeed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            movement.x -= playerSpeed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            movement.x += playerSpeed * dt;

        player.move(movement);

        sf::Vector2f pos = player.getPosition();
        sf::Vector2f size = player.getSize();
        sf::Vector2u winSize = window.getSize();

        if (pos.x < 0.f)
            pos.x = 0.f;
        if (pos.y < 0.f)
            pos.y = 0.f;
        if (pos.x + size.x > winSize.x)
            pos.x = winSize.x - size.x;
        if (pos.y + size.y > winSize.y)
            pos.y = winSize.y - size.y;

        player.setPosition(pos);

        sf::Vector2f enemyPos = enemy.getPosition();
        enemyPos.x += enemySpeed * dt;

        if (enemyPos.x < 0.f) {
            enemyPos.x = 0.f;
            enemySpeed = -enemySpeed;
        }
        if (enemyPos.x + enemy.getSize().x > winSize.x) {
            enemyPos.x = winSize.x - enemy.getSize().x;
            enemySpeed = -enemySpeed;
        }

        enemy.setPosition(enemyPos);

        if (player.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
            player.setPosition(startPos);
        }

        window.clear(sf::Color::Black);
        window.draw(player);
        window.draw(enemy);
        window.display();
    }

    return 0;
}
