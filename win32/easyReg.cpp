#pragma once

#include"windows.h"
#include"winreg.h"
#include<stdexcept>

/* Use Modern C++ to Access the Windows Registry
* https://docs.microsoft.com/zh-cn/archive/msdn-magazine/2017/may/c-use-modern-c-to-access-the-windows-registry
*/

class RegistryError
	: public std::invalid_argument
{
public:
	RegistryError(const char* message, LONG errorCode)
		: std::invalid_argument{ message }
		, m_errorCode{ errorCode }
	{}
	LONG ErrorCode() const noexcept
	{
		return m_errorCode;
	}
private:
	LONG m_errorCode;
};

[[nodiscard]] inline DWORD RegGetDword(
	HKEY hKey,
	const std::wstring& subKey,
	const std::wstring& value
) {
	DWORD data{};
	DWORD dataSize = sizeof(data);
	LONG retCode = ::RegGetValue(
		hKey,
		subKey.c_str(),
		value.c_str(),
		RRF_RT_REG_DWORD,
		nullptr,
		&data,
		&dataSize
	);
	if (retCode != ERROR_SUCCESS)
	{
		throw RegistryError{ "Cannot read DWORD from registry.", retCode };
	}
	return data;
}
[[nodiscard]] inline ULONGLONG RegGetQword(
	HKEY hKey,
	const std::wstring& subKey,
	const std::wstring& value
) {
	ULONGLONG data{};
	DWORD dataSize = sizeof(data);
	LONG retCode = ::RegGetValue(
		hKey,
		subKey.c_str(),
		value.c_str(),
		RRF_RT_REG_DWORD,
		nullptr,
		&data,
		&dataSize
	);
	if (retCode != ERROR_SUCCESS)
	{
		throw RegistryError{ "Cannot read QWORD from registry.", retCode };
	}
	return data;
}
[[nodiscard]] inline std::wstring RegGetString(
	HKEY hKey,
	const std::wstring& subKey,
	const std::wstring& value
) {
	DWORD dataSize{};
	LONG retCode = ::RegGetValue(
		hKey,
		subKey.c_str(),
		value.c_str(),
		RRF_RT_REG_SZ,
		nullptr,
		nullptr,
		&dataSize
	);

	if (retCode != ERROR_SUCCESS)
	{
		throw RegistryError{ "Cannot read wstring from registry" , retCode };
	}
	std::wstring data;
	data.resize(dataSize / sizeof(wchar_t));
	retCode = ::RegGetValue(
		hKey,
		subKey.c_str(),
		value.c_str(),
		RRF_RT_REG_SZ,
		nullptr,
		&data[0],
		&dataSize
	);
	DWORD stringLengthInWchars = dataSize / sizeof(wchar_t);
	stringLengthInWchars--;
	data.resize(stringLengthInWchars);
	return data;
}
[[nodiscard]] inline std::wstring getWindowsBuildNumber()
{
	// cost 0.1us on my Surface Book 3
	return RegGetString(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\", L"CurrentBuildNumber");
}