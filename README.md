# Click Picker (Geode mod for Geometry Dash)

Plays one of 20 click sounds on every jump, including during replay playback.
Choose the sound, volume and pitch variation in the mod's settings.

## Before building
- In mod.json change `id` ("yourname.click-picker") and `developer`.
- mod.json targets GD 2.2081 and Geode 5.x. Make sure your installed Geode is v5.0.0 or newer.

## Build locally (Windows)
1. Install the Geode CLI and SDK: https://docs.geode-sdk.org/getting-started/
2. `geode build` in this folder
3. Copy the resulting .geode into your GD `geode/mods` folder (or run `geode package install`).

## Build without a local toolchain
Push this folder to a GitHub repo. The included workflow builds it;
download the .geode from the Actions run's "Build Output" artifact.

## Swapping in your own sounds
Put .wav or .ogg files in resources/, add the file name (no extension) to the
`one-of` list in mod.json, and use .ogg's extension in main.cpp if needed.
