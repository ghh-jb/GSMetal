#include <Foundation/Foundation.h>
@interface CCSprite : NSObject
- (BOOL)isFrameDisplayed:(id)arg1;
@end
#include <UIKit/UIKit.h>
@interface CCDirectorIOS : UIViewController
- (BOOL)enableRetinaDisplay:(BOOL)arg1;
@end

@interface Player : NSObject
{
    BOOL canJump;
    BOOL toBounce;
    BOOL onPlatform;
    BOOL preventTouches;
    BOOL notMoving;
    BOOL isStunned;
    BOOL nearTreasure;
    BOOL onIce;
    BOOL stunfix;
    int weapontype;
    float weaponspeed;
    BOOL verticalAttack;
    BOOL invincible;
    BOOL canFire;
    float playerspeed;
    BOOL shadowsEnabled;
    BOOL tripleJump;
    BOOL moreInvincibility;
    BOOL glide;
    BOOL showWings;
    BOOL mfilocked;
    BOOL shieldEnabled;
}
@property(nonatomic) BOOL onIce;
@property(nonatomic) int shootMode;
@property(nonatomic) float fireCount;
@property(nonatomic) int dJumpcount;
@property(nonatomic) BOOL preventTouches;
@property(nonatomic) int onConveyor;
@property(nonatomic) BOOL invincible;
@property(nonatomic) BOOL notMoving;
@property(nonatomic) BOOL onPlatform;
@property(nonatomic) BOOL toBounce;
@property(nonatomic) BOOL onGround;

@property(readonly, nonatomic) BOOL dashPressed;
@property(readonly, nonatomic) BOOL attackPressed;
@property(readonly, nonatomic) BOOL jumpPressed;
@property(readonly, nonatomic) BOOL leftPressed;
@property(readonly, nonatomic) BOOL rightPressed;
@property(readonly, nonatomic) BOOL bobin;
- (void)endPower;
- (void)makeVulnerable;
- (void)shotEnded;
- (void)processTripleJump;
- (void)processJump;
- (void)stopInvi;
- (void)cleanAtma;
- (void)stopFiring;
- (void)extraShot;
- (void)swordAttack;




- (void)beginPower;
- (void)lockmfi;
- (void)mfijump;
- (void)togglePause;
- (void)mfireturn;
- (void)mfipause;
- (void)buttonUp:(int)arg1;
- (void)buttonDown:(int)arg1;
- (void)icadeclean;
- (void)icadereturn;
- (void)icadesupport;
@end





@interface GameLayer : NSObject
{
     int maxmagicpoints;
     int magicpoints;
     BOOL magnetEnabled;
     BOOL extraMagic;
     BOOL falconimproved;
     int gemCount;
     BOOL showEnemyHealth;

}
- (void)onEnter;
- (void)createSpeechBox;

- (void)attackButtonPressed:(id)arg1;
- (void)inLava;
- (void)healEffect;
- (void)magicEffect;
- (void)toggleShield;
- (void)playerBeam;
- (void)gameover;
@end