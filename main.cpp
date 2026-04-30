#include <iostream>
#include <vector>
#include <conio.h> // For _kbhit() and _getch()
#include <windows.h> // For Sleep()

using namespace std;

// Global Variables (To be managed by the Architect)
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

// Tail Data (For the Growth Specialist - Week 8 Arrays/Vectors)
vector<int> tailX, tailY; 
int nTail;

// *Function Prototypes* (Table of Contents)
void Setup();
void Draw();
void Input();
void Logic();

// *Setup*
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

// *Draw*
void Draw() {
    // UI Designer: Implement the nested loops to draw the map, snake, and fruit
    system("cls"); // Clears the console

    // Top Wall
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Logic for middle rows, snake head ('O'), and tail ('o') goes here...
   
    for (int i = 0; i < height; i++) {    // Map (middle area)
        cout << "#"; // Left wall

        for (int j = 0; j < width; j++) {

            // Snake head
            if (i == y && j == x) {
                cout << "O";
            }

            // Fruit
            else if (i == fruitY && j == fruitX) {
                cout << "F";
            }

            // Tail
            else {
                bool isTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        isTail = true;
                        break;
                    }
                }

                // Empty space
                if (!isTail)
                    cout << " ";
            }
        }

        cout << "#"; // Right wall
        cout << endl;
    }

    // Bottom Wall
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Score display
    cout << "Score: " << score << endl;
}

// *Input*
void Input() {
    // Physics Lead: Handle key presses (W, A, S, D)
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }
}

void Logic() {
    // Architect & Growth Specialist:
    // 1. Update tail positions (shifting coordinates in the vector)
    // 2. Update head position based on 'dir'
    // 3. Check for collisions (Wall or Self)
    // 4. Check if fruit is eaten (if x == fruitX && y == fruitY)
    switch (dir)
    {
    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case UP:
        y--;
        break;

    case DOWN:
        y++;
        break;

    default:
        break;
    }

    // Hit wall = Game Over
    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = true;
}

// The Main Loop aka the end
int main() {
    srand(time(0));   // randomize the fruit position
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100); // Controls game speed
    }
    cout << "Oops, Game Over! :(" << endl;

    return 0;
}
