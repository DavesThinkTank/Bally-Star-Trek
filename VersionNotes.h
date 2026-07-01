/**************************************************************************

  This file is part of Bally Star Trek: Arduino Version

  The author of this program disclaims all copyright in order to make this 
  program freely available in perpetuity to anyone who would like to use 
  it. David McIntosh, 2025/04/19

  Bally Star Trek: Arduino Version is free software: you can redistribute 
  it and/or modify it under the terms of the GNU General Public License as 
  published by the Free Software Foundation, either version 3 of the License, 
  or (at your option) any later version.

  Bally Star Trek: Arduino Version is distributed in the hope that it will 
  be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
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
- If skill shot made with the A or B lane, and BALLY completed, and the ball ends before the skill shot fanfare ends, the photon torpedoes would not fire.
- A rare error, but one known to have occured in many Arduino pinballs, will cause all switches to fire simultaneously, causing problems during 
  attract mode, or sometimes during a game. Code has been added to capture these errors before they can cause any disruption.
*/


/**************************************************************************

Version 2025.12 by Dave's Think Tank

Changes / Additions:
- I have been told that it is an expected function of pinball machines that, if you press the game button during ball 2 of a game or later, the 
  game will end. I have implemented this. Pressing the game button will end your game, and send you into Attract Mode.
- You can now get into Kids' Mode by turning on the machine while holding the game button. Be sure to wait for the Kid Ming laugh.
- You can still switch between regular and Kids' Mode by pressing the game button and the coin slot 3 switch at the same time, during Attract mode. 
  However, it will no longer automatically put you into a game.

*/


/**************************************************************************

Version 2026.01 by Dave's Think Tank

Changes / Additions:
- Tried to use RPU_InitializeMPU to read game switch, but didn't seem to work.
- If in match mode, can no longer cancel game by pressing the game switch. Prevents impatient players from accidentally ending game before match awards.

Bug Fixes:
- BadSwitches: Fixed so that error data written in credit and match windows cannot be written over until attract mode ends. Removed unnecessary overwriting 
    lines from scrolling display code.
- SW_SAUCER during attract mode handled when switch hit, rather than while switch closed. Should ensure BadSwitches does not repeatedly pop the saucer.
  - Needed to add code to Setup() to add SW_SAUCER to switch stack if ball in saucer when machine turned on.
- SW_SAUCER during tilt modified to avoid solenoid activation more than once during ball bounce in saucer.

*/


/**************************************************************************

Version 2026.02 by Dave's Think Tank

Rule Change:
- A new one-ball challenge game has been added, based on the Kobayashi Maru test! There are now three one-ball challenges, which are activated by passing the three reward levels 
    set in the self-tests. If DIP switches 14 and 15 are set for an extra ball then completing each challenge will result in same player shoots again. 

Changes / Additions:
- Number of pushes (strength / length of time) for outhole increased from 4 to 5.
- Display test modified to allow showing only the value eight. Assists in finding missing segments, dim segments, burnt segments.
- Instructions for handling music files have been added to the Operator Game Adjustments.

Bug Fixes:
- Coin chute 2, coins per credit was always set to 1. Not true if set equal to chute 1 and chute 1 coins per credit not equal to 1. Fixed.
- Timing of concurrent solenoid firings reviewed, some minor modifications.
- Switches 14 and 15 set the awards for a number of playfield targets, and the three scoring thresholds. The three possibilities for scoring thresholds have been a free 
    game, extra ball, or 25000 points. The original manual specifies the awards should be free game, extra ball, or no award. The "No Award" option has been restored.

*/


/**************************************************************************

Version 2026.03 by Dave's Think Tank

Rule Change:

Changes / Additions:
- Programming added to turn left and right nacelle lights on during game. Assumes a CPR playfield with lamps hooked up to lights #11 (A5-J3-15) and 12 (A5-J1-23). See the 
    manual, "Adding nacelle lights".
- Added an Operator Game Adjustment value to set nacelle lights to a standard brightness throughout the game. 31 levels are available. 0, 1, and 2 are the most
    useful here, for setting both lights to off, bright, or dim.
- Light test modified to include nacelle light patterns. Since very few people (i.e. nobody but me) will have nacelle lights hooked up to lights #11 and 12, I have
    set it to default to, in general, never (or really seldom ever) show the nacelle light patterns. To show nacelle patterns, go to the light test, press the game button to
    count up to #11 or 12 (the nacelle lights), then press coin switch #3 repeatedly to go through all nacelle light patterns. Review all patterns (31 of them), or press
    game button to continue with usual light test.
- Ball search added. If no playfield switch is hit for 20 seconds, a ball search is conducted by firing all solenoids. If there is still no switch hit, tilt is turned
    off, and remains off until a playfield switch is hit. You have the option to disallow this by defining BALL_SEARCH_TILT to 0 in the Operator Game Adjustments.
- There is no longer any ball save for challenge rounds. This seems more in line with the idea that you are earning another ball.
- The amount of user intervention required to set up music files has been greatly reduced. Instead of requiring you to go to a different file, find lines of code, add comments
    to some and remove comments from others, the whole process is now handled as a single Operator Game Adjustment.
- A new "Challenge Mode" game has been added. In this game you are given three balls to defeat three challenges - beat the Klingons, stop the ship's self-destruct, and 
    save the Kobayashi Maru. Great for quick competitions! Three gameplay modes are now available - regular gameplay, Kids' Mode, and Challenge Mode.
- "Game Mode" is selected at the start of a new game by pressing and holding the game button, either during attract mode or before player 1 begins play. After holding the 
    button for one second, the credit window will begin scrolling the values 1, 2, and 3. Release the button on 1 for a regular game, 2 for kids' mode, or 3 for Challenge 
    Mode. This also resolves a problem where players would find out after starting a game that they were in Kids' Mode. When this happens just long-press the game button and
    select the game you wanted. Short-pressing the game button will still allow you to add more players for as long as you are on ball 1.
- Two methods of turning on kids' mode - holding the game button while turning on the machine, and pressing the game button and coin slot 3 switch at the same time, have both
    been removed. The new game mode selection handles this far better than either.

Bug Fixes:
- A bug fix last month was inadvertently left out of this documentation. See, "Switches 14 and 15..." under 2026.02 bug fixes.
- If the user did not have music files added to the WAV Trigger, the pinball would stop playing background sounds after the winning or losing sounds were played
    following a challenge ball. The background sounds were stopped, but when asked to restart them, the program saw the same file number and assumed it was already 
    playing! Fixed.
- Player shoots again light did not come on when a challenge threshold was achieved. This was actually a choice, but I now think it was the wrong choice! Lights now let
    you know that you are the next player up.
- If you reached the first threshold on your first ball, your B-A-L-L-Y lights would be reset and you would start over at 10000 for your first regular ball following the 
    challenge ball. Fixed.
- Challenge 1 and 2 would sometimes give you an extra 25000, in addition to an extra ball and same player shoots again. Fixed.
- If sound test ended on a background sound, sound would not end when DIP switch test began. Fixed.

*/



/**************************************************************************

Version 2026.04 by Dave's Think Tank

Rule Change:

Changes / Additions:
- In the Kobayashi Maru challenge, all the planet targets were flashing, and all the Klingon ships were flashing. It was too much flashing, even if every one of
    them was a target! Now, the five Klingons do not flash, but are lit dimly.
- Modified high score and other large-value self-test updates to include values for the three game modes.
- Updates of high score and other large values begins with 10 slow increases, instead of 6. Should aid in fine tuning to ultimate value.
- Modified code to fully distinguish between single click, double click, and long press of reset button. For example, previously a double click registered as
  a single click followed by a double click.
- Reviewed self-tests to ensure they all use the available buttons in a consistent manner, and as much as possible can be achieved with just the game button.
- Replaced use of coin 3 switch in self-tests with "any other switch". That is, hitting any switch other than the game, slam, or sef-test switch replaces the use of the coin 3 switch.

Bug Fixes:
- Ball in Play and credit lights did not come on during Challenge mode. fixed.
*/




/**************************************************************************

Version 2026.05 by Dave's Think Tank

Rule Change:

Changes / Additions:
- Countdown from 10 added to ladder during 60-second (Challenge Mode 2) and 15-second (Challenge Mode 3) timers. Reasoning: last ten seconds expresses urgency,
  full 60-seconds looks junky and difficult to interpret, full 15 goes off and on too often. Last ten seconds seems about right.
- Sound added to solenoid test. Beeps whenever a switch is detected.
- Sound added to stuck switch test. Beeps whenever a switch is hit.
- Sound added to switch bounce test. Beeps whenever a switch bounce is detected.
- Modified version display, included RPU version, to match Dick Hamill's version display.

Bug Fixes:
- When challenges earned, same player shoots again lights would sometimes go out when ball started. Now will stay on until shooter lane rollover crossed.
*/





/**************************************************************************

Version 2026.06 by Dave's Think Tank

Rule Change:

Changes / Additions:
- The letter you are shooting for in the skill shot will now flash in the word B-A-L-L-Y in the middle of the playfield. This ensures the letter you need
  to hit is flashing somewhere, and you can be absolutely sure what letter is required.
- After ball search, and while tilt is deactivated, the Tilt light will flash. Spock tells you "We may be here for a very long time."
- All sounds end when a new game begins. For anyone who has modified the end quote to play the TV show's end music!

Bug Fixes:
- If the outhole switch was set off by vibration, or any other reason during one of the challenges, the challenge would immediately end with an
  Enterprise explosion. Okay, this must be rare, but it happened to me! For any other time or circumstance, the ball generally has to be in the outhole
  for a half second before the program takes action. The end-of-game trigger for the challenges is now set up the same way.
*/


