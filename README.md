# GSMetal
Goblin Sword cheat.
Please, dont pirate the game, consider buying in on appstore!
[Goblin Sword](https://apps.apple.com/en/app/goblin-sword/id905488045) on AppStore (en)
# Features
- Invincibility
- Always super attack
- Increased speed
- Endless jump
- No "on ice" effect
- Skeleton king boss stunned
# Known bugs
- Katar will show animation but will deal no damage after internal timer end - wait for super to finish and relaunch it, than it will deal damage again.
- Stardust blade will not grow when using endless super - collect orb to increase length.
- When app registered as system application the resolution will be broken, so it is really hard to use this on bootstrap from roothide. I recommend switching to rootless/rootful jailbreaks if possible.
# TODO
- Add stunning to other bosses
- Fix Katar bug
- Fix Stardust blade bug
- ???
# Credits
The following open-source software is used:
- [class-dump](https://github.com/nygard/class-dump): Used to get headers from application. 
# Building
Set up theos, download SDK(isnt it built-in sdk?) and simply run:
+ `make package` if you are on rootful
+ `make package THEOS_PACKAGE_SCHEME=rootless` if you are on rootless
+ `make package THEOS_PACKAGE_SCHEME=roothide` if you aare on roothide
# License
GNU GENERAL PUBLIC LICENSE Version 3. See the `LICENSE` file.