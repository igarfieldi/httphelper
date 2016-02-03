/*
 * StatusLine.cc
 *
 *  Author: Florian Bethe
 */

#include "http/StatusLine.h"

namespace httphelper {


const std::map<StatusLine::StatusCodes, std::string> StatusLine::statusCodeNames = {
		std::make_pair(StatusLine::StatusCodes::CODE_100, "100 Continue"),
		std::make_pair(StatusLine::StatusCodes::CODE_101, "101 Switching Protocols"),
		std::make_pair(StatusLine::StatusCodes::CODE_102, "102 Processing"),
		std::make_pair(StatusLine::StatusCodes::CODE_103, "103 Checkpoint"),

		std::make_pair(StatusLine::StatusCodes::CODE_200, "200 OK"),
		std::make_pair(StatusLine::StatusCodes::CODE_201, "201 Created"),
		std::make_pair(StatusLine::StatusCodes::CODE_202, "202 Accepted"),
		std::make_pair(StatusLine::StatusCodes::CODE_203, "203 Non-Authoritative Information"),
		std::make_pair(StatusLine::StatusCodes::CODE_204, "204 No Content"),
		std::make_pair(StatusLine::StatusCodes::CODE_205, "205 Reset Content"),
		std::make_pair(StatusLine::StatusCodes::CODE_206, "206 Partial Content"),
		std::make_pair(StatusLine::StatusCodes::CODE_207, "207 Multi-Status"),
		std::make_pair(StatusLine::StatusCodes::CODE_208, "208 Already Reported"),
		std::make_pair(StatusLine::StatusCodes::CODE_226, "226 IM Used"),

		std::make_pair(StatusLine::StatusCodes::CODE_300, "300 Multiple Choices"),
		std::make_pair(StatusLine::StatusCodes::CODE_301, "301 Moved Permanently"),
		std::make_pair(StatusLine::StatusCodes::CODE_302, "302 Found"),
		std::make_pair(StatusLine::StatusCodes::CODE_303, "303 See Other"),
		std::make_pair(StatusLine::StatusCodes::CODE_304, "304 Not Modified"),
		std::make_pair(StatusLine::StatusCodes::CODE_305, "305 Use Proxy"),
		std::make_pair(StatusLine::StatusCodes::CODE_306, "306 Switch Proxy"),
		std::make_pair(StatusLine::StatusCodes::CODE_307, "307 Temporary Redirect"),
		std::make_pair(StatusLine::StatusCodes::CODE_308, "308 Permanent Redirect"),

		std::make_pair(StatusLine::StatusCodes::CODE_400, "400 Bad Request"),
		std::make_pair(StatusLine::StatusCodes::CODE_401, "401 Unauthorized"),
		std::make_pair(StatusLine::StatusCodes::CODE_402, "402 Payment Required"),
		std::make_pair(StatusLine::StatusCodes::CODE_403, "403 Forbidden"),
		std::make_pair(StatusLine::StatusCodes::CODE_404, "404 Not Found"),
		std::make_pair(StatusLine::StatusCodes::CODE_405, "405 Method Not Allowed"),
		std::make_pair(StatusLine::StatusCodes::CODE_406, "406 Not Acceptable"),
		std::make_pair(StatusLine::StatusCodes::CODE_407, "407 Proxy Authentication Required"),
		std::make_pair(StatusLine::StatusCodes::CODE_408, "408 Request Timeout"),
		std::make_pair(StatusLine::StatusCodes::CODE_409, "409 Conflict"),
		std::make_pair(StatusLine::StatusCodes::CODE_410, "410 Gone"),
		std::make_pair(StatusLine::StatusCodes::CODE_411, "411 Length Required"),
		std::make_pair(StatusLine::StatusCodes::CODE_412, "412 Precondition Failed"),
		std::make_pair(StatusLine::StatusCodes::CODE_413, "413 Payload Too Large"),
		std::make_pair(StatusLine::StatusCodes::CODE_414, "414 URI Too Long"),
		std::make_pair(StatusLine::StatusCodes::CODE_415, "415 Unsupported Media Type"),
		std::make_pair(StatusLine::StatusCodes::CODE_416, "416 Range Not Satisfiable"),
		std::make_pair(StatusLine::StatusCodes::CODE_417, "417 Expectation Failed"),
		std::make_pair(StatusLine::StatusCodes::CODE_418, "418 I'm a teapot"),
		std::make_pair(StatusLine::StatusCodes::CODE_421, "421 Misdirected Request"),
		std::make_pair(StatusLine::StatusCodes::CODE_422, "422 Unprocessable Entity"),
		std::make_pair(StatusLine::StatusCodes::CODE_423, "423 Locked"),
		std::make_pair(StatusLine::StatusCodes::CODE_424, "424 Failed Dependency"),
		std::make_pair(StatusLine::StatusCodes::CODE_426, "426 Upgrade Required"),
		std::make_pair(StatusLine::StatusCodes::CODE_428, "428 Precondition Required"),
		std::make_pair(StatusLine::StatusCodes::CODE_429, "429 Too Many Requests"),
		std::make_pair(StatusLine::StatusCodes::CODE_431, "431 Request Header Fields Too Large"),
		std::make_pair(StatusLine::StatusCodes::CODE_451, "451 Unavailable For Legal Reasons"),

		std::make_pair(StatusLine::StatusCodes::CODE_500, "500 Internal StatusLine Error"),
		std::make_pair(StatusLine::StatusCodes::CODE_501, "501 Not Implemented"),
		std::make_pair(StatusLine::StatusCodes::CODE_502, "502 Bad Gateway"),
		std::make_pair(StatusLine::StatusCodes::CODE_503, "503 Service Unavailable"),
		std::make_pair(StatusLine::StatusCodes::CODE_504, "504 Gateway Timeout"),
		std::make_pair(StatusLine::StatusCodes::CODE_505, "505 HTTP Version Not Supported"),
		std::make_pair(StatusLine::StatusCodes::CODE_506, "506 Variant Also Negotiates"),
		std::make_pair(StatusLine::StatusCodes::CODE_507, "507 Insufficient Storage"),
		std::make_pair(StatusLine::StatusCodes::CODE_508, "508 Loop Detected"),
		std::make_pair(StatusLine::StatusCodes::CODE_510, "510 Not Extended"),
		std::make_pair(StatusLine::StatusCodes::CODE_511, "511 Network Authentication Required")
};

StatusLine::StatusLine(StatusCodes code) :
	httpVersion("1.1"), code(code) {
}

StatusLine::~StatusLine() {
}

void StatusLine::setCode(StatusCodes code) {
	this->code = code;
}

StatusLine::StatusCodes StatusLine::getCode() const {
	return code;
}

std::string StatusLine::toString() const {
	return "HTTP/" + httpVersion + " " + statusCodeNames.at(code);
}

} /* namespace httphelper */
