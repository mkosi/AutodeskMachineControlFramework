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

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AUTODESK INC. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "libmcdata_datamodel.hpp"
#include "libmcdata_interfaceexception.hpp"

// Include custom headers here.
#include "libmcdata_storage.hpp"
#include "libmcdata_logsession.hpp"
#include "libmcdata_buildjobhandler.hpp"

#include "amcdata_databasemigrator.hpp"
#include "amcdata_sqlhandler_sqlite.hpp"

#include "amcdata_databasemigrator_storage.hpp"
#include "amcdata_databasemigrator_buildjobs.hpp"

#include "common_utils.hpp"


using namespace LibMCData::Impl;

/*************************************************************************************************************************
 Class definition of CDataModel 
**************************************************************************************************************************/

CDataModel::CDataModel()
    : m_eDataBaseType(eDataBaseType::Unknown)
{

}

void CDataModel::InitialiseDatabase(const std::string & sDataDirectory, const LibMCData::eDataBaseType eDataBaseType, const std::string & sConnectionString)
    
{
    m_eDataBaseType = eDataBaseType;
    m_pStoragePath = std::make_shared<AMCData::CStoragePath> (sDataDirectory);
    if (eDataBaseType == eDataBaseType::SqLite) {
        m_pSQLHandler = std::make_shared<AMCData::CSQLHandler_SQLite>(sConnectionString);
    }
    else {
        throw ELibMCDataInterfaceException(LIBMCDATA_ERROR_UNKNOWNDATABASETYPE);
    }


    // ADD DATABASE MIGRATORS HERE!
    AMCData::CDatabaseMigrator migrator;
    migrator.addMigrationClass(std::make_shared<AMCData::CDatabaseMigrationClass_Storage>());
    migrator.addMigrationClass(std::make_shared<AMCData::CDatabaseMigrationClass_BuildJobs>());
    migrator.migrateDatabaseSchemas(m_pSQLHandler);
}

LibMCData_uint32 CDataModel::GetDataModelVersion()
{
	return AMCData::CDatabaseMigrator::getCurrentSchemaVersion ();
}

IStorage * CDataModel::CreateStorage()
{
    if (m_eDataBaseType == eDataBaseType::Unknown)
        throw ELibMCDataInterfaceException(LIBMCDATA_ERROR_UNKNOWNDATABASETYPE);
    if (m_pStoragePath.get() == nullptr)
        throw ELibMCDataInterfaceException(LIBMCDATA_ERROR_INVALIDSTORAGEPATH);

	return new CStorage (m_pSQLHandler, m_pStoragePath);
}

ILogSession* CDataModel::CreateNewLogSession()
{
    if (m_pStoragePath.get() == nullptr)
        throw ELibMCDataInterfaceException(LIBMCDATA_ERROR_INVALIDSTORAGEPATH);
    
    auto sLogName = m_pStoragePath->getLogPath();

	return new CLogSession(sLogName);
}


IBuildJobHandler* CDataModel::CreateBuildJobHandler()
{

    return new CBuildJobHandler(m_pSQLHandler, m_pStoragePath);
}
