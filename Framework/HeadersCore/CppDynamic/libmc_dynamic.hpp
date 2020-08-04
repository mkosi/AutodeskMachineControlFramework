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
 use of Machine Control library

Interface version: 1.0.0

*/

#ifndef __LIBMC_CPPHEADER_DYNAMIC_CPP
#define __LIBMC_CPPHEADER_DYNAMIC_CPP

#include "libmc_types.hpp"
#include "libmc_dynamic.h"

#include "libmcdata_dynamic.hpp"

#ifdef _WIN32
#include <windows.h>
#else // _WIN32
#include <dlfcn.h>
#endif // _WIN32
#include <string>
#include <memory>
#include <vector>
#include <exception>

namespace LibMC {

/*************************************************************************************************************************
 Forward Declaration of all classes
**************************************************************************************************************************/
class CWrapper;
class CBase;
class CAPIResponse;
class CMCContext;

/*************************************************************************************************************************
 Declaration of deprecated class types
**************************************************************************************************************************/
typedef CWrapper CLibMCWrapper;
typedef CBase CLibMCBase;
typedef CAPIResponse CLibMCAPIResponse;
typedef CMCContext CLibMCMCContext;

/*************************************************************************************************************************
 Declaration of shared pointer types
**************************************************************************************************************************/
typedef std::shared_ptr<CWrapper> PWrapper;
typedef std::shared_ptr<CBase> PBase;
typedef std::shared_ptr<CAPIResponse> PAPIResponse;
typedef std::shared_ptr<CMCContext> PMCContext;

/*************************************************************************************************************************
 Declaration of deprecated shared pointer types
**************************************************************************************************************************/
typedef PWrapper PLibMCWrapper;
typedef PBase PLibMCBase;
typedef PAPIResponse PLibMCAPIResponse;
typedef PMCContext PLibMCMCContext;


/*************************************************************************************************************************
 classParam Definition
**************************************************************************************************************************/

template<class T> class classParam {
private:
	const T* m_ptr;

public:
	classParam(const T* ptr)
		: m_ptr (ptr)
	{
	}

	classParam(std::shared_ptr <T> sharedPtr)
		: m_ptr (sharedPtr.get())
	{
	}

	LibMCHandle GetHandle()
	{
		if (m_ptr != nullptr)
			return m_ptr->GetHandle();
		return nullptr;
	}
};

/*************************************************************************************************************************
 Class ELibMCException 
**************************************************************************************************************************/
class ELibMCException : public std::exception {
protected:
	/**
	* Error code for the Exception.
	*/
	LibMCResult m_errorCode;
	/**
	* Error message for the Exception.
	*/
	std::string m_errorMessage;

public:
	/**
	* Exception Constructor.
	*/
	ELibMCException(LibMCResult errorCode, const std::string & sErrorMessage)
		: m_errorMessage("LibMC Error " + std::to_string(errorCode) + " (" + sErrorMessage + ")")
	{
		m_errorCode = errorCode;
	}

	/**
	* Returns error code
	*/
	LibMCResult getErrorCode() const noexcept
	{
		return m_errorCode;
	}

	/**
	* Returns error message
	*/
	const char* what() const noexcept
	{
		return m_errorMessage.c_str();
	}

};

/*************************************************************************************************************************
 Class CInputVector
**************************************************************************************************************************/
template <typename T>
class CInputVector {
private:
	
	const T* m_data;
	size_t m_size;
	
public:
	
	CInputVector( const std::vector<T>& vec)
		: m_data( vec.data() ), m_size( vec.size() )
	{
	}
	
	CInputVector( const T* in_data, size_t in_size)
		: m_data( in_data ), m_size(in_size )
	{
	}
	
	const T* data() const
	{
		return m_data;
	}
	
	size_t size() const
	{
		return m_size;
	}
	
};

// declare deprecated class name
template<typename T>
using CLibMCInputVector = CInputVector<T>;

/*************************************************************************************************************************
 Class CWrapper 
**************************************************************************************************************************/
class CWrapper {
public:
	
	CWrapper(void* pSymbolLookupMethod)
	{
		CheckError(nullptr, initWrapperTable(&m_WrapperTable));
		CheckError(nullptr, loadWrapperTableFromSymbolLookupMethod(&m_WrapperTable, pSymbolLookupMethod));
		
		CheckError(nullptr, checkBinaryVersion());
	}
	
	CWrapper(const std::string &sFileName)
	{
		CheckError(nullptr, initWrapperTable(&m_WrapperTable));
		CheckError(nullptr, loadWrapperTable(&m_WrapperTable, sFileName.c_str()));
		
		CheckError(nullptr, checkBinaryVersion());
	}
	
	static PWrapper loadLibrary(const std::string &sFileName)
	{
		return std::make_shared<CWrapper>(sFileName);
	}
	
	static PWrapper loadLibraryFromSymbolLookupMethod(void* pSymbolLookupMethod)
	{
		return std::make_shared<CWrapper>(pSymbolLookupMethod);
	}
	
	~CWrapper()
	{
		releaseWrapperTable(&m_WrapperTable);
	}
	
	inline void CheckError(CBase * pBaseClass, LibMCResult nResult);

	inline void GetVersion(LibMC_uint32 & nMajor, LibMC_uint32 & nMinor, LibMC_uint32 & nMicro);
	inline bool GetLastError(classParam<CBase> pInstance, std::string & sErrorMessage);
	inline void ReleaseInstance(classParam<CBase> pInstance);
	inline void AcquireInstance(classParam<CBase> pInstance);
	inline void InjectComponent(const std::string & sNameSpace, const LibMC_pvoid pSymbolAddressMethod);
	inline PMCContext CreateMCContext(classParam<LibMCData::CDataModel> pDataModel);

private:
	sLibMCDynamicWrapperTable m_WrapperTable;
	// Injected Components
	LibMCData::PWrapper m_pLibMCDataWrapper;

	
	LibMCResult checkBinaryVersion()
	{
		LibMC_uint32 nMajor, nMinor, nMicro;
		GetVersion(nMajor, nMinor, nMicro);
		if ( (nMajor != LIBMC_VERSION_MAJOR) || (nMinor < LIBMC_VERSION_MINOR) ) {
			return LIBMC_ERROR_INCOMPATIBLEBINARYVERSION;
		}
		return LIBMC_SUCCESS;
	}
	LibMCResult initWrapperTable(sLibMCDynamicWrapperTable * pWrapperTable);
	LibMCResult releaseWrapperTable(sLibMCDynamicWrapperTable * pWrapperTable);
	LibMCResult loadWrapperTable(sLibMCDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName);
	LibMCResult loadWrapperTableFromSymbolLookupMethod(sLibMCDynamicWrapperTable * pWrapperTable, void* pSymbolLookupMethod);

	friend class CBase;
	friend class CAPIResponse;
	friend class CMCContext;

};

	
/*************************************************************************************************************************
 Class CBase 
**************************************************************************************************************************/
class CBase {
public:
	
protected:
	/* Wrapper Object that created the class. */
	CWrapper * m_pWrapper;
	/* Handle to Instance in library*/
	LibMCHandle m_pHandle;

	/* Checks for an Error code and raises Exceptions */
	void CheckError(LibMCResult nResult)
	{
		if (m_pWrapper != nullptr)
			m_pWrapper->CheckError(this, nResult);
	}
public:
	/**
	* CBase::CBase - Constructor for Base class.
	*/
	CBase(CWrapper * pWrapper, LibMCHandle pHandle)
		: m_pWrapper(pWrapper), m_pHandle(pHandle)
	{
	}

	/**
	* CBase::~CBase - Destructor for Base class.
	*/
	virtual ~CBase()
	{
		if (m_pWrapper != nullptr)
			m_pWrapper->ReleaseInstance(this);
		m_pWrapper = nullptr;
	}

	/**
	* CBase::GetHandle - Returns handle to instance.
	*/
	LibMCHandle GetHandle() const
	{
		return m_pHandle;
	}
	
	friend class CWrapper;
};
	
/*************************************************************************************************************************
 Class CAPIResponse 
**************************************************************************************************************************/
class CAPIResponse : public CBase {
public:
	
	/**
	* CAPIResponse::CAPIResponse - Constructor for APIResponse class.
	*/
	CAPIResponse(CWrapper* pWrapper, LibMCHandle pHandle)
		: CBase(pWrapper, pHandle)
	{
	}
	
	inline LibMC_uint32 GetHTTPCode();
	inline std::string GetContentType();
	inline void GetData(std::vector<LibMC_uint8> & DataBuffer);
};
	
/*************************************************************************************************************************
 Class CMCContext 
**************************************************************************************************************************/
class CMCContext : public CBase {
public:
	
	/**
	* CMCContext::CMCContext - Constructor for MCContext class.
	*/
	CMCContext(CWrapper* pWrapper, LibMCHandle pHandle)
		: CBase(pWrapper, pHandle)
	{
	}
	
	inline void RegisterLibraryPath(const std::string & sLibraryName, const std::string & sLibraryPath);
	inline void ParseConfiguration(const std::string & sXMLString);
	inline void StartAllThreads();
	inline void TerminateAllThreads();
	inline void LoadClientPackage(const CInputVector<LibMC_uint8> & ZIPStreamBuffer);
	inline void Log(const std::string & sMessage, const eLogSubSystem eSubsystem, const eLogLevel eLogLevel);
	inline PAPIResponse HandleAPIGetRequest(const std::string & sURI);
	inline PAPIResponse HandleAPIPostRequest(const std::string & sURI, const CInputVector<LibMC_uint8> & BodyBuffer);
};
	
	/**
	* CWrapper::GetVersion - retrieves the binary version of this library.
	* @param[out] nMajor - returns the major version of this library
	* @param[out] nMinor - returns the minor version of this library
	* @param[out] nMicro - returns the micro version of this library
	*/
	inline void CWrapper::GetVersion(LibMC_uint32 & nMajor, LibMC_uint32 & nMinor, LibMC_uint32 & nMicro)
	{
		CheckError(nullptr,m_WrapperTable.m_GetVersion(&nMajor, &nMinor, &nMicro));
	}
	
	/**
	* CWrapper::GetLastError - Returns the last error recorded on this object
	* @param[in] pInstance - Instance Handle
	* @param[out] sErrorMessage - Message of the last error
	* @return Is there a last error to query
	*/
	inline bool CWrapper::GetLastError(classParam<CBase> pInstance, std::string & sErrorMessage)
	{
		LibMCHandle hInstance = pInstance.GetHandle();
		LibMC_uint32 bytesNeededErrorMessage = 0;
		LibMC_uint32 bytesWrittenErrorMessage = 0;
		bool resultHasError = 0;
		CheckError(nullptr,m_WrapperTable.m_GetLastError(hInstance, 0, &bytesNeededErrorMessage, nullptr, &resultHasError));
		std::vector<char> bufferErrorMessage(bytesNeededErrorMessage);
		CheckError(nullptr,m_WrapperTable.m_GetLastError(hInstance, bytesNeededErrorMessage, &bytesWrittenErrorMessage, &bufferErrorMessage[0], &resultHasError));
		sErrorMessage = std::string(&bufferErrorMessage[0]);
		
		return resultHasError;
	}
	
	/**
	* CWrapper::ReleaseInstance - Releases shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	inline void CWrapper::ReleaseInstance(classParam<CBase> pInstance)
	{
		LibMCHandle hInstance = pInstance.GetHandle();
		CheckError(nullptr,m_WrapperTable.m_ReleaseInstance(hInstance));
	}
	
	/**
	* CWrapper::AcquireInstance - Acquires shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	inline void CWrapper::AcquireInstance(classParam<CBase> pInstance)
	{
		LibMCHandle hInstance = pInstance.GetHandle();
		CheckError(nullptr,m_WrapperTable.m_AcquireInstance(hInstance));
	}
	
	/**
	* CWrapper::InjectComponent - Injects an imported component for usage within this component
	* @param[in] sNameSpace - NameSpace of the injected component
	* @param[in] pSymbolAddressMethod - Address of the SymbolAddressMethod of the injected component
	*/
	inline void CWrapper::InjectComponent(const std::string & sNameSpace, const LibMC_pvoid pSymbolAddressMethod)
	{
		CheckError(nullptr,m_WrapperTable.m_InjectComponent(sNameSpace.c_str(), pSymbolAddressMethod));
		
		bool bNameSpaceFound = false;
		if (sNameSpace == "LibMCData") {
			if (m_pLibMCDataWrapper != nullptr) {
				throw ELibMCException(LIBMC_ERROR_COULDNOTLOADLIBRARY, "Library with namespace " + sNameSpace + " is already registered.");
			}
			m_pLibMCDataWrapper = LibMCData::CWrapper::loadLibraryFromSymbolLookupMethod(pSymbolAddressMethod);
			bNameSpaceFound = true;
		}
		if (!bNameSpaceFound)
			throw ELibMCException(LIBMC_ERROR_COULDNOTLOADLIBRARY, "Unknown namespace " + sNameSpace);
	}
	
	/**
	* CWrapper::CreateMCContext - Creates and initializes new MC Context.
	* @param[in] pDataModel - DataModel Object
	* @return New Context instance
	*/
	inline PMCContext CWrapper::CreateMCContext(classParam<LibMCData::CDataModel> pDataModel)
	{
		LibMCDataHandle hDataModel = pDataModel.GetHandle();
		LibMCHandle hInstance = nullptr;
		CheckError(nullptr,m_WrapperTable.m_CreateMCContext(hDataModel, &hInstance));
		
		if (!hInstance) {
			CheckError(nullptr,LIBMC_ERROR_INVALIDPARAM);
		}
		return std::make_shared<CMCContext>(this, hInstance);
	}
	
	inline void CWrapper::CheckError(CBase * pBaseClass, LibMCResult nResult)
	{
		if (nResult != 0) {
			std::string sErrorMessage;
			if (pBaseClass != nullptr) {
				GetLastError(pBaseClass, sErrorMessage);
			}
			throw ELibMCException(nResult, sErrorMessage);
		}
	}
	

	inline LibMCResult CWrapper::initWrapperTable(sLibMCDynamicWrapperTable * pWrapperTable)
	{
		if (pWrapperTable == nullptr)
			return LIBMC_ERROR_INVALIDPARAM;
		
		pWrapperTable->m_LibraryHandle = nullptr;
		pWrapperTable->m_APIResponse_GetHTTPCode = nullptr;
		pWrapperTable->m_APIResponse_GetContentType = nullptr;
		pWrapperTable->m_APIResponse_GetData = nullptr;
		pWrapperTable->m_MCContext_RegisterLibraryPath = nullptr;
		pWrapperTable->m_MCContext_ParseConfiguration = nullptr;
		pWrapperTable->m_MCContext_StartAllThreads = nullptr;
		pWrapperTable->m_MCContext_TerminateAllThreads = nullptr;
		pWrapperTable->m_MCContext_LoadClientPackage = nullptr;
		pWrapperTable->m_MCContext_Log = nullptr;
		pWrapperTable->m_MCContext_HandleAPIGetRequest = nullptr;
		pWrapperTable->m_MCContext_HandleAPIPostRequest = nullptr;
		pWrapperTable->m_GetVersion = nullptr;
		pWrapperTable->m_GetLastError = nullptr;
		pWrapperTable->m_ReleaseInstance = nullptr;
		pWrapperTable->m_AcquireInstance = nullptr;
		pWrapperTable->m_InjectComponent = nullptr;
		pWrapperTable->m_CreateMCContext = nullptr;
		
		return LIBMC_SUCCESS;
	}

	inline LibMCResult CWrapper::releaseWrapperTable(sLibMCDynamicWrapperTable * pWrapperTable)
	{
		if (pWrapperTable == nullptr)
			return LIBMC_ERROR_INVALIDPARAM;
		
		if (pWrapperTable->m_LibraryHandle != nullptr) {
		#ifdef _WIN32
			HMODULE hModule = (HMODULE) pWrapperTable->m_LibraryHandle;
			FreeLibrary(hModule);
		#else // _WIN32
			dlclose(pWrapperTable->m_LibraryHandle);
		#endif // _WIN32
			return initWrapperTable(pWrapperTable);
		}
		
		return LIBMC_SUCCESS;
	}

	inline LibMCResult CWrapper::loadWrapperTable(sLibMCDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName)
	{
		if (pWrapperTable == nullptr)
			return LIBMC_ERROR_INVALIDPARAM;
		if (pLibraryFileName == nullptr)
			return LIBMC_ERROR_INVALIDPARAM;
		
		#ifdef _WIN32
		// Convert filename to UTF16-string
		int nLength = (int)strlen(pLibraryFileName);
		int nBufferSize = nLength * 2 + 2;
		std::vector<wchar_t> wsLibraryFileName(nBufferSize);
		int nResult = MultiByteToWideChar(CP_UTF8, 0, pLibraryFileName, nLength, &wsLibraryFileName[0], nBufferSize);
		if (nResult == 0)
			return LIBMC_ERROR_COULDNOTLOADLIBRARY;
		
		HMODULE hLibrary = LoadLibraryW(wsLibraryFileName.data());
		if (hLibrary == 0) 
			return LIBMC_ERROR_COULDNOTLOADLIBRARY;
		#else // _WIN32
		void* hLibrary = dlopen(pLibraryFileName, RTLD_LAZY);
		if (hLibrary == 0) 
			return LIBMC_ERROR_COULDNOTLOADLIBRARY;
		dlerror();
		#endif // _WIN32
		
		#ifdef _WIN32
		pWrapperTable->m_APIResponse_GetHTTPCode = (PLibMCAPIResponse_GetHTTPCodePtr) GetProcAddress(hLibrary, "libmc_apiresponse_gethttpcode");
		#else // _WIN32
		pWrapperTable->m_APIResponse_GetHTTPCode = (PLibMCAPIResponse_GetHTTPCodePtr) dlsym(hLibrary, "libmc_apiresponse_gethttpcode");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_APIResponse_GetHTTPCode == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_APIResponse_GetContentType = (PLibMCAPIResponse_GetContentTypePtr) GetProcAddress(hLibrary, "libmc_apiresponse_getcontenttype");
		#else // _WIN32
		pWrapperTable->m_APIResponse_GetContentType = (PLibMCAPIResponse_GetContentTypePtr) dlsym(hLibrary, "libmc_apiresponse_getcontenttype");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_APIResponse_GetContentType == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_APIResponse_GetData = (PLibMCAPIResponse_GetDataPtr) GetProcAddress(hLibrary, "libmc_apiresponse_getdata");
		#else // _WIN32
		pWrapperTable->m_APIResponse_GetData = (PLibMCAPIResponse_GetDataPtr) dlsym(hLibrary, "libmc_apiresponse_getdata");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_APIResponse_GetData == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_MCContext_RegisterLibraryPath = (PLibMCMCContext_RegisterLibraryPathPtr) GetProcAddress(hLibrary, "libmc_mccontext_registerlibrarypath");
		#else // _WIN32
		pWrapperTable->m_MCContext_RegisterLibraryPath = (PLibMCMCContext_RegisterLibraryPathPtr) dlsym(hLibrary, "libmc_mccontext_registerlibrarypath");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_MCContext_RegisterLibraryPath == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_MCContext_ParseConfiguration = (PLibMCMCContext_ParseConfigurationPtr) GetProcAddress(hLibrary, "libmc_mccontext_parseconfiguration");
		#else // _WIN32
		pWrapperTable->m_MCContext_ParseConfiguration = (PLibMCMCContext_ParseConfigurationPtr) dlsym(hLibrary, "libmc_mccontext_parseconfiguration");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_MCContext_ParseConfiguration == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_MCContext_StartAllThreads = (PLibMCMCContext_StartAllThreadsPtr) GetProcAddress(hLibrary, "libmc_mccontext_startallthreads");
		#else // _WIN32
		pWrapperTable->m_MCContext_StartAllThreads = (PLibMCMCContext_StartAllThreadsPtr) dlsym(hLibrary, "libmc_mccontext_startallthreads");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_MCContext_StartAllThreads == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_MCContext_TerminateAllThreads = (PLibMCMCContext_TerminateAllThreadsPtr) GetProcAddress(hLibrary, "libmc_mccontext_terminateallthreads");
		#else // _WIN32
		pWrapperTable->m_MCContext_TerminateAllThreads = (PLibMCMCContext_TerminateAllThreadsPtr) dlsym(hLibrary, "libmc_mccontext_terminateallthreads");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_MCContext_TerminateAllThreads == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_MCContext_LoadClientPackage = (PLibMCMCContext_LoadClientPackagePtr) GetProcAddress(hLibrary, "libmc_mccontext_loadclientpackage");
		#else // _WIN32
		pWrapperTable->m_MCContext_LoadClientPackage = (PLibMCMCContext_LoadClientPackagePtr) dlsym(hLibrary, "libmc_mccontext_loadclientpackage");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_MCContext_LoadClientPackage == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_MCContext_Log = (PLibMCMCContext_LogPtr) GetProcAddress(hLibrary, "libmc_mccontext_log");
		#else // _WIN32
		pWrapperTable->m_MCContext_Log = (PLibMCMCContext_LogPtr) dlsym(hLibrary, "libmc_mccontext_log");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_MCContext_Log == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_MCContext_HandleAPIGetRequest = (PLibMCMCContext_HandleAPIGetRequestPtr) GetProcAddress(hLibrary, "libmc_mccontext_handleapigetrequest");
		#else // _WIN32
		pWrapperTable->m_MCContext_HandleAPIGetRequest = (PLibMCMCContext_HandleAPIGetRequestPtr) dlsym(hLibrary, "libmc_mccontext_handleapigetrequest");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_MCContext_HandleAPIGetRequest == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_MCContext_HandleAPIPostRequest = (PLibMCMCContext_HandleAPIPostRequestPtr) GetProcAddress(hLibrary, "libmc_mccontext_handleapipostrequest");
		#else // _WIN32
		pWrapperTable->m_MCContext_HandleAPIPostRequest = (PLibMCMCContext_HandleAPIPostRequestPtr) dlsym(hLibrary, "libmc_mccontext_handleapipostrequest");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_MCContext_HandleAPIPostRequest == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetVersion = (PLibMCGetVersionPtr) GetProcAddress(hLibrary, "libmc_getversion");
		#else // _WIN32
		pWrapperTable->m_GetVersion = (PLibMCGetVersionPtr) dlsym(hLibrary, "libmc_getversion");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetVersion == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetLastError = (PLibMCGetLastErrorPtr) GetProcAddress(hLibrary, "libmc_getlasterror");
		#else // _WIN32
		pWrapperTable->m_GetLastError = (PLibMCGetLastErrorPtr) dlsym(hLibrary, "libmc_getlasterror");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetLastError == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_ReleaseInstance = (PLibMCReleaseInstancePtr) GetProcAddress(hLibrary, "libmc_releaseinstance");
		#else // _WIN32
		pWrapperTable->m_ReleaseInstance = (PLibMCReleaseInstancePtr) dlsym(hLibrary, "libmc_releaseinstance");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_ReleaseInstance == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_AcquireInstance = (PLibMCAcquireInstancePtr) GetProcAddress(hLibrary, "libmc_acquireinstance");
		#else // _WIN32
		pWrapperTable->m_AcquireInstance = (PLibMCAcquireInstancePtr) dlsym(hLibrary, "libmc_acquireinstance");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_AcquireInstance == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_InjectComponent = (PLibMCInjectComponentPtr) GetProcAddress(hLibrary, "libmc_injectcomponent");
		#else // _WIN32
		pWrapperTable->m_InjectComponent = (PLibMCInjectComponentPtr) dlsym(hLibrary, "libmc_injectcomponent");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_InjectComponent == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_CreateMCContext = (PLibMCCreateMCContextPtr) GetProcAddress(hLibrary, "libmc_createmccontext");
		#else // _WIN32
		pWrapperTable->m_CreateMCContext = (PLibMCCreateMCContextPtr) dlsym(hLibrary, "libmc_createmccontext");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_CreateMCContext == nullptr)
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		pWrapperTable->m_LibraryHandle = hLibrary;
		return LIBMC_SUCCESS;
	}

	inline LibMCResult CWrapper::loadWrapperTableFromSymbolLookupMethod(sLibMCDynamicWrapperTable * pWrapperTable, void* pSymbolLookupMethod)
{
		if (pWrapperTable == nullptr)
			return LIBMC_ERROR_INVALIDPARAM;
		if (pSymbolLookupMethod == nullptr)
			return LIBMC_ERROR_INVALIDPARAM;
		
		typedef LibMCResult(*SymbolLookupType)(const char*, void**);
		
		SymbolLookupType pLookup = (SymbolLookupType)pSymbolLookupMethod;
		
		LibMCResult eLookupError = LIBMC_SUCCESS;
		eLookupError = (*pLookup)("libmc_apiresponse_gethttpcode", (void**)&(pWrapperTable->m_APIResponse_GetHTTPCode));
		if ( (eLookupError != 0) || (pWrapperTable->m_APIResponse_GetHTTPCode == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_apiresponse_getcontenttype", (void**)&(pWrapperTable->m_APIResponse_GetContentType));
		if ( (eLookupError != 0) || (pWrapperTable->m_APIResponse_GetContentType == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_apiresponse_getdata", (void**)&(pWrapperTable->m_APIResponse_GetData));
		if ( (eLookupError != 0) || (pWrapperTable->m_APIResponse_GetData == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_mccontext_registerlibrarypath", (void**)&(pWrapperTable->m_MCContext_RegisterLibraryPath));
		if ( (eLookupError != 0) || (pWrapperTable->m_MCContext_RegisterLibraryPath == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_mccontext_parseconfiguration", (void**)&(pWrapperTable->m_MCContext_ParseConfiguration));
		if ( (eLookupError != 0) || (pWrapperTable->m_MCContext_ParseConfiguration == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_mccontext_startallthreads", (void**)&(pWrapperTable->m_MCContext_StartAllThreads));
		if ( (eLookupError != 0) || (pWrapperTable->m_MCContext_StartAllThreads == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_mccontext_terminateallthreads", (void**)&(pWrapperTable->m_MCContext_TerminateAllThreads));
		if ( (eLookupError != 0) || (pWrapperTable->m_MCContext_TerminateAllThreads == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_mccontext_loadclientpackage", (void**)&(pWrapperTable->m_MCContext_LoadClientPackage));
		if ( (eLookupError != 0) || (pWrapperTable->m_MCContext_LoadClientPackage == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_mccontext_log", (void**)&(pWrapperTable->m_MCContext_Log));
		if ( (eLookupError != 0) || (pWrapperTable->m_MCContext_Log == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_mccontext_handleapigetrequest", (void**)&(pWrapperTable->m_MCContext_HandleAPIGetRequest));
		if ( (eLookupError != 0) || (pWrapperTable->m_MCContext_HandleAPIGetRequest == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_mccontext_handleapipostrequest", (void**)&(pWrapperTable->m_MCContext_HandleAPIPostRequest));
		if ( (eLookupError != 0) || (pWrapperTable->m_MCContext_HandleAPIPostRequest == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_getversion", (void**)&(pWrapperTable->m_GetVersion));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetVersion == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_getlasterror", (void**)&(pWrapperTable->m_GetLastError));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetLastError == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_releaseinstance", (void**)&(pWrapperTable->m_ReleaseInstance));
		if ( (eLookupError != 0) || (pWrapperTable->m_ReleaseInstance == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_acquireinstance", (void**)&(pWrapperTable->m_AcquireInstance));
		if ( (eLookupError != 0) || (pWrapperTable->m_AcquireInstance == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_injectcomponent", (void**)&(pWrapperTable->m_InjectComponent));
		if ( (eLookupError != 0) || (pWrapperTable->m_InjectComponent == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmc_createmccontext", (void**)&(pWrapperTable->m_CreateMCContext));
		if ( (eLookupError != 0) || (pWrapperTable->m_CreateMCContext == nullptr) )
			return LIBMC_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		return LIBMC_SUCCESS;
}

	
	
	/**
	 * Method definitions for class CBase
	 */
	
	/**
	 * Method definitions for class CAPIResponse
	 */
	
	/**
	* CAPIResponse::GetHTTPCode - returns the HTTP Errorcode to set (200 for success).
	* @return HTTP Code
	*/
	LibMC_uint32 CAPIResponse::GetHTTPCode()
	{
		LibMC_uint32 resultHTTPCode = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_APIResponse_GetHTTPCode(m_pHandle, &resultHTTPCode));
		
		return resultHTTPCode;
	}
	
	/**
	* CAPIResponse::GetContentType - returns the content type string of the data.
	* @return Content Type.
	*/
	std::string CAPIResponse::GetContentType()
	{
		LibMC_uint32 bytesNeededContentType = 0;
		LibMC_uint32 bytesWrittenContentType = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_APIResponse_GetContentType(m_pHandle, 0, &bytesNeededContentType, nullptr));
		std::vector<char> bufferContentType(bytesNeededContentType);
		CheckError(m_pWrapper->m_WrapperTable.m_APIResponse_GetContentType(m_pHandle, bytesNeededContentType, &bytesWrittenContentType, &bufferContentType[0]));
		
		return std::string(&bufferContentType[0]);
	}
	
	/**
	* CAPIResponse::GetData - returns the stream content of the data.
	* @param[out] DataBuffer - Binary stream data
	*/
	void CAPIResponse::GetData(std::vector<LibMC_uint8> & DataBuffer)
	{
		LibMC_uint64 elementsNeededData = 0;
		LibMC_uint64 elementsWrittenData = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_APIResponse_GetData(m_pHandle, 0, &elementsNeededData, nullptr));
		DataBuffer.resize((size_t) elementsNeededData);
		CheckError(m_pWrapper->m_WrapperTable.m_APIResponse_GetData(m_pHandle, elementsNeededData, &elementsWrittenData, DataBuffer.data()));
	}
	
	/**
	 * Method definitions for class CMCContext
	 */
	
	/**
	* CMCContext::RegisterLibraryPath - registers a library for a given name.
	* @param[in] sLibraryName - Library Name.
	* @param[in] sLibraryPath - Path to the shared library.
	*/
	void CMCContext::RegisterLibraryPath(const std::string & sLibraryName, const std::string & sLibraryPath)
	{
		CheckError(m_pWrapper->m_WrapperTable.m_MCContext_RegisterLibraryPath(m_pHandle, sLibraryName.c_str(), sLibraryPath.c_str()));
	}
	
	/**
	* CMCContext::ParseConfiguration - parses and initialises the state machines from a configuration XML.
	* @param[in] sXMLString - XML Configuration String.
	*/
	void CMCContext::ParseConfiguration(const std::string & sXMLString)
	{
		CheckError(m_pWrapper->m_WrapperTable.m_MCContext_ParseConfiguration(m_pHandle, sXMLString.c_str()));
	}
	
	/**
	* CMCContext::StartAllThreads - starts the threads for all the state machines.
	*/
	void CMCContext::StartAllThreads()
	{
		CheckError(m_pWrapper->m_WrapperTable.m_MCContext_StartAllThreads(m_pHandle));
	}
	
	/**
	* CMCContext::TerminateAllThreads - terminates the threads for all the state machines.
	*/
	void CMCContext::TerminateAllThreads()
	{
		CheckError(m_pWrapper->m_WrapperTable.m_MCContext_TerminateAllThreads(m_pHandle));
	}
	
	/**
	* CMCContext::LoadClientPackage - load a client package to serve the client website.
	* @param[in] ZIPStreamBuffer - client package ZIP stream.
	*/
	void CMCContext::LoadClientPackage(const CInputVector<LibMC_uint8> & ZIPStreamBuffer)
	{
		CheckError(m_pWrapper->m_WrapperTable.m_MCContext_LoadClientPackage(m_pHandle, (LibMC_uint64)ZIPStreamBuffer.size(), ZIPStreamBuffer.data()));
	}
	
	/**
	* CMCContext::Log - log message with a certain log level.
	* @param[in] sMessage - log message
	* @param[in] eSubsystem - log subsystem
	* @param[in] eLogLevel - log level
	*/
	void CMCContext::Log(const std::string & sMessage, const eLogSubSystem eSubsystem, const eLogLevel eLogLevel)
	{
		CheckError(m_pWrapper->m_WrapperTable.m_MCContext_Log(m_pHandle, sMessage.c_str(), eSubsystem, eLogLevel));
	}
	
	/**
	* CMCContext::HandleAPIGetRequest - handle an API GET request.
	* @param[in] sURI - URI to serve
	* @return Response instance.
	*/
	PAPIResponse CMCContext::HandleAPIGetRequest(const std::string & sURI)
	{
		LibMCHandle hResponse = nullptr;
		CheckError(m_pWrapper->m_WrapperTable.m_MCContext_HandleAPIGetRequest(m_pHandle, sURI.c_str(), &hResponse));
		
		if (!hResponse) {
			CheckError(LIBMC_ERROR_INVALIDPARAM);
		}
		return std::make_shared<CAPIResponse>(m_pWrapper, hResponse);
	}
	
	/**
	* CMCContext::HandleAPIPostRequest - handle an API POST request.
	* @param[in] sURI - URI to serve
	* @param[in] BodyBuffer - Body that was sent.
	* @return Response instance.
	*/
	PAPIResponse CMCContext::HandleAPIPostRequest(const std::string & sURI, const CInputVector<LibMC_uint8> & BodyBuffer)
	{
		LibMCHandle hResponse = nullptr;
		CheckError(m_pWrapper->m_WrapperTable.m_MCContext_HandleAPIPostRequest(m_pHandle, sURI.c_str(), (LibMC_uint64)BodyBuffer.size(), BodyBuffer.data(), &hResponse));
		
		if (!hResponse) {
			CheckError(LIBMC_ERROR_INVALIDPARAM);
		}
		return std::make_shared<CAPIResponse>(m_pWrapper, hResponse);
	}

} // namespace LibMC

#endif // __LIBMC_CPPHEADER_DYNAMIC_CPP

