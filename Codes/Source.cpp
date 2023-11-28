#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Select.h"
#include "Mobs.h"

using namespace sf;

int main() {
	RenderWindow window(VideoMode(1000, 500), "Minecraft 2D!");

	Texture Picture;
	Picture.loadFromFile("C:/Users/Андрей/Desktop/Game/Paint/player.png");
	Player p(Picture);

	Texture Pcow;
	Pcow.loadFromFile("C:/Users/Андрей/Desktop/Game/Paint/mobs/cow.png");
	Mobs cow("cow", Pcow, 42, 8);

	Texture Pchicken;
	Pchicken.loadFromFile("C:/Users/Андрей/Desktop/Game/Paint/mobs/chicken.png");
	Mobs chicken("chicken", Pchicken, 44, 8);

	Texture Psheep;
	Psheep.loadFromFile("C:/Users/Андрей/Desktop/Game/Paint/mobs/sheep.png");
	Mobs sheep("sheep", Psheep, 45, 10);

	Texture Ppig;
	Ppig.loadFromFile("C:/Users/Андрей/Desktop/Game/Paint/mobs/pig.png");
	Mobs pig("pig", Ppig, 47, 10);
	Texture t2;
	t2.loadFromFile("C:/Users/Андрей/Desktop/Game/Paint/title.png");
	Sprite plat(t2), shad(t2);

	Sprite cursor[H][W];
	bool vid[H][W];
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			cursor[i][j].setTexture(t2);

			vid[i][j] = false;
		}

	Select select(t2);

	Clock clock;
	bool play = true, inventory = false;
	char set = 'A';

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Vector2i pos = Mouse::getPosition(window);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed) {
				if (play) {
					if (event.key.code == Mouse::Left) {
						for (int i = 0; i < H; i++)
							for (int j = 0; j < W; j++)
								if (vid[i][j] && TileMap[i][j] != 'X') {
									if (TileMap[i][j] != ' ') {
										sound.update(TileMap[i][j]);

										TileMap[i][j] = ' ';
									}
									else {
										bool down = TileMap[i + 1][j] != ' ';
										bool up = TileMap[i - 1][j] != ' ';
										bool left = TileMap[i][j - 1] != ' ';
										bool right = TileMap[i][j + 1] != ' ';
										bool block = Rear[i][j] != ' ';

										if (up || down || left || right || block) {
											TileMap[i][j] = set;

											sound.update(set);
										}
									}
								}

						p.set = true;
						p.curFrame = 0;
					}
					else if (event.key.code == Mouse::Right) {
						for (int i = 0; i < H; i++)
							for (int j = 0; j < W; j++)
								if (vid[i][j] && TileMap[i][j] != 'X') {
									if (Rear[i][j] != ' ') {
										sound.update(Rear[i][j]);

										Rear[i][j] = ' ';
									}
									else {
										bool down = Rear[i + 1][j] != ' ';
										bool up = Rear[i - 1][j] != ' ';
										bool left = Rear[i][j - 1] != ' ';
										bool right = Rear[i][j + 1] != ' ';
										bool block = TileMap[i][j] != ' ';

										if (up || down || left || right || block) {
											Rear[i][j] = set;

											sound.update(set);
										}
									}
								}

						p.set = true;
						p.curFrame = 0;
					}
				}

				if (inventory) {
					for (int i = 0; i < 12; i++)
						if (select.selblock[i].getGlobalBounds().contains(pos.x, pos.y)) {
							play = true;
							inventory = false;

							sound.click.play();

							int bx = ts * i;

							if (bx > ts * 3)
								bx += ts;

							select.block.setTextureRect(IntRect(bx, 0, ts, ts));

							switch (i)
							{
							case 0:
								set = 'A';
								break;
							case 1:
								set = 'B';
								break;
							case 2:
								set = 'C';
								break;
							case 3:
								set = 'D';
								break;
							case 4:
								set = 'F';
								break;
							case 5:
								set = 'G';
								break;
							case 6:
								set = 'H';
								break;
							case 7:
								set = 'I';
								break;
							case 8:
								set = 'J';
								break;
							case 9:
								set = 'K';
								break;
							case 10:
								set = 'L';
								break;
							case 11:
								set = 'M';
								break;
							}
						}
				}

				if (event.key.code == Mouse::Left)
					if (select.window.getGlobalBounds().contains(pos.x, pos.y)) {
						play = false;
						inventory = true;

						sound.click.play();
					}
			}
		}

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				vid[i][j] = false;

				if (cursor[i][j].getGlobalBounds().contains(pos.x, pos.y)
					&& pos.y + offsetY + ts * 2 > p.rect.top && pos.y + offsetY - ts * 3 < p.rect.top
					&& pos.x + offsetX + ts * 3 > p.rect.left && pos.x + offsetX - ts * 4 < p.rect.left)
					vid[i][j] = true;
			}

		if (!_kbhit())
			p.sprite.setTextureRect(IntRect(0, 0, 80, 160));

		if (play) {
			if (Keyboard::isKeyPressed(Keyboard::A))
				p.dx = -0.35;
			if (Keyboard::isKeyPressed(Keyboard::D))
				p.dx = 0.35;

			if (Keyboard::isKeyPressed(Keyboard::Space))
				if (p.onGround) {
					p.dy = -0.4;

					p.onGround = false;
				}
		}

		if (p.rect.left > 578 && p.rect.left < 10063)
			offsetX = p.rect.left - 500;
		offsetY = p.rect.top - 170;

		p.update(time, pos.x);
		cow.update(time, pos.x);
		chicken.update(time, pos.x);
		sheep.update(time, pos.x);
		pig.update(time, pos.x);
		window.clear(Color::White);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (Rear[i][j] == 'A')
					shad.setTextureRect(IntRect(0, ts, ts, ts));
				if (Rear[i][j] == 'B')
					shad.setTextureRect(IntRect(ts, ts, ts, ts));
				if (Rear[i][j] == 'C')
					shad.setTextureRect(IntRect(ts * 2, ts, ts, ts));
				if (Rear[i][j] == 'D')
					shad.setTextureRect(IntRect(ts * 3, ts, ts, ts));
				if (Rear[i][j] == 'F')
					shad.setTextureRect(IntRect(ts * 5, ts, ts, ts));
				if (Rear[i][j] == 'G')
					shad.setTextureRect(IntRect(ts * 6, ts, ts, ts));
				if (Rear[i][j] == 'H')
					shad.setTextureRect(IntRect(ts * 7, ts, ts, ts));
				if (Rear[i][j] == 'I')
					shad.setTextureRect(IntRect(ts * 8, ts, ts, ts));
				if (Rear[i][j] == 'J')
					shad.setTextureRect(IntRect(ts * 9, ts, ts, ts));
				if (Rear[i][j] == 'K')
					shad.setTextureRect(IntRect(ts * 10, ts, ts, ts));
				if (Rear[i][j] == 'L')
					shad.setTextureRect(IntRect(ts * 11, ts, ts, ts));
				if (Rear[i][j] == 'M')
					shad.setTextureRect(IntRect(ts * 12, ts, ts, ts));
				if (Rear[i][j] == ' ')
					shad.setTextureRect(IntRect(ts * 4, ts, ts, ts));

				shad.setPosition(j * ts - offsetX, i * ts - offsetY);
				window.draw(shad);
			}
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (TileMap[i][j] == 'A')
					plat.setTextureRect(IntRect(0, 0, ts, ts));
				if (TileMap[i][j] == 'B')
					plat.setTextureRect(IntRect(ts, 0, ts, ts));
				if (TileMap[i][j] == 'C')
					plat.setTextureRect(IntRect(ts * 2, 0, ts, ts));
				if (TileMap[i][j] == 'D')
					plat.setTextureRect(IntRect(ts * 3, 0, ts, ts));
				if (TileMap[i][j] == 'E')
					plat.setTextureRect(IntRect(ts * 4, 0, ts, ts));
				if (TileMap[i][j] == 'F')
					plat.setTextureRect(IntRect(ts * 5, 0, ts, ts));
				if (TileMap[i][j] == 'G')
					plat.setTextureRect(IntRect(ts * 6, 0, ts, ts));
				if (TileMap[i][j] == 'H')
					plat.setTextureRect(IntRect(ts * 7, 0, ts, ts));
				if (TileMap[i][j] == 'I')
					plat.setTextureRect(IntRect(ts * 8, 0, ts, ts));
				if (TileMap[i][j] == 'J')
					plat.setTextureRect(IntRect(ts * 9, 0, ts, ts));
				if (TileMap[i][j] == 'K')
					plat.setTextureRect(IntRect(ts * 10, 0, ts, ts));
				if (TileMap[i][j] == 'L')
					plat.setTextureRect(IntRect(ts * 11, 0, ts, ts));
				if (TileMap[i][j] == 'M')
					plat.setTextureRect(IntRect(ts * 12, 0, ts, ts));
				if (TileMap[i][j] == ' ' || TileMap[i][j] == 'X')
					continue;

				plat.setPosition(j * ts - offsetX, i * ts - offsetY);
				window.draw(plat);
			}

		window.draw(p.sprite);
		window.draw(cow.sprite);
		window.draw(chicken.sprite);
		window.draw(sheep.sprite);
		window.draw(pig.sprite);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				cursor[i][j].setPosition(j * ts - offsetX, i * ts - offsetY);

				if (play)
					cursor[i][j].setTextureRect(IntRect(0, ts * 2, ts, ts));
				else if (inventory)
					cursor[i][j].setTextureRect(IntRect(ts, ts * 2, ts, ts));

				if ((vid[i][j] && play) || inventory)
					window.draw(cursor[i][j]);
			}
		if (play) {
			window.draw(select.window);
			window.draw(select.block);
		}
		else if (inventory) {
			for (int i = 0; i < 12; i++)
				window.draw(select.selblock[i]);
		}
		window.display();
	}

	return 0;
}