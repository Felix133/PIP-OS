# PIP-OS V7.1.0.8

##### Copyright 2075 RobCo

## Extracting Vault Boy Sprites

SWF files are extracted from the game, condition clips exist in `interfaces/components/conditionclips`. From the files in Fallout 76 there are both full colour and monochromatic versions, the latter have the `_mono` postfix. The `.swf` files are opened with JPEXS, ~~each shape is exported as SVG and arranged in a sprite sheet with fixed width frames (120px), sprite sheets are then exported as transparent PNG and rendered using an `AnimatedSprite` in QML. When inspecting the body frames in JPEXS you can find the anchor point which is used for aligning the head elements, each body is a seperate SWF and then all of the heads are in the same SWF, each head needs alignment with the alignment points on the body frames.~~

- open condition_body_x

- open condition_head

  - under shapes, pick the DefineShape for the required head status
  - right click and 'raw edit' and change shapeId to (2) and save
  - right click again and "copy to" to condition_body_x SWF, this should put the head into the slot 2

- under condition_body_x

  - objects are placed every 8th frame
  - on the PlaceObject2 (1) which is positioning the body, we need to center it so click it, click transform at the bottom, expand the 'move' categoy on the right, set to horizontal 65px, vertical 120px, and set to relative, this positions the body for the whole animation
  - do the above again for (2) labelled as (Head_mc) and use the same relative position of 65px and 120px
  - do the above again for the Head_mc of every 8th frame
  - previewing the animation now at the top level the whole animation should render in the middle of the zone with the head in the right position
  - under the 'others' category delete the setBackgroundColor resource, this should make the background transparent
  - right click the frames category and pick export selection and export as GIF

- load the GIF up in CompressOrDie (https://processing.compress-or-die.com/gif-process)
  - set the colors to 16, this should remove the duplicate frames and also squash the colors resulting in a ~95% smaller file
