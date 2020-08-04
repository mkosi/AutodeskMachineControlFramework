/*++

Copyright (C) 2020 Autodesk Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Autodesk Inc. nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 'AS IS' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AUTODESK INC. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


This file has been generated by the Automatic Component Toolkit (ACT) version 1.7.0-develop.

Abstract: This is an autogenerated C++-Header file in order to allow an easy
 use of MC Plugin Interface

Interface version: 1.0.0

*/

#ifndef __LIBMCPLUGIN_HEADER_CPP
#define __LIBMCPLUGIN_HEADER_CPP

#ifdef __LIBMCPLUGIN_EXPORTS
#ifdef _WIN32
#define LIBMCPLUGIN_DECLSPEC __declspec (dllexport)
#else // _WIN32
#define LIBMCPLUGIN_DECLSPEC __attribute__((visibility("default")))
#endif // _WIN32
#else // __LIBMCPLUGIN_EXPORTS
#define LIBMCPLUGIN_DECLSPEC
#endif // __LIBMCPLUGIN_EXPORTS

#include "libmcplugin_types.hpp"

#include "libmcenv_dynamic.hpp"

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************************************************************
 Class definition for Base
**************************************************************************************************************************/

/*************************************************************************************************************************
 Class definition for State
**************************************************************************************************************************/

/**
* executes the state.
*
* @param[in] pState - State instance.
* @param[in] pStateEnvironment - Environment of this state.
* @return error code or 0 (success)
*/
LIBMCPLUGIN_DECLSPEC LibMCPluginResult libmcplugin_state_execute(LibMCPlugin_State pState, LibMCEnv_StateEnvironment pStateEnvironment);

/*************************************************************************************************************************
 Class definition for StateFactory
**************************************************************************************************************************/

/**
* creates a state
*
* @param[in] pStateFactory - StateFactory instance.
* @param[in] pStateName - Name of state to be created.
* @param[out] pState - instance of the state.
* @return error code or 0 (success)
*/
LIBMCPLUGIN_DECLSPEC LibMCPluginResult libmcplugin_statefactory_createstate(LibMCPlugin_StateFactory pStateFactory, const char * pStateName, LibMCPlugin_State * pState);

/*************************************************************************************************************************
 Global functions
**************************************************************************************************************************/

/**
* retrieves the binary version of this library.
*
* @param[out] pMajor - returns the major version of this library
* @param[out] pMinor - returns the minor version of this library
* @param[out] pMicro - returns the micro version of this library
* @return error code or 0 (success)
*/
LIBMCPLUGIN_DECLSPEC LibMCPluginResult libmcplugin_getversion(LibMCPlugin_uint32 * pMajor, LibMCPlugin_uint32 * pMinor, LibMCPlugin_uint32 * pMicro);

/**
* Returns the last error recorded on this object
*
* @param[in] pInstance - Instance Handle
* @param[in] nErrorMessageBufferSize - size of the buffer (including trailing 0)
* @param[out] pErrorMessageNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pErrorMessageBuffer -  buffer of Message of the last error, may be NULL
* @param[out] pHasError - Is there a last error to query
* @return error code or 0 (success)
*/
LIBMCPLUGIN_DECLSPEC LibMCPluginResult libmcplugin_getlasterror(LibMCPlugin_Base pInstance, const LibMCPlugin_uint32 nErrorMessageBufferSize, LibMCPlugin_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError);

/**
* Releases shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
LIBMCPLUGIN_DECLSPEC LibMCPluginResult libmcplugin_releaseinstance(LibMCPlugin_Base pInstance);

/**
* Acquires shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
LIBMCPLUGIN_DECLSPEC LibMCPluginResult libmcplugin_acquireinstance(LibMCPlugin_Base pInstance);

/**
* Injects an imported component for usage within this component
*
* @param[in] pNameSpace - NameSpace of the injected component
* @param[in] pSymbolAddressMethod - Address of the SymbolAddressMethod of the injected component
* @return error code or 0 (success)
*/
LIBMCPLUGIN_DECLSPEC LibMCPluginResult libmcplugin_injectcomponent(const char * pNameSpace, LibMCPlugin_pvoid pSymbolAddressMethod);

/**
* Creates a main State factory.
*
* @param[in] pInstanceName - Name of instance to be created.
* @param[out] pInstance - New State Factory instance
* @return error code or 0 (success)
*/
LIBMCPLUGIN_DECLSPEC LibMCPluginResult libmcplugin_createstatefactory(const char * pInstanceName, LibMCPlugin_StateFactory * pInstance);

#ifdef __cplusplus
}
#endif

#endif // __LIBMCPLUGIN_HEADER_CPP

