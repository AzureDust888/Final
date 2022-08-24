#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
using namespace std;

using namespace sf;


float offsetX = 0, offsetY = 0;


const int H = 19;
const int W = 150;


String TileMap[H] = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                   0",
"0                                          r                                                                                                         0",
"0                                          k                                                                                                         0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
};




class PLAYER {

public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;

	PLAYER(Texture& image)
	{
		sprite.setTexture(image);
		rect = FloatRect(100, 180, 16, 16);

		dx = dy = 0.1;
		currentFrame = 0;
	}


	void update(float time)
	{

		rect.left += dx * time;
		Collision(0);


		if (!onGround) dy = dy + 0.0005 * time;
		rect.top += dy * time;
		onGround = false;
		Collision(1);


		currentFrame += time * 0.005;
		if (currentFrame > 3) currentFrame -= 3;


		/*if (dx > 0) sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame), 144, 16, 16));
		if (dx < 0) sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame) + 16, 144, -16, 16));*/


		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		dx = 0;
	}


	void Collision(int num)
	{

		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
			{
				if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'k') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r') || (TileMap[i][j] == 't'))
				{
					if (dy > 0 && num == 1)
					{
						rect.top = i * 16 - rect.height;  dy = 0;   onGround = true;
					}
					if (dy < 0 && num == 1)
					{
						rect.top = i * 16 + 16;   dy = 0;
					}
					if (dx > 0 && num == 0)
					{
						rect.left = j * 16 - rect.width;
					}
					if (dx < 0 && num == 0)
					{
						rect.left = j * 16 + 16;
					}
				}

				if (TileMap[i][j] == 'c') {
					// TileMap[i][j]=' '; 
				}
			}

	}

};



class ENEMY
{

public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;


	void set(Texture& image, int x, int y)
	{
		sprite.setTexture(image);
		sprite.setColor(Color::Red);
		rect = FloatRect(x, y, 14, 14);

		dx = 0.05;
		currentFrame = 0;
	}

	void update(float time)
	{
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	}


	void Collision()
	{

		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
				if ((TileMap[i][j] == 'P') || (TileMap[i][j] == '0'))
				{
					if (dx > 0)
					{
						rect.left = j * 16 - rect.width; dx *= -1;
					}
					else if (dx < 0)
					{
						rect.left = j * 16 + 16;  dx *= -1;
					}

				}
	}

};

class ENEMY_WALL
{

public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;


	void set(int x, int y)
	{
		sprite.setColor(Color::Red);
		rect = FloatRect(x, y, 1, 15);

		dx = 0.05;
		currentFrame = 0;
	}

	void update(float time)	
	{
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	}


	void Collision()
	{

		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
				if ((TileMap[i][j] == 'P') || (TileMap[i][j] == '0'))
				{
					if (dx > 0)
					{
						rect.left = j * 16 - rect.width; dx *= -1;
					}
					else if (dx < 0)
					{
						rect.left = j * 16 + 16;  dx *= -1;
					}

				}
	}

};

int main()
{

	RenderWindow window(VideoMode(1000, 300), "SFML works!");

	Texture tileSet;//image_2022-08-24_16-50-32.png
	tileSet.loadFromFile("Tile.jpg");

	Texture tileSet2;//image_2022-08-24_16-50-32.png
	tileSet2.loadFromFile("image_2022-08-24_16-50-32.png");

	Texture Spike;
	Spike.loadFromFile("spike.png");

	Texture Cube;
	Cube.loadFromFile("CubeJ.jpg");

	Texture GameOver;
	GameOver.loadFromFile("Name.png");

	Texture buildcube;
	buildcube.loadFromFile("Tile.jpg");


	PLAYER Mario(Cube);
	vector<ENEMY> EN(2);
	for (int i = 0, k = 30; i < EN.size(); i++)
	{
		EN[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY_WALL> Wall(1);
	/*Wall[0].set(671, 15 * 16);*/
	Texture bg;
	bg.loadFromFile("Backgroung2.jpg");
	Sprite background(bg);
	Sprite tile(tileSet);
	Sprite tile2(tileSet2);
	background.setColor(Color::Cyan);
	tile.setColor(Color::Cyan);
	tile2.setColor(Color::Cyan);

	Clock clock;
	sf::Music music;
	if (!music.openFromFile("Clubstep.ogg"))
		return -1;
	music.play();
	while (window.isOpen())
	{	
		
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 600;  // здесь регулируем скорость игры

		if (time > 20) time = 20;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (true)    Mario.dx = 0.1;

		if (Keyboard::isKeyPressed(Keyboard::Space))	if (Mario.onGround) { Mario.dy = -0.19; Mario.onGround = false; }
		if (Keyboard::isKeyPressed(Keyboard::Up))	if (Mario.onGround) { Mario.dy = -0.19; Mario.onGround = false; }



		Mario.update(time);
		for (int i = 0; i < EN.size(); i++)
		{
			EN[i].update(time);
		}
		for (int i = 0; i < Wall.size(); i++)
		{
			Wall[i].update(time);
		}
		for (int i = 0; i < Wall.size(); i++)
		{
			if (Mario.rect.intersects(Wall[i].rect))
			{
				cout << "Game Over" << endl;
				window.close();
				system("pause");
				return 1;
			}
		}
		for (int i = 0; i < EN.size(); i++)
		{
			if (Mario.rect.intersects(EN[i].rect))
			{

				cout << "Game Over" << endl;
				window.close();
				system("pause");
				return 1;
			}
		}




		if (Mario.rect.left > 200) offsetX = Mario.rect.left - 200;




		window.clear(Color::White);
		window.draw(background);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'P') { tile.setTextureRect(IntRect(0, 0, 16, 16)); 
				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.draw(tile);
				}

				if (TileMap[i][j] == 'k') {
					tile2.setTextureRect(IntRect(0, 0, 16, 16));
					tile2.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.draw(tile2);
				}

				if (TileMap[i][j] == 'c')  {tile.setTextureRect(IntRect(0, 0, 16, 16));
				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.draw(tile);
				}
				if (TileMap[i][j] == 't')  {tile.setTextureRect(IntRect(0, 0, 16, 16));
				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.draw(tile);
				}
				if (TileMap[i][j] == 'g')  {tile.setTextureRect(IntRect(0, 0, 16, 16));
				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.draw(tile);
				}
				if (TileMap[i][j] == 'G')  {tile.setTextureRect(IntRect(0, 0, 16, 16));
				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.draw(tile);
				}
				if (TileMap[i][j] == 'd')  {tile.setTextureRect(IntRect(0, 0, 16, 16));
				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.draw(tile);
				}
				if (TileMap[i][j] == 'w')  {tile.setTextureRect(IntRect(0, 0, 16, 16));
				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.draw(tile);
				}
				if (TileMap[i][j] == 'r')  {tile.setTextureRect(IntRect(0, 0, 16, 16));
				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.draw(tile);
				}
				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) continue;

			}


		
		window.draw(Mario.sprite);
		for (int i = 0; i < EN.size(); i++)
		{
			window.draw(EN[i].sprite);
		}
		for (int i = 0; i < Wall.size(); i++)
		{
			window.draw(Wall[i].sprite);
		}
		window.display();
	}

}



