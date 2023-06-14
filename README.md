Maze Game

![maze gif](https://github.com/KipEric/Maze-Project/issues/1#issue-1756412617)

Welcome to a maze game project! This is a simple game where players navigate
through a maze environment.The objective is to reach the goal while avoiding
obstacles and challenges along the way

This project was inspired by my childhood fascination with mazes and my love
for puzzle-solving games. I wanted to create an engaging and interactive
maze game that challenges players to navigate through intricate
mazes while enjoying the thrill of exploration.

Throughout the development process, I aimed to strike a balance between 
simplicity and complexity, ensuring that the game is accessible to all players
while still providing a satisfying level of challenge. 
I also wanted to create an immersive experience by incorporating 
visually appealing graphics and responsive controls.

Check out the [Deployed Site](https://github.com/KipEric/) to play the Maze Game.
For a detailed overview of the project journey and development process, 
you can read the [Final Project Blog Article]
(https://www.linkedin.com/pulse/blog-post-maze-game-kipkoech-eric).
Feel free to connect with me on 
[LinkedIn](https://www.linkedin.com/in/kipkoech-eric/)
to discuss the project or explore potential collaboration opportunities.

## Dependencies

This project relies on the following dependencies:
1. SDL2
2. SDL2_image

Make sure you have these libraries installed on your system before compiling
and running the game

Getting Started
To compile and run the Maze Game, follow these steps:
1. Clone this repository to your local machine or download source code files.
2. Make sure you have the required dependencies installed.
3. Open a terminal or command prompt and navigate to the project directory.
4. Run the following command to build the game: make
5. Once the build process is complete, run the game with the following command:
make run
6. Enjoy playing the Maze Game!

## Controls

Use the arrow keys or WASD keys to move the player character.
Press the Escape key to exit the game.

Project Structure
The project directory is organized as follows:
1. `src/`: Contains the source code files
2. `header/`: Contains the header files
3. `images/`: Contains the images used in the game.

Feel free to explore the source code and make modifications according to your needs.


## Technical Details

### Maze Generation Algorithm

One of the key technical challenges in developing the Maze Game was generating
random mazes that are solvable and provide an enjoyable gameplay experience.
After researching various maze generation algorithms, 
I decided to implement the Recursive Backtracking algorithm.

The Recursive Backtracking algorithm starts by initializing a grid with walls
between each cell. It then chooses a random starting cell and recursively 
carves paths through the grid by removing walls. This process continues until
all cells have been visited. The algorithm ensures that there is always a path
between any two cells in the maze.

### Gameplay Mechanics

To enhance the gameplay experience, I incorporated several mechanics into the
Maze Game. These include:

- Player Movement: The player can navigate the maze using either the arrow
keys or the WASD keys. The movement is smooth and responsive, providing
a seamless control experience.

- Obstacles and Collectibles: The maze is filled with obstacles, such as
locked doors and hidden traps, that players must overcome to progress.
They can also collect keys to unlock doors and access new areas.

- Timer and Scoring: A timer keeps track of the player's progress, 
adding a sense of urgency to complete the maze. Additionally, a scoring
system rewards players based on their speed and efficiency in reaching the goal.

## Challenges and Next Steps

Throughout the development of the Maze Game, I faced various challenges,
including optimizing performance for larger maze sizes, implementing advanced
enemy AI, and enhancing the game's visuals and audio.

For future iterations of the game, I envision implementing the following
improvements:

- Level Editor: Allowing players to create and share their custom mazes,
fostering a community-driven experience.

- Multiplayer Mode: Introducing a multiplayer mode where players can compete
against each other or collaborate to solve mazes together.

- Enhanced Graphics and Effects: Adding more visual effects, animations,
and sound design elements to create a more immersive and engaging 
gameplay experience.

## Related Projects

Maze Solve Algorithim - A separate projects that focuses on
solving mazes programmatically using various algorithims

## License

Public Domain. No copy write protection
