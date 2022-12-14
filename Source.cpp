#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

using namespace sf;


float offsetX = 0, offsetY = 0;


const int H = 19;
const int W = 384;

String TileMap[H] = {
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                                                                                                                                                                                                                                                             0",
"0                                                                                                                                                                                                                                                                                                                                                                                             0",
"0                                                                                                                                                                                                                                                                                                                                                                                             0",
"0                                                                                                                                                                                                                                                                                                                                                                                             0",
"0                                                                                                                                                                                                                                                                                                                                                                                             0",
"0                                                                                                                                                                                                                                                                                                                                                                                             0",
"0                                                                                                                                      1                                                                                                                                                                                                                                                      0",
"0                                                                                                                                      c                                                                                                                                                                                                                                                      0",
"0                                                                                                                                  c                                                                                     1                                              kc                                                                                         1                          0",
"0                                                                                                                              c                cc       1111        cc       1111                                       c                                          k   k  cc                                                                                      c                          0",
"0                                                                                                                          c                   1111      cccc       1111      cccc      1                            c                                          k   k   k     cc                                                                               c                              0",
"0                                                                                                                      c               rrrrrrrrrrrrrrr          rrrrrrrrrrr          rrrr1         1             c                                          k   k   k   k        cc                                                                        c     c                            0",
"0                                                                  r                                               c                     kkkkkkkkkkkkrrrrrrrrrrrrkkkkkkkkkrrrrrrrrrrrrkkkrrrr  ccccc      1  c                                          k   k   k   k   k           cc                                cc                               c           c                          0",
"0                                                              r   k                         11       rrrrrrrrrr                         kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk        ccccccc                                         k   k   k   k   k   k              cc                 cc      cc                               c                 c                        0",
"0                              1      11      1        11rrr   k   k11                  1rrrrrrrrrr   kkkkkkkkkk                         kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk                             r111  1111            1k   k   k   k   k   k   k                 rr1        11r     rrr          rrr11            1cccc                       c1                     0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP ",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP ",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP ",
};



class END_GAME
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
		rect = FloatRect(30, 240, 16, 16);
		sprite.setOrigin(0, 0);
		dx = dy = 0.1;
		currentFrame = 0;
	}
	void update(float time)
	{

		rect.left += dx * time;
		Collision(0);


		if (!onGround) dy = dy + 0.000485 * time;
		rect.top += dy * time;
		onGround = false;
		Collision(1);

		currentFrame += time * 0.005;
		if (currentFrame > 3) currentFrame -= 3;
		sprite.setRotation(0);
		/*sprite.setOrigin(8.5, 0);*/
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
		dx = 0;
	}

	void update2(float time)
	{

		rect.left += dx * time;
		Collision(0);


		if (!onGround) dy = dy + 0.000485 * time;
		rect.top += dy * time;
		onGround = false;
		Collision(1);


		currentFrame += time * 0.005;
		if (currentFrame > 3) currentFrame -= 3;
		if (!onGround) { sprite.setOrigin(8.5, 8.5); sprite.rotate(3); }
		else { sprite.setOrigin(0, 0); sprite.rotate(0); }
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
		/*auto tmp = sprite.getOrigin();
		sprite.setOrigin(tmp);*/

		dx = 0;
	}
	void Collision(int num)
	{

		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
			{
				if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'k') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r') || (TileMap[i][j] == 't') || (TileMap[i][j] == 'c'))
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
		rect = FloatRect(x, y, 7, 7);

		dx = 0.05;
		currentFrame = 0;
	}

	void update(float time)
	{
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

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


};

class ENEMY_SP
{

public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;


	void set(Texture& image, int x, int y)
	{
		sprite.setTexture(image);
		rect = FloatRect(x, y, 16, 8);

		dx = 0.05;
		currentFrame = 0;
	}

	void update(float time)
	{
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	}


};

class ENEMY_WALL8
{

public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;


	void set(int x, int y)
	{
		sprite.setColor(Color::Red);
		rect = FloatRect(x, y, 1, 7);

		dx = 0.05;
		currentFrame = 0;
	}

	void update(float time)
	{
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	}

};

class Jump_boost
{

public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;


	void set(Texture& image, int x, int y)
	{

		sprite.setTexture(image);
		rect = FloatRect(x, y, 16, 8);

		dx = 0.05;
		currentFrame = 0;
	}

	void update(float time)
	{
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	}
};

class Portal
{

public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;


	void set(Texture& image, int x, int y)
	{

		sprite.setTexture(image);
		rect = FloatRect(x, y, 16, 16 * 16);

		dx = 0.05;
		currentFrame = 0;
	}

	void update(float time)
	{
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	}
};

int main()
{
	sf::Music music;
	if (!music.openFromFile("Clubstep.ogg"))
		return -1;
	music.play();


	RenderWindow window(VideoMode(1000, 300), "Geometry Dash");

	Texture tileSet;
	tileSet.loadFromFile("Tile.jpg");

	Texture tileSet2;
	tileSet2.loadFromFile("Tile2.jpg");

	Texture tileSet3;
	tileSet3.loadFromFile("Half-Tile.png");

	Texture Spike;
	Spike.loadFromFile("spike.png");

	Texture Jump;
	Jump.loadFromFile("jump.png");

	Texture Cube;
	Cube.loadFromFile("CubeJ.png");

	Texture portal;
	portal.loadFromFile("Portal.png");
	Portal P;
	P.set(portal, 16 * 381, 1);

	Texture GameOver;
	GameOver.loadFromFile("GameOVER.png");
	Sprite gover;
	gover.setTexture(GameOver);

	Texture buildcube;
	buildcube.loadFromFile("Tile.jpg");

	Texture Small_spike;
	Small_spike.loadFromFile("Small_SP.png");

	Texture bg;
	bg.loadFromFile("Backgroung2.jpg");
	Sprite background(bg);
	background.setColor(Color::Cyan);

	Texture ENDING;
	ENDING.loadFromFile("Over-removebg-preview.png");
	Sprite ending;
	ending.setTexture(ENDING);

	PLAYER Mario(Cube);

	vector<Jump_boost> J1(1);
	for (int i = 0, k = 67; i < J1.size(); i++)
	{
		J1[i].set(Jump, k * 16, 12.5 * 16);
		k--;
	}
	vector<ENEMY> EN(1);
	for (int i = 0, k = 30; i < EN.size(); i++)
	{
		EN[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY> EN1(2);
	for (int i = 0, k = 39; i < EN1.size(); i++)
	{
		EN1[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY> EN2(1);
	for (int i = 0, k = 46; i < EN2.size(); i++)
	{
		EN2[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY> EN3(2);
	for (int i = 0, k = 56; i < EN3.size(); i++)
	{
		EN3[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY> EN4(2);
	for (int i = 0, k = 69; i < EN4.size(); i++)
	{
		EN4[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY_SP> EN5(3);
	for (int i = 0, k = 62; i < EN5.size(); i++)
	{
		EN5[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY_SP> EN6(3);
	for (int i = 0, k = 66; i < EN6.size(); i++)
	{
		EN6[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY> EN7(1);
	for (int i = 0, k = 88; i < EN7.size(); i++)
	{
		EN7[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY> EN8(2);
	for (int i = 0, k = 94; i < EN8.size(); i++)
	{
		EN8[i].set(Spike, k * 16, 14 * 16);
		k--;
	}
	vector<ENEMY_SP> EN9(3);
	for (int i = 0, k = 101; i < EN9.size(); i++)
	{
		EN9[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY_SP> EN10(25);
	for (int i = 0, k = 136; i < EN10.size(); i++)
	{
		EN10[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY> EN11(1);
	for (int i = 0, k = 135; i < EN11.size(); i++)
	{
		EN11[i].set(Spike, k * 16, 7 * 16);
		k--;
	}
	vector<ENEMY> EN12(4);
	for (int i = 0, k = 146; i < EN12.size(); i++)
	{
		EN12[i].set(Spike, k * 16, 11 * 16);
		k--;
	}
	vector<ENEMY> EN13(4);
	for (int i = 0, k = 156; i < EN13.size(); i++)
	{
		EN13[i].set(Spike, k * 16, 10 * 16);
		k--;
	}
	vector<ENEMY> EN14(4);
	for (int i = 0, k = 167; i < EN14.size(); i++)
	{
		EN14[i].set(Spike, k * 16, 11 * 16);
		k--;
	}
	vector<ENEMY> EN15(4);
	for (int i = 0, k = 177; i < EN15.size(); i++)
	{
		EN15[i].set(Spike, k * 16, 10 * 16);
		k--;
	}
	vector<ENEMY> EN16(1);
	for (int i = 0, k = 184; i < EN16.size(); i++)
	{
		EN16[i].set(Spike, k * 16, 11 * 16);
		k--;
	}
	vector<ENEMY> EN17(1);
	for (int i = 0, k = 185; i < EN17.size(); i++)
	{
		EN17[i].set(Spike, k * 16, 12 * 16);
		k--;
	}
	vector<ENEMY> EN18(1);
	for (int i = 0, k = 195; i < EN18.size(); i++)
	{
		EN18[i].set(Spike, k * 16, 12 * 16);
		k--;
	}
	vector<ENEMY> EN19(1);
	for (int i = 0, k = 202; i < EN19.size(); i++)
	{
		EN19[i].set(Spike, k * 16, 13 * 16);
		k--;
	}
	vector<ENEMY> EN20(1);
	for (int i = 0, k = 217; i < EN20.size(); i++)
	{
		EN20[i].set(Spike, k * 16, 9 * 16);
		k--;
	}
	vector<ENEMY_SP> EN21(29);
	for (int i = 0, k = 216; i < EN21.size(); i++)
	{
		EN21[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY> EN22(3);
	for (int i = 0, k = 220; i < EN22.size(); i++)
	{
		EN22[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<Jump_boost> J2(1);
	for (int i = 0, k = 223; i < J2.size(); i++)
	{
		J2[i].set(Jump, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY> EN23(4);
	for (int i = 0, k = 227; i < EN23.size(); i++)
	{
		EN23[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY> EN24(1);
	for (int i = 0, k = 239; i < EN24.size(); i++)
	{
		EN24[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY_SP> EN25(3);
	for (int i = 0, k = 243; i < EN25.size(); i++)
	{
		EN25[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY_SP> EN26(3);
	for (int i = 0, k = 247; i < EN26.size(); i++)
	{
		EN26[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY_SP> EN27(3);
	for (int i = 0, k = 251; i < EN27.size(); i++)
	{
		EN27[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY_SP> EN28(3);
	for (int i = 0, k = 255; i < EN28.size(); i++)
	{
		EN28[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY_SP> EN29(3);
	for (int i = 0, k = 259; i < EN29.size(); i++)
	{
		EN29[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY_SP> EN30(3);
	for (int i = 0, k = 263; i < EN30.size(); i++)
	{
		EN30[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY_SP> EN31(17);
	for (int i = 0, k = 281; i < EN31.size(); i++)
	{
		EN31[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY> EN32(2);
	for (int i = 0, k = 294; i < EN32.size(); i++)
	{
		EN32[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY_SP> EN33(5);
	for (int i = 0, k = 300; i < EN33.size(); i++)
	{
		EN33[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY_SP> EN34(10);
	for (int i = 0, k = 313; i < EN34.size(); i++)
	{
		EN34[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY> EN35(2);
	for (int i = 0, k = 318; i < EN35.size(); i++)
	{
		EN35[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY> EN37(1);
	for (int i = 0, k = 331; i < EN37.size(); i++)
	{
		EN37[i].set(Spike, k * 16, 15 * 16);
		k--;
	}
	vector<ENEMY_SP> EN36(27);
	for (int i = 0, k = 358; i < EN36.size(); i++)
	{
		EN36[i].set(Small_spike, k * 16, 15.5 * 16);
		k--;
	}
	vector<ENEMY> EN38(1);
	for (int i = 0, k = 355; i < EN38.size(); i++)
	{
		EN38[i].set(Spike, k * 16, 9 * 16);
		k--;
	}
	vector<ENEMY> EN39(1);
	for (int i = 0, k = 360; i < EN39.size(); i++)
	{
		EN39[i].set(Spike, k * 16, 15 * 16);
		k--;
	}

	vector<ENEMY_WALL> Wall(1);
	//Wall[0].set(671, 15 * 16);

	Sprite tile(tileSet);
	tile.setColor(Color::Cyan);
	Sprite tile2(tileSet2);
	tile2.setColor(Color::Cyan);
	Sprite tile3(tileSet3);
	tile3.setColor(Color::Cyan);
	Clock clock;
	Clock cl;
	while (window.isOpen())
	{
		/*cout << cl.getElapsedTime().asSeconds() << endl;*/

		if (cl.getElapsedTime().asSeconds() <= 12 && cl.getElapsedTime().asSeconds() >= 11.674)
		{
			background.setColor(Color::Magenta);
			tile.setColor(Color::Magenta);
			tile2.setColor(Color::Magenta);
			tile3.setColor(Color::Magenta);
		}
		if (Mario.rect.intersects(J2[0].rect))
		{
			background.setColor(Color(125, 168, 50));
			tile.setColor(Color(125, 168, 50));
			tile2.setColor(Color(125, 168, 50));
			tile3.setColor(Color(125, 168, 50));
		}
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 550; //Change of game speed

		if (time > 20) time = 20;


		if (true) Mario.dx = 0.1;
		if (Keyboard::isKeyPressed(Keyboard::Space))	if (Mario.onGround) { Mario.dy = -0.185; Mario.onGround = false; }
		if (Keyboard::isKeyPressed(Keyboard::Up))	if (Mario.onGround) { Mario.dy = -0.185; Mario.onGround = false; }


		P.update(time);
		if (Mario.onGround)
		{
			Mario.update(time);
		}
		else
		{
			Mario.update2(time);
		}
		for (int i = 0; i < J1.size(); i++)
		{
			J1[i].update(time);
		}
		for (int i = 0; i < EN.size(); i++)
		{
			EN[i].update(time);
		}
		for (int i = 0; i < EN1.size(); i++)
		{
			EN1[i].update(time);
		}
		for (int i = 0; i < EN2.size(); i++)
		{
			EN2[i].update(time);
		}
		for (int i = 0; i < EN3.size(); i++)
		{
			EN3[i].update(time);
		}
		for (int i = 0; i < EN4.size(); i++)
		{
			EN4[i].update(time);
		}
		for (int i = 0; i < EN5.size(); i++)
		{
			EN5[i].update(time);
		}
		for (int i = 0; i < EN6.size(); i++)
		{
			EN6[i].update(time);
		}
		for (int i = 0; i < EN7.size(); i++)
		{
			EN7[i].update(time);
		}
		for (int i = 0; i < EN8.size(); i++)
		{
			EN8[i].update(time);
		}
		for (int i = 0; i < EN9.size(); i++)
		{
			EN9[i].update(time);
		}
		for (int i = 0; i < EN10.size(); i++)
		{
			EN10[i].update(time);
		}
		for (int i = 0; i < EN11.size(); i++)
		{
			EN11[i].update(time);
		}
		for (int i = 0; i < EN12.size(); i++)
		{
			EN12[i].update(time);
		}
		for (int i = 0; i < EN13.size(); i++)
		{
			EN13[i].update(time);
		}
		for (int i = 0; i < EN14.size(); i++)
		{
			EN14[i].update(time);
		}
		for (int i = 0; i < EN15.size(); i++)
		{
			EN15[i].update(time);
		}
		for (int i = 0; i < EN16.size(); i++)
		{
			EN16[i].update(time);
		}
		for (int i = 0; i < EN17.size(); i++)
		{
			EN17[i].update(time);
		}
		for (int i = 0; i < EN18.size(); i++)
		{
			EN18[i].update(time);
		}
		for (int i = 0; i < EN19.size(); i++)
		{
			EN19[i].update(time);
		}
		for (int i = 0; i < EN20.size(); i++)
		{
			EN20[i].update(time);
		}
		for (int i = 0; i < EN21.size(); i++)
		{
			EN21[i].update(time);
		}
		for (int i = 0; i < EN22.size(); i++)
		{
			EN22[i].update(time);
		}
		for (int i = 0; i < J2.size(); i++)
		{
			J2[i].update(time);
		}
		for (int i = 0; i < EN23.size(); i++)
		{
			EN23[i].update(time);
		}
		for (int i = 0; i < EN24.size(); i++)
		{
			EN24[i].update(time);
		}
		for (int i = 0; i < EN25.size(); i++)
		{
			EN25[i].update(time);
		}
		for (int i = 0; i < EN26.size(); i++)
		{
			EN26[i].update(time);
		}
		for (int i = 0; i < EN27.size(); i++)
		{
			EN27[i].update(time);
		}
		for (int i = 0; i < EN28.size(); i++)
		{
			EN28[i].update(time);
		}
		for (int i = 0; i < EN29.size(); i++)
		{
			EN29[i].update(time);
		}
		for (int i = 0; i < EN30.size(); i++)
		{
			EN30[i].update(time);
		}
		for (int i = 0; i < EN31.size(); i++)
		{
			EN31[i].update(time);
		}
		for (int i = 0; i < EN32.size(); i++)
		{
			EN32[i].update(time);
		}
		for (int i = 0; i < EN33.size(); i++)
		{
			EN33[i].update(time);
		}
		for (int i = 0; i < EN34.size(); i++)
		{
			EN34[i].update(time);
		}
		for (int i = 0; i < EN35.size(); i++)
		{
			EN35[i].update(time);
		}
		for (int i = 0; i < EN36.size(); i++)
		{
			EN36[i].update(time);
		}
		for (int i = 0; i < EN37.size(); i++)
		{
			EN37[i].update(time);
		}
		for (int i = 0; i < EN38.size(); i++)
		{
			EN38[i].update(time);
		}
		for (int i = 0; i < EN39.size(); i++)
		{
			EN39[i].update(time);
		}
		for (int i = 0; i < Wall.size(); i++)
		{
			Wall[i].update(time);
		}

		if (Mario.rect.intersects(P.rect))
		{
			window.clear(Color::White);
			background.setColor(Color(125, 168, 50));
			window.draw(background);
			ending.setPosition(200, 125);
			window.draw(ending);
			window.display();
			music.pause();
			goto breakpoint;
		}
		for (int i = 0; i < J1.size(); i++)
		{
			if (Mario.rect.intersects(J1[i].rect) || Mario.rect.intersects(J2[i].rect))
			{
				Mario.dy = -0.27;
			}
		}
		for (int i = 0; i < Wall.size(); i++)   //Wall
		{
			if (Mario.rect.intersects(Wall[i].rect))
			{
				window.clear(Color::White);
				background.setColor(Color::Red);
				window.draw(background);
				gover.setPosition(100, 15);
				window.draw(gover);
				window.display();
				music.pause();
				goto breakpoint;
			}
		}
		for (int i = 0; i < EN.size(); i++)   //1sp
		{
			if (Mario.rect.intersects(EN[i].rect) || Mario.rect.intersects(EN2[i].rect) || Mario.rect.intersects(EN7[i].rect) || Mario.rect.intersects(EN11[i].rect) || Mario.rect.intersects(EN16[i].rect) || Mario.rect.intersects(EN17[i].rect) || Mario.rect.intersects(EN18[i].rect) || Mario.rect.intersects(EN19[i].rect) || Mario.rect.intersects(EN20[i].rect) || Mario.rect.intersects(EN24[i].rect))
			{
				window.clear(Color::White);
				background.setColor(Color::Red);
				window.draw(background);
				gover.setPosition(100, 15);
				window.draw(gover);
				window.display();
				music.pause();
				goto breakpoint;;
			}
		}
		for (int i = 0; i < EN1.size(); i++)   //2sp
		{
			if (Mario.rect.intersects(EN1[i].rect) || Mario.rect.intersects(EN3[i].rect) || Mario.rect.intersects(EN4[i].rect) || Mario.rect.intersects(EN8[i].rect) || Mario.rect.intersects(EN32[i].rect))
			{
				window.clear(Color::White);
				background.setColor(Color::Red);
				window.draw(background);
				gover.setPosition(100, 15);
				window.draw(gover);
				window.display();
				music.pause();
				goto breakpoint;
			}
		}
		for (int i = 0; i < EN5.size(); i++)   //3sp
		{
			if (Mario.rect.intersects(EN5[i].rect) || Mario.rect.intersects(EN6[i].rect) || Mario.rect.intersects(EN9[i].rect) || Mario.rect.intersects(EN22[i].rect) || Mario.rect.intersects(EN25[i].rect) || Mario.rect.intersects(EN26[i].rect) || Mario.rect.intersects(EN27[i].rect) || Mario.rect.intersects(EN28[i].rect) || Mario.rect.intersects(EN29[i].rect) || Mario.rect.intersects(EN30[i].rect))
			{
				window.clear(Color::White);
				background.setColor(Color::Red);
				window.draw(background);
				gover.setPosition(100, 15);
				window.draw(gover);
				window.display();
				music.pause();
				goto breakpoint;
			}
		}
		for (int i = 0; i < EN12.size(); i++)   //4sp
		{
			if (Mario.rect.intersects(EN12[i].rect) || Mario.rect.intersects(EN13[i].rect) || Mario.rect.intersects(EN14[i].rect) || Mario.rect.intersects(EN15[i].rect) || Mario.rect.intersects(EN23[i].rect))
			{
				window.clear(Color::White);
				background.setColor(Color::Red);
				window.draw(background);
				gover.setPosition(100, 15);
				window.draw(gover);
				window.display();
				music.pause();
				goto breakpoint;
			}
		}
		for (int i = 0; i < EN10.size(); i++)   //25sp
		{
			if (Mario.rect.intersects(EN10[i].rect))
			{
				window.clear(Color::White);
				background.setColor(Color::Red);
				window.draw(background);
				gover.setPosition(100, 15);
				window.draw(gover);
				window.display();
				music.pause();
				goto breakpoint;
			}
		}
		for (int i = 0; i < EN21.size(); i++)   //29sp
		{
			if (Mario.rect.intersects(EN21[i].rect))
			{
				window.clear(Color::White);
				background.setColor(Color::Red);
				window.draw(background);
				gover.setPosition(100, 15);
				window.draw(gover);
				window.display();
				music.pause();
				goto breakpoint;
			}
		}
		for (int i = 0; i < EN31.size(); i++)   //17sp
		{
			if (Mario.rect.intersects(EN31[i].rect))
			{
				window.clear(Color::White);
				background.setColor(Color::Red);
				window.draw(background);
				gover.setPosition(100, 15);
				window.draw(gover);
				window.display();
				music.pause();
				goto breakpoint;
			}
		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (1 == 0)
		{
		breakpoint:system("pause");
			break;
		}

		if (Mario.rect.left > 200) offsetX = Mario.rect.left - 200;

		window.clear(Color::White);
		window.draw(background);

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'P') {
					tile.setTextureRect(IntRect(0, 0, 16, 16));
					tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.draw(tile);
				}

				if (TileMap[i][j] == 'k') {
					tile2.setTextureRect(IntRect(0, 0, 16, 16));
					tile2.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.draw(tile2);
				}

				if (TileMap[i][j] == 'c') {
					tile3.setTextureRect(IntRect(0, 0, 16, 8));
					tile3.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.draw(tile3);
				}
				if (TileMap[i][j] == 't') {
					tile.setTextureRect(IntRect(0, 0, 16, 16));
					tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.draw(tile);
				}
				if (TileMap[i][j] == 'g') {
					tile.setTextureRect(IntRect(0, 0, 16, 16));
					tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.draw(tile);
				}
				if (TileMap[i][j] == 'G') {
					tile.setTextureRect(IntRect(0, 0, 16, 16));
					tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.draw(tile);
				}
				if (TileMap[i][j] == 'd') {
					tile.setTextureRect(IntRect(0, 0, 16, 16));
					tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.draw(tile);
				}
				if (TileMap[i][j] == 'w') {
					tile.setTextureRect(IntRect(0, 0, 16, 16));
					tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.draw(tile);
				}
				if (TileMap[i][j] == 'r') {
					tile.setTextureRect(IntRect(0, 0, 16, 16));
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
		for (int i = 0; i < EN1.size(); i++)
		{
			window.draw(EN1[i].sprite);
		}
		for (int i = 0; i < EN2.size(); i++)
		{
			window.draw(EN2[i].sprite);
		}
		for (int i = 0; i < EN3.size(); i++)
		{
			window.draw(EN3[i].sprite);
		}
		for (int i = 0; i < EN4.size(); i++)
		{
			window.draw(EN4[i].sprite);
		}
		for (int i = 0; i < EN5.size(); i++)
		{
			window.draw(EN5[i].sprite);
		}
		for (int i = 0; i < EN6.size(); i++)
		{
			window.draw(EN6[i].sprite);
		}
		for (int i = 0; i < EN7.size(); i++)
		{
			window.draw(EN7[i].sprite);
		}
		for (int i = 0; i < EN8.size(); i++)
		{
			window.draw(EN8[i].sprite);
		}
		for (int i = 0; i < EN9.size(); i++)
		{
			window.draw(EN9[i].sprite);
		}
		for (int i = 0; i < EN10.size(); i++)
		{
			window.draw(EN10[i].sprite);
		}
		for (int i = 0; i < EN11.size(); i++)
		{
			window.draw(EN11[i].sprite);
		}
		for (int i = 0; i < EN12.size(); i++)
		{
			window.draw(EN12[i].sprite);
		}
		for (int i = 0; i < EN13.size(); i++)
		{
			window.draw(EN13[i].sprite);
		}
		for (int i = 0; i < EN14.size(); i++)
		{
			window.draw(EN14[i].sprite);
		}
		for (int i = 0; i < EN15.size(); i++)
		{
			window.draw(EN15[i].sprite);
		}
		for (int i = 0; i < EN16.size(); i++)
		{
			window.draw(EN16[i].sprite);
		}
		for (int i = 0; i < EN17.size(); i++)
		{
			window.draw(EN17[i].sprite);
		}
		for (int i = 0; i < EN18.size(); i++)
		{
			window.draw(EN18[i].sprite);
		}
		for (int i = 0; i < EN19.size(); i++)
		{
			window.draw(EN19[i].sprite);
		}
		for (int i = 0; i < EN20.size(); i++)
		{
			window.draw(EN20[i].sprite);
		}
		for (int i = 0; i < EN21.size(); i++)
		{
			window.draw(EN21[i].sprite);
		}
		for (int i = 0; i < EN22.size(); i++)
		{
			window.draw(EN22[i].sprite);
		}
		for (int i = 0; i < EN23.size(); i++)
		{
			window.draw(EN23[i].sprite);
		}
		for (int i = 0; i < EN24.size(); i++)
		{
			window.draw(EN24[i].sprite);
		}
		for (int i = 0; i < EN25.size(); i++)
		{
			window.draw(EN25[i].sprite);
		}
		for (int i = 0; i < EN26.size(); i++)
		{
			window.draw(EN26[i].sprite);
		}
		for (int i = 0; i < EN27.size(); i++)
		{
			window.draw(EN27[i].sprite);
		}
		for (int i = 0; i < EN28.size(); i++)
		{
			window.draw(EN28[i].sprite);
		}
		for (int i = 0; i < EN29.size(); i++)
		{
			window.draw(EN29[i].sprite);
		}
		for (int i = 0; i < EN30.size(); i++)
		{
			window.draw(EN30[i].sprite);
		}
		for (int i = 0; i < EN31.size(); i++)
		{
			window.draw(EN31[i].sprite);
		}
		for (int i = 0; i < EN32.size(); i++)
		{
			window.draw(EN32[i].sprite);
		}
		for (int i = 0; i < EN33.size(); i++)
		{
			window.draw(EN33[i].sprite);
		}
		for (int i = 0; i < EN34.size(); i++)
		{
			window.draw(EN34[i].sprite);
		}
		for (int i = 0; i < EN35.size(); i++)
		{
			window.draw(EN35[i].sprite);
		}
		for (int i = 0; i < EN36.size(); i++)
		{
			window.draw(EN36[i].sprite);
		}
		for (int i = 0; i < EN37.size(); i++)
		{
			window.draw(EN37[i].sprite);
		}
		for (int i = 0; i < EN38.size(); i++)
		{
			window.draw(EN38[i].sprite);
		}
		for (int i = 0; i < EN39.size(); i++)
		{
			window.draw(EN39[i].sprite);
		}
		for (int i = 0; i < Wall.size(); i++)
		{
			window.draw(Wall[i].sprite);
		}
		for (int i = 0; i < J1.size(); i++)
		{
			window.draw(J1[i].sprite);
		}
		for (int i = 0; i < J2.size(); i++)
		{
			window.draw(J2[i].sprite);
		}
		window.draw(P.sprite);
		window.display();
	}
}