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
1. Open the (Ubuntu)[https://ubuntu.com/] terminal
2. Update the terminal
```
sudo apt-get update && sudo apt-get upgrade -y
```
3. Install the GNU compiler tools
```
sudo apt install build-essential gdb
```
4. Install git
```
sudo apt install git
```
5. Install SFML
```
sudo install libsfml-dev
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

[StS]: https://cdn.discordapp.com/attachments/882030604437323827/1049470906411536424/Screen_Shot_2022-12-05_at_3.38.18_PM.png
[SkS]: https://cdn.discordapp.com/attachments/882030604437323827/1049470906742882485/Screen_Shot_2022-12-05_at_3.38.26_PM.png
[GS]: https://cdn.discordapp.com/attachments/882030604437323827/1049470907116159106/Screen_Shot_2022-12-05_at_3.38.53_PM.png
[DS]: https://cdn.discordapp.com/attachments/882030604437323827/1049470907422363819/Screen_Shot_2022-12-05_at_3.39.00_PM.png