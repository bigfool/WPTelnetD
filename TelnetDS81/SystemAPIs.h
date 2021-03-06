#pragma once

#include "pch.h"

using namespace Platform;

namespace TelnetDS81
{
	//namespace CoreAPI 
	//{		
		public ref class ProcessInfo sealed{
			private:
				PROCESS_INFORMATION _info;
			internal:
				ProcessInfo(PROCESS_INFORMATION pInfo) ;
		};

		/*public ref class CETWLogging sealed{
		private:
			PROCESS_INFORMATION _info;
		public:
			CETWLogging();
		};*/

		public ref class DevProgramReg sealed
		{
			public:
				static int CreateProcess(String ^pCmdLine);
				static int GetLastError();
				static String^ DevProgramReg::GetCommandLine();
				static Array<String^>^ GetCps(bool pIncludeFirst);
				static bool TelnetExecuteCommand(String^ pCommandLine);
				static bool TelnetProcessConnection(int pSocket, String^ pWelcomeInfo);
				static int TelnetListenForOneConnection(int pPort, int* pSocket, int *pWsaError);
				static int TelnetConnectTo(String^ pIpAddress, int pPort,int *pSocket, int *pWsaError);
				static bool TelnetInitNetworking(int *pWsaError);
				static bool TelnetShutDownNetworking();
		};

		
	//};
};