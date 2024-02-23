#include "jogo_do_galo.h"

int main(void) {
	using namespace std;
	using namespace jogo_do_galo;

	int turn = 0;
	State player[2] = { State::kPlayer1, State::kPlayer2 };

	cout << "Jogo do Galo" << endl << "Prima 'Enter' para iniciar o jogo..." << endl;

	// Aguardar que o utilizador prima 'Enter' para terminar.
	cin.get();
	//system("PAUSE"); // Esta seria uma alternativa para qualquer tecla

	do {
		Play(player[turn]);
		if (Winner(player[turn]) == true) {
			ClearScreen();
			DrawBoard();
			cout << "\n" << "You win!";
			break;
		}
		turn++;
		turn = turn % 2;
	} while (count_moves < 9);

	// Limpa o buffer de entrada 'cin'.
	// A função irá descartar até 1000 caracteres ou até encontrar um '\n'.
	cin.ignore(1000, '\n');
	// Aguardar que o utilizador prima 'Enter' para terminar.
	cin.get();

	return 0;
}