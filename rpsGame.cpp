#include <iostream>

std::string_view rpsWinner(char player1, char player2);

int main(void)
{
    // Standardize stream synchronization for professional C++ I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char player1, player2;

    std::cout << "Rock Paper Scissors Game\n";
    std::cout << "Enter choices (r = rock, p = paper, s = scissors)\n";
    std::cout << "Player 1 Choice: ";
    std::cin >> player1;

    std::cout << "Player 2 Choice: ";
    std::cin >> player2;
    
    std::cout << "\nThe winner is: " << rpsWinner(player1, player2) << "\n";
    return 0;
}

std::string_view rpsWinner(char player1, char player2)
{
    player1 = static_cast<char>(std::tolower(static_cast<unsigned char>(player1)));
    player2 = static_cast<char>(std::tolower(static_cast<unsigned char>(player2)));


    if ((player1 == 'r' && player2 == 's') ||
        (player1 == 's' && player2 == 'p') ||
        (player1 == 'p' && player2 == 'r') )
    {
        return "player one";
    }
    else if ((player2 == 'r' && player1 == 's') ||
             (player2 == 's' && player1 == 'p') ||
             (player2 == 'p' && player1 == 'r') )
    {
        return "player two";
    }
    else
    {
        return "tie";
    }
}