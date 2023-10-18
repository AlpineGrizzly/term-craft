## Term Craft by AlpineGrizzly 
C++ Terminal style game inspired by Starcraft I and II gameplay and my love of the RTS genre as a whole.


### Requirements  
### TODO 
- [X] Drawing of map
- [ ] Have game draw structures on the map from an array
- [ ] Opposing players with bases that have associated health
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

A while loop will probaly sit there and listen seperate from cursor 
movement while the menu is up.

### Controls
Arrow keys - Movement of player's cursor 
B - Build a structure (Numbers to denote each structure in menu)
D - Destroy a structure 
U - While hovering over a structure that can create units, will bring
up a menu of units to spawn 
