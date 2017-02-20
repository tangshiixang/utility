/*
 * common.h
 *
 *  Created on: 2017年2月20日
 *      Author: root
 */

#ifndef UTILITY_COMMON_H_
#define UTILITY_COMMON_H_

#include <string>

class noncopyable
{
protected:
	noncopyable() {}
private:
	noncopyable(const noncopyable&) = delete;
	void operator=(const noncopyable&) = delete;
};

struct copyable{};

// For passing C-style string argument to a function.
class StringArg
{
public:
	StringArg(const char* pstring): m_str(pstring){}
	StringArg(const std::string&): m_str(string.c_str()){}
	const char *c_str(){return m_str;}
private:
	char * m_str;
};

template<typename To, typename From>
inline To implicit_cast(From s)
{
    return s;
}


struct Options
{
  uint16_t port;
  int length;
  int number;
  bool transmit, receive, nodelay;
  std::string host;
  Options()
    : port(0), length(0), number(0),
      transmit(false), receive(false), nodelay(false)
  {
  }
};
bool parseCommandLine(int argc, char* argv[], Options* opt);

#endif /* UTILITY_COMMON_H_ */
