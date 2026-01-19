#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "C++ 2D Game");
    window.setFramerateLimit(60);

    sf::RectangleShape player(sf::Vector2f(40.f, 40.f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(380.f, 280.f);

    float speed = 200.f;
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
            movement.y -= speed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            movement.y += speed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            movement.x -= speed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            movement.x += speed * dt;

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

        window.clear(sf::Color::Black);
        window.draw(player);
        window.display();
    }

    return 0;
}
