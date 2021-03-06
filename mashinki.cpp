#include <SFML/Graphics.hpp>
#include <ctime>
const int window_length = 900;
const int window_width = 1350;
const float dt = 0.01;
const float speed0 = 700;

int main()
{
    sf::RenderWindow window(sf::VideoMode(window_length, window_width), "Game");
    sf::View view = window.getView();
    int k = 0;
    float x = 0;
    float x_car = 330;
    float y_car = 730;
    float vx_car = 0;
    float y = dt*(k-1)*speed0;
   
    while (window.isOpen())
    {
        k += 1;
        sf::Event event;

        window.clear();
        window.setView(view); 
        
        y = dt*(k-1)*speed0;
        x_car += vx_car*dt;
        vx_car = 0;
        
        //рисуем дорогу//
        sf::Texture t;
        sf::Sprite s1;
        sf::Sprite s2;
        t.loadFromFile("road.jpg");
        s1.scale(0.624f, 0.624);
        s2.scale(0.624f, 0.624);
        s1.setTexture(t);
        s2.setTexture(t);
        s1.setPosition(x, y);
        s2.setPosition(x, y-1345);
        window.draw(s1);
        window.draw(s2);
        if (y-1345 > 0)
        {
            k = 0;
        }
        
        //рисуем машинку//
        sf::Image im; 
        im.loadFromFile("5.png");
        im.createMaskFromColor(sf::Color(0, 0, 0));
        sf::Texture t2;
        t2.loadFromImage(im);
        sf::Sprite s3;
        s3.setTexture(t2);
        s3.scale(0.3f, 0.3);
        s3.setPosition(x_car, y_car);
        
        window.draw(s3);

        //изменяем положение машинки кнопками право-лево//

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			vx_car = -1000;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			vx_car = 1000;
		}


        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || (event.key.code == sf::Keyboard::Escape))
            {
                window.close();
                break;
            }
        }
        window.display();
    }
    return 0;
}