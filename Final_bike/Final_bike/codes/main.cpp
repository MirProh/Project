#include "../headers/main.h"

int getKeys()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//управление мотоциклом идёт с клавиатуры благодаря этим условиям
        return -1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return 0;
    return 2;
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 1000), "Final_bike");

    Bike b;

    sf::View w;
    w=window.getDefaultView();
    w.setCenter(0, 0);
    window.setView(w);

    sf::Sprite bike;//отрисовка корпуса
    sf::Texture t;
    t.loadFromFile("../Final_bike/resources/bike1.png");
    bike.setTexture(t);
    bike.setOrigin(bike.getTexture()->getSize().x / 2 , bike.getTexture()->getSize().y / 2);
    bike.setPosition(0,0);
    bike.setScale({ 2,2 });

    sf::Sprite wheel;//отрисовка колёс
    sf::Texture wheelt;
    wheelt.loadFromFile("../Final_bike/resources/Wheel.png");
    wheel.setTexture(wheelt);
    wheel.setOrigin(wheel.getTexture()->getSize().x / 2, wheel.getTexture()->getSize().y / 2);
    wheel.setPosition(0, 0);

     sf::RectangleShape line(sf::Vector2f(1800, 5));//отрисовка земли
    line.setFillColor(sf::Color::Black);
    //line.setOrigin(line.getSize().x/2, line.getSize().y/2);
    line.setPosition(-900, 40);

    /*
    sf::RectangleShape line(sf::Vector2f(400, 5));//отрисовка земли
    line.setFillColor(sf::Color::Black);
    line.setPosition(-900, 40);

    sf::RectangleShape line2(sf::Vector2f(400, 5));//отрисовка земли
    line2.setFillColor(sf::Color::Black);
    line2.setPosition(500, 40);

    sf::RectangleShape line1(sf::Vector2f(577, 5));//отрисовка земли
    line1.setFillColor(sf::Color::Black);
    line1.setPosition(-500, 40);
    line1.rotate(-30);

    sf::RectangleShape line3(sf::Vector2f(577, 5));//отрисовка земли
    line3.setFillColor(sf::Color::Black);
    line3.setPosition(0, -248);
    line3.rotate(30);
    */
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        b.update(getKeys());
        bike.setPosition(b.b.pos.x, -b.b.pos.y);
        bike.setRotation(b.b.angle / M_PI * 180);
        window.clear(sf::Color::White);

        window.draw(bike);

        sf::RectangleShape springr(sf::Vector2f(b.rear.s.len(), 5));//отрисовка передней и задней рессоры в каждый момент, так как они растягиваются
        springr.setFillColor(sf::Color::Red);
        springr.setOrigin(springr.getSize().x / 2, springr.getSize().y / 2);
        springr.setPosition(b.rear.s.mid().x, -b.rear.s.mid().y);
        springr.setRotation(b.rear.s.angle());
        window.draw(springr);

        sf::RectangleShape springf(sf::Vector2f(b.front.s.len(), 5));
        springf.setFillColor(sf::Color::Red);
        springf.setOrigin(springf.getSize().x / 2, springf.getSize().y / 2);
        springf.setPosition(b.front.s.mid().x, -b.front.s.mid().y);
        springf.setRotation(b.front.s.angle());
        window.draw(springf);

        double scale = 2 * b.rear.radius / (double)wheelt.getSize().x;//отрисовка колёс, чтобы они крутились
        wheel.setScale(scale, scale);
        wheel.setPosition(b.rear.b.pos.x, -b.rear.b.pos.y);
        wheel.setRotation(b.rear.b.angle / M_PI * 180);
        window.draw(wheel);
        scale = 2 * b.front.radius / (double)wheelt.getSize().x;
        wheel.setScale(scale, scale);
        wheel.setPosition(b.front.b.pos.x, -b.front.b.pos.y);
        wheel.setRotation(b.front.b.angle / M_PI * 180);
        window.draw(wheel);
        window.draw(line);
        //window.draw(line1);
        //window.draw(line2);
        //window.draw(line3);
        window.display();
    }

    return 0;
}