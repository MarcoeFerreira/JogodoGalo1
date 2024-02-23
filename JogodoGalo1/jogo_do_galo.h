#pragma once

#include <iostream>
#include <string>
#include <cstdlib> // system()

namespace jogo_do_galo {
	using namespace std;

	int count_moves; // Inicializada a zero, uma vez que está declarada fora do âmbito de uma função ou classe
	enum class State { kEmpty = 0, kPlayer1, kPlayer2 };
	State board[3][3]; // Todos os elementos são inicializados a zero, uma vez que está declarada fora do âmbito de uma função ou classe

	void ClearScreen(void) {
		system("cls");
	}

	void DrawBoard(void) {
		for (int y = 0; y < 3; y++) {
			if (y == 0) cout << "  0 1 2" << endl;
			for (int x = 0; x < 3; x++) {
				if (x == 0) cout << y << " ";
				if (board[y][x] == State::kEmpty) cout << ". ";
				else if (board[y][x] == State::kPlayer1) cout << "X ";
				else cout << "O ";
			}
			cout << endl;
		}
	}

	void Play(State player) {
		int y, x;

		do {
			ClearScreen();
			DrawBoard();

			cout << endl << (player == State::kPlayer1 ? "Jogador 1 " : "Jogador 2 ") << "Selecione jogada!" << endl;
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
		} while ((x < 0 || x >= 3) || (y < 0 || y >= 3) || (board[y][x] != State::kEmpty));

		board[y][x] = player;

		count_moves++;
	}

	bool Winner(State player) {
		int sum_y[3]{}, sum_x[3]{}, sum_diagonal[2]{};

		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				if (board[y][x] == player) {
					sum_y[y]++;
					sum_x[x]++;
					if (x == y) sum_diagonal[0]++;
					if (x == 2 - y) sum_diagonal[1]++;
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			if (sum_y[i] == 3) return true;
			if (sum_x[i] == 3) return true;
		}
		if (sum_diagonal[0] == 3) return true;
		if (sum_diagonal[1] == 3) return true;

		return false;
	}
}