#include "header.h"
#include <substrate.h> //for MSHookIVar
#include <os/log.h>

void my_nslog_internal(/*int priority, */const char *format, ...) {
     va_list args;
     va_start(args, format);
     /* === PRIORITY === */
     // 0 = Notice
     // 1 = Info
     // 2 = Debug
     // 3 = Error
     // 4 = Fault
     // Lets wait until idevicesyslog will support it...
     char buffer[256];
     vsnprintf(buffer, sizeof(buffer), format, args);
     os_log(OS_LOG_DEFAULT, "%{public}s", buffer);
     va_end(args);
     return;
}


int weapontype = -1337;
id orb_spawn = nil;
int crystals = 0;
BOOL treasure1 = false;
BOOL treasure2 = false; 
int weapon = 0;

%hook MapLayer
- (void)shop:(id)arg1 {
     %orig;
     my_nslog_internal("[GS] Shop: %s", [[arg1 description] UTF8String]);
}
- (void)house:(id)arg1 {
     %orig;
     my_nslog_internal("[GS] House: %s", [[arg1 description] UTF8String]);
}
// - (void)onEnter {
//      BOOL chap2unlocked = MSHookIvar<BOOL>(self, "chap2unlocked");
//      BOOL chap3unlocked = MSHookIvar<BOOL>(self, "chap3unlocked");
//      BOOL chap4unlocked = MSHookIvar<BOOL>(self, "chap4unlocked");
//      BOOL chap5unlocked = MSHookIvar<BOOL>(self, "chap5unlocked");
//      BOOL chap6unlocked = MSHookIvar<BOOL>(self, "chap6unlocked");
//      MSHookIvar<BOOL>(self, "chap2unlocked") = false;
//      MSHookIvar<BOOL>(self, "chap3unlocked") = false; 
//      MSHookIvar<BOOL>(self, "chap4unlocked") = false;
//      MSHookIvar<BOOL>(self, "chap5unlocked") = false;
//      MSHookIvar<BOOL>(self, "chap6unlocked") = false;
//      int levelsUnlocked = MSHookIvar<int>(self, "levelsUnlocked");
//      my_nslog_internal("[GS] 2:%i 3:%i 4:%i 5:%i 6:%i lvl:%i", chap2unlocked, chap3unlocked,chap4unlocked,chap5unlocked,chap6unlocked, levelsUnlocked);
//      %orig;
// }
%end


%hook CCCacheValue
- (id)initWithFullPath:(id)arg1 resolutionType:(int)arg2 {
     id ret = %orig(arg1, 1);
     // NSLog(@"[GS] Resolution:%i", arg2); 
     return ret;
}
%end


%hook CCDirectorIOS
- (BOOL)enableRetinaDisplay:(BOOL)arg1 {
     return true; //make good resolution always, hooked to test
}
%end

%hook SkeletonKing
- (void)chooseAttack {
     return;
}
- (void)stopCharge {
     return;
}
- (void)spawnImps {
     return;
}
- (void)throwboomer {
     return;
}
%end

%hook MagicOrb
%new
+ (id)sharedInstance { return 0; }

- (id)initWithWorld:(struct b2World *)arg1 atLocation:(struct CGPoint)arg2 isDyn:(int)arg3 {
     id ret = %orig;
     // my_nslog_internal("[GS] orb_init called isDyn:%i ret:%s", arg3, [[ret description] UTF8String]);
     return ret;
}
%end

%hook Player
//- (void)makeVulnerable {
//     return;
//} - DEPRECATED
// ==== PROPERTIES ====
- (int)onConveyor {
     return 0;
}

- (BOOL)isStunned {
     return true;
}

- (BOOL)onIce {
     return false;
}

- (BOOL)invincible {
     return true;
}

- (BOOL)shieldEnabled {
     return true; // but for what?...
}



- (BOOL)mfilocked {
     return false;
}

- (BOOL)toBounce {
     return false;
}

- (id)initWithWorld:(struct b2World *)arg1 atLocation:(struct CGPoint)arg2 withWeapon:(id)arg3 {
     id ret = %orig;
     // orb_spawn = [[%c(MagicOrb) sharedInstance] initWithWorld:arg1 atLocation:arg2 isDyn:2];
     // my_nslog_internal("[GS] orb_spawn returned: %s", [[orb_spawn description] UTF8String]);

     return ret;
}


 




- (void)processJump {
     BOOL backup = self.onGround;
     if (self.onGround == false) {
          self.onGround = true;
     }
     MSHookIvar<BOOL>(self, "canJump") = true;
     
     %orig;
     self.onGround = backup;
     MSHookIvar<float>(self, "playerspeed") = 10;
}

- (void)processTripleJump {
     BOOL backup = self.onGround;
     if (self.onGround == false) {
          self.onGround = true;
     }
     MSHookIvar<BOOL>(self, "canJump") = true;
     
     %orig;
     self.onGround = backup;
     MSHookIvar<float>(self, "playerspeed") = 10;
}

- (void)swordAttack {
     // int weapon = MSHookIvar<int>(self, "weapontype");
     if (weapontype == -1337) {
          weapontype = MSHookIvar<int>(self, "weapontype");
          my_nslog_internal("[GS] Weapontype [swordAttack]:%i",weapontype);

     }
     // MSHookIvar<int>(self, "weapontype") = weapon;
     // weapon = weapon + 1;
     

     
     self.onGround = false; // this, however causes some performance bugs but critiaclly needed
     %orig;
}

%end

%hook HudLayer
- (void)displayCrystals:(int)arg1 {
     return %orig(crystals);
}

- (void)displayGems:(int)arg1 {
     [self displayCrystals:3];
     [self displayHudTreasure2];
     [self displayHudTreasure1];
     return %orig;
}
%end


%hook GameLayer
- (void)onEnter {
     my_nslog_internal("[GS] Entered");
     MSHookIvar<int>(self, "crystalCount") = 3;
     crystals = 3;
     MSHookIvar<BOOL>(self, "Treasure1get") = true;
     MSHookIvar<BOOL>(self, "Treasure2get") = true;
     treasure1 = true;
     treasure2 = true; 
     %orig;
}

- (void)createSpeechBox {
     return;
}
/* === DEPRECATED === */ //arr not rreallyyy

- (void)attackButtonPressed:(id)arg1 {
     %orig;
     // NSLog(@"[GS] Weapontype [attackButtonPressed]: %i", weapontype);
     MSHookIvar<int>(self, "enemiesKilled") = 0;
     MSHookIvar<int>(self, "magicpoints") = MSHookIvar<int>(self, "maxmagicpoints") + 1;
}

- (BOOL)checkPayment {
     return true;
}

- (BOOL)checkTorches {
     return true;
}

- (void)initControls {
     %orig;
     MSHookIvar<int>(self, "magicpoints") = MSHookIvar<int>(self, "maxmagicpoints");
     MSHookIvar<BOOL>(self, "showEnemyHealth") = true;
}

%end

%hook Gem
- (int)gemvalue {
     return 100;
}
%end



%hook Gate
- (BOOL)nokey {
     return false;
}
- (BOOL)opengate {
     return true;
}
%end 




%ctor {
     my_nslog_internal("[GS] Hello from GSMetal cheat for Goblin Sword game!!!");
     my_nslog_internal("[GS] All logs marked with '[GS]' are logs of this dylib");
     my_nslog_internal("[GS] This is currently under development");
     my_nslog_internal("[GS] I(untether) am not responsible for any progress loss");
     my_nslog_internal("[GS] Licensed unger GNU GENERAL PUBLIC LICENSE V3");
     my_nslog_internal("[GS] Application is launching, have fun!");
     my_nslog_internal("[GS] ============");
}


