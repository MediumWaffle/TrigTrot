# MalAarCal - Trig Trot
  
<!--Partners and contribution-->
## Malik Robinson, Aaron Jarnes, and Caleb Carter
### Contribution:
* Malik - Made the game loop, implimented the logic for a moving player. Made the Objects class. Fixed bugs where spikes dont spawn correctly. 
* Aaron - Managed workflow. Made character sprites and crouching sprites. Implimented audio for the game. 3 songs [intro](https://www.youtube.com/watch?v=EpWHqdy6Tug), [play](https://www.youtube.com/watch?v=Pb6KyewC_Vg), [dead](https://www.youtube.com/watch?v=hdflkAQ3Qv0). Made the Game class. 
* Caleb - Sprite manager. Made most of the sprites using [piskel](https://www.piskelapp.com). Added a timer for a score that counts up for the time spent in game.
  
<!--How to play-->
### How to play
* Start Screen
  * Press 'S' to go to change skins
  * Press 'Enter' to play the game
* Skin Select Screen
  * There are 6 skins to select from
  * Num1, Num2, Num3, Num4, Num5, Num6
  * Default, Psycho, Piggy, Ghost, Minecraft, Spiderman
* Game Screen
  * Press 'Space Bar' to jump over the spikes
  * Press 'Right Shift' to crouch under spikes
  * The score will count for the time you spent alive
* Death Screen
  * Press 'R' to restart at the menu
  * The final score will be shown after losing
  
<!--How to download, compile, and run the game-->
### How to run the game
1. Open the [Ubuntu](https://ubuntu.com/) terminal
2. Update the terminal
```
sudo apt-get update && sudo apt-get upgrade -y
```
3. Install the GNU compiler tools
```
sudo apt-get install build-essential gdb
```
4. Install git
```
sudo apt-get install git
```
5. Install SFML
```
sudo apt-get install libsfml-dev
```
6. Clone our repository
```
git clone https://github.com/MediumWaffle/MalAarCal.git TrigTrot
```
7. Change into our directory
```
cd TrigTrot
```
8. Compile our game
```
g++ *.cpp -o TrigTrot -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
```
9. Run the executable
```
./TrigTrot
```
  
<!--Screen Shots and explaining-->
## This is the menu, you can either play the game or go to skin select screen.  
![StartScreen][StS]  
## This is the skin select screen, you can chose 1-6 to pick out your favorite skin.  
![SkinScreen][SkS]  
## During the game you have to jump over and duck under spikes.  
![GameScreen][GS]  
## If you run into a spike, the game over screen will show your end score.  
![DeathScreen][DS]  
  
<!--What we would improve on-->
### What would we improve on?
* Malik:  
  * I would have the game over by checking the Rectangle boundrays instead of the x positions. This would have given up more freedom to move the obstacles.  
  * I would also like to have improved the jump to check for more conditions to prevent double jumping and flying.  
  * I would have liked to add more obstacles and some power ups and movement options.  
* Aaron:  
  * Some of the music doesn't line up with the bpm. I would have made the music a little more similar, and tried to add in transitions between songs to make it seem seamless. 
  * If I had more time, I would've made a death screen for every character skin instead of just the default
* Caleb:  
  * I want to learn more about art and work on my visual assets
  * I would like to learn more about SFML and work on my skills
  
### Personal High Scores
1. Caleb - 131.46  
2. Aaron - 97.44  
3. Malik - 65.32  


[StS]: https://cdn.discordapp.com/attachments/882030604437323827/1049812840292286484/Screenshot_20221206_022108.png
[SkS]: https://cdn.discordapp.com/attachments/882030604437323827/1049812210773401610/Screenshot_20221206_021455.png
[GS]: https://cdn.discordapp.com/attachments/882030604437323827/1049812211851337869/Screenshot_20221206_021626.png
[DS]: https://cdn.discordapp.com/attachments/882030604437323827/1049812212497264731/Screenshot_20221206_021647.png