/**************************************************************************

  This file is part of Bally Star Trek 2025 -  for the Arduino Mega 2560

  The author of this program disclaims all copyright in order to make this 
  program freely available in perpetuity to anyone who would like to use 
  it. David McIntosh, 2025/04/19

  Bally Star Trek 2025 is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Bally Star Trek 2025 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  See <https://www.gnu.org/licenses/>.

*/

/**************************************************************************

Bally Star Trek: Arduino Version 2025.04 by Dave's Think Tank

Documentation of the Project:
- Detailed document created covering all new rules, self tests, accounting values, game settings, DIP switches, and more!

Changes / Additions:

1. Major New Features:

- Added "Ball Save":
  - If ball scores less than 5000 points, or lasts less than 15 seconds, the ball is played over.

- Added Skill Shot:
  - Next required letter in the word "BALLY" flashes. If you hit it, you get 3000 additional points. 
  - Award is also doubled every time 10-point bumper is hit.
  - 10-point bumper advances letters as usual.
  - If no letter is flashing, you need to advance them to the next required letter in the word "BALLY".
  - Double points are awarded even if you miss the required letter. If the required letter is impossible, your skill shot becomes 
    to hit the 10-point rebound (two or more times if you can!) before landing in the saucer.

- Added two new mini-games:

- Mini-Game 1: Klingon Battle
  - Activated by reaching second score level. Receive one extra ball for the purpose of playing the mini-game.
  - Five standing targets represent Klingon ships. Earn 10,000 for hitting each one, plus 50,000 for defeating them all.

- Mini-Game 2: Auto-Destruct Sequence
  - Activated by reaching third score level. Receive one extra ball for the purpose of playing the mini-game.
  - Alien intruders have started the ship's auto-destruct sequence and it must be deactivated.
  - Hit four drop targets in 60 seconds to deactivate auto-destruct.
  - 12,500 points awarded for each drop target hit, plus 50,000 for hitting all four.
  - 60-second countdown timer can be viewed in the credit window.

- Added three new sound and light shows:

- Show #1: Fire Photon Torpedoes!
  - Spell "BALLY", and Captain Kirk will order helm to fire photon torpedoes.
  - Three photon torpedoes are fired from the Enterprise in a display of light and sound.

- Show #2: Fire All Phasers!
  - Earn the bonus by re-entering the shooter lane, or falling into the out hole.
  - Captain Kirk will order helm to fire all phasers.
  - Phasers are fired from the Enterprise in a display of light and sound, one, two, or three times, depending on multiple earned.

- Show #3: Computer... Working...
  - The match result is calculated by the Enterprise computer.
  - The computer announces it is "Working...", while random lights flash off and on, just like the original!

- Added "Kids' Mode":
  - Pressing the credit switch and coin 3 switch at the same time puts you into Kids' Mode. Sound cues let you know what mode you are in.
  - Kids' Mode is intended to be used for children or guests, to set the pinball to all easy DIP switch and self-test game settings.
  - Press the credit switch and coin 3 switches at the same time again to return to regular mode.
  - Turning the machine off will also end Kids' Mode.

2. Added DIP-switch variables to control the game as per the original Bally manual:
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

3. Many additional features were added to the Self-Test function:
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

4. Other Changes and Additions:
- Version number (2025.04) displayed at beginning of game in display #1 (2025) and credit display (04). This is the date I started working on
  the project. Future changes made by other programmers can use the same convention, with less worry about creating multiple versions with the
  same identifier.
- New sounds added, to work with a WAV Trigger board. Background music, sound effects, and voices.
- Gain (sort of like volume) control added to sounds. Defaults for background, sfx, and voices, plus an easy method to override.
- Attract Mode, added rotating planet lights.
- All scoring checked. Conforms with descriptions on playfield, and original game to the extent possible.
- Scrolling displays during attract mode.
- Flashing display to identify next player.

Bug Fixes:
- High scores of a million or more are now maintained, and displayed in the 6-digit displays(!) Previously, your score simply started over again
  at zero.

*/

/**************************************************************************

Version 2025.06 by Dave's Think Tank

Changes / Additions:
- Light show added to Enterprise explosions and mini-game winners in Mini Games 1 and 2
- Lamp self-test has been extended to include six light shows from the game - photon torpedoes, phasers, Enterprise explosions, mini-game winner lights,
    Enterprise computer "Working..." (match), attract mode lights

Bug Fixes:
- Under some circumstances, B, A, L, L, or Y scored during photon torpedoes was being displayed at the switch but not in the middle BALLY lights.
*/

/**************************************************************************

Version 2025.09 by Dave's Think Tank

Changes / Additions:
- Coin lockout and K1 flipper relay have been added to the solenoid self-test.
- Slingshot sound changed to transporter, at regular volume.
- Reduced gain on "Fire all phasers" to sfx gain.
- Self-destruct timer starts at 60 when mini-game begins (rather than blank for 1.7 seconds). Flashes when game ends, to give you some sense of how you did.
- When bonus scored, points awarded will flash in the credit window. Since bonus ladder used for light show, this allows you to know how many points were won.
- When BALLY scored, points awarded will flash in the credit window. No reason, other than consistency with the bonus score!
*/

/**************************************************************************

Version 2025.10 by Dave's Think Tank

Rule Change:
- Previously if you won a mini-game, the flippers would be disabled, the ball would end, and the ball number would advance. If this was your last ball, the game
  would end. Now if you win a mini-game, and you have selected a threshold award of "extra ball" with the MPU DIP switches, the same happens except you are given
  same player shoots again.

Changes / Additions:
- Added ability to modify score values one digit at a time in self-test.
- improved timing of lights / scrolled values / knockers / voices for match sequence.
- Skillshot score will now display for a minimum of two seconds when you hit A or B. Skillshot score still displays for five seconds in the saucer.
- Music continues following skillshot fanfare, rather than restarting.
- Reviewed, and fixed as necessary, timing of light patterns, displays, music, and saucer kickout for A, B, and saucer, when hit during skillshot or otherwise, 
  when skillshot made or not, after finding the previous two updates were not as simple as I had expected them to be! All seem to work well again.

Bug Fixes:
- The code was not using RPU_OS_USE_WAV_TRIGGER or RPU_OS_USE_WAV_TRIGGER_1p3 appropriately. It was basically set up to always use 1p3. Fixed.
- If a mini-game score was zero, the ball number would not advance. Fixed.
- A rare error, but one known to have occured in many Arduino pinballs, will cause all switches to fire simultaneously, causing problems during 
  attract mode, or sometimes during a game. Code has been added to capture these errors before they can cause any disruption.
*/
