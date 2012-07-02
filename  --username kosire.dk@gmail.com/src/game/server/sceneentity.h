//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//
#ifndef SCENEENTITY_H
#define SCENEENTITY_H
#ifdef _WIN32
#pragma once
#endif

// List of the last 5 lines of speech from NPCs for bug reports
#define SPEECH_LIST_MAX_SOUNDS	5


struct recentNPCSpeech_t
{
	float	time;
	char	name[ 512 ];
	char	sceneName[ 128 ];
};

int GetRecentNPCSpeech( recentNPCSpeech_t speech[ SPEECH_LIST_MAX_SOUNDS ] );
float InstancedScriptedScene( CBaseFlex *pActor, const char *pszScene,  EHANDLE *phSceneEnt = NULL, float flPostDelay = 0.0f, bool bIsBackground = false, AI_Response *response = NULL, bool bMultiplayer = false, IRecipientFilter *filter = NULL );
float InstancedAutoGeneratedSoundScene( CBaseFlex *pActor, char const *soundname, EHANDLE *phSceneEnt = NULL );
void StopScriptedScene( CBaseFlex *pActor, EHANDLE hSceneEnt );
void RemoveActorFromScriptedScenes( CBaseFlex *pActor, bool instancedscenesonly, bool nonidlescenesonly = false, const char *pszThisSceneOnly = NULL );
void PauseActorsScriptedScenes( CBaseFlex *pActor, bool instancedscenesonly );
void ResumeActorsScriptedScenes( CBaseFlex *pActor, bool instancedscenesonly );
void QueueActorsScriptedScenesToResume( CBaseFlex *pActor, bool instancedscenesonly );
bool IsRunningScriptedScene( CBaseFlex *pActor, bool bIgnoreInstancedScenes = true );
bool IsRunningScriptedSceneAndNotPaused( CBaseFlex *pActor, bool bIgnoreInstancedScenes = true );
bool IsRunningScriptedSceneWithSpeech( CBaseFlex *pActor, bool bIgnoreInstancedScenes = false );
bool IsRunningScriptedSceneWithSpeechAndNotPaused( CBaseFlex *pActor, bool bIgnoreInstancedScenes = false );
float GetSceneDuration( char const *pszScene );
int GetSceneSpeechCount( char const *pszScene );
bool IsInInterruptableScenes( CBaseFlex *pActor );

void PrecacheInstancedScene( char const *pszScene );
HSCRIPT ScriptCreateSceneEntity( char const *pszScene );

char const *GetSceneFilename( CBaseEntity *ent );
void ReloadSceneFromDisk( CBaseEntity *ent );


#endif // SCENEENTITY_H
