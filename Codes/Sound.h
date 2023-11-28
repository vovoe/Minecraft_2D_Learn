#include <SFML/Audio.hpp>
#include <conio.h>
#pragma once

class setSound {
public:
	SoundBuffer g[4], gr[4], s[4], st[4], w[4], c, mc[5], mw[8], mp[8], ms[7];
	Sound grass[4], gravel[4], sand[4], stone[4], wood[4], click,
		chicken[5], cow[8], pig[8], sheep[7];

	setSound() {
		g[0].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/grass/1.ogg");
		g[1].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/grass/2.ogg");
		g[2].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/grass/3.ogg");
		g[3].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/grass/4.ogg");

		gr[0].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/gravel/1.ogg");
		gr[1].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/gravel/2.ogg");
		gr[2].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/gravel/3.ogg");
		gr[3].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/gravel/4.ogg");

		s[0].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/sand/1.ogg");
		s[1].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/sand/2.ogg");
		s[2].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/sand/3.ogg");
		s[3].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/sand/4.ogg");

		st[0].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/stone/1.ogg");
		st[1].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/stone/2.ogg");
		st[2].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/stone/3.ogg");
		st[3].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/stone/4.ogg");

		w[0].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/wood/1.ogg");
		w[1].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/wood/2.ogg");
		w[2].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/wood/3.ogg");
		w[3].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/blocks/wood/4.ogg");

		mc[0].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/chicken/say1.ogg");
		mc[1].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/chicken/say2.ogg");
		mc[2].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/chicken/say3.ogg");
		mc[3].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/chicken/step1.ogg");
		mc[4].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/chicken/step2.ogg");

		mw[0].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/cow/say1.ogg");
		mw[1].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/cow/say2.ogg");
		mw[2].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/cow/say3.ogg");
		mw[3].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/cow/say4.ogg");
		mw[4].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/cow/step1.ogg");
		mw[5].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/cow/step2.ogg");
		mw[6].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/cow/step3.ogg");
		mw[7].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/cow/step4.ogg");

		mp[0].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/pig/say1.ogg");
		mp[1].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/pig/say2.ogg");
		mp[2].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/pig/say3.ogg");
		mp[3].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/pig/step1.ogg");
		mp[4].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/pig/step2.ogg");
		mp[5].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/pig/step3.ogg");
		mp[6].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/pig/step4.ogg");
		mp[7].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/pig/step5.ogg");

		ms[0].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/sheep/say1.ogg");
		ms[1].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/sheep/say2.ogg");
		ms[2].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/sheep/say3.ogg");
		ms[3].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/sheep/step1.ogg");
		ms[4].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/sheep/step2.ogg");
		ms[5].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/sheep/step3.ogg");
		ms[6].loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/mobs/sheep/step4.ogg");

		c.loadFromFile("C:/Users/Андрей/Desktop/Game/Sound/click.ogg");

		for (int i = 0; i < 4; i++) {
			grass[i].setBuffer(g[i]);
			gravel[i].setBuffer(gr[i]);
			sand[i].setBuffer(s[i]);
			stone[i].setBuffer(st[i]);
			wood[i].setBuffer(w[i]);
		}
		for (int i = 0; i < 5; i++)
			chicken[i].setBuffer(mc[i]);
		for (int i = 0; i < 8; i++)
			cow[i].setBuffer(mw[i]);
		for (int i = 0; i < 8; i++)
			pig[i].setBuffer(mp[i]);
		for (int i = 0; i < 7; i++)
			sheep[i].setBuffer(ms[i]);

		click.setBuffer(c);
	}

	void update(char set) {
		int st = rand() % 4;

		if (set == 'A' || set == 'L')
			grass[st].play();
		else if (set == 'B')
			gravel[st].play();
		else if (set == 'D')
			sand[st].play();
		else if (set == 'C' || set == 'F' || set == 'G' ||
			set == 'H' || set == 'I' || set == 'K' || set == 'M')
			stone[st].play();
		else if (set == 'J')
			wood[st].play();
	}
};

setSound sound;