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

Abstract: This is an autogenerated C++ Header file with the basic internal
 exception type in order to allow an easy use of MC Driver Environment Interface

Interface version: 1.0.0

*/

#ifndef __LIBMCDRIVERENV_INTERFACEEXCEPTION_HEADER
#define __LIBMCDRIVERENV_INTERFACEEXCEPTION_HEADER

#include <exception>
#include <stdexcept>
#include "libmcdriverenv_types.hpp"

/*************************************************************************************************************************
 Class ELibMCDriverEnvInterfaceException
**************************************************************************************************************************/


class ELibMCDriverEnvInterfaceException : public std::exception {
protected:
	/**
	* Error code for the Exception.
	*/
	LibMCDriverEnvResult m_errorCode;
	/**
	* Error message for the Exception.
	*/
	std::string m_errorMessage;

public:
	/**
	* Exception Constructor.
	*/
	ELibMCDriverEnvInterfaceException(LibMCDriverEnvResult errorCode);

	/**
	* Custom Exception Constructor.
	*/
	ELibMCDriverEnvInterfaceException(LibMCDriverEnvResult errorCode, std::string errorMessage);

	/**
	* Returns error code
	*/
	LibMCDriverEnvResult getErrorCode();
	/**
	* Returns error message
	*/
	const char* what() const noexcept override;
};

#endif // __LIBMCDRIVERENV_INTERFACEEXCEPTION_HEADER
