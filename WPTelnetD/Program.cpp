﻿// Main Entry Point for TelnetD
//

#include "pch.h"


#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include<string.h>
#include<vector>
#include<string>
#include "TelnetD.h"
#include "Connection.h"
#include "CommandProcessor.h"
#include "Commands.h"

#ifdef PHONE
#include<WPKernel.h>
#endif

int main(int args, char *argv[]){
	printf("WP8\n");
	int wsaError;
	if (!InitNetworking(&wsaError)) {
		printf("Failed to initialise networking (WSAError: %d)", wsaError);
		return 1;
	}

	SOCKET socket;

	if (ListenForOneConnection(27249, &socket, &wsaError,NULL)){
		printf("Failed to to accept connection (WSAError: %d)", wsaError);
		ShutDownNetworking();
		return 1;
	}

	string str = "Arguments:\n";
	for (int i = 0; i < args; i++){
		str += string(argv[i]) + " ";
		
	}
	
	ProcessConnection(socket,(char*)str.c_str());
	;

	ShutDownNetworking();	
}