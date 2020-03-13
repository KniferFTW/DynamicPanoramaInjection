# DynamicPanoramic

A Program used to edit Counter Strike's new Panorama UI

This method bypasses the crypto checks of code.pbin by injecting into the process and editing the zip file as it loads, but after the checks done with crypto by valve.

Please Ensure you load the DLL as soon as possable, the module MUST hook before CSGO parses the zip file else it will not work.

# Use:
in dllmain.cpp i have an example use of the code, all you have todo is

1. Create a std::vector of std::pairs with both params as std::strings, the first string in each pair is the position on the disk of the file to inject, the second is where you wish it to be placed inside the panorama zip.
2. Inject as CSGO starts. Injecting later will cause this not to work due to hooking the parsing of panorama.
3. Win.

# Notes:
If you wish to edit panorama you may wish to check out WesserEsser's github OR dump it yourself for latest version: https://github.com/WasserEsser/panorama

Currently outdated.
