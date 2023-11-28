#include <SFML/Graphics.hpp>
#include "Title.h"
#pragma once

using namespace sf;

class Select {
public:
	Sprite window, block, selblock[12];

	Select(Texture& image) {
		window.setTexture(image);

		window.setTextureRect(IntRect(0, ts * 2, ts, ts));
		window.setScale(1.5, 1.5);
		window.setPosition(12, 380);

		block.setTexture(image);

		block.setTextureRect(IntRect(0, 0, ts, ts));
		block.setScale(1.2, 1.2);
		block.setPosition(24, 392);

		for (int i = 0; i < 12; i++) {
			int t = i;

			if (t >= 4)
				t++;

			int sx = ts * i + 90 + 25 * i;
			int sy = 100;

			if (i > 7) {
				sx -= 840;
				sy += 150;
			}

			selblock[i].setTexture(image);
			selblock[i].setTextureRect(IntRect(ts * t, 0, ts, ts));
			selblock[i].setPosition(sx, sy);
		}
	}
};