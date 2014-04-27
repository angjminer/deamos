// Copyright (C) 2004 Id Software, Inc.
//

#ifndef __GAME_TARGET_H__
#define __GAME_TARGET_H__


/*
===============================================================================

idTarget

===============================================================================
*/

class idTarget : public idEntity {
public:
	CLASS_PROTOTYPE( idTarget );
};


/*
===============================================================================

idTarget_Remove

===============================================================================
*/

class idTarget_Remove : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_Remove );

idTarget_Remove();

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_Show

===============================================================================
*/

class idTarget_Show : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_Show );

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_Damage

===============================================================================
*/

class idTarget_Damage : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_Damage );

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_SessionCommand

===============================================================================
*/

class idTarget_SessionCommand : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_SessionCommand );

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_EndLevel

===============================================================================
*/

class idTarget_EndLevel : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_EndLevel );

private:
	void				Event_Activate( idEntity *activator );

};


/*
===============================================================================

idTarget_WaitForButton

===============================================================================
*/

class idTarget_WaitForButton : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_WaitForButton );

	void				Think( void );

private:
	void				Event_Activate( idEntity *activator );
};

/*
===============================================================================

idTarget_SetGlobalShaderTime

===============================================================================
*/

class idTarget_SetGlobalShaderTime : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_SetGlobalShaderTime );

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_SetShaderParm

===============================================================================
*/

class idTarget_SetShaderParm : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_SetShaderParm );

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_SetShaderTime

===============================================================================
*/

class idTarget_SetShaderTime : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_SetShaderTime );

private:
	void				Event_Activate( idEntity *activator );
};

/*
===============================================================================

idTarget_FadeEntity

===============================================================================
*/

class idTarget_FadeEntity : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_FadeEntity );

						idTarget_FadeEntity( void );

	void				Save( idSaveGame *savefile ) const;
	void				Restore( idRestoreGame *savefile );

	void				Think( void );

private:
	idVec4				fadeFrom;
	int					fadeStart;
	int					fadeEnd;

	void				Event_Activate( idEntity *activator );
};

/*
===============================================================================

idTarget_LightFadeIn

===============================================================================
*/

class idTarget_LightFadeIn : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_LightFadeIn );

private:
	void				Event_Activate( idEntity *activator );
};

/*
===============================================================================

idTarget_LightFadeOut

===============================================================================
*/

class idTarget_LightFadeOut : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_LightFadeOut );

private:
	void				Event_Activate( idEntity *activator );
};

/*
===============================================================================

idTarget_Give

===============================================================================
*/

class idTarget_Give : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_Give );

	void				Spawn( void );

  void        Give( idPlayer *player );

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_GiveEmail

===============================================================================
*/

class idTarget_GiveEmail : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_GiveEmail );

	void				Spawn( void );
  enum {
    EVENT_GIVEEMAIL = idTarget::EVENT_MAXEVENTS,
    EVENT_MAXEVENTS
  };

  bool ClientReceiveEvent(int event,int time,const idBitMsg &msg);

private:
	void				Event_Activate( idEntity *activator );
};

/*
===============================================================================

idTarget_SetModel

===============================================================================
*/

class idTarget_SetModel : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_SetModel );

	void				Spawn( void );

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_SetInfluence

===============================================================================
*/

class idTarget_SetInfluence : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_SetInfluence );

						idTarget_SetInfluence( void );

	void				Save( idSaveGame *savefile ) const;
	void				Restore( idRestoreGame *savefile );

	void				Spawn( void );

  enum {
    EVENT_ACTIVATE = idTarget::EVENT_MAXEVENTS,
    EVENT_RESTORE,
    EVENT_CLEARFLASH,
    EVENT_FLASH,
    EVENT_MAXEVENTS
  };

  virtual void ClientPredictionThink();

  virtual bool ClientReceiveEvent(int event,int time,const idBitMsg &msg);


private:
	void				Event_Activate( idEntity *activator );
	void				Event_RestoreInfluence();
	void				Event_GatherEntities();
	void				Event_Flash( float flash, int out );
	void				Event_ClearFlash( float flash );
	void				Think( void );

	idList<int>			lightList;
	idList<int>			guiList;
	idList<int>			soundList;
	idList<int>			genericList;
	float				flashIn;
	float				flashOut;
	float				delay;
	idStr				flashInSound;
	idStr				flashOutSound;
	idEntity *			switchToCamera;
	idInterpolate<float>fovSetting;
	bool				soundFaded;
	bool				restoreOnTrigger;
};


/*
===============================================================================

idTarget_SetKeyVal

===============================================================================
*/

class idTarget_SetKeyVal : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_SetKeyVal );

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_SetFov

===============================================================================
*/

class idTarget_SetFov : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_SetFov );

	void				Save( idSaveGame *savefile ) const;
	void				Restore( idRestoreGame *savefile );

	void				Think( void );

private:
	idInterpolate<int>	fovSetting;

	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_SetPrimaryObjective

===============================================================================
*/

class idTarget_SetPrimaryObjective : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_SetPrimaryObjective );

  enum {
    EVENT_SETPRIMARYOBJ = idTarget::EVENT_MAXEVENTS,
    MAXEVENTS
  };

  idTarget_SetPrimaryObjective();

  virtual bool ClientReceiveEvent(int event, int time,const idBitMsg &msg);


private:
	void				Event_Activate( idEntity *activator );
};

/*
===============================================================================

idTarget_LockDoor

===============================================================================
*/

class idTarget_LockDoor: public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_LockDoor );

private:
	void				Event_Activate( idEntity *activator );
};

/*
===============================================================================

idTarget_CallObjectFunction

===============================================================================
*/

class idTarget_CallObjectFunction : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_CallObjectFunction );

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_LockDoor

===============================================================================
*/

class idTarget_EnableLevelWeapons : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_EnableLevelWeapons );

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_Tip

===============================================================================
*/

class idTarget_Tip : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_Tip );

						idTarget_Tip( void );

	void				Spawn( void );

	void				Save( idSaveGame *savefile ) const;
	void				Restore( idRestoreGame *savefile );

  enum {
    EVENT_TIP_ACTIVATE = idTarget::EVENT_MAXEVENTS,
    EVENT_MAXEVENTS
  };

  bool ClientReceiveEvent(int event,int time,const idBitMsg &msg);


private:
	idVec3				playerPos;

	void				Event_Activate( idEntity *activator );
	void				Event_TipOff( void );
	void				Event_GetPlayerPos( void );
};

/*
===============================================================================

idTarget_GiveSecurity

===============================================================================
*/
class idTarget_GiveSecurity : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_GiveSecurity );
  enum {
    EVENT_GIVESECURITY = idTarget::EVENT_MAXEVENTS,
    EVENT_MAXEVENTS
  };

  virtual bool ClientReceiveEvent(int event, int time, const idBitMsg &msg);

private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_RemoveWeapons

===============================================================================
*/
class idTarget_RemoveWeapons : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_RemoveWeapons );
private:
	void				Event_Activate( idEntity *activator );
};


/*
===============================================================================

idTarget_LevelTrigger

===============================================================================
*/
class idTarget_LevelTrigger : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_LevelTrigger );
private:
	void				Event_Activate( idEntity *activator );
};

/*
===============================================================================

idTarget_EnableStamina

===============================================================================
*/
class idTarget_EnableStamina : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_EnableStamina );
private:
	void				Event_Activate( idEntity *activator );
};

/*
===============================================================================

idTarget_FadeSoundClass

===============================================================================
*/
class idTarget_FadeSoundClass : public idTarget {
public:
	CLASS_PROTOTYPE( idTarget_FadeSoundClass );
private:
	void				Event_Activate( idEntity *activator );
	void				Event_RestoreVolume();
};


#endif /* !__GAME_TARGET_H__ */
