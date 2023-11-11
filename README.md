## Term Craft by AlpineGrizzly 
C++ Terminal style game inspired by Starcraft I and II gameplay and my love of the RTS genre as a whole. 

### Game Goal
This will be like a colony like game where you can mine resources to expand population at nodes that can go to neighboring nodes to increase population 
to fend off attacks from other players. Buildings can be constructed to encourage more growth. Player will attempt to overtake each others nodes until someone
has taken over the entire map.

Each node has population and enemy nodes feeding into opponent nodes will decrease it by one until it is overtaken
```sh
@ ----> @ <----- $  
23      1        40
```


### Requirements 
### BUGS
- [X] Structures can be built on each other (This may prompt the switch to a map that has elements already laid out for checking, computationally would be way easier)
- [ ] Player is able to create structures on the board of the map (Problem Im running into with this one
is the player's cursor has no way of knowing the dimensions of the map unless I let it see the const defined in main. Idk) 
- [ ] Not quite sure this counts as a bug, but when it comes time to do resources
The loop only updates itself as the player moves there cursor. Going to have to make
the Cin listener nonblocking.
(Another suggestion could be to use a thread to update the world and players seperately?) 
### TODO 
- [X] Drawing of map
- [X] Bounds checking for player's cursor 
- [X] Screen wrapping for cursorr
- [ ] Resource management ot include mining gems / gases to create
      new structures and units
- [ ] Have game draw structures on the map from an array
- [X] Opposing players with bases that have associated health
- [ ] Ability to create structures
- [ ] Structures will have a time before they are built , represented by the default structure icon
- [ ] Ability to create and control units (Selection? with HUD that shows stats on the individual units health and attack and whatnot)
- [ ] Procedural generation of terrain elements such as cliffs and trees
- [ ] Game start screen
- [ ] Multiplayer capabilities (This is likely to be divided into a ton of smaller tasks in the future)

#### Idea for what the build menu will look like 
Pressing B, will bring up a terminal menu on the right side that the
player will be able to select a structure to build. 

Programmatically, the map will draw the structures as a field as they are added
to the arraw of structures that are present on the map. 

```sh
<< Player presses B while cursor is on a spot >>

*****  |    BUILD STRUCTURE 
Game   |    1. Base
*****  |    2. Tower
            3. Wall 
```

#### Resource Management idea 
For the time being, each player will only be able to mine from a finite
amount of resources within so many blocks of the original base; This can
be further increased by the player by making upgrades to mine resources 
faster. 

A while loop will probaly sit there and listen seperate from cursor 
movement while the menu is up.

### Controls
Arrow keys - Movement of player's cursor 
B - Build a structure (Numbers to denote each structure in menu)
D - Destroy a structure 
U - While hovering over a structure that can create units, will bring
up a menu of units to spawn 
