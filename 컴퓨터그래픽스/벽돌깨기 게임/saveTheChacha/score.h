#pragma once
class Score{
public:
	void setChacha(int c) { chacha += c; }
	int getChacha() { return chacha; }
	int setLife(int l) { life += l; return life; }
	int setScore(int s) { score += s; return score; }
	int setLevel(int l) { level += l; return level; };
	Score(int l = 5, int c = 1) { life = 20; chacha = c; score = 0; level = 1; }
private :
	int life;
	int chacha;
	int score;
	int level;
};

Score gameScore = Score();