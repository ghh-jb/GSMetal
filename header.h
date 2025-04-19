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

- (id)initWithWorld:(struct b2World *)arg1 atLocation:(struct CGPoint)arg2 withWeapon:(id)arg3;

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
     int enemiesKilled;

}
- (void)onExit;
- (void)onEnter;
- (void)createSpeechBox;

- (void)attackButtonPressed:(id)arg1;
- (void)inLava;
- (void)healEffect;
- (void)magicEffect;
- (void)toggleShield;
- (void)playerBeam;
- (void)gameover;
- (BOOL)checkPayment;
- (BOOL)checkTorches;
- (id)initWithHudLayer:(id)arg1;
- (void)initControls;
@end

@interface GameObject : CCSprite
{
    BOOL isActive;
    int gameObjectType;
    float life;
    float maxlife;
    int hpadjust;
    int direction;
    int scorepoints;
    BOOL hasDeathAnim;
    BOOL noVulnerable;
    BOOL isHarmless;
    BOOL phonex;
    int x_adjust;
}

@property(nonatomic) BOOL isHarmless;
@property(nonatomic) BOOL noVulnerable;
@property(nonatomic) int scorepoints;
@property(nonatomic) BOOL hasDeathAnim;
@property(nonatomic) int direction;
@property(nonatomic) int gameObjectType;
@property(nonatomic) BOOL isActive;
@property(nonatomic) float life;
- (void)dealloc;
- (void)updateLifeBar;
- (void)lifebarPos;
- (void)createLifeBar:(id)arg1;
- (void)stopflash;
- (void)startflash;
- (void)redFlash;
- (id)loadPlistForAnimationWithName:(id)arg1 andClassName:(id)arg2;
- (void)loadAnim:(id)arg1 andClassName:(id)arg2;
- (void)loadAnimWithDifName:(id)arg1 frameCount:(int)arg2 delay:(float)arg3 name2:(id)arg4;
- (void)loadAnimWithName:(id)arg1 frameCount:(int)arg2 delay:(float)arg3;
- (id)getAnim:(id)arg1;
- (void)updateStateWithDeltaTime:(double)arg1;
- (void)changeState:(int)arg1;
- (id)init;
@end

@interface SkeletonKing : NSObject
{
    int characterState;
    BOOL onPlatform;
    BOOL onEdge;
    BOOL shotFire;
    BOOL shotImps;
    BOOL filtered;
    int runs;
    int jumpattacks;
    int chargeattacks;
}

- (void)dealloc;
- (void)Imp3;
- (void)Imp2;
- (void)Imp1;
- (void)Impfx3;
- (void)Impfx2;
- (void)Impfx1;
- (void)spawnImps;
- (void)throwboomer;
- (void)shootFireballs;
- (void)novisible;
- (void)bossExplosion;
- (void)chooseAttack;
- (void)switchToIdle;
- (void)stopCharge;
- (void)trail;
- (void)startCharge;
- (void)changeState:(int)arg1;
- (void)charge;
- (void)updateStateWithDeltaTime:(double)arg1;
@end

@interface CCCacheValue : NSObject
{
    NSString *_fullpath;
    int _resolutionType;
}

@property(nonatomic) int resolutionType;
@property(retain, nonatomic) NSString *fullpath;
- (void)dealloc;
- (id)initWithFullPath:(id)arg1 resolutionType:(int)arg2;

@end

@interface MapLayer : NSObject
{
    NSUserDefaults *us;
    struct CGSize winSize;
    int pod;
    NSMutableArray *clouds;
    BOOL mfilocked;
    int mfitab;
    int mfitab2;
    int curmenu;
    BOOL astate;
    BOOL bstate;
    BOOL upstate;
    BOOL downstate;
    BOOL rightstate;
    BOOL leftstate;
    BOOL chap2unlocked;
    BOOL chap3unlocked;
    BOOL chap4unlocked;
    BOOL chap5unlocked;
    BOOL chap6unlocked;
    int levelsUnlocked;
    BOOL quake;
    int mapoffset;
    int mapmovement;
    BOOL lockscroll;
    BOOL isScrolled;
    int language;
    BOOL phonex;
    int y_adjust;
}
- (void)dealloc;
- (void)onExit;
- (void)onEnter;
- (void)onEnterTransitionDidFinish;
- (void)unpop;
- (void)topop;
- (void)replaceBackgroundMusic:(id)arg1 volume:(float)arg2;
- (void)loadanimationWithName:(id)arg1 frameCount:(int)arg2 delay:(float)arg3;
- (id)playAnim:(id)arg1;
- (void)unloadTextures;
- (void)play:(id)arg1;
- (void)house:(id)arg1;
- (void)shop:(id)arg1;
- (void)musicOff:(id)arg1;
- (void)soundOff:(id)arg1;
- (void)gotoAchiev:(id)arg1;
- (void)gotoLeader:(id)arg1;
- (void)gotoMenu:(id)arg1;
- (void)gotoControls:(id)arg1;
- (void)gotoCredits:(id)arg1;
- (void)hideLevels2;
- (void)hideLevels:(id)arg1;
- (void)gotoLevels2;
- (void)hideChapters3;
- (void)gotoLevels:(id)arg1;
- (void)fixBattleMenu;
- (void)fixLevelMenu;
- (void)hideChapters2;
- (void)hideChapters:(id)arg1;
- (void)gotoChapters2;
- (void)gotoChapters:(id)arg1;
- (void)startGame:(id)arg1;
- (void)moveclouds;
- (void)stopMap;
- (void)moveMap;
- (void)screenMove;
- (void)checkdungeon;
- (void)cityintroend;
- (void)stopShake;
- (void)mapShake;
- (void)screenShake;
- (void)disableScroll;
- (void)nothing:(id)arg1;
- (void)createBattleLevels;
- (void)createLevels;
- (void)createChapters;
- (void)tabchange3;
- (void)tabclean3;
- (void)tabchange2;
- (void)tabclean2;
- (void)scrollleft;
- (void)scrollveryright;
- (void)scrollright;
- (void)unlockscroll;
- (void)tabchange;
- (void)tabclean;
- (void)pressedRight;
- (void)pressedLeft;
- (void)pressedDown;
- (void)pressedUp;
- (void)pressedB;
- (void)pressedA;
- (void)mfisupport;
- (void)buttonUp:(int)arg1;
- (void)buttonDown:(int)arg1;
- (void)icadesupport;
- (void)createMapScroller;
- (id)init;

@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;

@end

@interface MagicOrb : NSObject
{
    struct b2World *world;
}
+ (id)sharedInstance;
- (id)initWithWorld:(struct b2World *)arg1 atLocation:(struct CGPoint)arg2 isDyn:(int)arg3;
@end

@interface Torch : NSObject
{
    struct CGPoint startpos;
    BOOL destroyed;
    BOOL canPutout;
}
- (void)dealloc;
- (void)updateStateWithDeltaTime:(double)arg1;
- (id)initWithWorld:(struct b2World *)arg1 atLocation:(struct CGPoint)arg2 active:(BOOL)arg3 isCandles:(BOOL)arg4;

@end


@interface Gem : NSObject
{
    struct b2World *world;
    struct CGPoint startpos;
    Player *player;
    int gemtype;
    int gemvalue;
    struct b2Fixture *mainSensorFixture;
    struct b2Fixture *colSensorFixture;
    int touchingwall;
}

@property(nonatomic) int touchingwall;
@property(nonatomic) int gemvalue;
- (void)dealloc;
- (void)activateCollision;
- (void)collisionCheck:(double)arg1;
- (void)followplayer;
- (void)updateStateWithDeltaTime:(double)arg1;
- (id)initWithWorld:(struct b2World *)arg1 atLocation:(struct CGPoint)arg2 isDyn:(int)arg3 withPlayer:(id)arg4 withType:(int)arg5;

@end


@interface HudLayer : NSObject
{
    struct CGSize winSize;
    BOOL isBlue;
    int hudgemCount;
    int crystalCount;
    int pod;
    NSMutableArray *playerEnergy;
    int ewidth;
    int maxbosslife;
    int mwidth;
    int maxmagic;
    NSMutableArray *splosions;
    unsigned int currentSplosion;
    int language;
    int x_adjust;
}
- (void)dealloc;
- (void)removeLayerColor:(id)arg1;
- (void)uiatmaflash;
- (void)uibossflash;
- (void)hideKey;
- (void)showKey;
- (void)darkLayer;
- (void)removeNode2:(id)arg1;
- (void)moveGem:(struct CGPoint)arg1;
- (void)hideHelp;
- (void)displayHelp:(int)arg1;
- (void)stopTint;
- (void)redtint;
- (void)startTint;
- (void)textEffect:(id)arg1;
- (BOOL)displayText:(id)arg1 andOnCompleteCallTarget:(id)arg2 selector:(SEL)arg3;
- (void)hidemagic;
- (void)magicbaroffset;
- (void)displayMagicEnergy:(float)arg1;
- (void)displayBossEnergy:(float)arg1;
- (void)displayEnergy:(float)arg1;
- (void)increaseEnergyCapacity;
- (void)displayAmmo:(int)arg1;
- (void)createCrystalDisplay:(int)arg1;
- (void)displayCrystals:(int)arg1;
- (void)displayGems:(int)arg1;
- (void)createMagicEnergy:(float)arg1 expanded:(BOOL)arg2;
- (void)createBossEnergy:(float)arg1;
- (void)displayHudTreasure2;
- (void)displayHudTreasure1;
- (void)createHudTreasures;
- (void)showBest;
- (void)hideBest;
- (void)displayBest:(double)arg1;
- (void)showTimer;
- (void)hideTimer;
- (void)displaySecs:(double)arg1;
- (id)init;

@end
