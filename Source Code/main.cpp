/// Sanket Patel 0999383  


#include"tictactoe.h"
#include<iostream>
using namespace std;

int main()
{
	//int i, move_new;
	player p1, p2;
//	tictactoe t;
	Deck d;
	cout << "Enter Player1 name and symbol : " << endl;
	cin >> p1;
	cout << endl;
	cout << "Enter Player2 name and symbol : " << endl;
	cin >> p2;
	cout << "Player1 info " << endl;
	cout << p1 << endl;
	cout << "Player2 info " << endl;
	cout << p2 << endl;
	cout << endl;
	cout << endl;
	tictactoe t;
	char player1 = p1.get_playersymbol();
	char player2 = p2.get_playersymbol();
	t.sendsymbol(player1, player2);
	cout << endl;
	cout << endl;
	cout << "Decide who makes the first move: " << endl;
	cout << "Press 1 for player1" << endl;
	cout << "press 2 for player2" << endl;
	cin >> t;
	int total = 1;

	char ch = 'y';
	do {


	start:
	t:
		t.start_game();
		t.validateplayerinput();
		if (t.validateplayerinput() == true)
		{
			t.validateMove();
		}
		else
		{
			cout << "Please enter valid number between 0 to 8" << endl;
			cout << endl;
			goto t;
		}
		t.DrawBoard();
		bool check = t.isGameOver();
		/*move_new = */
		if (check == true)
		{
			d.appendstack();
			cout << endl;

			cout << "play more? y/n ";
			cin >> ch;

			// reset the board
			if (ch != 'n')
			{
				t.reset();
				Deck d;
				total++;
				goto start;
			}

			else
			{
				t.gamestatistics(total, p1, p2);
				cout << endl;
				cout << endl;
				if (p1.get_score() < p2.get_score())
				{
					cout << "Player2 Win the Game with score" << p2.get_score() << endl;
					cout << endl;
					cout << "Player1 loss the Game with score" << p1.get_score() << endl;
					cout << endl;
					break;
				}
				else if( p1.get_score() == p2.get_score())
				{
					cout << "Player 1 and player 2 won equal match" << endl;
					break;
				}
				else
				cout << "Player1 Win the Game with score" << p1.get_score() << endl;
				cout << endl;
				cout << "Player2 loss the Game with score" << p2.get_score() << endl;
				cout << endl;

				break;
				//goto end;
			}

		}
		t.changeturn();
		//t.getplayermove(move_new);

		//if (t.isGameOver()) {
		//	cout << "play more? y/n ";
		//	cin >> ch;

		//	// reset the board
		//	if (ch != 'n')
		//		t.reset();
		//}
		//end:


	} while (ch != 'n');


	system("pause");
	return 0;

}
