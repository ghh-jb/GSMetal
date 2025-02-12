#include "header.h"
#include "SkeletonKing.h"
#include <substrate.h>
#include "GameObject.h"

%hook CCSprite
- (BOOL)isFrameDisplayed:(id)arg1 {
     return true;
}
%end

%hook GameObject
- (void)createLifeBar:(id)arg1 {
    MSHookIvar<float>(self, "life") = 100.0;
    MSHookIvar<float>(self, "maxlife") = 100.0;
     %orig;
}
%end

%hook CCDirectorIOS
- (BOOL)enableRetinaDisplay:(BOOL)arg1 {
     return true;
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

%hook Player
//- (void)makeVulnerable {
//     return;
//} - DEPRECATED
// ==== PROPERTIES ====

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
     return true;
}



- (BOOL)mfilocked {
     return false;
}

- (BOOL)toBounce {
     return false;
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



- (void)shotEnded {
     //BOOL backup = self.onGround;
     self.onGround = false;
     %orig;
     //self.onGround = backup;
}


- (void)swordAttack {
     NSLog(@"[GS] %i",MSHookIvar<int>(self, "weapontype"));
     //BOOL backup = self.onGround;
     self.onGround = false;
     %orig;
}

%end

%hook GameLayer
- (void)onEnter {
     %orig;
     MSHookIvar<BOOL>(self, "showEnemyHealth") = true;
     MSHookIvar<int>(self, "magicpoints") = MSHookIvar<int>(self, "maxmagicpoints");
}

- (void)createSpeechBox {
     return;
}
- (void)inLava {
     return;
}
- (void)attackButtonPressed:(id)arg1 {
     %orig;
     MSHookIvar<int>(self, "magicpoints") = MSHookIvar<int>(self, "maxmagicpoints");
}


%end

