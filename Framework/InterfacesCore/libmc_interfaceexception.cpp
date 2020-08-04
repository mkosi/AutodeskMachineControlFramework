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

Abstract: This is an autogenerated C++ Implementation file with the basic internal
 exception type in order to allow an easy use of Machine Control library

Interface version: 1.0.0

*/


#include <string>

#include "libmc_interfaceexception.hpp"

/*************************************************************************************************************************
 Class ELibMCInterfaceException
**************************************************************************************************************************/
ELibMCInterfaceException::ELibMCInterfaceException(LibMCResult errorCode)
	: m_errorMessage(LIBMC_GETERRORSTRING (errorCode))
{
	m_errorCode = errorCode;
}

ELibMCInterfaceException::ELibMCInterfaceException(LibMCResult errorCode, std::string errorMessage)
	: m_errorMessage(errorMessage + " (" + std::to_string (errorCode) + ")")
{
	m_errorCode = errorCode;
}

LibMCResult ELibMCInterfaceException::getErrorCode ()
{
	return m_errorCode;
}

const char * ELibMCInterfaceException::what () const noexcept
{
	return m_errorMessage.c_str();
}

