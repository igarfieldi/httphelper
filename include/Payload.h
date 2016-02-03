/*
 * Payload.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_PAYLOAD_H_
#define HTTPHELPER_PAYLOAD_H_

namespace httphelper {

template < typename T, typename P >
class Payload {
protected:
	T message;
	P originalPacket;
	bool valid;

public:
	Payload() :
			message(), originalPacket(), valid(false) {
	}

	Payload(const T& message, const P& originalPacket) :
			message(message), originalPacket(originalPacket), valid(true) {
	}

	virtual ~Payload() {
	}

	virtual const T& getMessage() const {
		return message;
	}

	virtual void setMessage(const T& message) {
		this->message = message;
	}

	virtual const P& getOriginalPacket() const {
		return originalPacket;
	}

	virtual void setValidity(bool valid) {
		this->valid = valid;
	}

	virtual bool isValid() const {
		return valid;
	}

	virtual operator bool() const {
		return valid;
	}
};

} /* namespace httphelper */

#endif /* HTTPHELPER_PAYLOAD_H_ */
