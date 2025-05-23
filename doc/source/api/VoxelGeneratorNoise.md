# VoxelGeneratorNoise

Inherits: [VoxelGenerator](VoxelGenerator.md)

Voxel generator producing overhanging shapes using 3D noise.

## Properties: 


Type                                                                                      | Name                             | Default         
----------------------------------------------------------------------------------------- | -------------------------------- | ----------------
[ChannelId](VoxelBuffer.md#enumerations)                                                  | [channel](#i_channel)            | CHANNEL_SDF (1) 
[float](https://docs.godotengine.org/en/stable/classes/class_float.html)                  | [height_range](#i_height_range)  | 200.0           
[float](https://docs.godotengine.org/en/stable/classes/class_float.html)                  | [height_start](#i_height_start)  | -100.0          
[FastNoiseLite](https://docs.godotengine.org/en/stable/classes/class_fastnoiselite.html)  | [noise](#i_noise)                |                 
<p></p>

## Property Descriptions

### [ChannelId](VoxelBuffer.md#enumerations)<span id="i_channel"></span> **channel** = CHANNEL_SDF (1)

Channel into which the generator will produce voxel data. This depends on the type of meshing you need.

### [float](https://docs.godotengine.org/en/stable/classes/class_float.html)<span id="i_height_range"></span> **height_range** = 200.0

Range of altitudes within which the shape variations will be found. The higher this range, the more overhangs there will be.

Shapes will start at maximum density near the base of the shape (low probability to find air), and progressively loose density until it reaches maximum height.

### [float](https://docs.godotengine.org/en/stable/classes/class_float.html)<span id="i_height_start"></span> **height_start** = -100.0

Base of the shape. Everything below it will be filled with ground.

### [FastNoiseLite](https://docs.godotengine.org/en/stable/classes/class_fastnoiselite.html)<span id="i_noise"></span> **noise**

Noise used as density function. It is required for the generator to work.

_Generated on May 15, 2025_
