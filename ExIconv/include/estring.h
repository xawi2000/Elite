/* 
* @Author: sxf
* @Date:   2015-12-15 09:43:18
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-15 13:31:14
*/
#ifndef ESTRING_H
#define ESTRING_H

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>


typedef uint16_t echar_t;

class estring
{
public:
	estring();
	estring(const std::string& str);
	estring(const estring& estr);
	estring(const char* cstr);
	estring(const echar_t* ecstr);
	~estring();

	void autoreadfile(const std::string& path);
	void autoreadstr(const std::string& str);
	void readfile(const std::string& path, const string& encode);
	void readstr (const std::string& str,  const string& encode);
	void readstr (const char* data,  const string& encode);

	const char* c_str();
	const echar_t* ec_str();

	std::string to_utf8();
	std::string to_str(const string& encode);

	int find(echar_t c);
	int length();

	void clear();
	void append(echar_t c);

	estring substr(int begin, int end);

	static const char* encodedetect (const char* data);

private:
	static std::string load_full_file(const string& path);

	std::basic_string<echar_t> data;

};






#endif // ESTRING_H