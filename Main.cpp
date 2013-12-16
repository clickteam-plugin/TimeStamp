// ============================================================================
//
// This file are where the Conditions/Actions/Expressions are defined.
// You can manually enter these, or use CICK (recommended)
// See the Extension FAQ in this SDK for more info and where to download it
//
// ============================================================================

// Common Include
#include	"common.h"

// Quick memo: content of the eventInformations arrays
// ---------------------------------------------------
// Menu ID
// String ID
// Code
// Flags
// Number_of_parameters
// Parameter_type [Number_of_parameters]
// Parameter_TitleString [Number_of_parameters]

// Definitions of parameters for each condition
short conditionsInfos[]=
		{
		0
		};

// Definitions of parameters for each action
short actionsInfos[]=
		{
		0
		};

// Definitions of parameters for each expression
short expressionsInfos[]=
		{
		EID_GetTodayStamp,	EID_GetTodayStamp,	7,	0,	0,
		EID_GetTimeStamp,	EID_GetTimeStamp,	0,	0,	6,	EXPPARAM_LONG,	EXPPARAM_LONG,	EXPPARAM_LONG,	EXPPARAM_LONG,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_GetTimeStamp,	EP1ID_GetTimeStamp,	EP2ID_GetTimeStamp,	EP3ID_GetTimeStamp,	EP4ID_GetTimeStamp,	EP5ID_GetTimeStamp,
		EID_GetTimezone,	EID_GetTimezone,	17,	0,	0,

		EID_GetYearDiff,		EID_GetYearDiff,	20,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_GetYearDiff,	EP1ID_GetYearDiff,
		EID_GetMonthDiff,		EID_GetMonthDiff,	21,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_GetMonthDiff,	EP1ID_GetMonthDiff,
		EID_GetDayDiff,			EID_GetDayDiff,		22,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_GetDayDiff,	EP1ID_GetDayDiff,
		EID_GetHoursDiff,		EID_GetHoursDiff,	23,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_GetHoursDiff,	EP1ID_GetHoursDiff,
		EID_GetMinutesDiff,		EID_GetMinutesDiff,	24,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_GetMinutesDiff,	EP1ID_GetMinutesDiff,
		EID_GetSecondsDiff,		EID_GetSecondsDiff,	25,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_GetSecondsDiff,	EP1ID_GetSecondsDiff,

		EID_GetYear,		EID_GetYear,		1,	0,	1,	EXPPARAM_LONG,	EP0ID_GetYear,
		EID_GetMonth,		EID_GetMonth,		2,	0,	1,	EXPPARAM_LONG,	EP0ID_GetMonth,
		EID_GetDay,			EID_GetDay,			3,	0,	1,	EXPPARAM_LONG,	EP0ID_GetDay,
		EID_GetHours,		EID_GetHours,		4,	0,	1,	EXPPARAM_LONG,	EP0ID_GetHours,
		EID_GetMinutes,		EID_GetMinutes,		5,	0,	1,	EXPPARAM_LONG,	EP0ID_GetMinutes,
		EID_GetSeconds,		EID_GetSeconds,		6,	0,	1,	EXPPARAM_LONG,	EP0ID_GetSeconds,
		EID_GetDayofWeek,	EID_GetDayofWeek,	8,	0,	1,	EXPPARAM_LONG,	EP0ID_GetDayofWeek,

		EID_AddYears,		EID_AddYears,		10,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_AddYears,	EP1ID_AddYears,
		EID_AddMonths,		EID_AddMonths,		11,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_AddMonths,	EP1ID_AddMonths,
		EID_AddWeeks,		EID_AddWeeks,		12,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_AddWeeks,	EP1ID_AddWeeks,
		EID_AddDays,		EID_AddDays,		13,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_AddDays,	EP1ID_AddDays,
		EID_AddHours,		EID_AddHours,		14,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_AddHours,	EP1ID_AddHours,
		EID_AddMinutes,		EID_AddMinutes,		15,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_AddMinutes,	EP1ID_AddMinutes,
		EID_AddSeconds,		EID_AddSeconds,		16,	0,	2,	EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_AddSeconds,	EP1ID_AddSeconds,

		EID_GetFullString,	EID_GetFullString,	9,	EXPFLAG_STRING,	1,	EXPPARAM_LONG, EP0ID_GetFullString,
		EID_GetYYYYMMDD,	EID_GetYYYYMMDD,	18,	EXPFLAG_STRING,	1,	EXPPARAM_LONG, EP0ID_GetYYYYMMDD,
		EID_GetHHMMSS,		EID_GetHHMMSS,		19,	EXPFLAG_STRING,	1,	EXPPARAM_LONG, EP0ID_GetHHMMSS,
		EID_GetAsText,		EID_GetAsText,		26,	EXPFLAG_STRING,	1,	EXPPARAM_LONG, EP0ID_GetAsText,
		EID_GetVal,			EID_GetVal,			27,	0,	1,	EXPPARAM_STRING, EP0ID_GetVal,
		};



// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================


// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================


// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================


long WINAPI DLLExport GetTodayStamp(LPRDATA rdPtr, long param1)
{
	__time64_t timestamp=_time64(0);
	if(timestamp>4294967294 || timestamp==-1)
		return -1;
	else
		return (long)timestamp;
}

long WINAPI DLLExport GetTimeStamp(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long p3=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long p4=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long p5=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long p6=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	tm datetime;
	datetime.tm_year=p1-1900;
	datetime.tm_mon=p2-1;
	datetime.tm_mday=p3;
	datetime.tm_hour=p4;
	datetime.tm_min=p5;
	datetime.tm_sec=p6;
	datetime.tm_isdst=-1;
	datetime.tm_wday=0;
	datetime.tm_yday=0;

	__time64_t timestamp=_mktime64(&datetime);
	if(timestamp>4294967294 || timestamp==-1)
		return -1;

	rdPtr->datetime=datetime;
	rdPtr->timestamp=(time_t)timestamp;
	return (time_t)timestamp;
}

long WINAPI DLLExport GetTimezone(LPRDATA rdPtr, long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	_tzset();
	float timezone=-_timezone/3600.0f;
	return *(long*)&timezone;
}

long WINAPI DLLExport GetYear(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return temptime->tm_year+1900;
	}
	return rdPtr->datetime.tm_year+1900;
}

long WINAPI DLLExport GetMonth(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return temptime->tm_mon+1;
	}
	return rdPtr->datetime.tm_mon+1;
}

long WINAPI DLLExport GetDay(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return temptime->tm_mday;
	}
	return rdPtr->datetime.tm_mday;
}

long WINAPI DLLExport GetHours(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return temptime->tm_hour;
	}
	return rdPtr->datetime.tm_hour;
}

long WINAPI DLLExport GetMinutes(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return temptime->tm_min;
	}
	return rdPtr->datetime.tm_min;
}

long WINAPI DLLExport GetSeconds(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return temptime->tm_sec;
	}
	return rdPtr->datetime.tm_sec;
}

long WINAPI DLLExport GetDayofWeek(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return temptime->tm_wday;
	}
	return rdPtr->datetime.tm_wday;
}

long WINAPI DLLExport AddYears(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *datetime=_localtime64(&timestamp);
		if(datetime==0)
            return -1;
		datetime->tm_year+=p2;
		datetime->tm_isdst=-1;
		timestamp=_mktime64(datetime);
		if(timestamp>4294967294 || timestamp==-1)
			return -1;
		rdPtr->datetime=*datetime;
		rdPtr->timestamp=p1;
		return (time_t)timestamp;
	}

	tm datetime;
	datetime=rdPtr->datetime;
	datetime.tm_year+=p2;
	//datetime.tm_isdst=-1;
	__time64_t timestamp=_mktime64(&datetime);
	if(timestamp>4294967294 || timestamp==-1)
		return -1;
	rdPtr->datetime=datetime;
	rdPtr->timestamp=(time_t)timestamp;
	return (time_t)timestamp;
}

long WINAPI DLLExport AddMonths(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		temptime->tm_mon+=p2;
		temptime->tm_isdst=-1;
		timestamp=_mktime64(temptime);
		if(timestamp>4294967294 || timestamp==-1)
			return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return (time_t)timestamp;
	}

	tm datetime;
	datetime=rdPtr->datetime;
	datetime.tm_mon+=p2;
	//datetime.tm_isdst=-1;
	__time64_t timestamp=_mktime64(&datetime);
	if(timestamp>4294967294 || timestamp==-1)
		return -1;
	rdPtr->datetime=datetime;
	rdPtr->timestamp=(time_t)timestamp;
	return (time_t)timestamp;
}

long WINAPI DLLExport AddWeeks(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		temptime->tm_mday+=7*p2;
		temptime->tm_isdst=-1;
		timestamp=_mktime64(temptime);
		if(timestamp>4294967294 || timestamp==-1)
			return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return (time_t)timestamp;
	}

	tm datetime;
	datetime=rdPtr->datetime;
	datetime.tm_mday+=7*p2;
	//datetime.tm_isdst=-1;
	__time64_t timestamp=_mktime64(&datetime);
	if(timestamp>4294967294 || timestamp==-1)
		return -1;
	rdPtr->datetime=datetime;
	rdPtr->timestamp=(time_t)timestamp;
	return (time_t)timestamp;
}

long WINAPI DLLExport AddDays(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		temptime->tm_mday+=p2;
		temptime->tm_isdst=-1;
		timestamp=_mktime64(temptime);
		if(timestamp>4294967294 || timestamp==-1)
			return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return (time_t)timestamp;
	}

	tm datetime;
	datetime=rdPtr->datetime;
	datetime.tm_mday+=p2;
	//datetime.tm_isdst=-1;
	__time64_t timestamp=_mktime64(&datetime);
	if(timestamp>4294967294 || timestamp==-1)
		return -1;
	rdPtr->datetime=datetime;
	rdPtr->timestamp=(time_t)timestamp;
	return (time_t)timestamp;
}

long WINAPI DLLExport AddHours(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		temptime->tm_hour+=p2;
		temptime->tm_isdst=-1;
		timestamp=_mktime64(temptime);
		if(timestamp>4294967294 || timestamp==-1)
			return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return (time_t)timestamp;
	}

	tm datetime;
	datetime=rdPtr->datetime;
	datetime.tm_hour+=p2;
//	datetime.tm_isdst=-1;
	__time64_t timestamp=_mktime64(&datetime);
	if(timestamp>4294967294 || timestamp==-1)
		return -1;
	rdPtr->datetime=datetime;
	rdPtr->timestamp=(time_t)timestamp;
	return (time_t)timestamp;
}

long WINAPI DLLExport AddMinutes(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		temptime->tm_min+=p2;
		temptime->tm_isdst=-1;
		timestamp=_mktime64(temptime);
		if(timestamp>4294967294 || timestamp==-1)
			return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return (time_t)timestamp;
	}

	tm datetime;
	datetime=rdPtr->datetime;
	datetime.tm_min+=p2;
//	datetime.tm_isdst=-1;
	__time64_t timestamp=_mktime64(&datetime);
	if(timestamp>4294967294 || timestamp==-1)
		return -1;
	rdPtr->datetime=datetime;
	rdPtr->timestamp=(time_t)timestamp;
	return (time_t)timestamp;
}

long WINAPI DLLExport AddSeconds(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1)
		return -1;

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		temptime->tm_sec+=p2;
		temptime->tm_isdst=-1;
		timestamp=_mktime64(temptime);
		if(timestamp>4294967294 || timestamp==-1)
			return -1;
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
		return (time_t)timestamp;
	}

	tm datetime;
	datetime=rdPtr->datetime;
	datetime.tm_sec+=p2;
//	datetime.tm_isdst=-1;
	__time64_t timestamp=_mktime64(&datetime);
	if(timestamp>4294967294 || timestamp==-1)
		return -1;
	rdPtr->datetime=datetime;
	rdPtr->timestamp=(time_t)timestamp;
	return (time_t)timestamp;
}

long WINAPI DLLExport GetFullString(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	rdPtr->rHo.hoFlags |= HOF_STRING;
	if(p1==-1)
		return (long)"Error: Invalid TimeStamp";

	__time64_t timestamp=(unsigned)p1;
	char* temp;
	if((temp=_ctime64(&timestamp))==0)
		return (long)"Error: Invalid TimeStamp";
	else
		return (long)temp;
}

long WINAPI DLLExport GetYYYYMMDD(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	rdPtr->rHo.hoFlags |= HOF_STRING;
	if(p1==-1)
		return (long)"Error: Invalid TimeStamp";

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
			return (long)"Error: Invalid TimeStamp";
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
	}

	static char temp[9]="YYYYMMDD";
	temp[0]=(rdPtr->datetime.tm_year>=100)?'2':'1';//(rdPtr->datetime.tm_year+1900>=2000)
	temp[1]='0'+(rdPtr->datetime.tm_year/100+9)%10;
	temp[2]='0'+(rdPtr->datetime.tm_year/10)%10;
	temp[3]='0'+rdPtr->datetime.tm_year%10;
	temp[4]='0'+(rdPtr->datetime.tm_mon+1)/10;
	temp[5]='0'+(rdPtr->datetime.tm_mon+1)%10;
	temp[6]='0'+rdPtr->datetime.tm_mday/10;
	temp[7]='0'+rdPtr->datetime.tm_mday%10;
	return (long)temp;
}

long WINAPI DLLExport GetAsText(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	rdPtr->rHo.hoFlags |= HOF_STRING;
	if(p1==-1)
		return (long)"Error: Invalid TimeStamp";

	static char temp[66]=""; //_i64toa docs say that it can never write more than 65 chars + null
	_i64toa((unsigned)p1, temp, 10);
	return (long)temp;
}

long WINAPI DLLExport GetVal(LPRDATA rdPtr, long param1)
{
	char* p1=(char*)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

	unsigned int temp = -1;
	temp = (unsigned int)_atoi64(p1);
	return (long)temp;
}

long WINAPI DLLExport GetHHMMSS(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	rdPtr->rHo.hoFlags |= HOF_STRING;
	if(p1==-1)
		return (long)"Error: Invalid TimeStamp";

	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
			return (long)"Error: Invalid TimeStamp";
		rdPtr->datetime=*temptime;
		rdPtr->timestamp=p1;
	}

	static char temp[7]="HHMMSS";
	temp[0]='0'+rdPtr->datetime.tm_hour/10;
	temp[1]='0'+rdPtr->datetime.tm_hour%10;
	temp[2]='0'+rdPtr->datetime.tm_min/10;
	temp[3]='0'+rdPtr->datetime.tm_min%10;
	temp[4]='0'+rdPtr->datetime.tm_sec/10;
	temp[5]='0'+rdPtr->datetime.tm_sec%10;
	return (long)temp;
}

long WINAPI DLLExport GetYearDiff(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1 || p2==-1)
		return -1;
	if(p1==p2)
		return 0;

	tm datetime;
	int year1;
	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		datetime=*temptime;
		year1=temptime->tm_year;
	}
	else
	{
		datetime=rdPtr->datetime;
		year1=datetime.tm_year;
	}

	int year2;
	if(p2!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p2;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		year2=temptime->tm_year;
	}
	else
		year2=rdPtr->datetime.tm_year;

	datetime.tm_year=year2;
	__time64_t timestamp1a=_mktime64(&datetime);
	if(timestamp1a==-1) // shouldn't happen
		return -1;

	if((unsigned)p1>(unsigned)p2)
		if(timestamp1a>=(__time64_t)(unsigned)p2)
			return year1-year2;
		else
			return year1-year2-1;
	else
		if(timestamp1a<=(__time64_t)(unsigned)p2)
			return year1-year2;
		else
			return year1-year2+1;
}

long WINAPI DLLExport GetMonthDiff(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1 || p2==-1)
		return -1;
	if(p1==p2)
		return 0;

	tm datetime;
	int mon1;
	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		datetime=*temptime;
		mon1=temptime->tm_mon;
	}
	else
	{
		datetime=rdPtr->datetime;
		mon1=datetime.tm_mon;
	}

	int year2, mon2;
	if(p2!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p2;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		year2=temptime->tm_year;
		mon2=temptime->tm_mon;
	}
	else
	{
		year2=rdPtr->datetime.tm_year;
		mon2=rdPtr->datetime.tm_mon;
	}

	datetime.tm_year=year2;
	datetime.tm_mon=mon2;
	__time64_t timestamp1a=_mktime64(&datetime);
	if(timestamp1a==-1) // shouldn't happen
		return -1;

	if((unsigned)p1>(unsigned)p2)
		if(timestamp1a>=(__time64_t)(unsigned)p2)
			return (mon1-mon2+12)%12;
		else
			return (mon1-mon2+11)%12;
	else
		if(timestamp1a<=(__time64_t)(unsigned)p2)
			return (mon1-mon2-12)%12;
		else
			return (mon1-mon2-11)%12;
}

long WINAPI DLLExport GetDayDiff(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	if(p1==-1 || p2==-1)
		return -1;
	if(p1==p2)
		return 0;

	tm datetime1;
	if(p1!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p1;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		datetime1=*temptime;
	}
	else
	{
		datetime1=rdPtr->datetime;
	}

	tm datetime2;
	if(p2!=rdPtr->timestamp)
	{
		__time64_t timestamp=(unsigned)p2;
		tm *temptime=_localtime64(&timestamp);
		if(temptime==0)
            return -1;
		datetime2=*temptime;
	}
	else
	{
		datetime2=rdPtr->datetime;
	}

	// move datetime1 into the same dst block as datetime2
	// alter the hour instead of the isdst setting because a negative
	// isdst makes it set the isdst instead of alter the hour.
	datetime1.tm_hour += datetime2.tm_isdst - datetime1.tm_isdst;
	_mktime64(&datetime1);

	// prepare a datetime that is datetime1's time and datetime 2's date
	tm datetime1a = datetime1;
	datetime1a.tm_year=datetime2.tm_year;
	datetime1a.tm_mon=datetime2.tm_mon;
	datetime1a.tm_mday=datetime2.tm_mday;

	__time64_t timestamp1a=_mktime64(&datetime1a);
	if(timestamp1a==-1) // shouldn't happen
		return -1;

	if((unsigned)p1>(unsigned)p2)
	{

		if(timestamp1a>=(__time64_t)(unsigned)p2)
		{
			if(datetime1.tm_mday<datetime2.tm_mday)
				datetime1a.tm_mon++;
			datetime1a.tm_mday=datetime1.tm_mday;
			if(_mktime64(&datetime1a)==-1)
				return -1; // shouldn't happen
			return datetime1a.tm_yday-datetime2.tm_yday;
		}
		else
		{
			if(datetime1.tm_mday<=datetime2.tm_mday)
				datetime1a.tm_mon++;
			datetime1a.tm_mday=datetime1.tm_mday;
			if(_mktime64(&datetime1a)==-1)
				return -1; // shouldn't happen
			return datetime1a.tm_yday-datetime2.tm_yday-1;
		}
	}
	else
	{
		if(timestamp1a<=(__time64_t)(unsigned)p2)
		{
			if(datetime1.tm_mday>datetime2.tm_mday)
				datetime1a.tm_mon--;
			datetime1a.tm_mday=datetime1.tm_mday;
			if(_mktime64(&datetime1a)==-1)
				return -1; // shouldn't happen
			return datetime1a.tm_yday-datetime2.tm_yday;
		}
		else
		{
			if(datetime1.tm_mday>=datetime2.tm_mday)
				datetime1a.tm_mon--;
			datetime1a.tm_mday=datetime1.tm_mday;
			if(_mktime64(&datetime1a)==-1)
				return -1; // shouldn't happen
			return datetime1a.tm_yday-datetime2.tm_yday+1;
		}
	}
}

long WINAPI DLLExport GetHoursDiff(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	__time64_t timestamp1 = (unsigned)p1;
	__time64_t timestamp2 = (unsigned)p2;
	return (long)(((timestamp1-timestamp2)/3600)%24);
}

long WINAPI DLLExport GetMinutesDiff(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	__time64_t timestamp1 = (unsigned)p1;
	__time64_t timestamp2 = (unsigned)p2;
	return (long)(((timestamp1-timestamp2)/60)%60);
}

long WINAPI DLLExport GetSecondsDiff(LPRDATA rdPtr, long param1)
{
	long p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	__time64_t timestamp1 = (unsigned)p1;
	__time64_t timestamp2 = (unsigned)p2;
	return (long)((timestamp1-timestamp2)%60);
}

// ----------------------------------------------------------
// Condition / Action / Expression jump table
// ----------------------------------------------------------
// Contains the address inside the extension of the different
// routines that handle the action, conditions and expressions.
// Located at the end of the source for convinience
// Must finish with a 0
//
long (WINAPI * ConditionJumps[])(LPRDATA rdPtr, long param1, long param2) = 
			{ 
			0
			};
	
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
			{
			0
			};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = 
			{     
			GetTimeStamp,
			GetYear,
			GetMonth,
			GetDay,
			GetHours,
			GetMinutes,
			GetSeconds,
			GetTodayStamp,
			GetDayofWeek,
			GetFullString,
			AddYears,
			AddMonths,
			AddWeeks,
			AddDays,
			AddHours,
			AddMinutes,
			AddSeconds,
			GetTimezone,
			GetYYYYMMDD,
			GetHHMMSS,
			GetYearDiff,
			GetMonthDiff,
			GetDayDiff,
			GetHoursDiff,
			GetMinutesDiff,
			GetSecondsDiff,
			GetAsText,
			GetVal,
			0
			};
