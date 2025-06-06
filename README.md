# Bally Star Trek 2025
## Version 2025.04
## for the Arduino Mega 2560 Rev3

Re-imagined rules for Bally's 1979 Star Trek pinball machine. Implemented using the Retro Pin Upgrade (RPU), using a daughter card connected to the MPU's J5 connector. The card can be built yourself using instructions available online. I did not build mine myself and so cannot really advise you. The link to the original instructions is gone, but copies occasionally pop up online.

A safer option is to purchase a kit, or even a pre-built card. Both are available at:
https://pinside.com/pinball/shops/shop/1304-roygbev-pinball/13777-star-trek-arduino-upgrade-with-new-rules-and-sounds

### To use this code (more complete information is available in the manual):
* Download this zip file (Code > Download ZIP) or clone the repository to your hard drive.
* Unzip the ST2025p04 repository and make sure the parent folder is named: ST2025p04
* Download Arduino's IDE (Integrated Development Environment). And pay them a few bucks!
* Find ST2025p04.ino in your ST2025p04 folder, and open it with the Arduino IDE. Compile and upload to an Arduino Mega 2560 microcontroller.
* Attach the Arduino 2560 microcontroller, as part of the daughter card from above, to the J5 connector of your Flash Gordon pinball's MPU board.
* Sound files can be found at https://drive.google.com/drive/folders/175rKGxsXPs678i7x1qTePkK48J6tJLC7?usp=sharing 
* Copy and transfer the sound files to the micro SD card on your WAVTrigger.

### Adjustments on first startup
Be sure to review all self-test game settings as they may have defaulted to zero. See the included manual for a complete description of all settings.

### How to operate self-test / audit / game settings
- Inner coin door button: Enters self-test / audit mode and advances through sections
- Outer coin door game button: Can be used to control and direct some tests. See the included file StarTrek2025-04manual.pdf for a full explanation of the self-tests and game settings available.
- Coin 3 inner door switch: Some tests require the use of the right-most coin drop switch to modify or move between values. See the included manual for more information.
- Slam switch: The slam switch is located on the inside of the game door. It can be used to end a self-test session without going through all the tests. See the manual for more information.

### Version History
### Version 2025.04 by Dave's Think Tank

### Documentation of the Project:
- Detailed document created covering all new rules, self tests, accounting values, game settings, DIP switches, and more!

### Changes / Additions:

### 1. Major New Features:

### - Added "Ball Save":
  - If ball scores less than 5000 points, or lasts less than 15 seconds, the ball is played over. Captain Kirk tells you to "Try again".

### - Added Skill Shot:
  - Next required letter in the word "BALLY" flashes. If you hit it, you get 3000 additional points. 
  - Award is also doubled every time 10-point bumper is hit.
  - 10-point bumper advances letters as usual.
  - If no letter is flashing, you need to advance them to the next required letter in the word "BALLY".
  - Double points are awarded even if you miss the required letter. If the required letter is impossible, your skill shot becomes 
    to hit the 10-point rebound (two or more times if you can!) before landing in the saucer.

### - Added two new mini-games:

### - Mini-Game 1: Klingon Battle
  - Activated by reaching second score level. Receive one extra ball for the purpose of playing the mini-game.
  - Five standing targets represent Klingon ships. Earn 10,000 for hitting each one, plus 50,000 for defeating them all.

### - Mini-Game 2: Auto-Destruct Sequence
  - Activated by reaching third score level. Receive one extra ball for the purpose of playing the mini-game.
  - Alien intruders have started the ship's auto-destruct sequence and it must be deactivated.
  - Hit four drop targets in 60 seconds to deactivate auto-destruct.
  - 12,500 points awarded for each drop target hit, plus 50,000 for hitting all four.
  - 60-second countdown timer can be viewed in the credit window.

### - Added three new sound and light shows:

### - Show #1: Fire Photon Torpedoes!
  - Spell "BALLY", and Captain Kirk will order helm to fire photon torpedoes.
  - Three photon torpedoes are fired from the Enterprise in a display of light and sound.

### - Show #2: Fire All Phasers!
  - Earn the bonus by re-entering the shooter lane, or falling into the out hole.
  - Captain Kirk will order helm to fire all phasers.
  - Phasers are fired from the Enterprise in a display of light and sound, one, two, or three times, depending on multiple earned.

### - Show #3: Computer... Working...
  - The match result is calculated by the Enterprise computer.
  - The computer announces it is "Working...", while random lights flash off and on, just like the original!

### - Added "Kids' Mode":
  - Pressing the credit switch and coin 3 switch at the same time puts you into Kids' Mode. Sound cues let you know what mode you are in.
  - Kids' Mode is intended to be used for children or guests, to set the pinball to all easy DIP switch and self-test game settings.
  - Press the credit switch and coin 3 switches at the same time again to return to regular mode.
  - Turning the machine off will also end Kids' Mode.

### 2. Added DIP-switch variables to control the game as per the original Bally manual:
- DIP switch 1-5, 9-13, 25-28: Set coins per credit, and credits per coin, for each coin chute. As per the original Bally manual (more or less!)
- DIP switch 6-7: High score to date award setting. As per the original manual.
- DIP switch 8: Ignored (previously handled chimes, tunes, and knocker sounds, but no longer relevant).
- DIP Switch 14-15: Playfield special awards, and scoring threshold awards (applied to scoring level 1 only. See mini-games below.) As per original manual.
- DIP Switch 16: Balls per game. As per original manual.
- DIP Switch 17-19: Maximum credits. As per original manual.
- DIP Switch 20: Number of credits to be displayed, yes or no. As per original manual.
- DIP Switch 21: Match feature on or off. As per original manual.
- DIP Switch 22: Hyperspace starting value. As per original manual.
- DIP Switch 23: BALLY special remains lit, yes or no. As per original manual.
- DIP Switch 24: Center target remains lit or alternates. As per original manual.
- DIP Switch 29: BALLY starts at 10,000 or 25,000. As per original manual.
- DIP Switch 30: Outlane special, both lanes lit or alternate. As per original manual.
- DIP Switch 31: Flipper feed lanes, both lit for hyperspace or alternate. As per original manual.
- DIP switch 32: Ignored (previously handled chimes, tunes, and knocker sounds, but no longer relevant).

### 3. Many additional features were added to the Self-Test function:
- Lamp test: Added ability to turn on one light at a time.
- Display test: Added ability to turn on a single digit at a time.
- Solenoid test: Added ability to operate a single solenoid, or turn all solenoids off without leaving the test program. Added ability to use flippers.
- Solenoid test: Added feature to warn you when vibration from solenoid is causing a switch to close.
- Stuck switch test: Added ability to view up to four stuck switches at once. Instructions in manual show how to use this to find switch matrix errors.
- Double-hit switch test added. Allows you to check if a switch is "bouncing", causing it to be scored more than once when hit.
- Sound test: Changed to allow cycling through all sounds. Features using game button allow skipping sounds, repeating sounds, fast forward through sounds.
- DIP-switch test added. Shows all DIP switch values. Allows you to temporarily change a DIP switch value, and see the effect in an actual game.
- Added options in self test for all accounting values to be increased, as well as zeroed.
- Added "Personal Goal" to self tests. This is used to provide two different "types" of end-of-game sounds, good or bad, depending on if you beat your personal goal or not.
- Background music / sounds off or on.
- Free play, off or on.
- Ball save options (number of ball saves per game, maximum score and time to activate ball save).
- Relative volume settings for background music, voices, and sound effects.

### 4. Other Changes and Additions:
- Version number (2025.04) displayed at beginning of game in display #1 (2025) and credit display (04). This is the date I started working on
  the project. Future changes made by other programmers can use the same convention, with less worry about creating multiple versions with the
  same identifier.
- New sounds added, to work with a WAV Trigger board. Background music, sound effects, and voices.
- Gain (sort of like volume) control added to sounds. Defaults for background, sfx, and voices, plus an easy method to override.
- Attract Mode, added rotating planet lights.
- All scoring checked. Conforms with descriptions on playfield, and original game to the extent possible.
- Scrolling displays during attract mode.
- Flashing display to identify next player.

### Bug Fixes:
- High scores of a million or more are now maintained, and displayed in the 6-digit displays(!) Previously, your score simply started over again
  at zero.
