/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

class FieldCharsCountManager final {
public:
	FieldCharsCountManager();

	void setCount(int count);
	[[nodiscard]] int count() const;
	[[nodiscard]] bool isLimitExceeded() const;
	[[nodiscard]] rpl::producer<> limitExceeds() const;

private:
	int _current = 0;
	int _previous = 0;
	bool _isLimitExceeded = false;

	rpl::event_stream<> _limitExceeds;

};

