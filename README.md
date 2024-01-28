
# so_long  

This is game engine-like, a simple graphics project. Uses minilibX as a graphic library. 
<div align="center">
  <img src=https://github.com/altintoprakali/so_long/blob/main/screenshots/Screenshot.png />
</div> 

Our player is a swimmer whose ship crashes into rocks. In the aftermath of a shipwreck against unforgiving rocks, our protagonist, an adept swimmer, faces a daunting challenge. Scattered in the turbulent waters are vital aid kits crucial for survival. Navigating treacherous currents and encountering marine obstacles, the swimmer dives into a race against time, he must skillfully collecting each aid kit. The distant island on the horizon becomes a beacon of hope, urging the swimmer to persevere through exhaustion. With crashing waves and the sun setting, the narrative unfolds in a suspenseful tale of resilience. The swimmer's journey is a gripping adventure, as they strive to collect every aid kit and return to the safety of the island, battling against the elements and the unknown depths of the open sea..
  
  
## Game rules  
- The game's executable works with only one argument, which is ".ber" files.
- ".ber" files are maps for the game and must only contain '1' (Walls), '0' (Background), 'P' (Player), 'E' (Exit), and 'C' (Collectables). Otherwise, you can't run the game.
- There can be only one player and exit on the map.
- The map must be surrounded by '1' (Walls).
- The map must be rectangular.
- You can't exit the game until you collect all collectables.
- The map must be finishable (All collectables can be collected by the player, and the exit can be reachable).
  

## Run the game

You must comppile mlx library separetly. To do so

```bash
    cd mlx/
    make
```
It's gives errors when compiles. Ignore them totaly normal. Besides mlx library has memory leaks so I recommend when checking leaks in your code use "system(leaks so_long)". 

Then you can compile the game
```bash
    cd ..
    make
```
or
```bash
    cd ..
    make bonus
```
Three options for map in my project. It's same for bonus and mandatory part. One of them is for error checking so it won't work or you can use your own map.
```bash
    ./so_long maps/map.ber
```
There is no enemy in my bonus. Thats mean it's a boring game. But I had fun while coding and drawing. I hope you inspired by.

  
