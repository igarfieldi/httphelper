/*
 * StatusLine.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_STATUSLINE_H_
#define HTTPHELPER_HTTP_STATUSLINE_H_

#include <map>
#include <string>

namespace httphelper {

class StatusLine {
public:
	enum class StatusCodes {
		CODE_100,
		CODE_101,
		CODE_102,
		CODE_103,
		CODE_200,
		CODE_201,
		CODE_202,
		CODE_203,
		CODE_204,
		CODE_205,
		CODE_206,
		CODE_207,
		CODE_208,
		CODE_226,
		CODE_300,
		CODE_301,
		CODE_302,
		CODE_303,
		CODE_304,
		CODE_305,
		CODE_306,
		CODE_307,
		CODE_308,
		CODE_400,
		CODE_401,
		CODE_402,
		CODE_403,
		CODE_404,
		CODE_405,
		CODE_406,
		CODE_407,
		CODE_408,
		CODE_409,
		CODE_410,
		CODE_411,
		CODE_412,
		CODE_413,
		CODE_414,
		CODE_415,
		CODE_416,
		CODE_417,
		CODE_418,
		CODE_420,
		CODE_421,
		CODE_422,
		CODE_423,
		CODE_424,
		CODE_425,
		CODE_426,
		CODE_428,
		CODE_429,
		CODE_431,
		CODE_451,
		CODE_500,
		CODE_501,
		CODE_502,
		CODE_503,
		CODE_504,
		CODE_505,
		CODE_506,
		CODE_507,
		CODE_508,
		CODE_509,
		CODE_510,
		CODE_511
	};

protected:
	std::string httpVersion;
	StatusCodes code;

	static const std::map<StatusCodes, std::string> statusCodeNames;

public:
	StatusLine(StatusCodes code);
	virtual ~StatusLine();

	void setCode(StatusCodes code);
	StatusCodes getCode() const;

	std::string toString() const;
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_STATUSLINE_H_ */
