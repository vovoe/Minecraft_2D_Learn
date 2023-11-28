#include <SFML/Graphics.hpp>
#include "Title.h"
#include "Sound.h"
#pragma once

using namespace sf;

class Mobs {
public:
	float dx, dy;
	FloatRect rect;
	bool onGround, Bsound, Sone;
	Sprite sprite;
	float curFrame, anim;
	int soud, t, dwig, Tx, Ty;
	String name;

	Mobs(String who, Texture& image, int x, int y) {
		name = who;
		Sone = false;

		if (who == "cow") {
			Tx = 160;
			Ty = 160;
		}
		else if (who == "chicken") {
			Tx = 63;
			Ty = 80;
		}
		else if (who == "sheep") {
			Tx = 165;
			Ty = 160;
		}
		else if (who == "pig") {
			Tx = 88;
			Ty = 80;
		}

		sprite.setTexture(image);
		sprite.setTextureRect(IntRect(0, 0, Tx, Ty));
		rect = FloatRect(x * ts, y * ts, Tx, Ty);

		dx = dy = 0;
		curFrame = anim = soud = 0;
		t = 100;
		dwig = 1;
		Bsound = false;
	}

	void update(float time, int pos) {
		if (t > 0) {
			if (dwig == 1) {
				dx = 0;
				sprite.setTextureRect(IntRect(0, 0, Tx, Ty));

				if (Sone == true && Bsound) {
					if (name == "cow") {
						int st = rand() % 4;

						sound.cow[st].play();
					}
					else if (name == "chicken") {
						int st = rand() % 3;

						sound.chicken[st].play();
					}
					else if (name == "pig") {
						int st = rand() % 3;

						sound.pig[st].play();
					}
					else if (name == "sheep") {
						int st = rand() % 3;

						sound.sheep[st].play();
					}

					Sone = false;
				}
			}
			else if (dwig == 2) {
				dx = 0.1;

				Sone = true;
			}
			else if (dwig == 3) {
				dx = -0.1;

				Sone = true;
			}

			t -= 1;
		}
		if (t == 0) {
			t = 100;
			dwig = rand() % 3 + 1;
		}

		rect.left += dx * time;
		Collision(0);

		if (!onGround)
			dy = dy + 0.0005 * time;

		rect.top += dy * time;

		onGround = false;
		Collision(1);

		curFrame += 0.01 * time;

		if (curFrame < 6)
			anim = curFrame;
		else {
			anim = 5 - (curFrame - 5);
		}

		if (curFrame > 8)
			curFrame = 1;

		if (dx > 0)
			sprite.setTextureRect(IntRect(Tx * int(anim), 0, Tx, Ty));
		if (dx < 0)
			sprite.setTextureRect(IntRect(Tx * int(anim) + Tx, 0, -Tx, Ty));

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		dx = 0;

		if (rect.left - offsetX > -80 && rect.left - offsetX < 1080)
			Bsound = true;
		else
			Bsound = false;
	}

	void Collision(float dir) {
		for (int i = rect.top / ts; i < (rect.top + rect.height) / ts; i++)
			for (int j = rect.left / ts; j < (rect.left + rect.width) / ts; j++) {
				if (TileMap[i][j] == 'A' || TileMap[i][j] == 'B' || TileMap[i][j] == 'C' || TileMap[i][j] == 'D' ||
					TileMap[i][j] == 'F' || TileMap[i][j] == 'G' || TileMap[i][j] == 'H' || TileMap[i][j] == 'I' ||
					TileMap[i][j] == 'J' || TileMap[i][j] == 'K' || TileMap[i][j] == 'L' || TileMap[i][j] == 'M' ||
					TileMap[i][j] == 'X') {
					if (dx > 0 && dir == 0) {
						rect.left = j * ts - rect.width;
					}
					if (dx < 0 && dir == 0)
						rect.left = j * ts + ts;
					if (dx != 0 && dir == 0 && onGround) {
						dy = -0.4;

						onGround = false;
					}
					if (dy > 0 && dir == 1) {
						rect.top = i * ts - rect.height;
						dy = 0;
						onGround = true;

						if (dx != 0) {
							if (soud == 0 && Bsound) {
								if (name == "cow") {
									int st = rand() % 4 + 4;

									sound.cow[st].play();
								}
								else if (name == "chicken") {
									int st = rand() % 2 + 3;

									sound.chicken[st].play();
								}
								else if (name == "pig") {
									int st = rand() % 5 + 3;

									sound.pig[st].play();
								}
								else if (name == "sheep") {
									int st = rand() % 4 + 3;

									sound.sheep[st].play();
								}
							}

							soud++;

							if (soud == 15)
								soud = 0;
						}
					}
					if (dy < 0 && dir == 1) {
						rect.top = i * ts + ts;
						dy = 0;
					}
				}
			}
	}
};