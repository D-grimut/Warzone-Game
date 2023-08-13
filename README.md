# Warzone-Game

## Table of Contents
* Project Overview
* Features
* Game Mechanics
* Bot Strategies
* Design Patterns
* Map Files
* How to Play
* Getting Started
* Contributors
* Acknowledgments

## Project Overview
Our project aims to recreate the essence of the Warzone game by focusing on the core gameplay mechanics and strategies, all within a console-based environment. We have implemented different types of bots with varying levels of aggressiveness, allowing players to practice their skills against a range of opponents.

## Features
Console-based gameplay.
Four different types of bots with varying levels of aggressiveness: benevolent, aggressive, neutral, and cheater.
Ability to read and validate .map files for different maps, enhancing the game's replayability.
Implementation of essential game mechanics such as drawing cards, moving armies, selecting continents, invading territories, and defending against attacks.

## Game Mechanics
Our recreation encompasses all core gameplay elements of the Warzone game:

Draw Cards: Players can draw cards after successful invasions.
Move Armies: Transfer armies between owned territories.
Select Continent: Gain bonus armies by controlling entire continents.
Invade: Launch different types of attacks on adjacent enemy territories.
Defend: Players can defend against incoming attacks.

## Bot Strategies
Experience a range of bot behaviors:

Benevolent Bot: Prioritizes reinforcing weaker territories and maintaining a defensive strategy.
Aggressive Bot: Focuses on attacking and invading enemy territories aggressively.
Neutral Bot: Follows a balanced approach between defense and offense.
Cheater Bot: Attempts to break the rules and manipulate the game in its favor.

## Design Patterns
We've incorporated various design patterns to enhance the structure and maintainability of our project:

Model-View-Controller (MVC) Pattern: Separation of concerns between the game logic, user interface, and bot behavior.
Observer Pattern: Enables communication between different game components, such as notifying players of events.
Adapter Pattern: Enables the player to recreate a previous game or log a new game in the GameLog.

## Map Files
Our project supports custom maps defined in .map files. These files determine the layout of the game world, territories, continents, and connections between territories. We've implemented a validation mechanism to ensure the loaded map is valid for gameplay.
