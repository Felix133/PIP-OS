# PIP-OS V7.1.0.8

##### Copyright 2075 RobCo

## Extracting Vault Boy Sprites

SWF files are extracted from the game, condition clips exist in `interfaces/components/conditionclips`. From the files in Fallout 76 there are both full colour and monochromatic versions, the latter have the `_mono` postfix. The `.swf` files are opened with JPEXS, each shape is exported as SVG and arranged in a sprite sheet with fixed width frames (120px), sprite sheets are then exported as transparent PNG and rendered using an `AnimatedSprite` in QML. When inspecting the body frames in JPEXS you can find the anchor point which is used for aligning the head elements, each body is a seperate SWF and then all of the heads are in the same SWF, each head needs alignment with the alignment points on the body frames.
