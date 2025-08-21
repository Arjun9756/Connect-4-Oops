This is a C++ implementation of the classic Connect 4 game.
Two players take turns dropping discs (X for Player 1 and O for Player 2) into a 6x7 board. The goal is simple: connect four discs in a row before your opponent!

Winning combinations include:

Four in a row horizontally

Four in a row vertically

Four in a row diagonally

If the board is filled without any winner, the game ends in a draw.

🚀 How to Play

Run the program in your terminal/IDE.

Players alternate turns by entering a column number (0–6).

The disc automatically falls to the lowest available slot in that column.

The first player to connect four wins 🎉.

If no valid moves remain → Match Draw 🤝.

🖥️ Example Gameplay
Current Board:
. . . . . . .
. . . . . . .
. . . . . . .
. . . . . . .
. O . . . . .
. X . . . . .
0 1 2 3 4 5 6
-----------------
Player 1 Chance Enter Column: 0

⚡ Features

Classic 6x7 Connect 4 board

Two-player turn-based gameplay

Win detection in all directions

Input validation for invalid/full columns

Draw detection

Text-based board visualization

🛠️ Tech

Language: C++

Libraries: iostream, vector

📜 License

This project is open-source and free to use.
