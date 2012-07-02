//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================//

#ifndef SDK_CLIENTMODE_H
#define SDK_CLIENTMODE_H
#ifdef _WIN32
#pragma once
#endif

#include "clientmode_shared.h"
#include "sdkviewport.h"

class ClientModeSDKNormal : public ClientModeShared 
{
DECLARE_CLASS( ClientModeSDKNormal, ClientModeShared );

private:

// IClientMode overrides.
public:

					ClientModeSDKNormal();
	virtual			~ClientModeSDKNormal();

	virtual void	Init();
	virtual void	InitViewport();

	virtual float	GetViewModelFOV( void );

	int				GetDeathMessageStartHeight( void );

	virtual void	PostRenderVGui();

	void DoPostScreenSpaceEffects( const CViewSetup *pSetup );

	virtual bool	CanRecordDemo( char *errorMsg, int length ) const;

	virtual void	OverrideView( CViewSetup *pSetup );

	virtual void	Update( void );

	virtual void	Shutdown();

	virtual void	LevelInit( const char *newmap );

private:
	
	//	void	UpdateSpectatorMode( void );

};


extern IClientMode *GetClientModeNormal();
extern ClientModeSDKNormal* GetClientModeSDKNormal();


#endif // SDK_CLIENTMODE_H
