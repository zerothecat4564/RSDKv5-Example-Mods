#ifndef OBJ_PBL_PLAYER_H
#define OBJ_PBL_PLAYER_H

#include "GameAPI/Game.h"

#if MANIA_USE_PLUS
// Object Class
typedef struct {
    RSDK_OBJECT
    uint16 aniFrames;
    uint16 unused1;
    Hitbox innerBox;
    Hitbox outerBox;
    uint16 sfxPlunger;
    uint16 jumpFrames;
    uint16 ballFrames;
    uint16 sceneIndex;
} ObjectPBL_Player;

// Modded Object Class
typedef struct {
    int32 touchPause;
} ModObjectPBL_Player;

// Entity Class
typedef struct {
    RSDK_ENTITY
    StateMachine(state);
    int32 timer;
    int32 angleX;
    int32 height;
    int32 unused1;
    int32 unused2;
    Matrix matRotate;
    Matrix matTranslate;
    Matrix matWorld;
    Matrix matNormal;
    StateMachine(stateInput);
    int32 controllerID;
    bool32 up;
    bool32 down;
    bool32 left;
    bool32 right;
    bool32 jumpPress;
    bool32 jumpHold; // completely unused, but probably pretty likely
    Animator animator;
} EntityPBL_Player;

// Object Struct
extern ObjectPBL_Player *PBL_Player;
extern ModObjectPBL_Player *Mod_PBL_Player;

// Standard Entity Events

// Public Functions
extern StateMachine(PBL_Player_Input_P1);

// Extra Entity Functions
bool32 PBL_Player_Input_P1_Hook(bool32 skippedState);

#endif

#endif //! OBJ_PBL_PLAYER_H
