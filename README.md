## Term Craft by AlpineGrizzly 
C++ Terminal style game inspired by Starcraft I and II gameplay and my love of the RTS genre as a whole.


### Requirements 
### BUGS
- [X] Structures can be built on each other (This may prompt the switch to a map that has elements already laid out for checking, computationally would be way easier) 
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
