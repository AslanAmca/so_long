# So_Long

So_Long is a 2D tile-based game developed in C, where players navigate through a maze to collect items and reach the exit. This project emphasizes exploration, interaction, and basic game mechanics, inspired by classic arcade games.

## Project Rules

Your project must comply with the following rules:
- **Graphics Library**: You must use the MiniLibX library. Either the version available on the school machines, or install it using its sources.
- **Makefile**: You have to submit a Makefile that compiles your source files. It must not relink.
- **Map Parameter**: The program must take as a parameter a map description file ending with the `.ber` extension.

## Game Objectives

- The player’s goal is to collect every collectible present on the map, then escape by choosing the shortest possible route.
- Player movement is controlled using the W, A, S, and D keys to move the main character in four directions: up, down, left, and right.
- The player cannot move into walls.
- The current number of movements must be displayed in the terminal.
- The game must use a 2D view (top-down or profile).
- The game does not have to be real-time.
- While the given examples show a specific theme, you can create your own world.

## Graphic Management

- The program must display the game image in a window.
- The window management must remain smooth (changing to another window, minimizing, etc.).
- Pressing `ESC` must close the window and quit the program cleanly.
- Clicking the close button on the window's frame must also quit the program cleanly.
- The use of MiniLibX images is mandatory.

## Map Configuration

The game map must consist of the following components:
- **Walls** (1)
- **Collectibles** (C)
- **Free Space** (0)
- The map can be composed of only five characters:
  - `0` for an empty space
  - `1` for a wall
  - `C` for a collectible
  - `E` for the exit
  - `P` for the player’s starting position

## Map Requirements:
- The map must contain at least one exit, one collectible, and one starting position to be valid.
- If the map contains duplicate characters (exit/start), display an error message.
- The map must be rectangular and surrounded by walls. If not, the program must return an error.
- Ensure there is a valid path in the map.
- The program must be able to parse any map that follows the above rules.

### Example Valid Map:
```plaintext
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

## Controls
- W: Move up
- S: Move down
- A: Move left
- D: Move right
- ESC: Exit the game

## Bonus Part
While this project encourages the development of your own original features, focus on completing the main assignment efficiently. You can use additional functions for the bonus part as long as their use is justified during evaluation. Extra points will be awarded for:

- Making the player lose when they touch an enemy patrol.
- Adding sprite animations.
- Displaying the movement count directly on the screen instead of writing it in the terminal.

## Run

1. Clone the repository:
	```bash
	git clone https://github.com/AslanAmca/so_long
	cd so_long
	```

2. Compile the project: Ensure you have the necessary dependencies installed, then compile the code using:
	```bash
	make
	```
3. Run the game: Execute the game with a valid map file:
	```bash
	./so_long maps/your_map.ber
	```
