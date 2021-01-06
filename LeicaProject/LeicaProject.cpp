// LeicaProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "com_pub.hpp"
#define NUM_OF_RETRIES 1  

int main()
{
	// include application headers 
	GRC_TYPE RetCode;
	BOOLE bOpenAndRunning = FALSE;
	// initialize GeoCOM  
	RetCode = COM_Init();
	if (RetCode == GRC_OK)
	{
		// open a connection to the TPS1200 instrument  
		RetCode = COM_OpenConnection(COM_1, COM_BAUD_19200,
			NUM_OF_RETRIES);
		if (RetCode == GRC_OK)
		{
			bOpenAndRunning = TRUE;
		}
	}
	// optionally set up other comm. parameters here  
	if (RetCode == GRC_OK)
	{
		// -- functionality of the application --  
		// here we just test if communication is up  
		RetCode = COM_NullProc();
		if (RetCode != GRC_OK)
		{
			// handle error  
		}
	}
	// close channel  
	if (bOpenAndRunning)
	{
		RetCode = COM_CloseConnection();
		if (RetCode != GRC_OK)
		{
			// handle error  
		}
	}
	// anytime finalize and reset GeoCOM  
	RetCode = COM_End();
	if (RetCode != GRC_OK)
	{
		// handle error  
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
