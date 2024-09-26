# Cub3D

## Introduction

**Cub3D** is a raycasting-based game engine built as a part of the 42 school curriculum. The goal of the project is to create a first-person 3D rendering environment, similar to old-school games like *Wolfenstein 3D*. Using 2D maps, the program renders a 3D view using raycasting to simulate depth, walls, and textures. This project is good to understand mathematical concepts, such as vectors and trigonometry, and the application of them to develop a videogame.

## What are the features I can find in cub3D?

- First-person 3D perspective using raycasting
- Render textured walls based on a 2D map
- Player movement (WASD) and camera rotation (left/right arrows)
- Collision detection with walls
- Configurable maps with textures, floor, and ceiling colors
<p>
  <img src="https://github.com/user-attachments/assets/2a1e5eb4-edd2-415e-85a2-c83e78259439" alt="cub3D1" width="325"/>
  <img src="https://github.com/user-attachments/assets/f0629142-41a1-46ce-ab48-88f77a4c4281" alt="cub3D2" width="325"/>
</p>

## What do I need to try cub3D?

- A Unix-based system (Linux or macOS)
- A C compiler (gcc or clang)
- Basic knowledge of fractals and complex numbers

This repository already includes a version of Minilibx to work in macOS. However, if you want to try this project in linux, you can click [here](https://github.com/42Paris/minilibx-linux.git). You have to name the folder minilibx_linux to make it work. Keep in mind that the project was developed in macOS, using the macOS version of minilibx. It can be some compatibility errors trying to build the project in linux.

## How can I get and compile the program?

1. Clone this repository
```bash
git clone https://github.com/quiminbano/cub3D.git
```
2. In case that you are running the project in macOS, you can skip this step, otherwise you have to clone the latest version of minilibx for linux
```bash
git clone https://github.com/42Paris/minilibx-linux.git minilibx_linux
```
3. Compile the program.
```bash
make
```

## How can I execute the program?

To execute the program you must pass an absolute or relative path to the map file. The map format is `.cub`. For example:
```bash
./cub3D maps/oulu_kaupunki.cub`
```

## How should a map look like?

A valid map should have the following structure:

1. **Map Layout**: The map should be a grid of characters, where each character represents a different element:
	- `1`: Wall
	- `0`: Empty space
	- `N`, `S`, `E`, `W`: Player's spawning position and orientation (North, South, East, West)

2. **Map Borders**: The map must be enclosed by walls (`1`). There should be no gaps in the walls to prevent the player from escaping the map boundaries. Map files that contain two or more separated maps, either vertically or horizontally, are not considered valid maps.

3. **Configuration**: The map file should start with configuration settings before the actual map layout. These settings include:
	- `R`: Resolution (e.g., `R 1920 1080`)
	- `NO`, `SO`, `WE`, `EA`: Paths to the textures for the north, south, west, and east walls respectively (e.g., `NO ./path_to_north_texture`)
	- `S`: Path to the sprite texture (e.g., `S ./path_to_sprite_texture`)
	- `F`: Floor color in RGB format (e.g., `F 220,100,0`)
	- `C`: Ceiling color in RGB format (e.g., `C 225,30,0`)

### Example Map File

```
R 1920 1080
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
S ./textures/sprite_texture.xpm
F 220,100,0
C 225,30,0

11111111111111111111
10000000001100000001
10110000011100000001
10010000000000000001
11111111101100000111
10000000001100000001
10000000000000000001
10000000000000000001
10000000000000000001
11111111111111111111
```

This example demonstrates a simple map with a rectangular layout, enclosed by walls, and configuration settings for resolution, textures, and colors.

