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

Abstract: This is an autogenerated plain C Header file in order to allow an easy
 use of Machine Control data model library

Interface version: 1.0.0

*/

#include "libmcdata_types.h"
#include "libmcdata_dynamic.h"
#ifdef _WIN32
#include <windows.h>
#else // _WIN32
#include <dlfcn.h>
#include <stdlib.h>
#endif // _WIN32

LibMCDataResult InitLibMCDataWrapperTable(sLibMCDataDynamicWrapperTable * pWrapperTable)
{
	if (pWrapperTable == NULL)
		return LIBMCDATA_ERROR_INVALIDPARAM;
	
	pWrapperTable->m_LibraryHandle = NULL;
	pWrapperTable->m_Iterator_MoveNext = NULL;
	pWrapperTable->m_Iterator_MovePrevious = NULL;
	pWrapperTable->m_Iterator_GetCurrent = NULL;
	pWrapperTable->m_Iterator_Clone = NULL;
	pWrapperTable->m_Iterator_Count = NULL;
	pWrapperTable->m_LogSession_AddEntry = NULL;
	pWrapperTable->m_StorageStream_GetUUID = NULL;
	pWrapperTable->m_StorageStream_GetContextUUID = NULL;
	pWrapperTable->m_StorageStream_GetTimeStamp = NULL;
	pWrapperTable->m_StorageStream_GetName = NULL;
	pWrapperTable->m_StorageStream_GetMIMEType = NULL;
	pWrapperTable->m_StorageStream_GetSHA2 = NULL;
	pWrapperTable->m_StorageStream_GetSize = NULL;
	pWrapperTable->m_StorageStream_GetContent = NULL;
	pWrapperTable->m_StorageStream_GetCallbacks = NULL;
	pWrapperTable->m_Storage_StoreNewStream = NULL;
	pWrapperTable->m_Storage_BeginPartialStream = NULL;
	pWrapperTable->m_Storage_StorePartialStream = NULL;
	pWrapperTable->m_Storage_FinishPartialStream = NULL;
	pWrapperTable->m_BuildJob_GetUUID = NULL;
	pWrapperTable->m_BuildJob_GetName = NULL;
	pWrapperTable->m_BuildJob_GetStatus = NULL;
	pWrapperTable->m_BuildJob_GetTimeStamp = NULL;
	pWrapperTable->m_BuildJob_GetStorageStream = NULL;
	pWrapperTable->m_BuildJob_GetBuildJobLogger = NULL;
	pWrapperTable->m_BuildJobIterator_GetCurrentJob = NULL;
	pWrapperTable->m_BuildJobHandler_CreateJob = NULL;
	pWrapperTable->m_BuildJobHandler_RetrieveJob = NULL;
	pWrapperTable->m_BuildJobHandler_ListJobsByStatus = NULL;
	pWrapperTable->m_BuildJobHandler_ConvertBuildStatusToString = NULL;
	pWrapperTable->m_BuildJobHandler_ConvertStringToBuildStatus = NULL;
	pWrapperTable->m_DataModel_InitialiseDatabase = NULL;
	pWrapperTable->m_DataModel_GetDataModelVersion = NULL;
	pWrapperTable->m_DataModel_CreateStorage = NULL;
	pWrapperTable->m_DataModel_CreateBuildJobHandler = NULL;
	pWrapperTable->m_DataModel_CreateNewLogSession = NULL;
	pWrapperTable->m_GetVersion = NULL;
	pWrapperTable->m_GetLastError = NULL;
	pWrapperTable->m_ReleaseInstance = NULL;
	pWrapperTable->m_AcquireInstance = NULL;
	pWrapperTable->m_GetSymbolLookupMethod = NULL;
	pWrapperTable->m_CreateDataModelInstance = NULL;
	
	return LIBMCDATA_SUCCESS;
}

LibMCDataResult ReleaseLibMCDataWrapperTable(sLibMCDataDynamicWrapperTable * pWrapperTable)
{
	if (pWrapperTable == NULL)
		return LIBMCDATA_ERROR_INVALIDPARAM;
	
	if (pWrapperTable->m_LibraryHandle != NULL) {
	#ifdef _WIN32
		HMODULE hModule = (HMODULE) pWrapperTable->m_LibraryHandle;
		FreeLibrary(hModule);
	#else // _WIN32
		dlclose(pWrapperTable->m_LibraryHandle);
	#endif // _WIN32
		return InitLibMCDataWrapperTable(pWrapperTable);
	}
	
	return LIBMCDATA_SUCCESS;
}

LibMCDataResult LoadLibMCDataWrapperTable(sLibMCDataDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName)
{
	if (pWrapperTable == NULL)
		return LIBMCDATA_ERROR_INVALIDPARAM;
	if (pLibraryFileName == NULL)
		return LIBMCDATA_ERROR_INVALIDPARAM;
	
	#ifdef _WIN32
	// Convert filename to UTF16-string
	int nLength = (int)strlen(pLibraryFileName);
	int nBufferSize = nLength * 2 + 2;
	wchar_t* wsLibraryFileName = (wchar_t*)malloc(nBufferSize*sizeof(wchar_t));
	memset(wsLibraryFileName, 0, nBufferSize*sizeof(wchar_t));
	int nResult = MultiByteToWideChar(CP_UTF8, 0, pLibraryFileName, nLength, wsLibraryFileName, nBufferSize);
	if (nResult == 0) {
		free(wsLibraryFileName);
		return LIBMCDATA_ERROR_COULDNOTLOADLIBRARY;
	}
	
	HMODULE hLibrary = LoadLibraryW(wsLibraryFileName);
	free(wsLibraryFileName);
	if (hLibrary == 0) 
		return LIBMCDATA_ERROR_COULDNOTLOADLIBRARY;
	#else // _WIN32
	void* hLibrary = dlopen(pLibraryFileName, RTLD_LAZY);
	if (hLibrary == 0) 
		return LIBMCDATA_ERROR_COULDNOTLOADLIBRARY;
	dlerror();
	#endif // _WIN32
	
	#ifdef _WIN32
	pWrapperTable->m_Iterator_MoveNext = (PLibMCDataIterator_MoveNextPtr) GetProcAddress(hLibrary, "libmcdata_iterator_movenext");
	#else // _WIN32
	pWrapperTable->m_Iterator_MoveNext = (PLibMCDataIterator_MoveNextPtr) dlsym(hLibrary, "libmcdata_iterator_movenext");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_Iterator_MoveNext == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_Iterator_MovePrevious = (PLibMCDataIterator_MovePreviousPtr) GetProcAddress(hLibrary, "libmcdata_iterator_moveprevious");
	#else // _WIN32
	pWrapperTable->m_Iterator_MovePrevious = (PLibMCDataIterator_MovePreviousPtr) dlsym(hLibrary, "libmcdata_iterator_moveprevious");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_Iterator_MovePrevious == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_Iterator_GetCurrent = (PLibMCDataIterator_GetCurrentPtr) GetProcAddress(hLibrary, "libmcdata_iterator_getcurrent");
	#else // _WIN32
	pWrapperTable->m_Iterator_GetCurrent = (PLibMCDataIterator_GetCurrentPtr) dlsym(hLibrary, "libmcdata_iterator_getcurrent");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_Iterator_GetCurrent == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_Iterator_Clone = (PLibMCDataIterator_ClonePtr) GetProcAddress(hLibrary, "libmcdata_iterator_clone");
	#else // _WIN32
	pWrapperTable->m_Iterator_Clone = (PLibMCDataIterator_ClonePtr) dlsym(hLibrary, "libmcdata_iterator_clone");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_Iterator_Clone == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_Iterator_Count = (PLibMCDataIterator_CountPtr) GetProcAddress(hLibrary, "libmcdata_iterator_count");
	#else // _WIN32
	pWrapperTable->m_Iterator_Count = (PLibMCDataIterator_CountPtr) dlsym(hLibrary, "libmcdata_iterator_count");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_Iterator_Count == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_LogSession_AddEntry = (PLibMCDataLogSession_AddEntryPtr) GetProcAddress(hLibrary, "libmcdata_logsession_addentry");
	#else // _WIN32
	pWrapperTable->m_LogSession_AddEntry = (PLibMCDataLogSession_AddEntryPtr) dlsym(hLibrary, "libmcdata_logsession_addentry");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_LogSession_AddEntry == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_StorageStream_GetUUID = (PLibMCDataStorageStream_GetUUIDPtr) GetProcAddress(hLibrary, "libmcdata_storagestream_getuuid");
	#else // _WIN32
	pWrapperTable->m_StorageStream_GetUUID = (PLibMCDataStorageStream_GetUUIDPtr) dlsym(hLibrary, "libmcdata_storagestream_getuuid");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_StorageStream_GetUUID == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_StorageStream_GetContextUUID = (PLibMCDataStorageStream_GetContextUUIDPtr) GetProcAddress(hLibrary, "libmcdata_storagestream_getcontextuuid");
	#else // _WIN32
	pWrapperTable->m_StorageStream_GetContextUUID = (PLibMCDataStorageStream_GetContextUUIDPtr) dlsym(hLibrary, "libmcdata_storagestream_getcontextuuid");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_StorageStream_GetContextUUID == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_StorageStream_GetTimeStamp = (PLibMCDataStorageStream_GetTimeStampPtr) GetProcAddress(hLibrary, "libmcdata_storagestream_gettimestamp");
	#else // _WIN32
	pWrapperTable->m_StorageStream_GetTimeStamp = (PLibMCDataStorageStream_GetTimeStampPtr) dlsym(hLibrary, "libmcdata_storagestream_gettimestamp");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_StorageStream_GetTimeStamp == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_StorageStream_GetName = (PLibMCDataStorageStream_GetNamePtr) GetProcAddress(hLibrary, "libmcdata_storagestream_getname");
	#else // _WIN32
	pWrapperTable->m_StorageStream_GetName = (PLibMCDataStorageStream_GetNamePtr) dlsym(hLibrary, "libmcdata_storagestream_getname");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_StorageStream_GetName == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_StorageStream_GetMIMEType = (PLibMCDataStorageStream_GetMIMETypePtr) GetProcAddress(hLibrary, "libmcdata_storagestream_getmimetype");
	#else // _WIN32
	pWrapperTable->m_StorageStream_GetMIMEType = (PLibMCDataStorageStream_GetMIMETypePtr) dlsym(hLibrary, "libmcdata_storagestream_getmimetype");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_StorageStream_GetMIMEType == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_StorageStream_GetSHA2 = (PLibMCDataStorageStream_GetSHA2Ptr) GetProcAddress(hLibrary, "libmcdata_storagestream_getsha2");
	#else // _WIN32
	pWrapperTable->m_StorageStream_GetSHA2 = (PLibMCDataStorageStream_GetSHA2Ptr) dlsym(hLibrary, "libmcdata_storagestream_getsha2");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_StorageStream_GetSHA2 == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_StorageStream_GetSize = (PLibMCDataStorageStream_GetSizePtr) GetProcAddress(hLibrary, "libmcdata_storagestream_getsize");
	#else // _WIN32
	pWrapperTable->m_StorageStream_GetSize = (PLibMCDataStorageStream_GetSizePtr) dlsym(hLibrary, "libmcdata_storagestream_getsize");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_StorageStream_GetSize == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_StorageStream_GetContent = (PLibMCDataStorageStream_GetContentPtr) GetProcAddress(hLibrary, "libmcdata_storagestream_getcontent");
	#else // _WIN32
	pWrapperTable->m_StorageStream_GetContent = (PLibMCDataStorageStream_GetContentPtr) dlsym(hLibrary, "libmcdata_storagestream_getcontent");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_StorageStream_GetContent == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_StorageStream_GetCallbacks = (PLibMCDataStorageStream_GetCallbacksPtr) GetProcAddress(hLibrary, "libmcdata_storagestream_getcallbacks");
	#else // _WIN32
	pWrapperTable->m_StorageStream_GetCallbacks = (PLibMCDataStorageStream_GetCallbacksPtr) dlsym(hLibrary, "libmcdata_storagestream_getcallbacks");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_StorageStream_GetCallbacks == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_Storage_StoreNewStream = (PLibMCDataStorage_StoreNewStreamPtr) GetProcAddress(hLibrary, "libmcdata_storage_storenewstream");
	#else // _WIN32
	pWrapperTable->m_Storage_StoreNewStream = (PLibMCDataStorage_StoreNewStreamPtr) dlsym(hLibrary, "libmcdata_storage_storenewstream");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_Storage_StoreNewStream == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_Storage_BeginPartialStream = (PLibMCDataStorage_BeginPartialStreamPtr) GetProcAddress(hLibrary, "libmcdata_storage_beginpartialstream");
	#else // _WIN32
	pWrapperTable->m_Storage_BeginPartialStream = (PLibMCDataStorage_BeginPartialStreamPtr) dlsym(hLibrary, "libmcdata_storage_beginpartialstream");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_Storage_BeginPartialStream == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_Storage_StorePartialStream = (PLibMCDataStorage_StorePartialStreamPtr) GetProcAddress(hLibrary, "libmcdata_storage_storepartialstream");
	#else // _WIN32
	pWrapperTable->m_Storage_StorePartialStream = (PLibMCDataStorage_StorePartialStreamPtr) dlsym(hLibrary, "libmcdata_storage_storepartialstream");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_Storage_StorePartialStream == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_Storage_FinishPartialStream = (PLibMCDataStorage_FinishPartialStreamPtr) GetProcAddress(hLibrary, "libmcdata_storage_finishpartialstream");
	#else // _WIN32
	pWrapperTable->m_Storage_FinishPartialStream = (PLibMCDataStorage_FinishPartialStreamPtr) dlsym(hLibrary, "libmcdata_storage_finishpartialstream");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_Storage_FinishPartialStream == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJob_GetUUID = (PLibMCDataBuildJob_GetUUIDPtr) GetProcAddress(hLibrary, "libmcdata_buildjob_getuuid");
	#else // _WIN32
	pWrapperTable->m_BuildJob_GetUUID = (PLibMCDataBuildJob_GetUUIDPtr) dlsym(hLibrary, "libmcdata_buildjob_getuuid");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJob_GetUUID == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJob_GetName = (PLibMCDataBuildJob_GetNamePtr) GetProcAddress(hLibrary, "libmcdata_buildjob_getname");
	#else // _WIN32
	pWrapperTable->m_BuildJob_GetName = (PLibMCDataBuildJob_GetNamePtr) dlsym(hLibrary, "libmcdata_buildjob_getname");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJob_GetName == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJob_GetStatus = (PLibMCDataBuildJob_GetStatusPtr) GetProcAddress(hLibrary, "libmcdata_buildjob_getstatus");
	#else // _WIN32
	pWrapperTable->m_BuildJob_GetStatus = (PLibMCDataBuildJob_GetStatusPtr) dlsym(hLibrary, "libmcdata_buildjob_getstatus");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJob_GetStatus == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJob_GetTimeStamp = (PLibMCDataBuildJob_GetTimeStampPtr) GetProcAddress(hLibrary, "libmcdata_buildjob_gettimestamp");
	#else // _WIN32
	pWrapperTable->m_BuildJob_GetTimeStamp = (PLibMCDataBuildJob_GetTimeStampPtr) dlsym(hLibrary, "libmcdata_buildjob_gettimestamp");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJob_GetTimeStamp == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJob_GetStorageStream = (PLibMCDataBuildJob_GetStorageStreamPtr) GetProcAddress(hLibrary, "libmcdata_buildjob_getstoragestream");
	#else // _WIN32
	pWrapperTable->m_BuildJob_GetStorageStream = (PLibMCDataBuildJob_GetStorageStreamPtr) dlsym(hLibrary, "libmcdata_buildjob_getstoragestream");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJob_GetStorageStream == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJob_GetBuildJobLogger = (PLibMCDataBuildJob_GetBuildJobLoggerPtr) GetProcAddress(hLibrary, "libmcdata_buildjob_getbuildjoblogger");
	#else // _WIN32
	pWrapperTable->m_BuildJob_GetBuildJobLogger = (PLibMCDataBuildJob_GetBuildJobLoggerPtr) dlsym(hLibrary, "libmcdata_buildjob_getbuildjoblogger");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJob_GetBuildJobLogger == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJobIterator_GetCurrentJob = (PLibMCDataBuildJobIterator_GetCurrentJobPtr) GetProcAddress(hLibrary, "libmcdata_buildjobiterator_getcurrentjob");
	#else // _WIN32
	pWrapperTable->m_BuildJobIterator_GetCurrentJob = (PLibMCDataBuildJobIterator_GetCurrentJobPtr) dlsym(hLibrary, "libmcdata_buildjobiterator_getcurrentjob");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJobIterator_GetCurrentJob == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJobHandler_CreateJob = (PLibMCDataBuildJobHandler_CreateJobPtr) GetProcAddress(hLibrary, "libmcdata_buildjobhandler_createjob");
	#else // _WIN32
	pWrapperTable->m_BuildJobHandler_CreateJob = (PLibMCDataBuildJobHandler_CreateJobPtr) dlsym(hLibrary, "libmcdata_buildjobhandler_createjob");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJobHandler_CreateJob == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJobHandler_RetrieveJob = (PLibMCDataBuildJobHandler_RetrieveJobPtr) GetProcAddress(hLibrary, "libmcdata_buildjobhandler_retrievejob");
	#else // _WIN32
	pWrapperTable->m_BuildJobHandler_RetrieveJob = (PLibMCDataBuildJobHandler_RetrieveJobPtr) dlsym(hLibrary, "libmcdata_buildjobhandler_retrievejob");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJobHandler_RetrieveJob == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJobHandler_ListJobsByStatus = (PLibMCDataBuildJobHandler_ListJobsByStatusPtr) GetProcAddress(hLibrary, "libmcdata_buildjobhandler_listjobsbystatus");
	#else // _WIN32
	pWrapperTable->m_BuildJobHandler_ListJobsByStatus = (PLibMCDataBuildJobHandler_ListJobsByStatusPtr) dlsym(hLibrary, "libmcdata_buildjobhandler_listjobsbystatus");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJobHandler_ListJobsByStatus == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJobHandler_ConvertBuildStatusToString = (PLibMCDataBuildJobHandler_ConvertBuildStatusToStringPtr) GetProcAddress(hLibrary, "libmcdata_buildjobhandler_convertbuildstatustostring");
	#else // _WIN32
	pWrapperTable->m_BuildJobHandler_ConvertBuildStatusToString = (PLibMCDataBuildJobHandler_ConvertBuildStatusToStringPtr) dlsym(hLibrary, "libmcdata_buildjobhandler_convertbuildstatustostring");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJobHandler_ConvertBuildStatusToString == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_BuildJobHandler_ConvertStringToBuildStatus = (PLibMCDataBuildJobHandler_ConvertStringToBuildStatusPtr) GetProcAddress(hLibrary, "libmcdata_buildjobhandler_convertstringtobuildstatus");
	#else // _WIN32
	pWrapperTable->m_BuildJobHandler_ConvertStringToBuildStatus = (PLibMCDataBuildJobHandler_ConvertStringToBuildStatusPtr) dlsym(hLibrary, "libmcdata_buildjobhandler_convertstringtobuildstatus");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_BuildJobHandler_ConvertStringToBuildStatus == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_DataModel_InitialiseDatabase = (PLibMCDataDataModel_InitialiseDatabasePtr) GetProcAddress(hLibrary, "libmcdata_datamodel_initialisedatabase");
	#else // _WIN32
	pWrapperTable->m_DataModel_InitialiseDatabase = (PLibMCDataDataModel_InitialiseDatabasePtr) dlsym(hLibrary, "libmcdata_datamodel_initialisedatabase");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_DataModel_InitialiseDatabase == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_DataModel_GetDataModelVersion = (PLibMCDataDataModel_GetDataModelVersionPtr) GetProcAddress(hLibrary, "libmcdata_datamodel_getdatamodelversion");
	#else // _WIN32
	pWrapperTable->m_DataModel_GetDataModelVersion = (PLibMCDataDataModel_GetDataModelVersionPtr) dlsym(hLibrary, "libmcdata_datamodel_getdatamodelversion");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_DataModel_GetDataModelVersion == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_DataModel_CreateStorage = (PLibMCDataDataModel_CreateStoragePtr) GetProcAddress(hLibrary, "libmcdata_datamodel_createstorage");
	#else // _WIN32
	pWrapperTable->m_DataModel_CreateStorage = (PLibMCDataDataModel_CreateStoragePtr) dlsym(hLibrary, "libmcdata_datamodel_createstorage");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_DataModel_CreateStorage == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_DataModel_CreateBuildJobHandler = (PLibMCDataDataModel_CreateBuildJobHandlerPtr) GetProcAddress(hLibrary, "libmcdata_datamodel_createbuildjobhandler");
	#else // _WIN32
	pWrapperTable->m_DataModel_CreateBuildJobHandler = (PLibMCDataDataModel_CreateBuildJobHandlerPtr) dlsym(hLibrary, "libmcdata_datamodel_createbuildjobhandler");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_DataModel_CreateBuildJobHandler == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_DataModel_CreateNewLogSession = (PLibMCDataDataModel_CreateNewLogSessionPtr) GetProcAddress(hLibrary, "libmcdata_datamodel_createnewlogsession");
	#else // _WIN32
	pWrapperTable->m_DataModel_CreateNewLogSession = (PLibMCDataDataModel_CreateNewLogSessionPtr) dlsym(hLibrary, "libmcdata_datamodel_createnewlogsession");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_DataModel_CreateNewLogSession == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_GetVersion = (PLibMCDataGetVersionPtr) GetProcAddress(hLibrary, "libmcdata_getversion");
	#else // _WIN32
	pWrapperTable->m_GetVersion = (PLibMCDataGetVersionPtr) dlsym(hLibrary, "libmcdata_getversion");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_GetVersion == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_GetLastError = (PLibMCDataGetLastErrorPtr) GetProcAddress(hLibrary, "libmcdata_getlasterror");
	#else // _WIN32
	pWrapperTable->m_GetLastError = (PLibMCDataGetLastErrorPtr) dlsym(hLibrary, "libmcdata_getlasterror");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_GetLastError == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_ReleaseInstance = (PLibMCDataReleaseInstancePtr) GetProcAddress(hLibrary, "libmcdata_releaseinstance");
	#else // _WIN32
	pWrapperTable->m_ReleaseInstance = (PLibMCDataReleaseInstancePtr) dlsym(hLibrary, "libmcdata_releaseinstance");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_ReleaseInstance == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_AcquireInstance = (PLibMCDataAcquireInstancePtr) GetProcAddress(hLibrary, "libmcdata_acquireinstance");
	#else // _WIN32
	pWrapperTable->m_AcquireInstance = (PLibMCDataAcquireInstancePtr) dlsym(hLibrary, "libmcdata_acquireinstance");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_AcquireInstance == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_GetSymbolLookupMethod = (PLibMCDataGetSymbolLookupMethodPtr) GetProcAddress(hLibrary, "libmcdata_getsymbollookupmethod");
	#else // _WIN32
	pWrapperTable->m_GetSymbolLookupMethod = (PLibMCDataGetSymbolLookupMethodPtr) dlsym(hLibrary, "libmcdata_getsymbollookupmethod");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_GetSymbolLookupMethod == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	#ifdef _WIN32
	pWrapperTable->m_CreateDataModelInstance = (PLibMCDataCreateDataModelInstancePtr) GetProcAddress(hLibrary, "libmcdata_createdatamodelinstance");
	#else // _WIN32
	pWrapperTable->m_CreateDataModelInstance = (PLibMCDataCreateDataModelInstancePtr) dlsym(hLibrary, "libmcdata_createdatamodelinstance");
	dlerror();
	#endif // _WIN32
	if (pWrapperTable->m_CreateDataModelInstance == NULL)
		return LIBMCDATA_ERROR_COULDNOTFINDLIBRARYEXPORT;
	
	pWrapperTable->m_LibraryHandle = hLibrary;
	return LIBMCDATA_SUCCESS;
}

