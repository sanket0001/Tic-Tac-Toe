#include"tictactoe.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//Player Class
player::player()
{

	score = 0;
}
player::player(string n, char s)
{
	Playername = n;
	Playersymbol = s;
	score = 0;

}

string player::get_playername()
{
	return Playername;
}

char player::get_playersymbol()
{
	return Playersymbol;
}

int player::get_score()
{
	player::score = ((won * 2) + draw - loss);
	return score;
}
void player::set_score(int w, int d, int l)
{

	won = w;
	loss = l;
	draw = d;
	//score = ((won * 2) + draw - loss);

}
ostream & operator<<(ostream & out, player & p)
{
	out << "PlayerName : " << p.Playername << " , PlayerSymbol : " << p.Playersymbol << " , PlayerScore : " << p.score;
	return out;
}
istream & operator>>(istream & in, player & p)
{
	in >> p.Playername;
	in >> p.Playersymbol;
	return in;
}
bool operator < (const player & lhs, const player & rhs)
{
	if (lhs < rhs)
		return true;
	else
		return false;

}


//Deck Class

Deck::Deck()
{

	int i, j, k = 48;
	board = new char*[3];

	for (i = 0; i<3; i++)
	{
		board[i] = new char[3];
		cout << " -- -- -- " << endl;
		for (j = 0; j<3; j++)
		{
			cout << "|";
			set(i, j, k);
			cout << get(i, j) << " ";
			k++;

		}
		cout << "|";
		cout << endl;
	}
	cout << " -- -- -- " << endl;
}
void Deck::set(int r, int c, char value)
{
	board[r][c] = value;
}

char Deck::get(int r, int c)
{
	return board[r][c];
}
void Deck::insertchoices(int m, int i)
{
	int move = m;
	int input = i;
	if (move == 1)
		player1choices.push(input);
	else
		player2choices.push(input);
}

void Deck::appendstack()
{
	ofstream fout("ticTacToe.txt", ios::app);
	if (fout.is_open())
	{
		fout << "Player1 choices : ";
		while (!player1choices.empty())
		{
			fout << '  ' << player1choices.top();
			player1choices.pop();
		}
		fout << endl;
		fout << "Player2 choices : ";
		while (!player2choices.empty())
		{
			fout << '  ' << player2choices.top();
			player2choices.pop();
		}
		fout << endl;

	}
	else
	{
		cout << "File could not opened for inserting player choices" << endl;
	}

}

//Deck::print
ostream & operator<<(ostream & out, Deck & dc)
{
	for (int i = 0; i <3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			out << dc.board[i][j];
		}
		cout << endl;
	}
	return out;

}



//TicTacToe Class
tictactoe::tictactoe()
{

}
tictactoe::tictactoe(string n, char s)
{
	player(n, s);
}

istream & operator>>(istream & in, tictactoe & t)
{
	in >> t.move;
	return in;
}
void tictactoe::getplayermove(int i)
{

	move = i;

	if (move == 1)
	{
		symbol = symbol1;
		cout << "Enter player1 move :" << endl;
		cin >> input;


	}
	else
	{
		symbol = symbol2;
		cout << "Enter player2 move :" << endl;
		cin >> input;

	}
}
bool tictactoe::validateplayerinput()
{
	if (input <= 8)
		return true;
	else
		return false;
}

void tictactoe::validateMove()
{
	if (Decklist.empty())
	{

		Decklist.push_front(input);
		deck.insertchoices(move, input);
		boardchange(input);
	}
	else
	{
		for (list<int>::iterator it = Decklist.begin(); it != Decklist.end(); ++it)
		{
			if (*it == input)
			{
				cout << "enter valid move " << endl;
				getplayermove(move);
			}

		}
		Decklist.push_front(input);
		deck.insertchoices(move, input);
		boardchange(input);

	}
}
void tictactoe::boardchange(int num)
{

	int i = num;

	if (i == 0)
	{
		deck.set(0, 0, symbol);
	}
	if (i == 1)
	{
		deck.set(0, 1, symbol);
	}
	if (i == 2)
	{
		deck.set(0, 2, symbol);
	}
	if (i == 3)
	{
		deck.set(1, 0, symbol);
	}
	if (i == 4)
	{
		deck.set(1, 1, symbol);
	}
	if (i == 5)
	{
		deck.set(1, 2, symbol);
	}
	if (i == 6)
	{
		deck.set(2, 0, symbol);
	}
	if (i == 7)
	{
		deck.set(2, 1, symbol);
	}
	if (i == 8)
	{
		deck.set(2, 2, symbol);
	}

}
bool tictactoe::isDraw()
{
	if (Decklist.size() == 9)
	{
		cout << "Game is draw" << endl;
		appenddeck();
		draw_player();
		return true;

	}
	else
		return false;



}
bool tictactoe::isGameOver()
{
	bool res = false;
	if (deck.get(0, 0) == deck.get(0, 1) && deck.get(0, 1) == deck.get(0, 2))
	{
		if (move == 1)
		{
			cout << "Player1 Wins" << endl;
			appenddeck();
			win_player();
		}
		else
		{
			cout << "Player2 Wins" << endl;
			appenddeck();
			win_player();
		}
		res = true;
	}
	else if (deck.get(1, 0) == deck.get(1, 1) && deck.get(1, 1) == deck.get(1, 2))
	{
		if (move == 1)
		{
			cout << "Player1 Wins" << endl;
			appenddeck();
			win_player();
		}
		else
		{
			cout << "Player2 Wins" << endl;
			appenddeck();
			win_player();
		}
		res = true;

	}
	else if (deck.get(2, 0) == deck.get(2, 1) && deck.get(2, 1) == deck.get(2, 2))
	{
		if (move == 1)
		{
			cout << "Player1 Wins" << endl;
			appenddeck();
			win_player();
		}
		else
		{
			cout << "Player2 Wins" << endl;
			appenddeck();
			win_player();
		}
		res = true;

	}
	else if (deck.get(0, 0) == deck.get(1, 0) && deck.get(1, 0) == deck.get(2, 0))
	{
		if (move == 1)
		{
			cout << "Player1 Wins" << endl;
			appenddeck();
			win_player();
		}
		else
		{
			cout << "Player2 Wins" << endl;
			appenddeck();
			win_player();
		}
		res = true;

	}
	else if (deck.get(0, 1) == deck.get(1, 1) && deck.get(1, 1) == deck.get(2, 1))
	{
		if (move == 1)
		{
			cout << "Player1 Wins" << endl;
			appenddeck();
			win_player();
		}
		else
		{
			cout << "Player2 Wins" << endl;
			appenddeck();
			win_player();
		}
		res = true;

	}
	else if (deck.get(0, 2) == deck.get(1, 2) && deck.get(1, 2) == deck.get(2, 2))
	{
		if (move == 1)
		{
			cout << "Player1 Wins" << endl;
			appenddeck();
			win_player();
		}
		else
		{
			cout << "Player2 Wins" << endl;
			appenddeck();
			win_player();
		}
		res = true;

	}
	else if (deck.get(0, 0) == deck.get(1, 1) && deck.get(1, 1) == deck.get(2, 2))
	{
		if (move == 1)
		{
			cout << "Player1 Wins" << endl;
			appenddeck();
			win_player();
		}
		else
		{
			cout << "Player2 Wins" << endl;
			appenddeck();
			win_player();
		}
		res = true;

	}
	else if (deck.get(2, 0) == deck.get(1, 1) && deck.get(1, 1) == deck.get(0, 2))
	{
		if (move == 1)
		{
			cout << "Player1 Wins" << endl;
			appenddeck();
			win_player();
		}
		else
		{
			cout << "Player2 Wins" << endl;
			appenddeck();
			win_player();
		}
		res = true;

	}
	else
	{
		res = isDraw();
	}

	return res;
}
void tictactoe::start_game()
{
	getplayermove(move);
}
int tictactoe::changeturn()
{

	if (move == 1)
	{
		return move = 2;
	}
	else
	{
		return move = 1;
	}


}
void tictactoe::appenddeck()
{
	ofstream fout("ticTacToe.txt", ios::app);
	if (fout.is_open())
	{
		cout << "File open successfully!!. Appending data from decklist to file..." << endl;
		fout << "Game moves: ";
		for (list<int>::iterator it = Decklist.begin(); it != Decklist.end(); ++it)
		{

			fout << *it << "  ";
		}
		//for (list<int>::iterator it = .begin(); it != Decklist.end(); ++it)
		fout << endl;
		cout << "decklist appended successfully..." << endl;
		cout << endl;
	}
	else
	{
		cout << "File could not opened" << endl;
		cout << endl;
	}

}
void tictactoe::sendsymbol(char p1, char p2)
{
	symbol1 = p1;
	symbol2 = p2;
}
void tictactoe::DrawBoard()
{
	for (int i = 0; i<3; i++)
	{

		cout << " -- -- -- " << endl;
		for (int j = 0; j<3; j++)
		{
			cout << "|";
			cout << deck.get(i, j) << " ";
		}
		cout << "|";
		cout << endl;
	}
	cout << " -- -- -- " << endl;

}

void tictactoe::reset()
{
	int k = 48;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			deck.set(r, c, k++);
		}
	}
	Decklist.clear();

}
void tictactoe::win_player()
{
	if (move == 1)
	{
		player1_win = player1_win + 1;
	}
	else
	{
		player2_win = player2_win + 1;
	}
}
void tictactoe::draw_player()
{
	player1_draw = player1_draw + 1;
	player2_draw = player2_draw + 1;
}

void tictactoe::gamestatistics(int a, player& p1, player &p2)
{
	int t = a;
	int player1_loss, player2_loss;
	cout << "total game : " << t << endl;
	player1_loss = t - player1_win - player1_draw;
	player2_loss = t - player2_win - player2_draw;
	cout << "Player1 Statistic : " << " Win = " << player1_win << "  Draw = " << player1_draw << "  Loss = " << player1_loss << endl;
	cout << endl;
	cout << endl;
	cout << "Player2 Statistic : " << " Win = " << player2_win << "  Draw = " << player2_draw << "  Loss = " << player2_loss << endl;
	cout << endl;
	cout << endl;
	p1.set_score(player1_win, player1_draw, player1_loss);
	//p1.player::get_score();// score = player1.get_score();
	p2.set_score(player2_win, player2_draw, player2_loss);
	//p2_score = player2.get_score();

	cout << "Player1 Score is = " << p1.get_score() << endl;
	cout << endl;
	cout << "Player2 Score is = " << p2.get_score() << endl;
	cout << endl;

}