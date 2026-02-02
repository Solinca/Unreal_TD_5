# Unreal_TD_5

## Controls:

Z Q S D     -> Player Movement

Left Shift  -> Hold to run

E (hold)    -> Grab an interactable item if focused (white outline on the object)

Space       -> Jump

Escape      -> Trigger in game pause menu

Inputs are disabled on victory and during pause

## Puzzles

### First Puzzle: Lever

A simple constraint between the handle and the wall. The puzzle is considered complete when the lever goes beyond the middle point threshold.

Simply put a weight on it to complete the puzzle.

**Alternate solution: Interact with the lever and pull it down**

### Second Puzzle: Button

Another constraint between the button and the ground. The puzzle is considered complete for 2 seconds when the button is pressed.

Simply roll a ball down the alley and wait before the door until the ball press the button.

**Alternate solution: Balance the ball on top of the button, keeping it pressed "forever".**

### Third Puzzle: Scale

This one is the most complex. There is 3 constraints, one on each side and in the middle, to act as a scale.

The Output weight is randomized at start between 100kg and 1000kg. The input box weight is 100kg.

A pink box is 500kg, a yellow one is 200kg and a blue one is 50kg.

The puzzle is considered complete when the output weight and the input box are at the same level (nearly equal in Z axis)

To complete it, simply go little by little until you find the perfect balance.

**Alternate solution: Put a big weight right off the bat, and wait next to the door. Be careful, you may have a low amount of time to cross the door.**

## References

### Musics

Victory: https://pixabay.com/sound-effects/musical-victory-chime-366449/

### Sounds

Locked Door: https://pixabay.com/sound-effects/household-mortice-door-lock-being-locked-and-unlocked-95884/

Complete Puzzle: https://pixabay.com/sound-effects/technology-mistery-474083/
