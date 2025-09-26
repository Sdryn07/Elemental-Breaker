# Elemental Breaker

## Game Description

**Elemental Breaker** is a simple graphics project created using the **iGraphics** library in C. The project demonstrates basic graphics programming concepts like drawing shapes, handling user input, and simple animations.

## Features
- Classic DX Ball style gameplay.
- Unique interactions between ball and bricks of different elements.
- Dynamic scoring system based on performance.
- Keyboard controls for movement.



## Project Details
IDE: Visual studio 2013

Language: C,C++.

Platform : Windows PC.

Genre : 2D, casual, arcade


## How to Run the Project

Make sure you have the following installed:
- **Visual Studio 2013**
- **MinGW Compiler** (if needed)
- **iGraphics Library** (included in this repository)


Open the project in Visual Studio 2013
- Open Visual Studio 2013.
- Go to File → Open → Project/Solution.
- Locate and select the .sln file from the cloned repositoryafter adding in iGraphics LIbrary.
- Click Build → Build Solution
- Run the program


## How to Play

### **Controls**
Spacebar to start the game, left and right directional arrow keys for movement.


### **Game Rules**

- Player aims to destroy all bricks in the stage to complete the level.
- Ball starts neutral and inherits the element of the brick it comes in contact with.
- Ball and Bricks of different elements(or color) create different effects and reward different values of score:
- Fire(Orange): With water(blue)-> 2 points and 0.2 combo. With electric(purple)-> triggers *OverLoaded* reaction
- Water: With fire-> 4 points, 0.4 combo. With electric-> triggers *Electrocharged* reaction
- Electric: With fire-> triggers *Overloaded*. With water-> triggers *Electrocharged*.
- **Electrocharged**: Converts all water and electric bricks in the balls vicinity into *Charged* bricks for a short time. Charged bricks have property of both water and electric bricks.
- **Overloaded**: Destroys bricks in a certain radius from point of contact. Has the property of fire.
- Causing a reactions changes ball element back to neutral.
- Score increases multiplicatively with the combo awarded from destroying bricks in one go.
- Combo resets if player fails to bounce the ball back up.

## Project Contributors

1. Saad Raiyan
2. Jarir Hasan Navid
  
## Youtube Link
[Elemental Breaker SD-1 Lab Project](https://youtu.be/C0A77C6Fk_g)

## Project Report
[Project Report: Elemental Breaker]([https://drive.google.com/drive/u/1/my-drive](https://docs.google.com/document/d/1NGsbhluSWHwunAgcGKGqbjvpsrCL2usn/edit?usp=drive_link&ouid=114792122558511338648&rtpof=true&sd=true))
