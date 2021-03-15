#pragma once
#include"ControllerAdministrator.h"
#include "UIcomun.h"

class UIAdministrator
{

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	UIAdministrator();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Menius this.  </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void meniu();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Optiunis this.  </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void optiuni();

private:
	ControllerAdministrator ctrl;

};
