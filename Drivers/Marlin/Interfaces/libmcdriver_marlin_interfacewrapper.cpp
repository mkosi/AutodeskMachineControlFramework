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

Abstract: This is an autogenerated C++ implementation file in order to allow easy
development of MC Driver Marlin 2.0. The functions in this file need to be implemented. It needs to be generated only once.

Interface version: 1.0.0

*/

#include "libmcdriver_marlin_abi.hpp"
#include "libmcdriver_marlin_interfaces.hpp"
#include "libmcdriver_marlin_interfaceexception.hpp"

#include <map>

using namespace LibMCDriver_Marlin::Impl;

LibMCDriver_MarlinResult handleLibMCDriver_MarlinException(IBase * pIBaseClass, ELibMCDriver_MarlinInterfaceException & Exception)
{
	LibMCDriver_MarlinResult errorCode = Exception.getErrorCode();

	if (pIBaseClass != nullptr)
		pIBaseClass->RegisterErrorMessage(Exception.what());

	return errorCode;
}

LibMCDriver_MarlinResult handleStdException(IBase * pIBaseClass, std::exception & Exception)
{
	LibMCDriver_MarlinResult errorCode = LIBMCDRIVER_MARLIN_ERROR_GENERICEXCEPTION;

	if (pIBaseClass != nullptr)
		pIBaseClass->RegisterErrorMessage(Exception.what());

	return errorCode;
}

LibMCDriver_MarlinResult handleUnhandledException(IBase * pIBaseClass)
{
	LibMCDriver_MarlinResult errorCode = LIBMCDRIVER_MARLIN_ERROR_GENERICEXCEPTION;

	if (pIBaseClass != nullptr)
		pIBaseClass->RegisterErrorMessage("Unhandled Exception");

	return errorCode;
}



/*************************************************************************************************************************
 Class implementation for Base
**************************************************************************************************************************/

/*************************************************************************************************************************
 Class implementation for Driver
**************************************************************************************************************************/
LibMCDriver_MarlinResult libmcdriver_marlin_driver_getname(LibMCDriver_Marlin_Driver pDriver, const LibMCDriver_Marlin_uint32 nNameBufferSize, LibMCDriver_Marlin_uint32* pNameNeededChars, char * pNameBuffer)
{
	IBase* pIBaseClass = (IBase *)pDriver;

	try {
		if ( (!pNameBuffer) && !(pNameNeededChars) )
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		std::string sName("");
		IDriver* pIDriver = dynamic_cast<IDriver*>(pIBaseClass);
		if (!pIDriver)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		bool isCacheCall = (pNameBuffer == nullptr);
		if (isCacheCall) {
			sName = pIDriver->GetName();

			pIDriver->_setCache (new ParameterCache_1<std::string> (sName));
		}
		else {
			auto cache = dynamic_cast<ParameterCache_1<std::string>*> (pIDriver->_getCache ());
			if (cache == nullptr)
				throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
			cache->retrieveData (sName);
			pIDriver->_setCache (nullptr);
		}
		
		if (pNameNeededChars)
			*pNameNeededChars = (LibMCDriver_Marlin_uint32) (sName.size()+1);
		if (pNameBuffer) {
			if (sName.size() >= nNameBufferSize)
				throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_BUFFERTOOSMALL);
			for (size_t iName = 0; iName < sName.size(); iName++)
				pNameBuffer[iName] = sName[iName];
			pNameBuffer[sName.size()] = 0;
		}
		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_gettype(LibMCDriver_Marlin_Driver pDriver, const LibMCDriver_Marlin_uint32 nTypeBufferSize, LibMCDriver_Marlin_uint32* pTypeNeededChars, char * pTypeBuffer)
{
	IBase* pIBaseClass = (IBase *)pDriver;

	try {
		if ( (!pTypeBuffer) && !(pTypeNeededChars) )
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		std::string sType("");
		IDriver* pIDriver = dynamic_cast<IDriver*>(pIBaseClass);
		if (!pIDriver)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		bool isCacheCall = (pTypeBuffer == nullptr);
		if (isCacheCall) {
			sType = pIDriver->GetType();

			pIDriver->_setCache (new ParameterCache_1<std::string> (sType));
		}
		else {
			auto cache = dynamic_cast<ParameterCache_1<std::string>*> (pIDriver->_getCache ());
			if (cache == nullptr)
				throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
			cache->retrieveData (sType);
			pIDriver->_setCache (nullptr);
		}
		
		if (pTypeNeededChars)
			*pTypeNeededChars = (LibMCDriver_Marlin_uint32) (sType.size()+1);
		if (pTypeBuffer) {
			if (sType.size() >= nTypeBufferSize)
				throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_BUFFERTOOSMALL);
			for (size_t iType = 0; iType < sType.size(); iType++)
				pTypeBuffer[iType] = sType[iType];
			pTypeBuffer[sType.size()] = 0;
		}
		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_getversion(LibMCDriver_Marlin_Driver pDriver, LibMCDriver_Marlin_uint32 * pMajor, LibMCDriver_Marlin_uint32 * pMinor, LibMCDriver_Marlin_uint32 * pMicro, const LibMCDriver_Marlin_uint32 nBuildBufferSize, LibMCDriver_Marlin_uint32* pBuildNeededChars, char * pBuildBuffer)
{
	IBase* pIBaseClass = (IBase *)pDriver;

	try {
		if (!pMajor)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (!pMinor)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (!pMicro)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if ( (!pBuildBuffer) && !(pBuildNeededChars) )
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		std::string sBuild("");
		IDriver* pIDriver = dynamic_cast<IDriver*>(pIBaseClass);
		if (!pIDriver)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		bool isCacheCall = (pBuildBuffer == nullptr);
		if (isCacheCall) {
			pIDriver->GetVersion(*pMajor, *pMinor, *pMicro, sBuild);

			pIDriver->_setCache (new ParameterCache_4<LibMCDriver_Marlin_uint32, LibMCDriver_Marlin_uint32, LibMCDriver_Marlin_uint32, std::string> (*pMajor, *pMinor, *pMicro, sBuild));
		}
		else {
			auto cache = dynamic_cast<ParameterCache_4<LibMCDriver_Marlin_uint32, LibMCDriver_Marlin_uint32, LibMCDriver_Marlin_uint32, std::string>*> (pIDriver->_getCache ());
			if (cache == nullptr)
				throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
			cache->retrieveData (*pMajor, *pMinor, *pMicro, sBuild);
			pIDriver->_setCache (nullptr);
		}
		
		if (pBuildNeededChars)
			*pBuildNeededChars = (LibMCDriver_Marlin_uint32) (sBuild.size()+1);
		if (pBuildBuffer) {
			if (sBuild.size() >= nBuildBufferSize)
				throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_BUFFERTOOSMALL);
			for (size_t iBuild = 0; iBuild < sBuild.size(); iBuild++)
				pBuildBuffer[iBuild] = sBuild[iBuild];
			pBuildBuffer[sBuild.size()] = 0;
		}
		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_getheaderinformation(LibMCDriver_Marlin_Driver pDriver, const LibMCDriver_Marlin_uint32 nNameSpaceBufferSize, LibMCDriver_Marlin_uint32* pNameSpaceNeededChars, char * pNameSpaceBuffer, const LibMCDriver_Marlin_uint32 nBaseNameBufferSize, LibMCDriver_Marlin_uint32* pBaseNameNeededChars, char * pBaseNameBuffer)
{
	IBase* pIBaseClass = (IBase *)pDriver;

	try {
		if ( (!pNameSpaceBuffer) && !(pNameSpaceNeededChars) )
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if ( (!pBaseNameBuffer) && !(pBaseNameNeededChars) )
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		std::string sNameSpace("");
		std::string sBaseName("");
		IDriver* pIDriver = dynamic_cast<IDriver*>(pIBaseClass);
		if (!pIDriver)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		bool isCacheCall = (pNameSpaceBuffer == nullptr) || (pBaseNameBuffer == nullptr);
		if (isCacheCall) {
			pIDriver->GetHeaderInformation(sNameSpace, sBaseName);

			pIDriver->_setCache (new ParameterCache_2<std::string, std::string> (sNameSpace, sBaseName));
		}
		else {
			auto cache = dynamic_cast<ParameterCache_2<std::string, std::string>*> (pIDriver->_getCache ());
			if (cache == nullptr)
				throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
			cache->retrieveData (sNameSpace, sBaseName);
			pIDriver->_setCache (nullptr);
		}
		
		if (pNameSpaceNeededChars)
			*pNameSpaceNeededChars = (LibMCDriver_Marlin_uint32) (sNameSpace.size()+1);
		if (pNameSpaceBuffer) {
			if (sNameSpace.size() >= nNameSpaceBufferSize)
				throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_BUFFERTOOSMALL);
			for (size_t iNameSpace = 0; iNameSpace < sNameSpace.size(); iNameSpace++)
				pNameSpaceBuffer[iNameSpace] = sNameSpace[iNameSpace];
			pNameSpaceBuffer[sNameSpace.size()] = 0;
		}
		if (pBaseNameNeededChars)
			*pBaseNameNeededChars = (LibMCDriver_Marlin_uint32) (sBaseName.size()+1);
		if (pBaseNameBuffer) {
			if (sBaseName.size() >= nBaseNameBufferSize)
				throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_BUFFERTOOSMALL);
			for (size_t iBaseName = 0; iBaseName < sBaseName.size(); iBaseName++)
				pBaseNameBuffer[iBaseName] = sBaseName[iBaseName];
			pBaseNameBuffer[sBaseName.size()] = 0;
		}
		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}


/*************************************************************************************************************************
 Class implementation for Driver_Marlin
**************************************************************************************************************************/
LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_connect(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin, const char * pCOMPort, LibMCDriver_Marlin_uint32 nBaudrate)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		if (pCOMPort == nullptr)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		std::string sCOMPort(pCOMPort);
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		pIDriver_Marlin->Connect(sCOMPort, nBaudrate);

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_disconnect(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		pIDriver_Marlin->Disconnect();

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_setabsolutepositioning(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin, bool bAbsolute)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		pIDriver_Marlin->SetAbsolutePositioning(bAbsolute);

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_updatestate(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		pIDriver_Marlin->UpdateState();

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_getcurrentposition(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin, LibMCDriver_Marlin_double * pX, LibMCDriver_Marlin_double * pY, LibMCDriver_Marlin_double * pZ)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		if (!pX)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (!pY)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (!pZ)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		pIDriver_Marlin->GetCurrentPosition(*pX, *pY, *pZ);

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_gettargetposition(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin, LibMCDriver_Marlin_double * pX, LibMCDriver_Marlin_double * pY, LibMCDriver_Marlin_double * pZ)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		if (!pX)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (!pY)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (!pZ)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		pIDriver_Marlin->GetTargetPosition(*pX, *pY, *pZ);

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_getextrudertemperature(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin, LibMCDriver_Marlin_uint32 nExtruderID, LibMCDriver_Marlin_double * pCurrentTemperature, LibMCDriver_Marlin_double * pTargetTemperature)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		if (!pCurrentTemperature)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (!pTargetTemperature)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		pIDriver_Marlin->GetExtruderTemperature(nExtruderID, *pCurrentTemperature, *pTargetTemperature);

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_canexecutemovement(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin, bool * pValue)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		if (pValue == nullptr)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		*pValue = pIDriver_Marlin->CanExecuteMovement();

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_ismoving(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin, bool * pValue)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		if (pValue == nullptr)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		*pValue = pIDriver_Marlin->IsMoving();

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_moveto(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin, LibMCDriver_Marlin_double dX, LibMCDriver_Marlin_double dY, LibMCDriver_Marlin_double dZ, LibMCDriver_Marlin_double dSpeed)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		pIDriver_Marlin->MoveTo(dX, dY, dZ, dSpeed);

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_driver_marlin_movefastto(LibMCDriver_Marlin_Driver_Marlin pDriver_Marlin, LibMCDriver_Marlin_double dX, LibMCDriver_Marlin_double dY, LibMCDriver_Marlin_double dZ, LibMCDriver_Marlin_double dSpeed)
{
	IBase* pIBaseClass = (IBase *)pDriver_Marlin;

	try {
		IDriver_Marlin* pIDriver_Marlin = dynamic_cast<IDriver_Marlin*>(pIBaseClass);
		if (!pIDriver_Marlin)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		pIDriver_Marlin->MoveFastTo(dX, dY, dZ, dSpeed);

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}



/*************************************************************************************************************************
 Function table lookup implementation
**************************************************************************************************************************/

LibMCDriver_MarlinResult LibMCDriver_Marlin::Impl::LibMCDriver_Marlin_GetProcAddress (const char * pProcName, void ** ppProcAddress)
{
	if (pProcName == nullptr)
		return LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM;
	if (ppProcAddress == nullptr)
		return LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM;
	*ppProcAddress = nullptr;
	std::string sProcName (pProcName);
	
	if (sProcName == "libmcdriver_marlin_driver_getname") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_getname;
	if (sProcName == "libmcdriver_marlin_driver_gettype") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_gettype;
	if (sProcName == "libmcdriver_marlin_driver_getversion") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_getversion;
	if (sProcName == "libmcdriver_marlin_driver_getheaderinformation") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_getheaderinformation;
	if (sProcName == "libmcdriver_marlin_driver_marlin_connect") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_connect;
	if (sProcName == "libmcdriver_marlin_driver_marlin_disconnect") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_disconnect;
	if (sProcName == "libmcdriver_marlin_driver_marlin_setabsolutepositioning") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_setabsolutepositioning;
	if (sProcName == "libmcdriver_marlin_driver_marlin_updatestate") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_updatestate;
	if (sProcName == "libmcdriver_marlin_driver_marlin_getcurrentposition") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_getcurrentposition;
	if (sProcName == "libmcdriver_marlin_driver_marlin_gettargetposition") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_gettargetposition;
	if (sProcName == "libmcdriver_marlin_driver_marlin_getextrudertemperature") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_getextrudertemperature;
	if (sProcName == "libmcdriver_marlin_driver_marlin_canexecutemovement") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_canexecutemovement;
	if (sProcName == "libmcdriver_marlin_driver_marlin_ismoving") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_ismoving;
	if (sProcName == "libmcdriver_marlin_driver_marlin_moveto") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_moveto;
	if (sProcName == "libmcdriver_marlin_driver_marlin_movefastto") 
		*ppProcAddress = (void*) &libmcdriver_marlin_driver_marlin_movefastto;
	if (sProcName == "libmcdriver_marlin_getversion") 
		*ppProcAddress = (void*) &libmcdriver_marlin_getversion;
	if (sProcName == "libmcdriver_marlin_getlasterror") 
		*ppProcAddress = (void*) &libmcdriver_marlin_getlasterror;
	if (sProcName == "libmcdriver_marlin_releaseinstance") 
		*ppProcAddress = (void*) &libmcdriver_marlin_releaseinstance;
	if (sProcName == "libmcdriver_marlin_acquireinstance") 
		*ppProcAddress = (void*) &libmcdriver_marlin_acquireinstance;
	if (sProcName == "libmcdriver_marlin_injectcomponent") 
		*ppProcAddress = (void*) &libmcdriver_marlin_injectcomponent;
	if (sProcName == "libmcdriver_marlin_getsymbollookupmethod") 
		*ppProcAddress = (void*) &libmcdriver_marlin_getsymbollookupmethod;
	if (sProcName == "libmcdriver_marlin_createdriver") 
		*ppProcAddress = (void*) &libmcdriver_marlin_createdriver;
	
	if (*ppProcAddress == nullptr) 
		return LIBMCDRIVER_MARLIN_ERROR_COULDNOTFINDLIBRARYEXPORT;
	return LIBMCDRIVER_MARLIN_SUCCESS;
}

/*************************************************************************************************************************
 Global functions implementation
**************************************************************************************************************************/
LibMCDriver_MarlinResult libmcdriver_marlin_getversion(LibMCDriver_Marlin_uint32 * pMajor, LibMCDriver_Marlin_uint32 * pMinor, LibMCDriver_Marlin_uint32 * pMicro)
{
	IBase* pIBaseClass = nullptr;

	try {
		if (!pMajor)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (!pMinor)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (!pMicro)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		CWrapper::GetVersion(*pMajor, *pMinor, *pMicro);

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_getlasterror(LibMCDriver_Marlin_Base pInstance, const LibMCDriver_Marlin_uint32 nErrorMessageBufferSize, LibMCDriver_Marlin_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError)
{
	IBase* pIBaseClass = nullptr;

	try {
		if ( (!pErrorMessageBuffer) && !(pErrorMessageNeededChars) )
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (pHasError == nullptr)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		IBase* pIBaseClassInstance = (IBase *)pInstance;
		IBase* pIInstance = dynamic_cast<IBase*>(pIBaseClassInstance);
		if (!pIInstance)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		std::string sErrorMessage("");
		*pHasError = CWrapper::GetLastError(pIInstance, sErrorMessage);

		if (pErrorMessageNeededChars)
			*pErrorMessageNeededChars = (LibMCDriver_Marlin_uint32) (sErrorMessage.size()+1);
		if (pErrorMessageBuffer) {
			if (sErrorMessage.size() >= nErrorMessageBufferSize)
				throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_BUFFERTOOSMALL);
			for (size_t iErrorMessage = 0; iErrorMessage < sErrorMessage.size(); iErrorMessage++)
				pErrorMessageBuffer[iErrorMessage] = sErrorMessage[iErrorMessage];
			pErrorMessageBuffer[sErrorMessage.size()] = 0;
		}
		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_releaseinstance(LibMCDriver_Marlin_Base pInstance)
{
	IBase* pIBaseClass = nullptr;

	try {
		IBase* pIBaseClassInstance = (IBase *)pInstance;
		IBase* pIInstance = dynamic_cast<IBase*>(pIBaseClassInstance);
		if (!pIInstance)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		CWrapper::ReleaseInstance(pIInstance);

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_acquireinstance(LibMCDriver_Marlin_Base pInstance)
{
	IBase* pIBaseClass = nullptr;

	try {
		IBase* pIBaseClassInstance = (IBase *)pInstance;
		IBase* pIInstance = dynamic_cast<IBase*>(pIBaseClassInstance);
		if (!pIInstance)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		CWrapper::AcquireInstance(pIInstance);

		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_injectcomponent(const char * pNameSpace, LibMCDriver_Marlin_pvoid pSymbolAddressMethod)
{
	IBase* pIBaseClass = nullptr;

	try {
		if (pNameSpace == nullptr)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		std::string sNameSpace(pNameSpace);
		
		bool bNameSpaceFound = false;
		
		if (sNameSpace == "LibMCDriverEnv") {
			if (CWrapper::sPLibMCDriverEnvWrapper.get() != nullptr) {
				throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_COULDNOTLOADLIBRARY);
			}
			CWrapper::sPLibMCDriverEnvWrapper = LibMCDriverEnv::CWrapper::loadLibraryFromSymbolLookupMethod(pSymbolAddressMethod);
			bNameSpaceFound = true;
		}
		
		if (!bNameSpaceFound)
			throw ELibMCDriver_MarlinInterfaceException(LIBMCDRIVER_MARLIN_ERROR_COULDNOTLOADLIBRARY);
		
		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_getsymbollookupmethod(LibMCDriver_Marlin_pvoid * pSymbolLookupMethod)
{
	IBase* pIBaseClass = nullptr;

	try {
		if (pSymbolLookupMethod == nullptr)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		*pSymbolLookupMethod = (void*)&LibMCDriver_Marlin::Impl::LibMCDriver_Marlin_GetProcAddress;
		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibMCDriver_MarlinResult libmcdriver_marlin_createdriver(const char * pName, const char * pType, LibMCDriverEnv_DriverEnvironment pDriverEnvironment, LibMCDriver_Marlin_Driver * pInstance)
{
	IBase* pIBaseClass = nullptr;

	try {
		if (pName == nullptr)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (pType == nullptr)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		if (pInstance == nullptr)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDPARAM);
		std::string sName(pName);
		std::string sType(pType);
		LibMCDriverEnv::PDriverEnvironment pIDriverEnvironment = std::make_shared<LibMCDriverEnv::CDriverEnvironment>(CWrapper::sPLibMCDriverEnvWrapper.get(), pDriverEnvironment);
		CWrapper::sPLibMCDriverEnvWrapper->AcquireInstance(pIDriverEnvironment.get());
		if (!pIDriverEnvironment)
			throw ELibMCDriver_MarlinInterfaceException (LIBMCDRIVER_MARLIN_ERROR_INVALIDCAST);
		
		IBase* pBaseInstance(nullptr);
		pBaseInstance = CWrapper::CreateDriver(sName, sType, pIDriverEnvironment);

		*pInstance = (IBase*)(pBaseInstance);
		return LIBMCDRIVER_MARLIN_SUCCESS;
	}
	catch (ELibMCDriver_MarlinInterfaceException & Exception) {
		return handleLibMCDriver_MarlinException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}


