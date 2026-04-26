# snake-game-cpp
This project is a simple terminal-based Snake game built in C++. The game uses a 2D grid rendered in the console where the player controls a snake, collects fruit, and tries to avoid crashing into walls or its own tail.
The project demonstrates the use of loops, functions, and vectors to manage game state and movement.

# 🎮 Features
- Real-time snake movement using keyboard input (WASD)
- Growing snake body when fruit is collected
- Random fruit spawning
- Score tracking system
- Collision detection (walls + self)

# 🧠 Controls
- W → Move up
- A → Move left
- S → Move down
- D → Move right
- X → Exit game

# How to Compile & Run ⚙️
# Windows (MinGW / g++)
```bash
g++ snake.cpp -o snake
snake
```
# 🎮 Game Rules
- Eat fruit (F) to increase score and grow the snake
- Don't hit any walls (#)
- Don't hit your own tail (o)
- Game will end when a collision occurs

