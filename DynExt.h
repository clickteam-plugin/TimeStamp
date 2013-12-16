#ifndef __DynExt_h__
#define __DynExt_h__

// Make identifier
#define MAKEID(a,b,c,d) ((#@a << 24)|(#@b << 16)|(#@c << 8)|(#@d)) 

#define IS_SET(flags, flag) (((flags) & (flag)) ? true : false)
#define PACK_FLOAT(f) *((long*)&(f))
#define UNPACK_FLOAT(f) *((float*)&(f))

////
__inline rCom* getrCom(LPRO object)
{
	DWORD OEFlags = object->roHo.hoOEFlags;
	if(!IS_SET(OEFlags, OEFLAG_MOVEMENTS) && !IS_SET(OEFlags, OEFLAG_ANIMATIONS))
		return 0;

	return (rCom*)((__int8*)object + sizeof(headerObject));
}

__inline rMvt* getrMvt(LPRO object)
{
	DWORD OEFlags = object->roHo.hoOEFlags;
	if(!IS_SET(OEFlags, OEFLAG_MOVEMENTS))
		return 0;

	return (rMvt*)((__int8*)object + sizeof(headerObject) + sizeof(rCom));
}

__inline rAni* getrAni(LPRO object)
{
	DWORD OEFlags = object->roHo.hoOEFlags;
	if(!IS_SET(OEFlags, OEFLAG_ANIMATIONS))
		return 0;

	return (rAni*)((__int8*)object + sizeof(headerObject) + sizeof(rCom) +
		(IS_SET(OEFlags, OEFLAG_MOVEMENTS) ? sizeof(rMvt) : 0));
}

__inline rSpr* getrSpr(LPRO object)
{
	DWORD OEFlags = object->roHo.hoOEFlags;
	if(!IS_SET(OEFlags, OEFLAG_SPRITES))
		return 0;

	return (rSpr*)((__int8*)object + sizeof(headerObject) +
		((IS_SET(OEFlags, OEFLAG_MOVEMENTS) ||
		 IS_SET(OEFlags, OEFLAG_ANIMATIONS)) ? sizeof(rCom) : 0) +
		(IS_SET(OEFlags, OEFLAG_MOVEMENTS) ? sizeof(rMvt) : 0) +
		(IS_SET(OEFlags, OEFLAG_ANIMATIONS) ? sizeof(rAni) : 0));
}

__inline rVal* getrVal(LPRO object)
{
	DWORD OEFlags = object->roHo.hoOEFlags;
	if(!IS_SET(OEFlags, OEFLAG_VALUES))
		return 0;

	return (rVal*)((__int8*)object + sizeof(headerObject) +
		((IS_SET(OEFlags, OEFLAG_MOVEMENTS) ||
		 IS_SET(OEFlags, OEFLAG_ANIMATIONS)) ? sizeof(rCom) : 0) +
		(IS_SET(OEFlags, OEFLAG_MOVEMENTS) ? sizeof(rMvt) : 0) +
		(IS_SET(OEFlags, OEFLAG_ANIMATIONS) ? sizeof(rAni) : 0) +
		(IS_SET(OEFlags, OEFLAG_SPRITES) ? sizeof(rSpr) : 0));
}

////
__inline rCom* getrCom(headerObject* object)
{
	DWORD OEFlags = object->hoOEFlags;
	if(!IS_SET(OEFlags, OEFLAG_MOVEMENTS) && !IS_SET(OEFlags, OEFLAG_ANIMATIONS))
		return 0;

	return (rCom*)((__int8*)object + sizeof(headerObject));
}

__inline rMvt* getrMvt(headerObject* object)
{
	DWORD OEFlags = object->hoOEFlags;
	if(!IS_SET(OEFlags, OEFLAG_MOVEMENTS))
		return 0;

	return (rMvt*)((__int8*)object + sizeof(headerObject) + sizeof(rCom));
}

__inline rAni* getrAni(headerObject* object)
{
	DWORD OEFlags = object->hoOEFlags;
	if(!IS_SET(OEFlags, OEFLAG_ANIMATIONS))
		return 0;

	return (rAni*)((__int8*)object + sizeof(headerObject) + sizeof(rCom) +
		(IS_SET(OEFlags, OEFLAG_MOVEMENTS) ? sizeof(rMvt) : 0));
}

__inline rSpr* getrSpr(headerObject* object)
{
	DWORD OEFlags = object->hoOEFlags;
	if(!IS_SET(OEFlags, OEFLAG_SPRITES))
		return 0;

	return (rSpr*)((__int8*)object + sizeof(headerObject) +
		((IS_SET(OEFlags, OEFLAG_MOVEMENTS) ||
		 IS_SET(OEFlags, OEFLAG_ANIMATIONS)) ? sizeof(rCom) : 0) +
		(IS_SET(OEFlags, OEFLAG_MOVEMENTS) ? sizeof(rMvt) : 0) +
		(IS_SET(OEFlags, OEFLAG_ANIMATIONS) ? sizeof(rAni) : 0));
}

__inline rVal* getrVal(headerObject* object)
{
	DWORD OEFlags = object->hoOEFlags;
	if(!IS_SET(OEFlags, OEFLAG_VALUES))
		return 0;

	return (rVal*)((__int8*)object + sizeof(headerObject) +
		((IS_SET(OEFlags, OEFLAG_MOVEMENTS) ||
		 IS_SET(OEFlags, OEFLAG_ANIMATIONS)) ? sizeof(rCom) : 0) +
		(IS_SET(OEFlags, OEFLAG_MOVEMENTS) ? sizeof(rMvt) : 0) +
		(IS_SET(OEFlags, OEFLAG_ANIMATIONS) ? sizeof(rAni) : 0) +
		(IS_SET(OEFlags, OEFLAG_SPRITES) ? sizeof(rSpr) : 0));
}

#else
#ifdef WARNING_MULTI_INCLUDE
#pragma message(__FILE__ " included multiple times")
#endif
#endif
