#include<iostream>
#include<stack>
#include<list>
#include<string>
using namespace std;

class player
{
protected:
	string Playername;
	char Playersymbol;
	int gamestatistics;
	int score;
	int won, draw, loss;

public:
	player();
	player(string, char);
	string get_playername();
	int get_score();
	void set_score(int, int, int);
	char get_playersymbol();
	friend ostream & operator<<(ostream & out, player & p);
	friend istream & operator>>(istream & in, player & p);
	friend bool operator < (const player & lhs, const player & rhs);


};


class Deck
{
private:
	char **board;

	stack<int> player1choices;
	stack<int> player2choices;

public:
	Deck();
	void set(int r, int c, char value);
	char get(int r, int c);
	void insertchoices(int, int);
	friend ostream & operator << (ostream & out, Deck & dc);
	void appendstack();


};


class tictactoe
{
private:
	list<int>Decklist; // use the list<Deck>
	player player1;
	player player2;
	char symbol1, symbol2, symbol;
	int move, p1_score, p2_score;
	int input;
	Deck deck;
	int player1_win = 0, player2_win = 0, player1_draw = 0, player2_draw = 0;
	bool statistic;
	bool draw;

public:
	tictactoe();
	tictactoe(string, char);
	friend istream & operator >> (istream & in, tictactoe & t);
	bool validateplayerinput();
	void getplayermove(int);
	void validateMove();
	void boardchange(int);
	bool isGameOver();
	bool isDraw();
	void start_game();
	int changeturn();
	void appenddeck();
	void sendsymbol(char, char);
	void DrawBoard();
	void reset();
	void win_player();
	void draw_player();
	void gamestatistics(int, player & p1, player & p2);



};
#pragma once
