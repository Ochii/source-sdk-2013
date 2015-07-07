//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: SRM silenced submachinegun
//
//=============================================================================//

#include "cbase.h"

#ifdef CLIENT_DLL
	#include "c_hl2mp_player.h"
#else
	#include "hl2mp_player.h"
#endif

#include "weapon_hl2mpbase.h"

#ifdef CLIENT_DLL
#define CWeaponSRMSilenced C_WeaponSRMSilenced
#endif

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

class CWeaponSRMSilenced : public CWeaponHL2MPBase
{
public:
	DECLARE_CLASS( CWeaponSRMSilenced, CWeaponHL2MPBase );

	CWeaponSRMSilenced();

	DECLARE_NETWORKCLASS(); 
	DECLARE_PREDICTABLE();

	void	AddViewKick( void );

#ifndef CLIENT_DLL
	DECLARE_ACTTABLE();
#endif
	
private:
	CWeaponSRMSilenced( const CWeaponSRMSilenced & );
};

IMPLEMENT_NETWORKCLASS_ALIASED( WeaponSRMSilenced, DT_WeaponSRMSilenced )

BEGIN_NETWORK_TABLE( CWeaponSRMSilenced, DT_WeaponSRMSilenced )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CWeaponSRMSilenced )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( weapon_srms, CWeaponSRMSilenced );
PRECACHE_WEAPON_REGISTER(weapon_srms);

#ifndef CLIENT_DLL
acttable_t	CWeaponSRMSilenced::m_acttable[] = 
{
	{ ACT_HL2MP_IDLE,					ACT_HL2MP_IDLE_SMG1,					false },
	{ ACT_HL2MP_RUN,					ACT_HL2MP_RUN_SMG1,						false },
	{ ACT_HL2MP_IDLE_CROUCH,			ACT_HL2MP_IDLE_CROUCH_SMG1,				false },
	{ ACT_HL2MP_WALK_CROUCH,			ACT_HL2MP_WALK_CROUCH_SMG1,				false },
	{ ACT_HL2MP_GESTURE_RANGE_ATTACK,	ACT_HL2MP_GESTURE_RANGE_ATTACK_SMG1,	false },
	{ ACT_HL2MP_GESTURE_RELOAD,			ACT_HL2MP_GESTURE_RELOAD_SMG1,			false },
	{ ACT_HL2MP_JUMP,					ACT_HL2MP_JUMP_SMG1,					false },
	{ ACT_RANGE_ATTACK1,				ACT_RANGE_ATTACK_SMG1,					false },
};

IMPLEMENT_ACTTABLE(CWeaponSRMSilenced);
#endif

//=========================================================
CWeaponSRMSilenced::CWeaponSRMSilenced( )
{

}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CWeaponSRMSilenced::AddViewKick( void )
{
	#define	EASY_DAMPEN			0.5f
	#define	MAX_VERTICAL_KICK	1.0f	//Degrees
	#define	SLIDE_LIMIT			2.0f	//Seconds
	
	//Get the view kick
	CBasePlayer *pPlayer = ToBasePlayer( GetOwner() );

	if ( pPlayer == NULL )
		return;

	DoMachineGunKick( pPlayer, EASY_DAMPEN, MAX_VERTICAL_KICK, m_fFireDuration, SLIDE_LIMIT );
}