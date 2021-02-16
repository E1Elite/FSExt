
#include "pch.h"
#include <Syringe.h>
#include <Helpers/Macro.h>
#include "script_combo.h"

DEFINE_HOOK(4CD0E9, script_combo, 5)
{
	R->ESI(script_text);
	return 0x4CD0EE;
}

DEFINE_HOOK(4CD157, script_combo_size, 8)
{
	GET(int, pTextLocation, EBP);

	if (pTextLocation < script_max_count)
	{
		return 0x4CD0EE;
	}
	else
	{
		return 0x4CD15F;
	}
}

DEFINE_HOOK(4CB99A, script_details_text, 7)
{
	GET(int, pDetailsIndex, EAX);
	if (pDetailsIndex >= script_max_count)
	{
		pDetailsIndex = 0;
	}
	const char * pX = script_details[pDetailsIndex];
	R->EAX(pX);

	return 0x4CB9A1;
}

DEFINE_HOOK(4CA9FC, script_details_default, 7)
{
	GET(int, pDefaultIndex, EAX);
	if (pDefaultIndex >= script_max_count)
	{
		pDefaultIndex = 0;
	}
	const char * pY = script_details[pDefaultIndex];
	R->EDX(pY);

	return 0x4CAA03;
}

